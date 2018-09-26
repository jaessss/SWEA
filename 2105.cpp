//디저트 카페
//#include <stdio.h>
//#define MAX(a,b) a>b?a:b
//#define MAXN 20+1
//#define MAXDES 100+1
//
////typedef struct{
////	int r, c;
////}NODE;
//
//int map[MAXN][MAXN];
////NODE now;
//int ans;
//int N;
//int rr, cc;
//
//int DFS(int r, int c, int i, int j, int turn, int check[])
//{
//	if (turn == 1){//오위
//		if (r - 1 < 1 || c + 1 > cc+j) return DFS(r, c, i, j, turn + 1, check);
//		else{
//			if (check[map[r][c]]==1) return -1;
//			else{
//				check[map[r][c]] = 1;
//				return DFS(r - 1, c + 1, i, j, turn, check);
//			}
//		}
//
//	}
//	else if (turn == 2){//오아
//		if (r + 1 > rr || c + 1 > cc + i+j) return DFS(r, c, i, j, turn + 1, check);
//		else{
//			if (check[map[r][c]] == 1) return -1;
//			else{
//				check[map[r][c]] = 1;
//				return DFS(r + 1, c + 1, i, j, turn, check);
//			}
//		}
//	}
//	else if (turn == 3){//왼아
//		if (r + 1 > rr+i || c - 1 < 1) return DFS(r, c, i, j, turn + 1, check);
//		else{
//			if (check[map[r][c]] == 1) return -1;
//			else{
//				check[map[r][c]] = 1;
//				return DFS(r + 1, c - 1, i, j, turn, check);
//			}
//		}
//	}
//	else if (turn == 4){//왼위
//		if (r - 1 == rr && c - 1 == cc && check[map[r][c]]==0) return 1;
//		else{
//			if (check[map[r][c]] == 1 || r-1<1 || c-1<1) return -1;
//			else{
//				check[map[r][c]] = 1;
//				return DFS(r - 1, c - 1, i, j, turn, check);
//			}
//		}
//	}
//}
//
//void solve(int r, int c)
//{
//	int check[MAXDES] = { 0 };
//	int temp;
//	for (int i = 1; i <= N-2; i++){
//		for (int j = 1; j <= N-2; j++){
//			if (c + i + j > N || r - j <1 || r + i>N) continue;
//			else{
//				rr = r;
//				cc = c;
//				for (int k = 0; k < MAXDES; k++) check[k] = 0;
//				if (DFS(r, c, i, j, 1, check) == 1){
//					temp = 2 * (i + j);					
//				}
//				else temp = -1;
//				ans = MAX(ans, temp);
//			}
//		}
//	}
//}
////체크배열 지역변수로
//
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
//		//입력부
//		scanf("%d", &N);
//		for (int i = 1; i <= N; i++){
//			for (int j = 1; j <= N; j++){
//				scanf("%d", &map[i][j]);
//			}
//		}
//
//		//연산부
//		ans = -1000;
//		//모든점에 대해 탐색
//		for (int i = 1; i <= N; i++){
//			for (int j = 1; j <= N; j++){
//				solve(i, j);
//			}
//		}
//		//solve(3, 1);
//
//
//		printf("#%d %d\n", testcase,ans);
//
//	}
//
//
//	return 0;
//}

