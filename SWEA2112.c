////49/50
////A B 투입순서 모두 고려 할 수 있게
//#include <stdio.h>
//#define min(a,b) (a>b)?(b):(a)
//#define INF 0xffff
//#define MAXD 13+1
//#define MAXW 20+1
//int Arow[MAXW] = { 0 };
//int Brow[MAXW];
//int D, W, K;
//int ans;
//int tempans[2];
//
//int check(int map[][MAXW], int ttry, int flag){
//
//	int start;
//	int cnt;
//	int ok = 0;
//	for (int i = 1; i <= W; i++){
//		cnt = 0;
//		for (int j = 2; j <= D; j++){
//			if (map[j - 1][i] == map[j][i]){
//				if (++cnt == K - 1){
//					ok |= (1 << i);
//					break;
//				}
//			}
//			else{
//				cnt = 0;
//			}
//		}
//	}
//
//	if ((1 << (W + 1)) - 2 == ok) {
//		tempans[flag] = min(tempans[flag], ttry);
//		return 1;
//	}
//	else return 0;
//}
//
//void DFS(int map[][MAXW], int ttry, int ttryRow, int flag){
//	
//	
//	if (check(map, ttry, flag) == 1) return;
//	else if (ttry == D) return;
//	else{
//		//투입순서 고려 
//		//for (int k = 0; k <= 1; k++){
//			if (flag == 0){
//				//A투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Arow[j];
//						}
//						DFS(map, ttry + 1, ttryRow,flag);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//				//B투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Brow[j];
//						}
//						DFS(map, ttry + 1, ttryRow, flag);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//			}
//			if (flag == 1){
//				//B투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Brow[j];
//						}
//						DFS(map, ttry + 1, ttryRow, flag);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//				//A투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Arow[j];
//						}
//						DFS(map, ttry + 1, ttryRow, flag);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}				
//			}
//		
//	}
//}
//
//int main(void)
//{
//	int T;
//	int map[MAXD][MAXW] = { 0 };
//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		//입력부
//		scanf("%d %d %d", &D, &W, &K);
//		for (int i = 1; i <= D; i++)
//			for (int j = 1; j <= W; j++)
//				scanf("%d", &map[i][j]);
//
//		for (int i = 1; i <= W; i++)
//			Brow[i] = 1;
//
//		ans = tempans[0]=tempans[1] = INF;
//		DFS(map, 0, 0,0);
//		DFS(map, 0, 0, 1);
//		ans = min( tempans[0] , tempans[1]);
//
//		printf("#%d %d\n", testcase, ans);
//	}
//	return 0;
//}




//
////A B 투입순서 모두 고려 할 수 있게
//#include <stdio.h>
//#define min(a,b) (a>b)?(b):(a)
//#define INF 0xffff
//#define MAXD 13+1
//#define MAXW 20+1
//int Arow[MAXW] = { 0 };
//int Brow[MAXW];
//int D, W, K;
//int ans;
//int tempans[2];
//
//int check(int map[][MAXW], int ttry){
//
//	int start;
//	int cnt;
//	int ok = 0;
//	for (int i = 1; i <= W; i++){
//		cnt = 0;
//		for (int j = 2; j <= D; j++){
//			if (map[j - 1][i] == map[j][i]){
//				if (++cnt == K - 1){
//					ok |= (1 << i);
//					break;
//				}
//			}
//			else{
//				cnt = 0;
//			}
//		}
//	}
//
//	if ((1 << (W + 1)) - 2 == ok) {
//		//tempans[flag] = min(tempans[flag], ttry);
//		ans = min(ans, ttry);
//		return 1;
//	}
//	else return 0;
//}
//
//void DFS(int map[][MAXW], int ttry, int ttryRow){
//
//
//	if (check(map, ttry) == 1) return;
//	else if (ttry == D) return;
//	else{
//		//투입순서 고려 
//		for (int k = 0; k <= 1; k++){
//			//if (flag == 0){
//			if (k == 0){
//				//A투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Arow[j];
//						}
//						DFS(map, ttry + 1, ttryRow);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//				//B투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Brow[j];
//						}
//						DFS(map, ttry + 1, ttryRow);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//			}
//			
//			//}
//			//if (flag == 1){
//			if (k == 1){
//				//B투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Brow[j];
//						}
//						DFS(map, ttry + 1, ttryRow);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//				//A투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Arow[j];
//						}
//						DFS(map, ttry + 1, ttryRow);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//			}
//			
//			//}
//		}
//	}
//}
//
//int main(void)
//{
//	int T;
//	int map[MAXD][MAXW] = { 0 };
//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		//입력부
//		scanf("%d %d %d", &D, &W, &K);
//		for (int i = 1; i <= D; i++)
//			for (int j = 1; j <= W; j++)
//				scanf("%d", &map[i][j]);
//
//		for (int i = 1; i <= W; i++)
//			Brow[i] = 1;
//
//		ans = tempans[0] = tempans[1] = INF;
//		DFS(map, 0, 0);
//		//DFS(map, 0, 0, 1);
//		//ans = min(tempans[0], tempans[1]);
//
//		printf("#%d %d\n", testcase, ans);
//	}
//	return 0;
//}


