#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#define N 5 //N을 다음 숫자로 치환한다. 빙고의 크기 
#define M //M을 다음 숫자로 치환한다. 빙고에서 이기는 조건 

/*
1. 프로그램 시작 시 상대방(컴퓨터)와 내가 아래와 같이 NxN 크기 표에 1~N*N 사이의 숫자가 한번 씩 쓰여진 빙고 테이블 두 개를 만든다.
2. 숫자 배치는 random으로 함
3. 매 turn마다 다음을 반복
	-나의 현재 NxN 빙고 테이블 상태를 화면에 표시 (이미 채운 칸은 -1을 표시하고, 아직 채워지지 않은 칸은 숫자를 표시
	-숫자를 선택하라고 화면에 출력하고 이번 turn에서 내가 채울 칸의 숫자를 입력
	-선택한 숫자에 해당하는 내 빙고 테이블과 상대방 빙고 테이블의 칸을 채움
	-상대방(컴퓨터)가 채울 칸의 숫자를 random으로 선택하고 선택된 숫자를 화면에 출력
	-나 혹은 상대방의 빙고테이블이 가로/세로/대각선 줄이 M개 이상 만들어지면 반복 종료
4. M개 줄이 만들어진 쪽이 승리하며, 승리자가 누군지와 몇번째 turn에서 승부가 났는지 출력
5. 내가 숫자를 선택할 때, 이미 선택되었거나 범위 밖의 숫자를 선택하면 오류 메세지를 출력하고 다시 숫자를 입력.
6. 내가 숫자를 선택할 때, 이미 선택되었거나 범위 밖의 숫자를 선택하면 오류 메시지를 출력하고 다시 숫자를 입력 받음 */


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
 int bingo[N][N]; //빙고 배열 선언 
 int i, j ; //행과 열 변수 
 int inputMe, inputCom ; //내가 입력한 숫자, 컴퓨터가 입력한 숫자 
 int bingoMe[N][N], bingoCom[N][N] ; //내 빙고판, 컴퓨터 빙고판 

 /*함수*/ 
 int initiate_bingo(int bingo[N][N]) { //빙고 테이블을 초기에 만들어 줌 

	srand((int)time(NULL)); //랜덤 함수
	int count = 1;
	
	/*배열에 1부터 N*N 넣기*/ 
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			bingo[i][j] = count++;
		}
	} 
 }
	
 void print_bingo(int bingo[N][N]) {  //빙고 테이블 현재 상황을 화면에 출력
 		/*빙고판 출력*/
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			printf("%2d ", bingo[i][j]);
		}
		printf("\n");
	} 
 }

 int get_number_byMe() { //내가 빙고 번호 입력 선택

	int inputMe=0; //입력받을 숫자
	  
	printf("숫자를 입력하세요. : ");
	scanf("%d", &inputMe);

	/*1~N*N 정수 입력시*/ 
	if (inputMe>=1 && inputMe<=(N*N)) {
		for (i=0 ; i<N ; i++) {
			for (j=0 ; j<N ; j++){
				if(bingo[i][j]==inputMe) { //입력값이 빙고에 있을 때 
					bingo[i][j] = -1 ; //-1로 치환
					break; 
				}
			}
		}
	} 
	
	/*내가 입력한 숫자와 컴퓨터가 입력한 숫자가 같을 때*/ 
	else if (inputMe == inputCom) {
		printf("이미 선택된 숫자입니다. 다시 선택해 주세요. : ");
		scanf("%d", &inputMe); 
		
	}
	
	/*1~N*N 정수 입력이 아닐시*/ 
	else {
		printf("잘못입력하였습니다. 다시 입력해주세요. : ");
		scanf("%d", &inputMe); 
	}
 }
 
 int get_number_byCom() { //컴퓨터가 임의로 빙고 번호 선택
	inputCom = rand()% N*N+1;
 }
 
 int process_bingo(int bingo[N][N], int inputMe, int inputCom) { //선택된 숫자를 입력받아서 빙고 테이들 칸을 채움
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if(bingo[i][j] == inputMe || bingo[i][j] == inputCom) 
				bingo[i][j] = -1;
		}
	}
 }
 
 
 int count_bingo(int bingo[N][N]) { //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
	
	int sumbingo[N+N+2] = {0}; //초기화 
	int count = 0; //빙고 수 저장
	
	/* 모든 *들 이상하니까 다시 확인*/
	 
	//가로
	for (i=0 ; i<N ; i++) {
		for(j=0 ; j<N ; j++) {
			if (bingo[i*N+j] == 35 ) //얘가 좀 이상함; 
				sumbingo[i]++;
			
		}
	}
	
	//세로
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if(bingo[j*N+i] == 35)
				sumbingo[i+N]++;
		}
	} 
	 
	//대각선(왼쪽>>오른쪽)
	for (i=0 ; i<N ; i++) {
		for (j=i ; j<=i ; j++) {
			if(bingo[i*5+j] == 35)
				sumbingo[N+N]++;
		}
	} 
	
	//대각선(오른쪽>>왼쪽)
	for (i=(N-1) ; i>=0 ; i--) {
		for (j=(N-1) ; j>=4-i ; j--) {
			if (bingo[i*5+j] == 35)
				sumbingo[N+N+1]++;
		}
	} 
	
	//수세기
	for(i=0 ; i<(N+N+2) ; i++)
		if (sumbingo[i] == -N)
			count++;
			
	return count; 
	
 }
 

int main(int argc, char *argv[]) {
	
	srand((int)time(NULL)); //랜덤 함수
	int k, temp; //변수 선언
	int count = 1;
	int ran_row = rand()%N; //행의 랜덤
	int ran_col = rand()%N; //열의 랜덤
	
	printf("=====빙고 게임을 시작하지=====\n");  
	
	initiate_bingo(bingoMe[N][N]);
	
	/*빙고판섞기*/
	for (k=0 ; k<N ; k++){
		for (i=0 ; i<N ; i++){
			for (j=0 ; j<N ; j++) {
				temp = bingo[i][j];
				bingo[i][j] = bingo[ran_row][ran_col];
				bingo[ran_row][ran_col] = temp;
			}
		}
	} 
	
	/*빙고판 출력*/
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			printf("%2d ", bingo[i][j]);
		}
		printf("\n");
	} 
	
	/*컴퓨터의 빙고판*/
	printf("\n \n");
	printf("이것은 컴퓨터의 빙고판\n");
	
	int Cran_row = rand()%N; //행의 랜덤
	int Cran_col = rand()%N; //열의 랜덤
	
	/*배열에 1부터 N*N 넣기*/ 
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			bingo[i][j] = count++;
		}
	} 
	
	/*빙고판섞기*/
	for (k=0 ; k<N ; k++){
		for (i=0 ; i<N ; i++){
			for (j=0 ; j<N ; j++) {
				temp = bingo[i][j];
				bingo[i][j] = bingo[Cran_row][Cran_col];
				bingo[Cran_row][Cran_col] = temp;
			}
		}
	} 
	
	/*빙고판 출력*/
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			printf("%2d ", bingo[i][j]);
		}
		printf("\n");
	}  
	
	printf("\n"); 
	
	get_number_byMe();
	
	printf("\n");
	
	get_number_byCom();
	
	printf("\n");
	
	process_bingo;
	
	printf("\n");
	
	count_bingo;
	
	printf("\n");
	
	
	
	
	
	
	return 0;
}

 
