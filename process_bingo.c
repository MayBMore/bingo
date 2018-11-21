#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#define N 5 //N을 다음 숫자로 치환한다. 빙고의 크기 
#define M 4//M을 다음 숫자로 치환한다. 빙고에서 이기는 조건 
#define L 25 //N*N을 다음 숫자로 치환한다.

//전역 변수 
 int checking [L] ;
 int bingoMe[N][N]; //내 빙고 
 int bingoCom[N][N]; //컴퓨터 빙고 
 int input; //나 그리고  컴퓨터가 입력한 숫자 

void process_bingo(int bingo[N][N], int number) { //선택된 숫자를 입력받아서 빙고 테이들 칸을 채움
	int i,j;
	
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if(bingo[i][j] == input || bingo[i][j] == input) 
				bingo[i][j] = -1;
		}
	}
}
