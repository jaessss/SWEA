#include <stdio.h>
#define MAX(a,b) (a>b)?(a):(b)
#define MAXM 25+1

long long N;
int M;
int select[MAXM];
//0번부터 M-1번 상품
typedef struct{
	long long price;
	int good;
	int select;
}PRODUCT;

PRODUCT product[MAXM];
PRODUCT selproduct[MAXM];
int ans; 


void solve(){

	long long temppricesum;
	int tempgoodsum;

	for (int i = 0; i <= ((1 << M) - 1); i++){
		temppricesum = 0;
		tempgoodsum = 0;
		for (int j = 0; j < M; j++){
			product[j].select = 0;
			if (i & (1 << j)){
				temppricesum += product[j].price;
				tempgoodsum += product[j].good;
				product[j].select = 1;
			}
		}

		if (temppricesum <= N){			
			if (ans < tempgoodsum){
				for (int j = 0; j < M; j++){
					selproduct[j].select = 0;
					if (product[j].select) selproduct[j].select = 1;					
				}
				ans = tempgoodsum;
			}
		}
		else continue;
	}
}

int main(void)
{
	int T;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; ++testcase)
	{		
		scanf("%lld %d", &N,&M);
		for (int i = 0; i < M; i++)
			scanf("%lld %d", &product[i].price, &product[i].good);

		ans = 0;
		solve();

		printf("#%d ", testcase);
		for (int i = 0; i < M; i++)
			if (selproduct[i].select==1) printf("%d ", i);
		printf("%d\n", ans);
	}
	return 0;
}