//
////시간초과 47/50
////A B 투입순서 모두 고려 할 수 있게
//#include <stdio.h>
//#define min(a,b) (a>b)?(b):(a)
//#define INF 0xffff
//#define MAXD 13+1
//#define MAXW 20+1
//int Arow[MAXW] = { 0 };
//int Brow[MAXW];
//int D, W, K;
//int ans;
//int tempans[2];
//int cnt;
//int ok = 0;
//
////int temp[MAXW];
//
//int check(int map[][MAXW], int ttry, int flag){
//
//	cnt=0;
//	ok = 0;
//	for (int i = 1; i <= W; i++){
//		cnt = 0;
//		for (int j = 2; j <= D; j++){
//			if (map[j - 1][i] == map[j][i]){
//				if (++cnt == K - 1){
//					ok |= (1 << i);
//					break;
//				}
//			}
//			else if (j + K - cnt > W) break;
//			else{
//				cnt = 0;
//			}
//		}
//	}
//
//	if ((1 << (W + 1)) - 2 == ok) {
//		tempans[flag] = min(tempans[flag], ttry);
//		return 1;
//	}
//	else return 0;
//}
//
//void DFS(int map[][MAXW], int ttry, int ttryRow, int flag){
//	//int temp[MAXW];
//	if (tempans[0]>ttry && tempans[1]>ttry){
//		if (check(map, ttry, flag) == 1) return;
//		//else if (ttry == D) return;
//		else{
//			//투입순서 고려 
//			//for (int k = 0; k <= 1; k++){
//			if (flag == 0){
//				//A투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Arow[j];
//						}
//						DFS(map, ttry + 1, ttryRow, 0);
//						DFS(map, ttry + 1, ttryRow, 1);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//				//B투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Brow[j];
//						}
//						DFS(map, ttry + 1, ttryRow, 0);
//						DFS(map, ttry + 1, ttryRow, 1);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//			}
//			if (flag == 1){
//				//B투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Brow[j];
//						}
//						DFS(map, ttry + 1, ttryRow, 0);
//						DFS(map, ttry + 1, ttryRow, 1);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//				//A투입
//				for (int i = 1; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						int temp[MAXW];
//						ttryRow |= (1 << i);
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = Arow[j];
//						}
//						DFS(map, ttry + 1, ttryRow, 0);
//						DFS(map, ttry + 1, ttryRow, 1);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//					}
//				}
//			}
//
//		}
//	}
//	else return;
//	
//}
//
//int main(void)
//{
//	int T;
//	int map[MAXD][MAXW] = { 0 };
//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		//입력부
//		scanf("%d %d %d", &D, &W, &K);
//		for (int i = 1; i <= D; i++)
//			for (int j = 1; j <= W; j++)
//				scanf("%d", &map[i][j]);
//
//		for (int i = 1; i <= W; i++)
//			Brow[i] = 1;
//
//		ans = tempans[0]=tempans[1] = INF;
//		DFS(map, 0, 0, 0);
//		DFS(map, 0, 0, 1);
//		ans = min( tempans[0] , tempans[1]);
//
//		printf("#%d %d\n", testcase, ans);
//	}
//	return 0;
//}







