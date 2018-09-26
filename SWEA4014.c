
//flag 211122
//���μ��� ���ٿ� ���� ������ �ӽù迭�� �����ϰ� ���ڷ� �Ѱ� �Ǵ��ϵ���
#include <stdio.h>
#define MAXN 20+1

int map[MAXN][MAXN];
int N,X;
int ans;

int downcheck(int now_order, int now_index, int nowh, int flag){
	
	if (flag == 0){//����
		if (now_index + X-1 <= N){
			for (int i = 0; i < X; i++){
				if (nowh == map[now_order][now_index + i]) continue;
				else return 0;
			}
			return 1;
		}
		else return 0;
	}
	else if (flag == 1){//����
		if (now_index + X-1 <= N){
			for (int i = 0; i < X; i++){
				if (nowh == map[now_index + i][now_order]) continue;
				else return 0;
			}
			return 1;
		}
		else return 0;
	}
	else return 0;
}

int solve(){
	int upcnt;
	int cnt;
	int nowh;	
	int flag = 0;

	//����Ž��
	upcnt = cnt = nowh = 0;
	for (int i = 1; i <= N; i++){//���ζ��ε� Ž��
		nowh = map[i][1];
		upcnt = flag = 0;
		for (int j = 1; j <= N-1; j++){//�ϳ��� ���ο� ���� �˻�
			if (map[i][j + 1] == nowh){
				  upcnt++;
				  if (j == N - 1) cnt++;
				  if (flag == 1)upcnt--;//////////////////////////211122���� ��� ���� ��ġ���� Ȯ���� �������ÿ����� ��Ʈ
				  flag = 0;
			}
			else if (map[i][j + 1] > nowh){
				if (map[i][j + 1] == nowh + 1 && upcnt >= X-1){
					nowh++;
					upcnt = 0;
					if (j == N - 1) cnt++;
					flag = 0;
				}
				else break;
			}
			else {
				if (downcheck(i, j + 1, nowh - 1, 0)){
					j += (X-1);
					if (j == N - 1) cnt++;
					nowh--;
					upcnt = 0;
					flag = 1;//���� ��ġǥ��
				}
				else break;
			}
		}
	}
	
	//����Ž��
	upcnt = nowh = 0;
	for (int i = 1; i <= N; i++){
		nowh = map[1][i];
		upcnt = flag = 0;
		for (int j = 1; j <= N-1; j++){
			if (map[j+1][i] == nowh){
				upcnt++;		
				if (j == N - 1) cnt++;
				if (flag == 1)upcnt--;
				flag = 0;
			}
			else if (map[j+1][i] > nowh){
				if (map[j + 1][i] == nowh + 1 && upcnt >= X-1){
					nowh++;
					upcnt = 0;
					if (j == N - 1) cnt++;
					flag = 0;
				}
				else break;
			}
			else {
				if (downcheck(i, j + 1, nowh - 1, 1)){
					j += (X-1);					
					upcnt = 0;
					nowh--;
					flag = 1;
					if (j == N - 1) cnt++;
				}
				else break;
			}			
		}
	}
	return cnt;
}

int main(void)
{
	int T;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; ++testcase)
	{
		scanf("%d %d", &N, &X);

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &map[i][j]);

		ans = 0;
		ans = solve();

		printf("#%d %d\n", testcase,ans);
	}
	return 0;
}
//
//
//
//#include <stdio.h>
//#define MAXN 20+1
//
//int map[MAXN][MAXN];
//int N, X;
//int ans;
//
//int downcheck(int now_order, int now_index, int nowh, int flag){
//
//	if (flag == 0){//����
//		if (now_index + X - 1 <= N){
//			for (int i = 0; i < X; i++){
//				if (nowh == map[now_order][now_index + i]) continue;
//				else return 0;
//			}
//			return 1;
//		}
//		else return 0;
//	}
//	else if (flag == 1){//����
//		if (now_index + X - 1 <= N){
//			for (int i = 0; i < X; i++){
//				if (nowh == map[now_index + i][now_order]) continue;
//				else return 0;
//			}
//			return 1;
//		}
//		else return 0;
//	}
//	else return 0;
//
//
//}
//
//int solve(){
//	int upcnt;
//	int cnt;
//	int nowh;
//
//	//����Ž��
//	upcnt = cnt = nowh = 0;
//	for (int i = 1; i <= N; i++){//���ζ��ε� Ž��
//		nowh = map[i][1];
//		upcnt = 0;
//		for (int j = 1; j <= N - 1; j++){//�ϳ��� ���ο� ���� �˻�
//			if (map[i][j + 1] == nowh){
//				upcnt++;
//				if (j == N - 1) cnt++;
//			}
//			else if (map[i][j + 1] > nowh){
//				if (map[i][j + 1] == nowh + 1 && upcnt >= X - 1){
//					nowh++;
//					upcnt = 0;
//					if (j == N - 1) cnt++;
//				}
//				else break;
//			}
//			else {
//				if (downcheck(i, j + 1, nowh - 1, 0)){
//					j += (X - 1);
//					if (j == N - 1) cnt++;
//					nowh--;
//					upcnt = 0;
//				}
//				else break;
//			}
//		}
//	}
//
//	//����Ž��
//	upcnt = nowh = 0;
//	for (int i = 1; i <= N; i++){
//		nowh = map[1][i];
//		upcnt = 0;
//		for (int j = 1; j <= N - 1; j++){
//			if (map[j + 1][i] == nowh){
//				upcnt++;
//				if (j == N - 1) cnt++;
//			}
//			else if (map[j + 1][i] > nowh){
//				if (map[j + 1][i] == nowh + 1 && upcnt >= X - 1){
//					nowh++;
//					upcnt = 0;
//					if (j == N - 1) cnt++;
//				}
//				else break;
//			}
//			else {
//				if (downcheck(i, j + 1, nowh - 1, 1)){
//					j += (X - 1);
//					upcnt = 0;
//					nowh--;
//					if (j == N - 1) cnt++;
//				}
//				else break;
//			}
//		}
//	}
//
//	return cnt;
//}
//
//int main(void)
//{
//	int T;
//
//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		scanf("%d %d", &N, &X);
//
//		for (int i = 1; i <= N; i++)
//			for (int j = 1; j <= N; j++)
//				scanf("%d", &map[i][j]);
//
//		ans = 0;
//		ans = solve();
//
//		printf("#%d %d\n", testcase, ans);
//
//	}
//
//
//	return 0;
//}