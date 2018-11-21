#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#include "C:\code\bingo\bingo\initiate_bingo().h"
#define N 3 //N�� ���� ���ڷ� ġȯ�Ѵ�. ������ ũ�� 
#define M 2//M�� ���� ���ڷ� ġȯ�Ѵ�. ������ �̱�� ���� 
#define L N*N //N*N�� ���� ���ڷ� ġȯ�Ѵ�.

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
 //���� ���� 
 int checking [L] ;
 int count = 0;
 int bingoMe[N][N]; //�� ���� 
 int bingoCom[N][N]; //��ǻ�� ���� 
 int input; //�� �׸���  ��ǻ�Ͱ� �Է��� ���� 
 int turn = 0; //���� �Է� Ƚ��
  
 //�Լ�����
 void print_bingo(int bingo[N][N]); //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
 int get_number_byMe(int sth); //���� ���� ��ȣ �Է� ����
 int get_number_byCom(int sth); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
 void process_bingo(int bingo[N][N], int number); //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��
 int count_bingo(int bingo[N][N]); //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
 
 
 void main() {
 	
	int num;
	int winMe, winCom; //���� �̰��� �� ����, ��ǻ�Ͱ� �̰��� �� ���� 
	
	initiate_bingo(); //�������̺� ��ȯ 
	
	printf("=====���� ������ ��������=====\n");
	
	printf("\n\n");  
	
	do {
		
		printf(">>�� ������\n"); //�� ������ ��� 
		print_bingo(bingoMe);
		
		num = get_number_byMe(input); //���� ��ȣ ����
		
		process_bingo(bingoMe, num); //������ ���� -1�� ��ȯ 
		process_bingo(bingoCom, num);
		
		num =  get_number_byCom(input); //��ǻ�Ͱ� ��ȣ ����
		
		process_bingo(bingoMe, num); //������ ���� -1�� ��ȯ 
		process_bingo(bingoCom, num);
		
		winMe = count_bingo(bingoMe); //���� Ȯ�� 
		winCom = count_bingo(bingoCom);
		
		turn = turn++;
		
	} while ((winMe!=M)&&(winCom!=M)); //0:�ºΰ� ���� ���� 1:���� �ϼ� ��.
	
	if (winMe == M) {
		printf(">>���� ���\n"); //�� ������ ��� 
		print_bingo(bingoMe);
	
		printf(">>��ǻ���� ���\n"); //��ǻ���� ������ ���
		print_bingo(bingoCom);
		
		printf("���� %d���� ����� �¸��Դϴ�.\n���� Ƚ�� : %d\n", M, turn);
	}
	else if (winCom == M) {
		printf(">>���� ���\n"); //�� ������ ��� 
		print_bingo(bingoMe);
	
		printf(">>��ǻ���� ���\n"); //��ǻ���� ������ ���
		print_bingo(bingoCom);
		
		printf("���� %d���� ��ǻ���� �¸��Դϴ�. \n���� Ƚ�� : %d\n", M, turn);
	}
	else if ((winMe == M) && (winCom == M)){
		printf(">>���� ���\n"); //�� ������ ��� 
		print_bingo(bingoMe);
	
		printf(">>��ǻ���� ���\n"); //��ǻ���� ������ ���
		print_bingo(bingoCom);
		
		printf("�����ϴ�. \n���� Ƚ�� : %d", turn);
	} 
	
}

 int count_bingo(int bingo[N][N]) { //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
	
	int i, j, sum; //�� ���� ���� -N�� �Ǹ� ����
	
	for (i=0 ; i<N ; i++) { //�� Ȯ�� 
		sum = 0; //sum �ʱ�ȭ
		
		for (j=0 ; j<N ; j++) {
			sum += bingo[i][j];
		} 
		
		if (sum == -N) {
			return 1;
		}
	} 
	
	for (j=0 ; j<N ; j++) { //�� Ȯ�� 
		sum = 0 ; //sum �ʱ�ȭ
		
		for (i=0 ; i<N ; i++) {
			sum += bingo[i][j];
		} 
		
		if (sum == -N) {
			return 1;
		}
	}
	
	sum = 0; //�밢���� ���� sum �ʱ�ȭ
	
	for (i=0 ; i<N ; i++) { //�밢�� Ȯ��
		sum += bingo[i][i]; 
	}
	
	if (sum == -N) {
		return 1;
	}
	
	sum = 0;
	
	for (i=0 ; i<N ; i++) { //�밢�� Ȯ�� 
		sum += bingo[i][N-i-1];
	}
	
	if (sum == -N) {
		return 1;
	} 
	
	return 0; //���� ���� ���� 

}

 void print_bingo(int bingo[N][N]) {  //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
 	
 	int i, j;
	
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if (bingo[i][j] != -2) { //why?
				printf("%7d", bingo[i][j]);
			}
			
			else { //������ ��� 
				printf("Error\n"); 
			}
		}
		
		printf("\n\n");
		
	} 
 }

 int get_number_byMe(int sth) { //���� ���� ��ȣ �Է� ����
	
	int x, retry;
	
	do {
		retry = 0;
			printf(">>1 ~ %d ������ ���ڸ� �Է��ϼ���. : ", L);
			scanf("%d", &input);
			if(input<1 || input>25) {
				retry = 1; //retry = 1�̸� �Է� ����. �ٽ� �Է��ϰ� �ؾ� ��. 
			} 
		
		if (retry == 0) {
			for (x=0 ; x<count ; x++) {
				if (checking[x] == input) {
					retry = 1;
					break;
				}
			}
		}
	} while (retry == 1); //retry=1�̸� �ٽ� �Է��ؾ��ϹǷ� do �������� ���ư��� ��
	
	checking[count++] = input;
	if (sth == 0) {
		printf(">����ڰ� '%d'�� �����߽��ϴ�. \n", input);
	}
	
	return input;
}

 int get_number_byCom(int sth) { //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
	
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
	} while (retry == 1); //do �������� ���ư���
	checking[count++] = input;
	printf(">��ǻ�Ͱ� '%d'�� �����߽��ϴ�. \n\n", input);
	return input; 
}

 void process_bingo(int bingo[N][N], int number) { //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��
 	int i, j;
	 for (i=0 ; i<N ; i++) { //�Է¹��� input�� ������ Ȯ�� 
	 	for (j=0 ; j<N ; j++) {
	 		if (bingo[i][j] == input) {
	 			bingo[i][j] = -1;
			 }
		 } 
	 } 
 }



/* �ؾ��� ��
1. M���� ���� �ϼ��Ǹ� ���� ��ġ��
2. ���ڸ� ���ϸ鼭 ���°�� ���� �̰峪 ���ϱ�
3. ���� �̸� �ٲٱ�
4. �ּ��ޱ�
5. ���� ���ڸ� ������ ��, �̹� ���õǾ��ų� ���� ���� ���ڸ� �����ϸ� ���� �޼����� ����ϰ� �ٽ� ���ڸ� �Է�.*/ 