//
//#include <stdio.h>
//#define MAX(a,b) a>b?a:b
//#define MAXN 20+1
//#define MAXDES 100+1
//
////typedef struct{
////	int r, c;
////}NODE;
//
//int map[MAXN][MAXN];
////NODE now;
//int ans;
//int N;
//int rr, cc;
//
//int DFS(int r, int c, int i, int j, int turn, int check[])
//{
//	if (turn == 1){//오위
//		if (r - 1 < 1 || c + 1 > cc + j) return DFS(r, c, i, j, turn + 1, check);
//		else{
//			if (check[map[r][c]] == 1) return -1;
//			else{
//				check[map[r][c]] = 1;
//				return DFS(r - 1, c + 1, i, j, turn, check);
//			}
//		}
//
//	}
//	else if (turn == 2){//오아
//		if (r + 1 > rr +i|| c + 1 > cc + i + j) return DFS(r, c, i, j, turn + 1, check);
//		else{
//			if (check[map[r][c]] == 1) return -1;
//			else{
//				check[map[r][c]] = 1;
//				return DFS(r + 1, c + 1, i, j, turn, check);
//			}
//		}
//	}
//	else if (turn == 3){//왼아
//		if (r + 1 > rr  || c - 1 < 1) return DFS(r, c, i, j, turn + 1, check);
//		else{
//			if (check[map[r][c]] == 1) return -1;
//			else{
//				check[map[r][c]] = 1;
//				return DFS(r + 1, c - 1, i, j, turn, check);
//			}
//		}
//	}
//	else if (turn == 4){//왼위
//		if (r == rr && c == cc && check[map[r][c]] == 0) return 1;
//		else{
//			if (check[map[r][c]] == 1 || r - 1<1 || c - 1<1) return -1;
//			else{
//				check[map[r][c]] = 1;
//				return DFS(r - 1, c - 1, i, j, turn, check);
//			}
//		}
//	}
//}
//
//void solve(int r, int c)
//{
//	int check[MAXDES] = { 0 };
//	int temp;
//	for (int i = 1; i <= N - 2; i++){
//		for (int j = 1; j <= N - 2; j++){
//			if (c + i + j > N || r - j <1 || r + i>N) continue;
//			else{
//				rr = r;
//				cc = c;
//				for (int k = 0; k < MAXDES; k++) check[k] = 0;
//				if (DFS(r, c, i, j, 1, check) == 1){
//					temp = 2 * (i + j);
//				}
//				else temp = -1;
//				ans = MAX(ans, temp);
//			}
//		}
//	}
//}
////체크배열 지역변수로
//
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
//		//입력부
//		scanf("%d", &N);
//		for (int i = 1; i <= N; i++){
//			for (int j = 1; j <= N; j++){
//				scanf("%d", &map[i][j]);
//			}
//		}
//
//		//연산부
//		ans = -1000;
//		//모든점에 대해 탐색
//		for (int i = 1; i <= N; i++){
//			for (int j = 1; j <= N; j++){
//				solve(i, j);
//			}
//		}
//		//solve(3, 1);
//
//
//		printf("#%d %d\n", testcase, ans);
//
//	}
//
//
//	return 0;
//}

#include <stdio.h>
#define MAX(a,b) a>b?a:b
#define MAXN 20+1
#define MAXDES 100+1

//typedef struct{
//	int r, c;
//}NODE;

int map[MAXN][MAXN];
//NODE now;
int ans;
int N;
int rr, cc;

int DFS(int r, int c, int i, int j, int turn, int check[])
{
	if (turn == 1){//오위
		if (r - 1 < 1 || c + 1 > cc + j) return DFS(r, c, i, j, turn + 1, check);
		else{
			if (check[map[r][c]] == 1) return -1;
			else{
				check[map[r][c]] = 1;
				return DFS(r - 1, c + 1, i, j, turn, check);
			}
		}

	}
	else if (turn == 2){//오아
		if (r + 1 > rr+i || c + 1 > cc + i + j) return DFS(r, c, i, j, turn + 1, check);
		else{
			if (check[map[r][c]] == 1) return -1;
			else{
				check[map[r][c]] = 1;
				return DFS(r + 1, c + 1, i, j, turn, check);
			}
		}
	}
	else if (turn == 3){//왼아
		if (r + 1 > rr + i || c - 1 < 1) return DFS(r, c, i, j, turn + 1, check);
		else{
			if (check[map[r][c]] == 1) return -1;
			else{
				check[map[r][c]] = 1;
				return DFS(r + 1, c - 1, i, j, turn, check);
			}
		}
	}
	else if (turn == 4){//왼위
		if (r - 1 == rr && c - 1 == cc && check[map[r][c]] == 0) return 1;//정상탐색완료
		else{
			if (check[map[r][c]] == 1 || r - 1<1 || c - 1<1) return -1;
			else{
				check[map[r][c]] = 1;
				return DFS(r - 1, c - 1, i, j, turn, check);
			}
		}
	}
}

void solve(int r, int c)
{
	int check[MAXDES] = { 0 };
	int temp;
	for (int i = 1; i <= N - 2; i++){
		for (int j = 1; j <= N - 2; j++){//i,j가 직사각형 각 변의 길이
			if (c + i + j > N || r - j <1 || r + i>N) continue;//범위 검사
			else{
				rr = r;//시작점 저장
				cc = c;
				for (int k = 0; k < MAXDES; k++) check[k] = 0;
				if (DFS(r, c, i, j, 1, check) == 1){
					temp = 2 * (i + j);
				}
				else temp = -1;
				ans = MAX(ans, temp);
			}
		}
	}
}
//체크배열 지역변수로


int main(void)
{
	int T;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; ++testcase)
	{
		//입력부
		scanf("%d", &N);
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				scanf("%d", &map[i][j]);
			}
		}

		//연산부
		ans = -1000;
		//모든점에 대해 탐색
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				solve(i, j);
			}
		}

		printf("#%d %d\n", testcase, ans);
	}
	
	return 0;
}
