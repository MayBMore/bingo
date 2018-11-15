#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#define N 5 //N을 다음 숫자로 치환한다. 
#define M //M을 다음 숫자로 치환한다. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initiate_bingo() //빙고 테이블을 초기에 만들어 줌 
 {
	int bingo[N][N]={0,};
	int i, j;
	int temp[50];
	int tem;
	
	srand((int)time(NULL)); //랜덤함수
	
	for (i=0 ; i<N ; i++) //1부터 N까지 숫자 넣기 
	{
		for (j=0 ; j<N ; j++)
		{
			while(1)
			{
				tem = rand()%(N*N)+1;
				if(temp[tem]==0)
				{
					bingo[i][j] = tem;
					temp[tem]=1;
					break;
				}
			}
		}
		
	}
 }
	
 int print_bingo() //빙고 테이블 현재 상황을 화면에 출력
 {
 	int bingo[N][N];
	 int i,j; 
	 
	 for (i=0 ; i<N ; i++)
	 {
	 	for (j=0 ; j<N ; j++)
	 	{
	 		printf("%Nd", bingo[i][j]);
		 }
		printf("\n");
	 }
 }
 
 int get_number_byMe(); //내가 빙고 번호 입력 선택
 
 int get_number_byCom(); //컴퓨터가 임의로 빙고 번호 선택
 
 int process_bingo(); //선택된 숫자를 입력받아서 빙고 테이들 칸을 채움
 
 int count_bingo(); //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
 

int main(int argc, char *argv[]) {
	
	printf("=====빙고 게임을 시작하지=====\n"); 
	
	initiate_bingo();
	print_bingo();
	 
	 
	
	
	
	
	
	return 0;
}

 
