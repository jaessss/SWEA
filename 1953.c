//탈주범 검거
//#include <stdio.h>
//#define MAXMAPSIZE 50
//int N, M, R, C, L;
//int map[MAXMAPSIZE][MAXMAPSIZE];
//int visit[MAXMAPSIZE][MAXMAPSIZE];
//int dr[4] = { -1, 1, 0, 0 };
//int dc[4] = { 0, 0, -1, 1 };
//int ans;
//int check[4][4] = { { 1, 2, 5, 6 }, { 1, 2, 4, 7 }, { 1, 3, 4, 5 }, { 1, 3, 6, 7 } };
//
//int check_func(int r, int c,int dir){
//	int ok = 0;
//
//	if (r + dr[dir] >= 0 && r + dr[dir] < N && c + dc[dir] >= 0 && c + dc[dir] < M)
//	{
//		for (int i = 0; i < 4; i++)
//			if (map[r + dr[dir]][c + dc[dir]] == check[dir][i]){
//				ok++;
//				break;
//			}
//	}
//	
//	if (ok != 0 && visit[r + dr[dir]][c + dc[dir]] <= 100000) return 1;
//	else return 0;
//}
//
//void search(int r, int c, int time){
//	
//	if (time > L) return;
//	
//	visit[r][c] += 1;
//
//	switch (map[r][c]){
//	case 1://상하좌우확인
//		for (int i = 0; i < 4; i++){
//			if (check_func(r,c,i))
//				search(r + dr[i], c + dc[i], time + 1);
//			else continue;
//		}
//		break;
//	case 2://상하확인
//		for (int i = 0; i < 2; i++){
//			if (check_func(r, c, i))
//				search(r + dr[i], c + dc[i], time + 1);
//			else continue;
//		}
//		break;
//	case 3://좌우확인
//		for (int i = 2; i < 4; i++){
//			if (check_func(r, c, i))
//				search(r + dr[i], c + dc[i], time + 1);
//			else continue;
//		}
//		break;
//	case 4://상우확인
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 0 && check_func(r, c, i))
//				search(r + dr[i], c + dc[i], time + 1);
//			if (i == 3 && check_func(r, c, i))
//				search(r + dr[i], c + dc[i], time + 1);
//		}
//		break;
//	case 5://하우확인
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 1 && check_func(r, c, i))
//				search(r + dr[i], c + dc[i], time + 1);
//			if (i == 3 && check_func(r, c, i))
//				search(r + dr[i], c + dc[i], time + 1);
//		}
//		break;
//	case 6://하좌
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 1 && check_func(r, c, i))
//				search(r + dr[i], c + dc[i], time + 1);
//			if (i == 2 && check_func(r, c, i))
//				search(r + dr[i], c + dc[i], time + 1);
//		}
//		break;
//	case 7://상좌
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 0 && check_func(r, c, i))
//				search(r + dr[i], c + dc[i], time + 1);
//			if (i == 2 && check_func(r, c, i))
//				search(r + dr[i], c + dc[i], time + 1);
//		}
//		break;
//	}	
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
//		//입력부
//		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
//		for (int i = 0; i < N; i++){
//			for (int j = 0; j < M; j++)
//				scanf("%d", &map[i][j]);
//		}
//		//연산부
//		ans = 0;
//		for (int i = 0; i < N; i++){
//			for (int j = 0; j < M; j++)
//				visit[i][j] = 0;
//		}
//		search(R, C, 1);
//		for (int i = 0; i < N; i++){
//			for (int j = 0; j < M; j++)
//				if (visit[i][j]) ans++;
//		}
//
//		//출력부
//		printf("#%d %d\n", testcase,ans);
//
//	}
//
//
//	return 0;
//}

