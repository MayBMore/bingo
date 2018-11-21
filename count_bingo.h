#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#define N 5 //N을 다음 숫자로 치환한다. 빙고의 크기 
#define M 4//M을 다음 숫자로 치환한다. 빙고에서 이기는 조건 
#define L 25 //N*N을 다음 숫자로 치환한다.

//전역 변수 
 int checking [L] ;
 int count = 0;
 int bingoMe[N][N]; //내 빙고 
 int bingoCom[N][N]; //컴퓨터 빙고 
 int input; //나 그리고  컴퓨터가 입력한 숫자 
 
 int count_bingo(int bingo[N][N]) { //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
	
	int i, j, sum; //한 줄의 합이 -N이 되면 빙고
	
	for (i=0 ; i<N ; i++) { //행 확인 
		sum = 0; //sum 초기화
		
		for (j=0 ; j<N ; j++) {
			sum += bingo[i][j];
		} 
		
		if (sum == -5) {
			return 1;
		}
	} 
	
	for (j=0 ; j<N ; j++) { //열 확인 
		sum = 0 ; //sum 초기화
		
		for (i=0 ; i<N ; i++) {
			sum += bingo[i][j];
		} 
		
		if (sum == -5) {
			return 1;
		}
	}
	
	sum = 0; //대각선을 위한 sum 초기화
	
	for (i=0 ; i<N ; i++) { //대각선 확인
		sum += bingo[i][i]; 
	}
	
	if (sum == -5) {
		return 1;
	}
	
	sum = 0;
	
	for (i=0 ; i<N ; i++) { //대각선 확인 
		sum += bingo[i][N-i-1];
	}
	
	if (sum == -5) {
		return 1;
	} 
	
	return 0; //아직 빙고가 없음 

}
