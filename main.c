#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#define N 5 //N을 다음 숫자로 치환한다. 빙고의 크기 
#define M 3//M을 다음 숫자로 치환한다. 빙고에서 이기는 조건 

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
 int checking [N*N] ;
 int count = 0;
 int bingoMe[N][N]; //내 빙고 
 int bingoCom[N][N]; //컴퓨터 빙고 

 //함수선언

 void initiate_bingo(); // 빙고 테이블을 초기에 만들어줌
 void print_bingo(int bingo[N][N]); //빙고 테이블 현재 상황을 화면에 출력
 int get_number_byMe(); //내가 빙고 번호 입력 선택
 int get_number_byCom(); //컴퓨터가 임의로 빙고 번호 선택
 void process_bingo(int bingo[N][N], int number); //선택된 숫자를 입력받아서 빙고 테이블 칸을 채움
 int count_bingo(int bingo[N][N]); //빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환 
 
 void main() {
 	
	int num;
	int winMe, winCom; //내가 이겼을 때 변수, 컴퓨터가 이겼을 때 변수 
	
	initiate_bingo; //빙고테이블 소환 
	
	printf("=====빙고 게임을 시작하지=====\n");  
	
	do {
		
		printf("===내 빙고판===\n"); //내 빙고판 출력 
		print_bingo(bingoMe[N][N]);
		
		num = get_number_byMe; //내가 번호 선택
		
		process_bingo(bingoMe[N][N], num); //선택한 숫자 -1로 변환 
		process_bingo(bingoCom[N][N], num);
		
		num =  get_number_byCom; //컴퓨터가 번호 선택
		
		process_bingo(bingoMe[N][N], num); //선택한 숫자 -1로 변환 
		process_bingo(bingoCom[N][N], num);
		
		winMe = count_bingo(bingoMe[N][N]); //빙고 확인 
		winCom = count_bingo(bingoCom[N][N]);
		
	} while ((winMe==0)&&(winCom==0)); //0:승부가 나지 않음 1:빙고가 완성 됨.
	
	printf("===나의 결과==="); //내 빙고판 출력 
	print_bingo(bingoMe[N][N]);
	
	printf("===컴퓨터의 결과==="); //컴퓨터의 빙고판 출력
	print_bingo(bingoCom[N][N]); 
	
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

//함수
 void initiate_bingo() { //빙고 테이블을 초기에 만들어 줌 
	
	int i, j;
	int temp;
	int k;
	int order = 1;
	int bingo[N][N];
	
	srand((unsigned int)time(NULL));
	int ran_row = rand()%N; //행의 랜덤
	int ran_col = rand()%N; //열의 랜덤
	
	for (i=0 ; i<N ; i++) { //배열에 1~N 배치 
		for (j=0 ; j<N ; j++) {
			bingo[i][j] = order++;
		}
	} 
	
	for (k=0 ; k<N ; k++) { //빙고판 섞기 
		for (i=0 ; i<N ; i++) {
			for (j=0 ; j<N ; j++) {
				temp = bingo[i][j];
				bingo[i][j] = bingo[ran_row][ran_col];
				bingo[ran_row][ran_col] = temp;
			}
		}
	}
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
 
 int get_number_byCom() { //컴퓨터가 임의로 빙고 번호 선택
	inputCom = rand()% N*N+1;
 }
 
 void process_bingo(int bingo[N][N], int number) { //선택된 숫자를 입력받아서 빙고 테이들 칸을 채움
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if(bingo[i][j] == inputMe || bingo[i][j] == inputCom) 
				bingo[i][j] = -1;
		}
	}
	
	/*void erase_bingo(int arr[5][5], int number) { //입력받은 number와 같은 수를 0으로 만드는 함수 

	int x, y;

	

	for (y=0 ; y<SIZE ; y++) { //x,y를 일일이 바꿔가면서 number와 같은지 확인 

		for(x=0 ; x<SIZE ; x++) {

			if(arr[y][x] == number) {

				arr[y][x] = 0;

			}

		} 

	} 

}*/
 }
 
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




/*내일 할 일
1.  get_number_byMe
	get_number_byCom
	함수 뜯어 고치기 ㅡㅡ

2.	그리고 전체적으로 돌아가나 보기
3.	안 돌아가면 운다
4.	퀸 너무 좋다 포토티켓 다 모으고 싶고 한정판 포스터 다 모으고 싶다
5.	돈이 없어 너무 슬프다.
6.	이번 달 어떻게 버티지
7.	이렇게 늦게 자서 내일 어떻게 버티지
*/ 
 
