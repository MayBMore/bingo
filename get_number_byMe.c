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

 int get_number_byMe(int sth) { //내가 빙고 번호 입력 선택
	int x, retry; //??
	
	do {
		retry = 0;
		if (sth == 0) { //0:나, 1:컴퓨터 
			printf("1~L 사이의 숫자를 입력하세요. : ");
			scanf("%d", &input);
			if (input<1 || input>N*N) {
				retry = 1; //retry=1이면 입력에러. 다시 입력 
			}
			else { //컴퓨터가 입력 
				get_number_byCom(input); 
			} 
			
		if (retry == 0) {
			for (x=0 ; x<count ; x++) {
				if (checking[x] == input) { //내가 입력하거나 컴퓨터가 입력한거 같은지 확인. 그냥 전역변수 선언하자 
					retry = 1;
					break; 
				}
			}
		}	
 }
} while (retry == 1); //retry=1이면 다시 입력해야하므로 do 구문으로 돌아가게 함

checking[count++] = input;

			if (sth == 0) {

				printf(">사용자가 '%d'를 선택했습니다. \n", input);

			} 

			else {

				printf(">컴퓨터가 '%d'를 선택했습니다. \n \n", input);

			}
			
}
