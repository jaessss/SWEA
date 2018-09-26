//#include <stdio.h>
//#define min(a,b) a<b?a:b
//#define MAXMONTH 12
//#define INF 0xffff
//
//int toll[4];
//int plan[MAXMONTH + 1 + 2];
//int now_price;
//int ans;
////int temp_price;
////int temp[3];
//
//void DFS(int price, int plan[])
//{
//	int check = 0;
//	int start = 0;
//	//temp_price = 0;
//	//for (int i = 0; i < 3; i++) temp[i] = 0;
//	int temp_price;
//	int temp[3];
//	//base case
//	for (int i = 1; i <= 12; i++)
//		if (plan[i] != 0){
//			check++;
//			start = i;
//			break;
//		}
//	if (check == 0){
//		ans = min(now_price, ans);
//		return;
//	}
//	else{
//		//다중 재귀
//		//for (int k = start; k <= 12; k++)
//		//if (plan[k] != 0)
//		//{
//		for (int i = 1; i < 4; i++)
//		{
//			/*for (int k = 1; k <= 12; k++)
//			if (plan[k] != 0)
//			{*/
//
//			//if (flag==0 && i == 0){//1년권 사용
//			//	now_price = toll[3];
//			//	int temp[13];
//			//	for (int j = 1; j <= 12; j++){
//			//		temp[j] = plan[j];
//			//		plan[j] = 0;
//			//	}
//			//	
//			//	DFS(now_price, plan, flag+1);
//			//	for (int j = 1; j <= 12; j++)
//			//		plan[j] = temp[j];
//			//}
//
//			if (i == 1){//1일권 사용
//				for (int j = start; j <= 12; j++){
//					if (now_price + plan[j] * toll[0]<ans && plan[j] != 0){
//						temp_price = now_price;
//						now_price += plan[j] * toll[0];
//						temp[0] = plan[j];
//
//						plan[j] = 0;
//						DFS(now_price, plan);
//						plan[j] = temp[0];
//						now_price = temp_price;
//					}
//				}
//			}
//			else if (i == 2){//1달권 사용
//				for (int j = start; j <= 12; j++){
//					if (now_price + toll[1] <ans && (plan[j] != 0)){
//						temp_price = now_price;
//						now_price += toll[1];
//						temp[0] = plan[j];
//
//						plan[j] = 0;
//						DFS(now_price, plan);
//						plan[j] = temp[0];
//						now_price = temp_price;
//					}
//				}
//			}
//			else if (i == 3){//3달권 사용
//				for (int j = start; j <= 12; j++){
//					if (now_price + toll[2]<ans && plan[j] != 0){
//						temp_price = now_price;
//						now_price += toll[2];
//						temp[0] = plan[j];
//						temp[1] = plan[j + 1];
//						temp[2] = plan[j + 2];
//
//						plan[j] = plan[j + 1] = plan[j + 2] = 0;
//						DFS(now_price, plan);
//						plan[j] = temp[0];
//						plan[j + 1] = temp[1];
//						plan[j + 2] = temp[2];
//						now_price = temp_price;
//					}
//				}
//			}
//			//	}
//
//		}
//
//
//
//
//		//}
//		//else return;
//	}
//
//
//}
//
//int main(void)
//{
//	int T;
//
//	//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		//입력부
//		for (int i = 0; i < 4; i++)
//			scanf("%d", &toll[i]);
//		for (int i = 1; i <= MAXMONTH; i++)
//			scanf("%d", &plan[i]);
//
//		//연산부
//		now_price = 0;
//		ans = toll[3];
//
//		DFS(0, plan);
//
//
//		//출력부
//
//		printf("#%d %d\n", testcase, ans);
//
//	}
//
//
//	return 0;
//}