////48/50...
//#include <stdio.h>
//#define min(a,b) (a>b)?(b):(a)
//#define INF 0xffff
//#define MAXD 13+1
//#define MAXW 20+1
//int Arow[MAXW] = { 0 };
//int Brow[MAXW];
//int ABrow[2][MAXW];
//
//int D, W, K;
//int ans;
//int tempans[2];
//int cnt;
//int ok = 0;
//
//int check(int map[][MAXW], int ttry, int flag){
//
//	cnt = 0;
//	ok = 0;
//	for (int i = 1; i <= W; i++){
//		cnt = 0;
//		for (int j = 2; j <= D; j++){
//			if (map[j - 1][i] == map[j][i]){
//				if (++cnt >= K - 1){
//					ok |= (1 << i);
//					break;
//				}
//			}
//			else if (j + K - cnt -1 > D) return 0;
//			else{
//				cnt = 0;
//			}
//		}
//	}
//
//	if ((1 << (W + 1)) - 2 == ok) {
//		ans = min(ans, ttry);
//		//tempans[flag] = min(tempans[flag], ttry);
//		return 1;
//	}
//	else return 0;
//}
//
//void DFS(int map[][MAXW], int ttry, int ttryRow, int flag, int search){
//	int temp[MAXW];
//	//int temtry;
//	if (check(map, ttry, flag) == 1) return;
//	if (ans > ttry+1){
//			//if (flag == 0){
//				//A투입
//		for (int i = search; i <= D; i++){
//					if (!(ttryRow & (1 << i))){
//						//for (int j = 0; j < 2; j++){
//							//if (j == 1) i++;
//						//	if (j == 0){
//						
//						//DFS(map, ttry, ttryRow, 1, search + 1);
//						//temtry = ttryRow;
//						ttryRow |= (1 << i);
//
//						for (int j = 1; j <= W; j++){
//							temp[j] = map[i][j];
//							map[i][j] = ABrow[0][j];
//						}								
//						DFS(map, ttry + 1, ttryRow, 0, search+1);
//
//						for (int j = 1; j <= W; j++){							
//							map[i][j] = ABrow[1][j];
//						}
//						DFS(map, ttry + 1, ttryRow, 1, search+1);
//						for (int j = 1; j <= W; j++)
//							map[i][j] = temp[j];
//						//ttryRow = temtry;
//						DFS(map, ttry, ttryRow, 0, search + 1);
//							//}
//						//}
//
//					}
//				}
//			//}
//			//if (flag == 1){
//			//	//B투입
//			//	for (int i = 1; i <= D; i++){
//			//		if (!(ttryRow & (1 << i))){		
//			//			//for (int j = 0; j < 2; j++){
//			//				//if (j == 1) i++;
//			//			//	if (j == 0){
//			//					ttryRow |= (1 << i);
//			//					for (int j = 1; j <= W; j++){
//			//						temp[j] = map[i][j];
//			//						map[i][j] = Brow[j];
//			//					}
//			//					DFS(map, ttry + 1, ttryRow, 0);
//			//					DFS(map, ttry + 1, ttryRow, 1);
//			//					for (int j = 1; j <= W; j++)
//			//						map[i][j] = temp[j];
//			//			//	}
//			//			//}
//			//			
//			//		}
//			//	}				
//			//}
//	}
//	else return;	
//}
//
//int main(void)
//{
//	int T;
//	int map[MAXD][MAXW] = { 0 };
//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		//입력부
//		scanf("%d %d %d", &D, &W, &K);
//		for (int i = 1; i <= D; i++)
//			for (int j = 1; j <= W; j++)
//				scanf("%d", &map[i][j]);
//
//		for (int i = 1; i <= W; i++)
//			ABrow[1][i] = 1;
//
//		ans = tempans[0] = tempans[1] = INF;
//		DFS(map, 0, 0, 0,1);
//	//	DFS(map, 0, 0, 1,1);
//	//	ans = min(tempans[0], tempans[1]);
//
//		printf("#%d %d\n", testcase, ans);
//	}
//	return 0;
//}



