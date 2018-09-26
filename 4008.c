//숫자만들기
//중복순열 개념
//분기 방향 설정, 분기 시 변경되는 사항에 대한 원상복구 생각

#include <stdio.h>
#define MAXN 13+1
#define INF 0xffff;

int N;
int MAX = -INF;
int min = INF;
int array[MAXN];
int ans;

typedef struct
{
	int arr[4];
}OP;

OP operator;//파라미터 배열로 받기
int index;
int equation;
//DFS 받아야할 파라미터 확실히
void DFS(int equ, OP op, int ind)
{
	if (ind > N)
	{
		if (equ > MAX) MAX = equ;
		if (equ < min) min = equ;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (op.arr[i] > 0)
		{
			op.arr[i]--;//연산자 감소
			if (i == 0 )
			{
				DFS(equ + array[ind], op, ind + 1);
			}
			else if (i == 1 )
			{
				DFS(equ - array[ind], op, ind + 1);
			}
			else if (i == 2 )
			{
				DFS(equ*array[ind], op, ind + 1);
			}
			else
			{
				DFS(equ / array[ind], op, ind + 1);
			}
			op.arr[i]++;//다른 탐색을 위한 원상복구 주의
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
		scanf("%d", &N);
		for (int i = 0; i < 4; i++)
		{
			scanf("%d", &operator.arr[i]);
		}
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &array[i]);
		}

		//연산부
		ans = 0;
		index = 2;
		equation = array[1];
		MAX = -INF;
		min = INF;
		DFS(equation, operator, index);//초기값, 인덱스 신경써  
		ans = MAX - min;
		
		printf("#%d %d\n", testcase, ans);

	}
	return 0;
}