//다른 visit check 방법
//
//#include <stdio.h>
//#define MAXMAPSIZE 50
//int N, M, R, C, L;
//int map[MAXMAPSIZE][MAXMAPSIZE];
//int visit[MAXMAPSIZE][MAXMAPSIZE][4];
//int dr[4] = { -1, 1, 0, 0 };
//int dc[4] = { 0, 0, -1, 1 };
//int ans;
//int check[4][4] = { { 1, 2, 5, 6 }, { 1, 2, 4, 7 }, { 1, 3, 4, 5 }, { 1, 3, 6, 7 } };
//
//typedef struct{
//	int r, c;
//	int ch;
//}NODE;
//
//int check_func(int r, int c, int dir){
//	int ok = 0;
//	int new_dir;
//	if (dir == 0) new_dir = 1;
//	else if (dir == 1)new_dir = 0;
//	else if (dir == 2)new_dir = 3;
//	else if (dir == 3)new_dir = 2;
//
//	if (r + dr[dir] >= 0 && r + dr[dir] < N && c + dc[dir] >= 0 && c + dc[dir] < M)
//	{
//		for (int i = 0; i < 4; i++)
//			if (map[r + dr[dir]][c + dc[dir]] == check[dir][i]){
//				ok++;
//				break;
//			}
//	}
//
//	if (ok != 0 && visit[r + dr[dir]][c + dc[dir]][new_dir] == 0){
//		visit[r + dr[dir]][c + dc[dir]][new_dir] = 1;
//		return 1;
//	}
//	else return 0;
//}
//
//void search(int r, int c, int time){
//
//	if (time > L) return;
//
//	//visit[r][c][i] = 1;
//
//	switch (map[r][c]){
//	case 1://상하좌우확인
//		for (int i = 0; i < 4; i++){
//			if (check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);
//			else continue;
//		}
//		break;
//	case 2://상하확인
//		for (int i = 0; i < 2; i++){
//			if (check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);				
//			else continue;
//		}
//		break;
//	case 3://좌우확인
//		for (int i = 2; i < 4; i++){
//			if (check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);				
//			else continue;
//		}
//		break;
//	case 4://상우확인
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 0 && check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);
//			if (i == 3 && check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);
//		}
//		break;
//	case 5://하우확인
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 1 && check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);
//			if (i == 3 && check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);
//		}
//		break;
//	case 6://하좌
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 1 && check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);
//			if (i == 2 && check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);
//		}
//		break;
//	case 7://상좌
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 0 && check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);
//			if (i == 2 && check_func(r, c, i)) search(r + dr[i], c + dc[i], time + 1);
//		}
//		break;
//	}
//}
//
//int main(void)
//{
//	int T;
//	int cnt;
//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		//입력부
//		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
//		for (int i = 0; i < N; i++){
//			for (int j = 0; j < M; j++)
//				scanf("%d", &map[i][j]);
//		}
//		//연산부
//		ans = 0;
//		for (int i = 0; i < N; i++){
//			for (int j = 0; j < M; j++)
//				for (int k = 0; k < 4;k++)
//					visit[i][j][k] = 0;
//		}
//		search(R, C, 1);
//		
//		for (int i = 0; i < N; i++){
//			for (int j = 0; j < M; j++){
//				cnt = 0;
//				for (int k = 0; k < 4; k++)
//					if (visit[i][j][k]){
//						cnt++;
//						break;
//					}
//				if (cnt!=0) ans++;
//			}
//				
//		}
//		//시작점 따로고려
//
//		//출력부
//		printf("#%d %d\n", testcase, ans);
//
//	}
//
//
//	return 0;
//}

//BFS
#include <stdio.h>
#define MAXMAPSIZE 50+1
int N, M, R, C, L;
int map[MAXMAPSIZE][MAXMAPSIZE];
int visit[MAXMAPSIZE][MAXMAPSIZE];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int ans;
int check[4][4] = { { 1, 2, 5, 6 }, { 1, 2, 4, 7 }, { 1, 3, 4, 5 }, { 1, 3, 6, 7 } };

typedef struct{
	int r, c;
	int time;
}NODE;

NODE queue[1000000];
int rp, wp;

int check_func(int r, int c,int dir,int time){
	int ok = 0;

	if (r + dr[dir] >= 0 && r + dr[dir] < N && c + dc[dir] >= 0 && c + dc[dir] < M)
	{
		for (int i = 0; i < 4; i++)
			if (map[r + dr[dir]][c + dc[dir]] == check[dir][i]){
				ok++;
				break;
			}
	}
	
	if (ok != 0 && time + 1<L && visit[r + dr[dir]][c + dc[dir]]==0) return 1;
	else return 0;
}

void BFS(int R, int C){
	NODE now;
	queue[wp].time = 0;
	queue[wp].r = R;
	queue[wp++].c = C;
	now.time = 0;

	while (rp < wp)
	{
		now.time = queue[rp].time;
		now.r = queue[rp].r;
		now.c = queue[rp++].c;

		visit[now.r][now.c] = 1;
		switch (map[now.r][now.c]){//파이프 종류에 따라 확인
		case 1://상하좌우확인
			for (int i = 0; i < 4; i++){
				if (check_func(now.r, now.c, i,now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
				else continue;
			}
			break;
		case 2://상하확인
			for (int i = 0; i < 2; i++){
				if (check_func(now.r, now.c, i, now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
				else continue;
			}
			break;
		case 3://좌우확인
			for (int i = 2; i < 4; i++){
				if (check_func(now.r, now.c, i, now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
				else continue;
			}
			break;
		case 4://상우확인
			for (int i = 0; i < 4; i++)
			{
				if (i == 0 && check_func(now.r, now.c, i, now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
				if (i == 3 && check_func(now.r, now.c, i, now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
			}
			break;
		case 5://하우확인
			for (int i = 0; i < 4; i++)
			{
				if (i == 1 && check_func(now.r, now.c, i, now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
				if (i == 3 && check_func(now.r, now.c, i, now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
			}
			break;
		case 6://하좌
			for (int i = 0; i < 4; i++)
			{
				if (i == 1 && check_func(now.r, now.c, i, now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
				if (i == 2 && check_func(now.r, now.c, i, now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
			}
			break;
		case 7://상좌
			for (int i = 0; i < 4; i++)
			{
				if (i == 0 && check_func(now.r, now.c, i, now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
				if (i == 2 && check_func(now.r, now.c, i, now.time)){
					queue[wp].time = now.time + 1;
					queue[wp].r = now.r + dr[i];
					queue[wp++].c = now.c + dc[i];
				}
			}
			break;
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
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++)
				scanf("%d", &map[i][j]);
		}
		//연산부
		ans = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++)
				visit[i][j] = 0;
		}
		rp = wp = 0;
		BFS(R, C);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++)
				if (visit[i][j]==1) ans++;
		}

		//출력부
		printf("#%d %d\n", testcase,ans);
	}
	return 0;
}