//8:10
//#include <stdio.h>
//#define min(a,b) (a>b)?(b):(a)
//#define INF 0xffff
//#define MAXD 13+1
//#define MAXW 20+1
//int ABrow[2][MAXW];
//int D, W, K;
//int ans;
//int cnt;
//int ok = 0;
//int map[MAXD][MAXW] = { 0 };
//
//int check(int map[][MAXW], int ttry){
//
//	cnt = 0;
//	ok = 0;
//	for (int i = 1; i <= W; i++){
//		cnt = 0;
//		for (int j = 2; j <= D; j++){
//			if (map[j - 1][i] == map[j][i]){
//				if (++cnt >= K - 1){
//					ok |= (1 << i);
//					break;
//				}
//			}
//			else if (j + K - cnt - 1 > D) return 0;
//			else cnt = 0;			
//		}
//	}
//	if ((1 << (W + 1)) - 2 == ok) {
//		ans = min(ans, ttry);
//		return 1;
//	}
//	else return 0;
//}
//
//void DFS(int map[][MAXW], int ttry, int ttryRow, int search){
//	int temp[MAXW];
//	if (check(map, ttry) == 1) return;
//	if (ans > ttry + 1){
//		for (int i = search; i <= D; i++){
//			if (!(ttryRow & (1 << i))){				
//				ttryRow |= (1 << i);
//				for (int j = 1; j <= W; j++){
//					temp[j] = map[i][j];
//					map[i][j] = ABrow[0][j];//A약품 투입준비
//				}
//				DFS(map, ttry + 1, ttryRow, search + 1);
//
//				for (int j = 1; j <= W; j++){
//					map[i][j] = ABrow[1][j];//B약품 투입준비
//				}
//				DFS(map, ttry + 1, ttryRow, search + 1);
//
//				for (int j = 1; j <= W; j++)
//					map[i][j] = temp[j];//원상복구
//				DFS(map, ttry, ttryRow, search + 1); //투입x 다음 row확인
//			}
//		}	
//	}
//	else return;
//}
//
//int main(void)
//{
//	int T;
//	//int map[MAXD][MAXW] = { 0 };
//	freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		//입력부
//		scanf("%d %d %d", &D, &W, &K);
//		for (int i = 1; i <= D; i++)
//			for (int j = 1; j <= W; j++)
//				scanf("%d", &map[i][j]);
//
//		for (int i = 1; i <= W; i++)
//			ABrow[1][i] = 1;
//
//		ans = INF;
//		DFS(map, 0, 0, 1);
//
//		printf("#%d %d\n", testcase, ans);
//	}
//	return 0;
//}




//8:23
//49개
//#include <stdio.h>
//#define min(a,b) (a>b)?(b):(a)
//#define INF 0xffff
//#define MAXD 13+1
//#define MAXW 20+1
//int ABrow[2][MAXW];
//int D, W, K;
//int ans;
//int cnt;
//int ok = 0;
//int map[MAXD][MAXW] = { 0 };
//
//int check(int map[][MAXW], int ttry){
//
//	cnt = 0;
//	ok = 0;
//	for (int i = 1; i <= W; i++){
//		cnt = 0;
//		for (int j = 2; j <= D; j++){
//			if (map[j - 1][i] == map[j][i]){
//				if (++cnt >= K - 1){
//					ok |= (1 << i);
//					break;
//				}
//			}
//			else if (j + K - cnt - 1 > D) return 0;
//			else cnt = 0;
//		}
//	}
//	if ((1 << (W + 1)) - 2 == ok) {
//		ans = min(ans, ttry);
//		return 1;
//	}
//	else return 0;
//}
//
//void DFS(int map[][MAXW], int ttry, int ttryRow, int search){
//	int temp[MAXW];
//	if (check(map, ttry) == 1) return;
//	if (ans > ttry + 1 && search <= D){
//		if (!(ttryRow & (1 << search))){
//			ttryRow |= (1 << search);
//			for (int j = 1; j <= W; j++){
//				temp[j] = map[search][j];
//				map[search][j] = ABrow[0][j];//A약품 투입준비
//			}
//			DFS(map, ttry + 1, ttryRow, search + 1);
//
//			for (int j = 1; j <= W; j++){
//				map[search][j] = ABrow[1][j];//B약품 투입준비
//			}
//			DFS(map, ttry + 1, ttryRow, search + 1);
//
//			for (int j = 1; j <= W; j++)
//				map[search][j] = temp[j];//원상복구
//			DFS(map, ttry, ttryRow, search + 1); //투입x 다음 row확인
//		}
//	}
//	else return;
//}
//
//int main(void)
//{
//	int T;
//
//	//freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		//입력부
//		scanf("%d %d %d", &D, &W, &K);
//		for (int i = 1; i <= D; i++)
//			for (int j = 1; j <= W; j++)
//				scanf("%d", &map[i][j]);
//
//		for (int i = 1; i <= W; i++)
//			ABrow[1][i] = 1;
//
//		ans = INF;
//		DFS(map, 0, 0, 1);
//
//		printf("#%d %d\n", testcase, ans);
//	}
//	return 0;
//}




