#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#define N 3 //N을 다음 숫자로 치환한다. 빙고의 크기 
#define M 2//M을 다음 숫자로 치환한다. 빙고에서 이기는 조건 
#define L N*N //N*N을 다음 숫자로 치환한다.

 //전역 변수 
 int bingoMe[N][N]; //내 빙고 
 int bingoCom[N][N]; //컴퓨터 빙고 
 
 void initiate_bingo(); // 빙고 테이블을 초기에 만들어줌
 void set_rand(int*bingo);
 void swap(int*x, int*y);
 
 void initiate_bingo() { //빙고 테이블을 초기에 만들어 줌 
	
	srand((unsigned int)time(NULL));
	
	set_rand((int*)bingoMe);
	set_rand((int*)bingoCom);
}

 void set_rand(int*bingo) { 
	int i;
	
	for (i=0 ; i<L ; i++) {
		bingo[i] = i+1;
	}
	
	for (i=0 ; i<L ; i++) {
		swap(&bingo[i], &bingo[rand()%L]);
	}
}

 void swap(int*x, int*y) {
	int temp;
	
	temp = *x;
	*x = *y;
	*y = temp;
}
