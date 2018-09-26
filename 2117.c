//홈 방범 서비스
//#include <stdio.h>
//#define MAXN 20+1
//#define MAX(a,b) ((a>b)?(a):(b))
//#define ABS(a,b) a>b?a-b:b-a
//
//int N, M;
//int ans;
//int map[MAXN][MAXN];
//int dr[4] = { -1, 0, 1, 0 };
//int dc[4] = { 0, 1, 0, -1 };
//
//typedef struct{
//	int r, c, k;
//}NODE;
//NODE queue[MAXN*MAXN*MAXN*MAXN];
//
//void solve(int r, int c);
//int check(int visit[][MAXN], int K);
//int range(int r, int c, int nowr, int nowc, int K);
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
//		scanf("%d %d", &N, &M);
//		for (int i = 1; i <= N; i++)
//			for (int j = 1; j <= N; j++)
//				scanf("%d", &map[i][j]);
//
//		//연산부
//		ans = 0;
//		for (int i = 1; i <= N; i++)
//			for (int j = 1; j <= N; j++)
//				solve(i, j);
//
//
//
//		//출력부
//		printf("#%d %d\n", testcase, ans);
//
//	}
//
//
//	return 0;
//}
//
//void solve(int r, int c){
//
//	int cont = 1;
//	int K = 1;
//
//	int rp = 0, wp = 0;
//	int visit[MAXN][MAXN] = { 0 };
//	NODE now;
//	now.r = r;
//	now.c = c;
//	now.k = 1;
//	queue[wp++] = now;
//	visit[now.r][now.c] = 1;
//	while (cont){
//
//		cont = check(visit, K);
//
//		do{
//			NODE temp;
//			if (rp < wp){
//				temp = queue[rp];
//			}
//			else break;
//			//visit[temp.r][temp.c] = 1;
//
//			if (temp.k <= N){
//				for (int i = 0; i < 4; i++){
//					if (range(temp.r + dr[i], temp.c + dc[i], now.r, now.c, K + 1) && visit[temp.r + dr[i]][temp.c + dc[i]] == 0){
//						visit[temp.r + dr[i]][temp.c + dc[i]] = 1;
//						queue[wp].r = temp.r + dr[i];
//						queue[wp].c = temp.c + dc[i];
//						queue[wp++].k = temp.k + 1;
//					}
//				}
//			}
//
//			
//		} while (queue[++rp].k <= K && rp < wp);
//		//queue[++rp].k <= K &&  rp<wp
//
//		//cont = check(visit, K);
//		//if (K == N)cont = 0;
//		//else K++;
//		K++;
//
//
//	}
//
//}
//int check(int visit[][MAXN], int K){
//	int cnt = 0;
//	if (K <= N+1){
//		for (int i = 1; i <= N; i++)
//			for (int j = 1; j <= N; j++)
//				if (map[i][j] == 1 && visit[i][j] == 1) cnt++;
//
//		if (cnt*M >= K*K + (K - 1)*(K - 1)){
//			ans = MAX(ans, cnt);
//		}
//		return 1;
//
//	}
//	else return 0;
//
//
//}
//
//int range(int r, int c, int nowr, int nowc, int K){
//	int diff = 0;
//	int diffr, diffc;
//	//diff = (ABS(r, nowr) + ABS(c, nowc));
//	if (r > nowr)diffr = r - nowr;
//	else diffr = nowr - r;
//	if (c > nowc)diffc = c - nowc;
//	else diffc = nowc - c;
//	diff = diffr + diffc;
//	/*if (r > 0 && r <= N && c > 0 && c <= N && diff<=K){
//
//	}*/
//	return (r > 0 && r <= N && c > 0 && c <= N && diff < K);
//}

