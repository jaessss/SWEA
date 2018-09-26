//18.4.12 pass
//��������ȭ -> ��Ʈ����ŷ���� ��ü Ž��
#include <stdio.h>
#define MAXN 10+1
#define MAXM 5+1
#define MAX(a,b) (a>b)?(a):(b)

int ans;
int N, M, C;
int map[MAXN][MAXN];
int visit[MAXN][MAXN];

int cal(int r, int c){//��������ȭ �־��� ����� �߿� �ִ� ���� Ȯ��
	int Array[MAXN];
	int tempsum = 0;
	int tempsquaresum = 0;
	int gain = 0;
	for (int i = 0; i < M; i++)//Ȯ�� ��� array�����	
		Array[i] = map[r][c + i];
	
	for (int i = 0; i <= ((1 << M) - 1); i++){//���� ����� �� Ȯ��
		tempsum = 0;
		tempsquaresum = 0;
		for (int j = 0; j < M; j++){
			if (i & (1 << j)){
				tempsum += Array[j];
				tempsquaresum += Array[j]*Array[j];
			}
			else continue;
		}

		if (tempsum > C) continue;
		else{
			gain = MAX(tempsquaresum, gain);
		}
	}
	return gain;
}

int check(int visit[][MAXN]){//�ϲ�B ������ ��� �� �ִ� ���� Ȯ��
	int gain = 0;
	int tempgain = 0;
	for (int i = 1; i <= N; i++)//row
		for (int j = 1; j <= N - M + 1; j++){//col
			if (!visit[i][j] && !visit[i][j + M - 1]){//visitȮ���ؼ� ������ġ �Ǵ�
				tempgain = cal(i, j);
				gain = MAX(gain, tempgain);
			}				
		}
	return gain;
}

void solve(){
	//A����
	int gainA, gainB;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N - M + 1; j++){
			for (int k = j; k <= j + M - 1; k++)
				visit[i][k] = 1;//visit üũ �� ����
			
			gainA = cal(i, j);			
			gainB = check(visit);
			ans = MAX(ans, gainA + gainB);
			for (int k = j; k <= j + M - 1; k++)
				visit[i][k] = 0;//visit ���󺹱�
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
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &map[i][j]);

		ans =  0;
		solve();

		printf("#%d %d\n", testcase,ans);

	}


	return 0;
}

//�ٸ���� DP �ڵ�
/*
#include <stdio.h>

int n, m, c;
int map[12][12];
int dp[12][12]; // ���� �ִ밪 ����

void findMax(int x, int y) {
	int cnt = 0;
	int sum = 0;
	int max = -1;
	for (int i = 0; i < (1 << m); i++) {
		sum = cnt = 0;
		for (int j = 0; j < m; j++) {
			if (i & (1 << j))
				cnt += map[x][y + j];
		}

		if (cnt <= c) {
			for (int j = 0; j < m; j++) {
				if (i & (1 << j))
					sum += (map[x][y + j] * map[x][y + j]);
			}

			if (max < sum) max = sum;
		}
	}

	dp[x][y] = max;
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 0;
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		scanf("%d %d %d", &n, &m, &c);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		init();

		// dp�� �� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++) {
				findMax(i, j);
			}
		}

		int ans = -1;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b <= n - m; b++) {
				for (int c = 0; c < n; c++) {
					for (int d = 0; d <= n - m; d++) {
						if (a == c) {
							if (b == d) continue;
							else if (b < d && b + m >= d) continue;
							else if (b > d && d + m >= b) continue;
						}

						int val = dp[a][b] + dp[c][d];
						if (ans < val) ans = val;
					}
				}
			}
		}


		printf("#%d %d\n", t, ans);
	}
}
*/