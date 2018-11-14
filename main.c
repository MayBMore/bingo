#include <stdio.h>
#include <stdlib.h>
#define N 5 //N을 다음 숫자로 치환한다. 
#define M //M을 다음 숫자로 치환한다. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo(int row, int col)
{
	int i;
	int max = N*N;
	
	srand((unsigned)time(NULL));
	for(i=0 ; i<=max ; i++)
		printf("%d", 1+rand()%max);
		
	return 0;
 } 

int main(int argc, char *argv[]) {
	
	printf("빙고 게임을 시작하지\n"); 
	
	int bingo[N][N] = {0,}; //빙고판 2차원 배열하고 0으로 초기화
	int row; //행
	int col; //열
	
	 
	 
	
	
	
	
	
	return 0;
}


/* 사용해야 할 함수
initiate_bingo():빙고 테이블을 초기에 만들어줌
print_bingo():빙고 테이블 현재 상황을 화면에 출력
get_number_byMe():내가 빙고 번호 입력 선택
get_number_byCom():컴퓨터가 임의로 빙고 번호 선택
process_bingo():선택된 숫자를 ㅣㅂ력받아서 빙고 테이블 칸을 채움
count_bingo():빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환 */

 
