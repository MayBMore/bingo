#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#define N 5 //N�� ���� ���ڷ� ġȯ�Ѵ�. ������ ũ�� 
#define M 3//M�� ���� ���ڷ� ġȯ�Ѵ�. ������ �̱�� ���� 

/*
1. ���α׷� ���� �� ����(��ǻ��)�� ���� �Ʒ��� ���� NxN ũ�� ǥ�� 1~N*N ������ ���ڰ� �ѹ� �� ������ ���� ���̺� �� ���� �����.
2. ���� ��ġ�� random���� ��
3. �� turn���� ������ �ݺ�
	-���� ���� NxN ���� ���̺� ���¸� ȭ�鿡 ǥ�� (�̹� ä�� ĭ�� -1�� ǥ���ϰ�, ���� ä������ ���� ĭ�� ���ڸ� ǥ��
	-���ڸ� �����϶�� ȭ�鿡 ����ϰ� �̹� turn���� ���� ä�� ĭ�� ���ڸ� �Է�
	-������ ���ڿ� �ش��ϴ� �� ���� ���̺�� ���� ���� ���̺��� ĭ�� ä��
	-����(��ǻ��)�� ä�� ĭ�� ���ڸ� random���� �����ϰ� ���õ� ���ڸ� ȭ�鿡 ���
	-�� Ȥ�� ������ �������̺��� ����/����/�밢�� ���� M�� �̻� ��������� �ݺ� ����
4. M�� ���� ������� ���� �¸��ϸ�, �¸��ڰ� �������� ���° turn���� �ºΰ� ������ ���
5. ���� ���ڸ� ������ ��, �̹� ���õǾ��ų� ���� ���� ���ڸ� �����ϸ� ���� �޼����� ����ϰ� �ٽ� ���ڸ� �Է�.
*/


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
 //���� ���� 
 int checking [N*N] ;
 int count = 0;
 int bingoMe[N][N]; //�� ���� 
 int bingoCom[N][N]; //��ǻ�� ���� 

 //�Լ�����

 void initiate_bingo(); // ���� ���̺��� �ʱ⿡ �������
 void print_bingo(int bingo[N][N]); //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
 int get_number_byMe(); //���� ���� ��ȣ �Է� ����
 int get_number_byCom(); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
 void process_bingo(int bingo[N][N], int number); //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��
 int count_bingo(int bingo[N][N]); //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
 
 void main() {
 	
	int num;
	int winMe, winCom; //���� �̰��� �� ����, ��ǻ�Ͱ� �̰��� �� ���� 
	
	initiate_bingo; //�������̺� ��ȯ 
	
	printf("=====���� ������ ��������=====\n");  
	
	do {
		
		printf("===�� ������===\n"); //�� ������ ��� 
		print_bingo(bingoMe[N][N]);
		
		num = get_number_byMe; //���� ��ȣ ����
		
		process_bingo(bingoMe[N][N], num); //������ ���� -1�� ��ȯ 
		process_bingo(bingoCom[N][N], num);
		
		num =  get_number_byCom; //��ǻ�Ͱ� ��ȣ ����
		
		process_bingo(bingoMe[N][N], num); //������ ���� -1�� ��ȯ 
		process_bingo(bingoCom[N][N], num);
		
		winMe = count_bingo(bingoMe[N][N]); //���� Ȯ�� 
		winCom = count_bingo(bingoCom[N][N]);
		
	} while ((winMe==0)&&(winCom==0)); //0:�ºΰ� ���� ���� 1:���� �ϼ� ��.
	
	printf("===���� ���==="); //�� ������ ��� 
	print_bingo(bingoMe[N][N]);
	
	printf("===��ǻ���� ���==="); //��ǻ���� ������ ���
	print_bingo(bingoCom[N][N]); 
	
	switch (winCom*2+winMe) { //���� �˷��� 
		case 1 : //���� �̱�
			printf("���� �̰���ϴ�.\n");
			break;
		case 2 : //��ǻ�Ͱ� �̱�
			printf("��ǻ�Ͱ� �̰���ϴ�.\n");
			break;
		case 3 : //���
			 printf("�����ϴ�.\n");
			 break;
		default : //���� 
			printf("Error\n");
			break;
	}
	
}

