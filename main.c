#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#define N 5 //N을 다음 숫자로 치환한다. 
#define M //M을 다음 숫자로 치환한다. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
 /*전역변수*/ 
 int bingo[N][N];
 int i, j ; //행과 열 변수 
 int inputMe, inputCom ; //내가 입력한 숫자, 컴퓨터가 입력한 숫자 

 /*함수*/ 
 int initiate_bingo(int bingo[N][N]); //빙고 테이블을 초기에 만들어 줌 
	
 void print_bingo(int bingo[N][N]); //빙고 테이블 현재 상황을 화면에 출력

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
 
 int get_number_byCom(); //컴퓨터가 임의로 빙고 번호 선택
 
 int process_bingo(); //선택된 숫자를 입력받아서 빙고 테이들 칸을 채움
 
 int count_bingo(int bingo[N][N]) { //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
	
	int sumbingo[N+N+2] = {0}; //초기화 
	int count = 0; //빙고 수 저장
	
	//가로
	 
 	
	
	
 }
 

int main(int argc, char *argv[]) {
	
	srand((int)time(NULL)); //랜덤 함수
	int bingo[N][N]; //빙고 배열 선언
	int k, temp; //변수 선언
	int count = 1;
	
	printf("=====빙고 게임을 시작하지=====\n"); 
	
	int ran_row = rand()%N; //행의 랜덤
	int ran_col = rand()%N; //열의 랜덤
	
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
	 
	 
	
	
	
	
	
	return 0;
}

 
