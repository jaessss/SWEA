#include <stdio.h>
#define DIFF(a,b) a>b?a-b:b-a
#define min(a,b) a>b?b:a
#define MAXN 16+1
#define INF 0xffff

int map[MAXN][MAXN];

int N;

int ans;

int sum(int food[]){

	int rp = 0;
	int now_index;
	int sum = 0;
	int target_index = 0;

	while (rp <= N / 2){
		now_index = food[rp++];
		while (target_index <=N/2){

			if (target_index != now_index) sum += map[now_index][food[target_index]];
			target_index++;
		}
	}

	return sum;
}

void solve(){
	int cnt = 0;
	int Asum = 0;
	int Bsum = 0;
	

	for (int i = 1; i <= ((1 << N) - 1); i++){
		cnt = 0;
		for (int j = 0; j < N; j++)
			if (i & (1 << j)) cnt++;
		if (cnt == N / 2){
			int temp_indexA = 0;
			int temp_indexB = 0;

			int foodA[MAXN / 2] = { 0 };
			int foodB[MAXN / 2] = { 0 };
			for (int j = 0; j < N; j++){
				if (i & (1 << j)) foodA[temp_indexA++] = j;
				else foodB[temp_indexB++] = j;
			}
			Asum = sum(foodA);
			Bsum = sum(foodB);
			ans = min(ans, DIFF(Asum, Bsum));			
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
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &map[i][j]);

		ans = INF;
		solve();




		printf("#%d %d\n", testcase, ans);

	}


	return 0;
}