//�Լ�
 void initiate_bingo() { //���� ���̺��� �ʱ⿡ ����� �� 
	
	int i, j;
	int temp;
	int k;
	int order = 1;
	int bingo[N][N];
	
	srand((unsigned int)time(NULL));
	int ran_row = rand()%N; //���� ����
	int ran_col = rand()%N; //���� ����
	
	for (i=0 ; i<N ; i++) { //�迭�� 1~N ��ġ 
		for (j=0 ; j<N ; j++) {
			bingo[i][j] = order++;
		}
	} 
	
	for (k=0 ; k<N ; k++) { //������ ���� 
		for (i=0 ; i<N ; i++) {
			for (j=0 ; j<N ; j++) {
				temp = bingo[i][j];
				bingo[i][j] = bingo[ran_row][ran_col];
				bingo[ran_row][ran_col] = temp;
			}
		}
	}
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

 int get_number_byMe(int input) { //���� ���� ��ȣ �Է� ����
	int inputMe; //���� �Է��� ����
	int x, retry; //??
	
	do {
		retry = 0;
		if (input == 0) { //0:��, 1:��ǻ�� 
			printf("1~N*N ������ ���ڸ� �Է��ϼ���. : ");
			scanf("%d", &inputMe);
			if (inputMe<1 || inputMe>N*N) {
				retry = 1; //retry=1�̸� �Է¿���. �ٽ� �Է� 
			} 
		} 
		}
		
		if (retry == 0) {
			for (x=0 ; x<count ; x++) {
				if (checking[x] == inputMe && checking[x] == inputCom) { //���� �Է��ϰų� ��ǻ�Ͱ� �Է��Ѱ� ������ Ȯ��. �׳� �������� �������� 
					retry = 1;
					break; 
				}
			}
		}
	} while (retry == 1); //retry=1�̸� �ٽ� �Է��ؾ��ϹǷ� do �������� ���ư�
	
	checking[count++] = inputMe;
	if (input == 0) {
		printf("����ڰ� '%d'�� �����߽��ϴ�. \n", inputMe);
	} 
	else {
		printf("��ǻ�Ͱ� '%d'�� �����߽��ϴ�. \n\n", inputCom);
	}
	
	return inputMe;
	
 }
 
 int get_number_byCom() { //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
	int inputCom;
	inputCom = rand()%(N*N)+1; 
 }
 
 void process_bingo(int bingo[N][N], int number) { //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̵� ĭ�� ä��
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if(bingo[i][j] == inputMe || bingo[i][j] == inputCom) 
				bingo[i][j] = -1;
		}
	}
}
 
 int count_bingo(int bingo[N][N]) { //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
	
	int i, j, sum; //�� ���� ���� -N�� �Ǹ� ����
	
	for (i=0 ; i<N ; i++) { //�� Ȯ�� 
		sum = 0; //sum �ʱ�ȭ
		
		for (j=0 ; j<N ; j++) {
			sum += bingo[i][j];
		} 
		
		if (sum == -5) {
			return 1;
		}
	} 
	
	for (j=0 ; j<N ; j++) { //�� Ȯ�� 
		sum = 0 ; //sum �ʱ�ȭ
		
		for (i=0 ; i<N ; i++) {
			sum += bingo[i][j];
		} 
		
		if (sum == -5) {
			return 1;
		}
	}
	
	sum = 0; //�밢���� ���� sum �ʱ�ȭ
	
	for (i=0 ; i<N ; i++) { //�밢�� Ȯ��
		sum += bingo[i][i]; 
	}
	
	if (sum == -5) {
		return 1;
	}
	
	sum = 0;
	
	for (i=0 ; i<N ; i++) { //�밢�� Ȯ�� 
		sum += bingo[i][N-i-1];
	}
	
	if (sum == -5) {
		return 1;
	} 
	
	return 0; //���� ���� ���� 
}


