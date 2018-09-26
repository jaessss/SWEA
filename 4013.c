//특이한 자석
#include <stdio.h>

struct magnet
{
	int pole[8];
	int point;
};
//원형큐개념 착안, 고정된 배열에 인덱스를 가리키는 화살표만 변경해가며 확인
void rotate(struct magnet* mag, int dir)
{
	if (dir == 1)
	{
		mag->point = (mag->point + 7) % 8;	
	}
	else if (dir == -1)
	{
		mag->point = (mag->point + 1) % 8;
	}
}

int main(void)
{
	int T;
	int try[20][2];//각 시도 당 몇번 자석, 회전방향
	int K;//회전시키는 횟수 최대20
	int ans;
	struct magnet mag[4];

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; ++testcase)
	{
		//입력부
		scanf("%d", &K);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				scanf("%d", &mag[i].pole[j]);
			}
			mag[i].point = 0;
		}
		for (int i = 0; i < K; i++)
		{
			scanf("%d%d", &try[i][0], &try[i][1]);
		}

		//진행부
		for (int i = 0; i < K; i++)
		{
			switch (try[i][0]-1)
			{
			case 0:				
				if (mag[0].pole[(mag[0].point + 2) % 8] != mag[1].pole[(mag[1].point + 6) % 8])
				{					
					if (mag[1].pole[(mag[1].point + 2) % 8] != mag[2].pole[(mag[2].point + 6) % 8])
					{						
						if (mag[2].pole[(mag[2].point + 2) % 8] != mag[3].pole[(mag[3].point + 6) % 8])
							rotate(&mag[3], (-1)*try[i][1]);
						rotate(&mag[2], try[i][1]);
					}
					rotate(&mag[1], (-1)*try[i][1]);
				}
				rotate(&mag[0], try[i][1]);
				break;
			case 1:				
				if (mag[0].pole[(mag[0].point + 2) % 8] != mag[1].pole[(mag[1].point + 6) % 8])
					rotate(&mag[0], (-1)*try[i][1]);
				if (mag[1].pole[(mag[1].point + 2) % 8] != mag[2].pole[(mag[2].point + 6) % 8])
				{					
					if (mag[2].pole[(mag[2].point + 2) % 8] != mag[3].pole[(mag[3].point + 6) % 8])
						rotate(&mag[3], try[i][1]);
					rotate(&mag[2], (-1)*try[i][1]);
				}
				rotate(&mag[1], try[i][1]);
				break;
			case 2:							
				if (mag[1].pole[(mag[1].point + 2) % 8] != mag[2].pole[(mag[2].point + 6) % 8])
				{					
					if (mag[0].pole[(mag[0].point + 2) % 8] != mag[1].pole[(mag[1].point + 6) % 8])
						rotate(&mag[0], try[i][1]);
					rotate(&mag[1], (-1)*try[i][1]);
				}
				if (mag[2].pole[(mag[2].point + 2) % 8] != mag[3].pole[(mag[3].point + 6) % 8])
					rotate(&mag[3], (-1)*try[i][1]);
				rotate(&mag[2], try[i][1]);
				break;
			case 3:				
				if (mag[2].pole[(mag[2].point + 2) % 8] != mag[3].pole[(mag[3].point + 6) % 8])
				{				
					if (mag[1].pole[(mag[1].point + 2) % 8] != mag[2].pole[(mag[2].point + 6) % 8])
					{						
						if (mag[0].pole[(mag[0].point + 2) % 8] != mag[1].pole[(mag[1].point + 6) % 8])
							rotate(&mag[0], (-1)*try[i][1]);
						rotate(&mag[1], try[i][1]);
					}
					rotate(&mag[2], (-1)*try[i][1]);
				}
				rotate(&mag[3], try[i][1]);
				break;
			}			
		}
		//답도출부
		ans = 0;
		for (int i = 0; i < 4; i++)
		{//점수계산 -> 2의 제곱수는 비트연산으로 처리
			if (mag[i].pole[mag[i].point] == 1) ans += 1 << i;
		}

		printf("#%d %d\n", testcase, ans);
	}
	return 0;
}
