#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#include "C:\code\bingo\bingo\initiate_bingo().h"
#define N 3 //N을 다음 숫자로 치환한다. 빙고의 크기 
#define M 2//M을 다음 숫자로 치환한다. 빙고에서 이기는 조건 
#define L N*N //N*N을 다음 숫자로 치환한다.

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
 //전역 변수 
 int checking [L] ;
 int count = 0;
 int bingoMe[N][N]; //내 빙고 
 int bingoCom[N][N]; //컴퓨터 빙고 
 int input; //나 그리고  컴퓨터가 입력한 숫자 
 int turn = 0; //빙고 입력 횟수
  
 //함수선언
 void print_bingo(int bingo[N][N]); //빙고 테이블 현재 상황을 화면에 출력
 int get_number_byMe(int sth); //내가 빙고 번호 입력 선택
 int get_number_byCom(int sth); //컴퓨터가 임의로 빙고 번호 선택
 void process_bingo(int bingo[N][N], int number); //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움
 int count_bingo(int bingo[N][N]); //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환 
 
 
 void main() {
 	
	int num;
	int winMe, winCom; //내가 이겼을 때 변수, 컴퓨터가 이겼을 때 변수 
	
	initiate_bingo(); //빙고테이블 소환 
	
	printf("=====빙고 게임을 시작하지=====\n");
	
	printf("\n\n");  
	
	do {
		
		printf(">>내 빙고판\n"); //내 빙고판 출력 
		print_bingo(bingoMe);
		
		num = get_number_byMe(input); //내가 번호 선택
		
		process_bingo(bingoMe, num); //선택한 숫자 -1로 변환 
		process_bingo(bingoCom, num);
		
		num =  get_number_byCom(input); //컴퓨터가 번호 선택
		
		process_bingo(bingoMe, num); //선택한 숫자 -1로 변환 
		process_bingo(bingoCom, num);
		
		winMe = count_bingo(bingoMe); //빙고 확인 
		winCom = count_bingo(bingoCom);
		
		turn = turn++;
		
	} while ((winMe!=M)&&(winCom!=M)); //0:승부가 나지 않음 1:빙고가 완성 됨.
	
	if (winMe == M) {
		printf(">>나의 결과\n"); //내 빙고판 출력 
		print_bingo(bingoMe);
	
		printf(">>컴퓨터의 결과\n"); //컴퓨터의 빙고판 출력
		print_bingo(bingoCom);
		
		printf("빙고 %d개로 당신의 승리입니다.\n빙고 횟수 : %d\n", M, turn);
	}
	else if (winCom == M) {
		printf(">>나의 결과\n"); //내 빙고판 출력 
		print_bingo(bingoMe);
	
		printf(">>컴퓨터의 결과\n"); //컴퓨터의 빙고판 출력
		print_bingo(bingoCom);
		
		printf("빙고 %d개로 컴퓨터의 승리입니다. \n빙고 횟수 : %d\n", M, turn);
	}
	else if ((winMe == M) && (winCom == M)){
		printf(">>나의 결과\n"); //내 빙고판 출력 
		print_bingo(bingoMe);
	
		printf(">>컴퓨터의 결과\n"); //컴퓨터의 빙고판 출력
		print_bingo(bingoCom);
		
		printf("비겼습니다. \n빙고 횟수 : %d", turn);
	} 
	
}

 int count_bingo(int bingo[N][N]) { //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
	
	int i, j, sum; //한 줄의 합이 -N이 되면 빙고
	
	for (i=0 ; i<N ; i++) { //행 확인 
		sum = 0; //sum 초기화
		
		for (j=0 ; j<N ; j++) {
			sum += bingo[i][j];
		} 
		
		if (sum == -N) {
			return 1;
		}
	} 
	
	for (j=0 ; j<N ; j++) { //열 확인 
		sum = 0 ; //sum 초기화
		
		for (i=0 ; i<N ; i++) {
			sum += bingo[i][j];
		} 
		
		if (sum == -N) {
			return 1;
		}
	}
	
	sum = 0; //대각선을 위한 sum 초기화
	
	for (i=0 ; i<N ; i++) { //대각선 확인
		sum += bingo[i][i]; 
	}
	
	if (sum == -N) {
		return 1;
	}
	
	sum = 0;
	
	for (i=0 ; i<N ; i++) { //대각선 확인 
		sum += bingo[i][N-i-1];
	}
	
	if (sum == -N) {
		return 1;
	} 
	
	return 0; //아직 빙고가 없음 

}

 void print_bingo(int bingo[N][N]) {  //빙고 테이블 현재 상황을 화면에 출력
 	
 	int i, j;
	
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if (bingo[i][j] != -2) { //why?
				printf("%7d", bingo[i][j]);
			}
			
			else { //에러난 경우 
				printf("Error\n"); 
			}
		}
		
		printf("\n\n");
		
	} 
 }

 int get_number_byMe(int sth) { //내가 빙고 번호 입력 선택
	
	int x, retry;
	
	do {
		retry = 0;
			printf(">>1 ~ %d 사이의 숫자를 입력하세요. : ", L);
			scanf("%d", &input);
			if(input<1 || input>25) {
				retry = 1; //retry = 1이면 입력 에러. 다시 입력하게 해야 함. 
			} 
		
		if (retry == 0) {
			for (x=0 ; x<count ; x++) {
				if (checking[x] == input) {
					retry = 1;
					break;
				}
			}
		}
	} while (retry == 1); //retry=1이면 다시 입력해야하므로 do 구문으로 돌아가게 함
	
	checking[count++] = input;
	if (sth == 0) {
		printf(">사용자가 '%d'를 선택했습니다. \n", input);
	}
	
	return input;
}

 int get_number_byCom(int sth) { //컴퓨터가 임의로 빙고 번호 선택
	
	int x, retry;
	
	do {
		retry=0;
		input = rand()%L+1;
		if (retry == 0) {
			for (x=0 ; x<count ; x++) {
				if (checking[x] == input) {
					retry = 1;
					break;
				}
			}
		}
	} while (retry == 1); //do 구문으로 돌아가기
	checking[count++] = input;
	printf(">컴퓨터가 '%d'를 선택했습니다. \n\n", input);
	return input; 
}

 void process_bingo(int bingo[N][N], int number) { //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움
 	int i, j;
	 for (i=0 ; i<N ; i++) { //입력받은 input과 같은지 확인 
	 	for (j=0 ; j<N ; j++) {
	 		if (bingo[i][j] == input) {
	 			bingo[i][j] = -1;
			 }
		 } 
	 } 
 }



/* 해야할 것
1. M개의 줄이 완성되면 승자 외치기
2. 승자를 말하면서 몇번째에 내가 이겼나 말하기
3. 변수 이름 바꾸기
4. 주석달기
5. 내가 숫자를 선택할 때, 이미 선택되었거나 범위 밖의 숫자를 선택하면 오류 메세지를 출력하고 다시 숫자를 입력.*/ 