//다른 사람 코드
//#include<stdio.h>
//#include<stdlib.h>
//
//int S[20][20];
//int N, M;
//int K;
//int max;
//
//int pos(int y, int x) {
//	if (x < 0 || y < 0 || x >= N || y >= N)
//		return 0;
//
//	if (S[y][x] == 1)
//		return 1;
//	else
//		return 0;
//
//
//}
//
//
//void how_many(int y, int x) {
//	int sum, i, j;
//
//	sum = 0;
//
//	for (i = y - K + 1; i <= y + K - 1; i++) {
//		for (j = x - K + 1; j <= x + K - 1; j++){
//			if (abs(i - y) + abs(j - x) <= K - 1) {
//				sum += pos(i, j);
//				if ((sum * M) - (K*K) - (K - 1)*(K - 1) >= 0){
//					//printf("k = %d, [%d][%d] [%d][%d] sum = %d, max = %d\n", K, y, x, i, j, sum, max);
//					if (max < sum){
//						max = sum;
//					}
//				}
//			}
//		}
//	}
//}
//
//
//int main() {
//	int testcase;
//	int i, j, k;
//	freopen("sample_input.txt", "r", stdin);
//
//	scanf("%d", &testcase);
//
//	for (i = 0; i < testcase; i++) {
//		scanf("%d %d", &N, &M);
//
//		for (j = 0; j < N; j++) {
//			for (k = 0; k < N; k++) {
//				scanf("%d", &S[j][k]);
//			}
//		}
//		max = 0;
//		K = 1;
//		while (K <= N + 1) {
//			for (j = 0; j < N; j++) {
//				for (k = 0; k < N; k++) {
//					how_many(j, k);
//				}
//			}
//			K++;
//		}
//		printf("#%d %d\n", i + 1, max);
//	}
//}

//pass
#include <stdio.h>
#define MAXN 20+1
#define MAX(a,b) ((a>b)?(a):(b))
#define ABS(a,b) (a>b)?(a-b):(b-a)

int N, M;
int ans;
int map[MAXN][MAXN];
int cost[MAXN+1];

void solve(int r, int c, int k);
int check(int r, int c, int startR, int startC, int k);
int range(int r, int c);

int main(void)
{
	int T;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	//cost값 미리계산
	for (int i = 1; i <= MAXN+1; i++)
		cost[i] = i*i + (i - 1)*(i - 1);

	for (int testcase = 1; testcase <= T; ++testcase)
	{
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &map[i][j]);

		//연산부		
		ans = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= N + 1; k++)//K값 변경하면서 진행
					solve(i, j, k);

		//출력부
		printf("#%d %d\n", testcase, ans);
	}
	return 0;
}

void solve(int r, int c, int k){		
	int cnt = 0;
	for (int i = r - k + 1; i <= r + k - 1; i++)//마름모 확인
		for (int j = c - k + 1; j <= c + k - 1; j++)
			if (check(i, j, r, c, k) == 1)	//집 유무 확인
				cnt++;		
	
	if (cnt * M >= cost[k])
		ans = MAX(cnt, ans);
}

int check(int r, int c, int startR, int startC, int k){//map안에 마름모꼴 안에 속하는 위치인지
		
	if (map[r][c] == 1 && range(r, c)){//집이 있으면 
		int diffR = ABS(r, startR);
		int diffC = ABS(c, startC);
		int diff = diffR + diffC;
		if (diff < k) return 1;
		else return 0;
	}
	else return 0;
}

int range(int r, int c){
	return ((r >= 1 && r <= N) && (c >= 1 && c <= N));
}



//다른 사람 코드
//#include <stdio.h>
//#include <stdlib.h>
// 
//int main() {
//    int t, hx[400], hy[400], idx, n, m, ans;
//    char a[20][20];
//    scanf("%d", &t);
//    for (int tc = 1; tc <= t; tc++) {
//        ans = idx = 0;
//        scanf("%d%d", &n,&m);
//        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
//            scanf(" %c", &a[i][j]);
//            if (a[i][j] == '1') hx[idx] = i, hy[idx++] = j;
//        }
//        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
//            int c[41] = { 0, };
//            for (int k = 0; k < idx; k++) c[abs(i - hx[k]) + abs(j - hy[k]) + 1]++;
//            for (int k = 1; k < 41; k++) {
//                c[k] += c[k - 1];
//                if (c[k] > ans && c[k] * m - ((k - 1)*(k - 1) + k * k) >= 0)
//                    ans = c[k];
//            }
//        }
//        printf("#%d %d\n",tc,ans);
//    }
//    return 0;
//}
