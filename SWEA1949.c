#include <stdio.h>
#define MAXN 8+1
#define MAX(a,b) a>b?a:b

int ans;
int N, K;
int map[MAXN][MAXN];
int dr[4] = { -1, 1, 0, 0 };//ªÛ«œ¡¬øÏ
int dc[4] = { 0, 0, -1, 1 };
typedef struct{
	int r, c, h, cnt;
}NODE;

NODE queue[10000];
int rpq, wpq;
NODE maxbong[MAXN * MAXN];
int mrp, mwp;

int range(int r, int c){
	return ((r >= 1 && r <= N) && (c >= 1 && c <= N));
}

void BFS(int map[][MAXN], NODE start){
	rpq = wpq = 0;
	queue[wpq++] = start;

	while (rpq < wpq){
		NODE temp = queue[rpq++];
		for (int i = 0; i < 4; i++){
			if (range(temp.r + dr[i], temp.c + dc[i]) && temp.h>map[temp.r + dr[i]][temp.c + dc[i]]){
				if (temp.r + dr[i] != start.r || temp.c + dc[i] != start.c){
					NODE insert;
					insert.r = temp.r + dr[i];
					insert.c = temp.c + dc[i];
					insert.h = map[temp.r + dr[i]][temp.c + dc[i]];
					insert.cnt = temp.cnt + 1;
					queue[wpq++] = insert;
				}				
			}
			else if (i == 3)//¡¯«‡∫“∞° -> ¡æ∑·¡∂∞«
				ans = MAX(ans, temp.cnt);			
		}
	}
}

int main(void)
{
	int T;
	int maxbongvalue = 0;
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; ++testcase)
	{
		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &map[i][j]);

		ans = mrp = mwp = maxbongvalue = 0;
		//∏∆Ω∫∫¿øÏ∏Æ √£æ∆º≠ ∏∆Ω∫∫¿≈•ø° ¿˙¿Â
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				maxbongvalue = MAX(maxbongvalue, map[i][j]);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (maxbongvalue == map[i][j]){
					NODE temp;
					temp.r = i;
					temp.c = j;
					temp.h = map[i][j];
					temp.cnt = 1;
					maxbong[mwp++] = temp;					
				}
		//∏ ¿¸√º, k∞™, ∏∆Ω∫∫¿start¿ßƒ°∑Œ BFS»£√‚
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= K; k++){
						map[i][j] -= k;
						for (int l = 0; l < mwp;l++){
							NODE start = maxbong[l];
							BFS(map, start);
						}
						map[i][j] += k;		
				}

		printf("#%d %d\n", testcase, ans);
	}
	return 0;
}