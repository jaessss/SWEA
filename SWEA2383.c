#include <stdio.h>
#define MAXN 10 + 1
#define INF 0xffff
#define min(a,b) (a>b)?(b):(a)
#define ABS(a,b) (a>b)?(a-b):(b-a)

int N;
int map[MAXN][MAXN];
int time;
int ans;

typedef struct{
	int r, c;
	int distanc;
	int step;
	int remain;
}PERSON;

typedef struct{
	int r, c;
	int value;
}STEP;

typedef struct{
	PERSON array[MAXN];
	int rp, wp;
}QUEUE;

STEP step[2];
int stepwp;
QUEUE ready;//사람정보저장
QUEUE stepA;//계단A이용자 정보
QUEUE stepB;//

void init(){
	stepA.rp = stepA.wp = 0;
	stepB.rp = stepB.wp = 0;
	time = 0;
}

void solve(){
	ans = INF;
	int num;
	//rpwp초기화
	ready.rp = ready.wp = stepwp = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++){
			if (map[i][j] == 1){//사람 위치 판단
				PERSON temp;
				temp.r = i;
				temp.c = j;
				ready.array[ready.wp++] = temp;
			}
			else if (map[i][j] > 1){//계단 2개 위치 판단
				STEP temp;
				temp.r = i;
				temp.c = j;
				temp.value = map[i][j];
				step[stepwp++] = temp;
			}
			else continue;
		}
	num = ready.wp;//사람수

	//진행
	for (int i = 0; i <= ((1 << (num)) - 1); i++){
		init();//각 경우의 수마다 초기화
		for (int j = 0; j < num; j++){//계단 분배
			if (i & (1 << j)){//A계단
				ready.array[j].step = 1;
				int disr = ABS(ready.array[j].r, step[0].r);
				int disc = ABS(ready.array[j].c, step[0].c);
				ready.array[j].distanc = disr + disc;
			}
			else{//B계단
				ready.array[j].step = 2;
				int disr = ABS(ready.array[j].r, step[1].r);
				int disc = ABS(ready.array[j].c, step[1].c);
				ready.array[j].distanc = disr + disc;
			}
		}

		while (stepA.rp + stepB.rp < num){//종료조건
			//계단 입구 도착 확인
			for (int i = 0; i < num; i++)
				if (ready.array[i].distanc == 0){//계단 입구 도착했으면
					if ((ready.array[i].step == 1) && (stepA.wp - stepA.rp < 3)){//계단 위 3 명 판단하는 rp,wp
						ready.array[i].remain = step[0].value;
						stepA.array[stepA.wp++] = ready.array[i];
						ready.array[i].distanc = -1;
					}
					else if ((ready.array[i].step == 2) && (stepB.wp - stepB.rp < 3)){
						ready.array[i].remain = step[1].value;
						stepB.array[stepB.wp++] = ready.array[i];
						ready.array[i].distanc = -1;
					}
				}


			time++;
			//시간 경과에 따른 남은 이동 시간 감소
			//계단까지
			for (int i = 0; i < num; i++){
				if (ready.array[i].distanc > 0) ready.array[i].distanc--;
			}
			//계단 위
			for (int i = stepA.rp; i < stepA.wp; i++)
				if (--(stepA.array[i].remain) == 0) stepA.rp++;
			for (int i = stepB.rp; i < stepB.wp; i++)
				if (--(stepB.array[i].remain) == 0) stepB.rp++;					
		}
		ans = min(ans, time+1);
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
		
		solve();
		
		printf("#%d %d\n", testcase, ans);
	}
	return 0;
}