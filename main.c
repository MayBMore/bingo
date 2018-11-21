#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#define N 5 //N을 다음 숫자로 치환한다. 빙고의 크기 
#define M 4//M을 다음 숫자로 치환한다. 빙고에서 이기는 조건 
#define L 25 //N*N을 다음 숫자로 치환한다.
 
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
*/


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
 //전역 변수 
 int checking [L] ;
 int count = 0;
 int bingoMe[N][N]; //내 빙고 
 int bingoCom[N][N]; //컴퓨터 빙고 
 int input; //나 그리고  컴퓨터가 입력한 숫자 

 //함수선언

 void initiate_bingo(); // 빙고 테이블을 초기에 만들어줌
 void print_bingo(int bingo[N][N]); //빙고 테이블 현재 상황을 화면에 출력
 int get_number_byMe(int sth); //내가 빙고 번호 입력 선택
 int get_number_byCom(int sth); //컴퓨터가 임의로 빙고 번호 선택
 void process_bingo(int bingo[N][N], int number); //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움
 int count_bingo(int bingo[N][N]); //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환 
 void set_rand(int*bingo);
 void swap(int*x, int*y);
 
 
 void main() {
 	
	int num;
	int winMe, winCom; //내가 이겼을 때 변수, 컴퓨터가 이겼을 때 변수
	int sth; //get number에 있는 변수 
	
	initiate_bingo(); //빙고테이블 소환 
	
	printf("=====빙고 게임을 시작하지=====\n");  
	
	do {
		
		printf("===내 빙고판===\n"); //내 빙고판 출력 
		print_bingo(bingoMe);
		
		num = get_number_byMe(input); //내가 번호 선택
		
		process_bingo(bingoMe, num); //선택한 숫자 -1로 변환 
		process_bingo(bingoCom, num);
		
		num =  get_number_byCom(input); //컴퓨터가 번호 선택
		
		process_bingo(bingoMe, num); //선택한 숫자 -1로 변환 
		process_bingo(bingoCom, num);
		
		winMe = count_bingo(bingoMe); //빙고 확인 
		winCom = count_bingo(bingoCom);
		
	} while ((winMe==0)&&(winCom==0)); //0:승부가 나지 않음 1:빙고가 완성 됨.
	
	printf("===나의 결과==="); //내 빙고판 출력 
	print_bingo(bingoMe);
	
	printf("===컴퓨터의 결과==="); //컴퓨터의 빙고판 출력
	print_bingo(bingoCom); 
	
	switch (winCom*2+winMe) { //승자 알려줌 
		case 1 : //내가 이김
			printf("내가 이겼습니다.\n");
			break;
		case 2 : //컴퓨터가 이김
			printf("컴퓨터가 이겼습니다.\n");
			break;
		case 3 : //비김
			 printf("비겼습니다.\n");
			 break;
		default : //에러 
			printf("Error\n");
			break;
	}
	
}

			



/* 해야할 것
1. 일단 돌아가나
2. M개의 줄이 완성되면 승자 외치기
3. 승자를 말하면서 몇번째에 내가 이겼나 말하기
4. 변수 이름 바꾸기
5. 주석달기*/ 