//8:31~
//정답 K=1 하드코딩
//#include <stdio.h>
//#define min(a,b) (a>b)?(b):(a)
//#define INF 0xffff
//#define MAXD 13+1
//#define MAXW 20+1
//int ABrow[2][MAXW];
//int D, W, K;
//int ans;
//int cnt;
//int ok;
//int map[MAXD][MAXW] = { 0 };
//
//int check(int map[][MAXW], int ttry){
//
//	cnt = 0;
//	ok = 0;
//	if (K == 1){
//		ans = 0;
//		return 1;
//	}
//	for (int i = 1; i <= W; i++){
//		cnt = 0;
//		for (int j = 2; j <= D; j++){
//			if (map[j - 1][i] == map[j][i]){
//				if (++cnt >= K - 1){
//					ok |= (1 << i);
//					break;
//				}
//			}
//			else if (j + K - cnt - 1 > D) return 0;
//			else cnt = 0;
//		}
//	}
//	if ((1 << (W + 1)) - 2 == ok) {
//		ans = min(ans, ttry);
//		return 1;
//	}
//	else return 0;
//}
//
//void DFS(int map[][MAXW], int ttry, int search){
//	int temp[MAXW];
//	if (check(map, ttry) == 1) return;
//	if (ans > ttry  && search <= D){
//		DFS(map, ttry, search + 1); //투입x 다음 row확인	
//		for (int j = 1; j <= W; j++){
//			temp[j] = map[search][j];//기존맵저장
//			map[search][j] = ABrow[0][j];//A약품 투입준비
//		}
//		DFS(map, ttry + 1, search + 1);
//
//		for (int j = 1; j <= W; j++){
//			map[search][j] = ABrow[1][j];//B약품 투입준비
//		}
//		DFS(map, ttry + 1, search + 1);
//
//		for (int j = 1; j <= W; j++)
//			map[search][j] = temp[j];//원상복구
//	}
//	else return;
//}
//
//int main(void)
//{
//	int T;
//	//freopen("sample_input.txt", "r", stdin);
//	setbuf(stdout, NULL);
//	scanf("%d", &T);
//
//	for (int testcase = 1; testcase <= T; ++testcase)
//	{
//		//입력부
//		scanf("%d %d %d", &D, &W, &K);
//		for (int i = 1; i <= D; i++)
//			for (int j = 1; j <= W; j++)
//				scanf("%d", &map[i][j]);
//
//		for (int i = 1; i <= W; i++)
//			ABrow[1][i] = 1;
//
//		ans = INF;
//		DFS(map, 0, 1);
//
//		printf("#%d %d\n", testcase, ans);
//	}
//	return 0;
//}


//9시~
//K조건 재확인
#include <stdio.h>
#define min(a,b) (a>b)?(b):(a)
#define INF 0xffff
#define MAXD 13+1
#define MAXW 20+1
int ABrow[2][MAXW];
int D, W, K;
int ans;
int cnt;
int ok;
int map[MAXD][MAXW] = { 0 };

int check(int map[][MAXW], int ttry){
	cnt = 1;
	ok = 0;////////////////K=1인경우 주의!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 1; i <= W; i++){
		cnt = 1;
		for (int j = 2; j <= D; j++){
			if (cnt>=K || map[j - 1][i] == map[j][i]){
				if (++cnt >= K ){
					ok |= (1 << i);
					break;
				}
			}
			else if (j + K - cnt - 1 > D) return 0;
			else cnt = 1;
		}
	}
	if ((1 << (W + 1)) - 2 == ok) {
		ans = min(ans, ttry);
		return 1;
	}
	else return 0;
}

void DFS(int map[][MAXW], int ttry, int search){
	int temp[MAXW];
	if (check(map, ttry) == 1) return;
	if (ans > ttry  && search<=D){		
				DFS(map, ttry, search + 1); //투입x 다음 row확인	
				for (int j = 1; j <= W; j++){
					temp[j] = map[search][j];//기존맵저장
					map[search][j] = ABrow[0][j];//A약품 투입준비
				}
				DFS(map, ttry + 1, search + 1);

				for (int j = 1; j <= W; j++){
					map[search][j] = ABrow[1][j];//B약품 투입준비
				}
				DFS(map, ttry + 1, search + 1);

				for (int j = 1; j <= W; j++)
					map[search][j] = temp[j];//원상복구
	}
	else return;
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
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 1; i <= D; i++)
			for (int j = 1; j <= W; j++)
				scanf("%d", &map[i][j]);

		for (int i = 1; i <= W; i++)
			ABrow[1][i] = 1;

		ans = INF;
		DFS(map, 0, 1);

		printf("#%d %d\n", testcase, ans);
	}
	return 0;
}