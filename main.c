#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#define N 5 //N을 다음 숫자로 치환한다. 
#define M //M을 다음 숫자로 치환한다. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int bingo[N][N];

int initiate_bingo(int grade[N][N]) //빙고 테이블을 초기에 만들어 줌 
 {
	int i, j, temp = 0; //0으로 초기화 
	
	for (i=0 ; i<N ; i++) //1부터 N까지 숫자 넣기 
	{
		temp += bingo[i][j]; 
				}
	return temp;
 }
	
void print_bingo(int bingo[N][N]) //빙고 테이블 현재 상황을 화면에 출력
 {
	 int i,j; 
	 
	 for (i=0 ; i<N ; i++)
	 {
	 	for (j=0 ; j<N ; j++)
	 	{
	 		printf("%Nd", bingo[i][j]);
	 		if(j==N-1)
	 		printf("\n");
		 }
	 }
 }
 
 int get_number_byMe(); //내가 빙고 번호 입력 선택
 
 int get_number_byCom(); //컴퓨터가 임의로 빙고 번호 선택
 
 int process_bingo(); //선택된 숫자를 입력받아서 빙고 테이들 칸을 채움
 
 int count_bingo(); //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
 

int main(int argc, char *argv[]) {
	
	int bingo[N][N]; //빙고 배열 선언
	int i, j; //변수 선언
	
	srand((int)time(NULL)); //랜덤 함수
	
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
			bingo[i][j] = rand()%(N*N)+1;
		}
	} 
	
	printf("=====빙고 게임을 시작하지=====\n"); 
	
	initiate_bingo(int bingo [N][N]); //빙고판 함수 호출 
	
	
	print_bingo();
	 
	 
	
	
	
	
	
	return 0;
}

 