//#include <stdio.h>
//#define min(a,b) a<b?a:b
//#define MAXMONTH 12
//#define INF 0xffff
//
//int toll[4];
//int plan[MAXMONTH + 1 +2];
//int now_price;
//int ans;
//int stack[100000];
//int top=0;
////int temp_price;
////int temp[3];
////int check = 0;
//
//void DFS(int price, int plan[], int flag)
//{
//	int start = 0;
//
//	int check = 0;
//	//temp_price = 0;
//	//for (int i = 0; i < 3; i++) temp[i] = 0;
//	//int temp_price;
//	//int temp[3];
//	//base case
//	for (int i = 1; i <= 12; i++)
//		if (plan[i] != 0){
//			check++;
//			start = i;
//			break;
//		}
//	if (check == 0){
//		ans = min(now_price, ans);
//		switch (flag)
//		{
//		case 1:
//		case 2:
//			top-=2;
//			break;
//		case 3:
//			top -= 4;
//			break;
//		}
//		return;
//	}
//	else{
//		//다중 재귀
//		//for (int k = start; k <= 12; k++)
//			//if (plan[k] != 0)
//			//{
//				for (int i = 1; i < 4; i++)
//				{
//					/*for (int k = 1; k <= 12; k++)
//					if (plan[k] != 0)
//					{*/
//
//					//if (flag==0 && i == 0){//1년권 사용
//					//	now_price = toll[3];
//					//	int temp[13];
//					//	for (int j = 1; j <= 12; j++){
//					//		temp[j] = plan[j];
//					//		plan[j] = 0;
//					//	}
//					//	
//					//	DFS(now_price, plan, flag+1);
//					//	for (int j = 1; j <= 12; j++)
//					//		plan[j] = temp[j];
//					//}
//
//					if (i == 1){//1일권 사용
//						flag = 1;
//						for (int j = start; j <= 12; j++){
//							if (now_price + plan[j] * toll[0]<ans && plan[j] != 0){
//								stack[top++] = now_price;
//								now_price += plan[j] * toll[0];
//								stack[top++] = plan[j];
//								
//								plan[j] = 0;
//								DFS(now_price, plan,i);
//								plan[j] = stack[top--];
//								now_price = stack[top--];
//								
//							}
//						}
//					}
//					else if (i == 2){//1달권 사용
//						flag = 2;
//						for (int j = start; j <= 12; j++){
//							if (now_price + toll[1] <ans && (plan[j] != 0)){
//								stack[top++] = now_price;
//								now_price += toll[1];
//								stack[top++] = plan[j];
//								
//								plan[j] = 0;
//								DFS(now_price, plan, i);
//								plan[j] = stack[top--];
//								now_price = stack[top--];
//								
//							}
//						}
//					}
//					else if (i == 3){//3달권 사용
//						flag = 3;
//						for (int j = start; j <= 12; j++){
//							if (now_price + toll[2]<ans && plan[j] != 0){
//								stack[top++] = now_price;
//								now_price += toll[2];
//								stack[top++] = plan[j];
//								stack[top++] = plan[j + 1];
//								stack[top++] = plan[j + 2];
//								
//								plan[j] = plan[j + 1] = plan[j + 2] = 0;
//								DFS(now_price, plan, i);
//								plan[j + 2] = stack[top--];
//								plan[j + 1] = stack[top--];
//								plan[j] = stack[top--];
//								now_price = stack[top--];
//								
//							}
//						}
//					}
//					//	}
//					
//				}
//
//			//}
//			//else return;
//	}
//	
//
//}
//
//int main(void)
//{
//	int T;
//	int flag = 0;
//
//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		//입력부
//		for (int i = 0; i < 4; i++)
//			scanf("%d", &toll[i]);
//		for (int i = 1; i <= MAXMONTH; i++)
//			scanf("%d", &plan[i]);
//
//		//연산부
//		now_price = 0;
//		ans = toll[3];
//		flag= 1;
//		DFS(0, plan,flag);
//
//
//		//출력부
//
//		printf("#%d %d\n", testcase,ans);
//
//	}
//
//
//	return 0;
//}

//DP시도
#include <stdio.h>
#define min(a,b) a<b?a:b
#define MAXMONTH 12
#define INF 0xffff

int toll[4];
int plan[MAXMONTH + 1 + 2];
int DP[MAXMONTH + 1];
int ans;

void solve(){
	
	DP[12] = toll[3];//1년권과 비교
	DP[1] = min(plan[1] * toll[0], toll[1]);
	DP[1] = min(DP[1], toll[2]);
	DP[3] = toll[2];

	for (int i = 2; i <= MAXMONTH; i++){
		for (int j = 0; j < 2; j++){
			if (j == 0){//1일권vs1달권				
				DP[i] = min(DP[i - 1] + plan[i] * toll[0], DP[i-1]+toll[1]);				
			}
			else if (j == 1 && i>=3){//3달권vs이전값
				DP[i] = min(DP[i], DP[i - 3] + toll[2]);
				if (i == 12) DP[i] = min(DP[i], toll[3]);
			}
		}
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
		//입력부
		for (int i = 0; i < 4; i++)
			scanf("%d", &toll[i]);
		for (int i = 1; i <= MAXMONTH; i++)
			scanf("%d", &plan[i]);
		
		//연산부
		for (int i = 1; i <= 12; i++)
			DP[i] = 0;
		solve();
		ans = DP[12];

		//출력부
		printf("#%d %d\n", testcase, ans);
	}
	return 0;
}
