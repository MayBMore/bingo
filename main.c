#include <stdio.h>
#include <stdlib.h>
#include <time.h> //난수 
#include "initiate_bingo().h" //initiate_bingo() 함수를 헤더파일로 만든다. 
#define N 3 //N을 다음 숫자로 치환한다. 빙고의 크기 
#define M 2//M을 다음 숫자로 치환한다. 빙고에서 이기는 조건 
#define L N*N //N*N을 다음 숫자로 치환한다.

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
 //전역 변수 
 int checking [L] ; //입력하는 빙고값을 저장하는 배열 변수 
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
 	
	int num; //임시변수 
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
		
		turn = turn+1; //턴수 증가 
		printf("턴 수 : %d\n\n", turn);
		
	} while ((winMe!=M)&&(winCom!=M)); 
	
	if (winMe == M) { //내가 이겼을 때 
		printf(">>나의 결과\n"); //내 빙고판 출력 
		print_bingo(bingoMe);
	
		printf(">>컴퓨터의 결과\n"); //컴퓨터의 빙고판 출력
		print_bingo(bingoCom);
		
		printf("빙고 %d개로 당신의 승리입니다.\n빙고 횟수 : %d\n", M, turn);
	}
	else if (winCom == M) { //컴퓨터가 이겼을 때 
		printf(">>나의 결과\n"); //내 빙고판 출력 
		print_bingo(bingoMe);
	
		printf(">>컴퓨터의 결과\n"); //컴퓨터의 빙고판 출력
		print_bingo(bingoCom);
		
		printf("빙고 %d개로 컴퓨터의 승리입니다. \n빙고 횟수 : %d\n", M, turn);
	}
	else if ((winMe == M) && (winCom == M)){ //비겼을 때 
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
		
		if (sum == -N) { //행이 빙고가 되었을 경우 
			return 1;
		}
	} 
	
	for (j=0 ; j<N ; j++) { //열 확인 
		sum = 0 ; //sum 초기화
		
		for (i=0 ; i<N ; i++) {
			sum += bingo[i][j];
		} 
		
		if (sum == -N) { //열이 빙고가 되었을 경우 
			return 1;
		}
	}
	
	sum = 0; //대각선을 위한 sum 초기화
	
	for (i=0 ; i<N ; i++) { //대각선 확인(왼쪽 위->오른쪽 아래) 
		sum += bingo[i][i]; 
	}
	
	if (sum == -N) { //대각선이 빙고가 되었을 경우 
		return 1;
	}
	
	sum = 0; //초기화 
	
	for (i=0 ; i<N ; i++) { //대각선 확인(오른쪽 위->왼쪽 아래) 
		sum += bingo[i][N-i-1];
	}
	
	if (sum == -N) { //대각선이 빙고가 되었을 경우 
		return 1;
	} 
	
	return 0; //아직 빙고가 없음 

}

 void print_bingo(int bingo[N][N]) {  //빙고 테이블 현재 상황을 화면에 출력
 	
 	int i, j; //행과 열의 임시 변수 
	
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if (bingo[i][j] != -2) { //-2가 나오는 경우는 절대 없으므로 이렇게 설정(임시) 
				printf("%7d", bingo[i][j]); //빙고를 위해 같은 칸 만들기 
			}
			
			else { //에러난 경우 
				printf("Error\n"); 
			}
		}
		
		printf("\n\n");
		
	} 
 }

 int get_number_byMe(int sth) { //내가 빙고 번호 입력 선택
	
	int x, retry; //임시 변수와 번호 중복을 알기 위한 변수 
	
	do {
		retry = 0; //에러가 없는 경우 retry=0 
			printf(">>1 ~ %d 사이의 숫자를 입력하세요. : ", L);
			scanf("%d", &input); //숫자를 받아 input에 저장 
			if(input<1 || input>L) { //받는 값이 1보다 작거나 L보다 클 때 오류
				printf("잘못 입력하였습니다. 다시 입력해주세요.\n"); //다시 입력 요청 
				retry = 1; //retry = 1이면 입력 에러. 다시 입력하게 해야 함. 
			} 
		
		if (retry == 0) { //오류가 없을 때 
			for (x=0 ; x<count ; x++) { 
				if (checking[x] == input) { //아까 받은 값과 같을 때 
					retry = 1;
					break;
				}
			}
		}
	} while (retry == 1); //retry=1이면 다시 입력해야하므로 do 구문으로 돌아가게 함
	
	checking[count++] = input;
	
	if (sth == 0) { //에러없음 
		printf(">사용자가 '%d'를 선택했습니다. \n", input);
	}
	
	return input; //반환값 input 
}

 int get_number_byCom(int sth) { //컴퓨터가 임의로 빙고 번호 선택
	
	int x, retry; //임시 변수와 번호 중복을 알기 위한 변수 
	
	do {
		retry=0;
		input = rand()%L+1; //컴퓨터 랜덤값 
		if (retry == 0) {
			for (x=0 ; x<count ; x++) { 
				if (checking[x] == input) { //중복체크 
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
 	int i, j; //행과 열 임시변수 
	 for (i=0 ; i<N ; i++) { //입력받은 input과 같은지 확인 
	 	for (j=0 ; j<N ; j++) {
	 		if (bingo[i][j] == input) {
	 			bingo[i][j] = -1;
			 }
		 } 
	 } 
 }
