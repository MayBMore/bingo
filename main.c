#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#define N 5 //N�� ���� ���ڷ� ġȯ�Ѵ�. ������ ũ�� 
#define M //M�� ���� ���ڷ� ġȯ�Ѵ�. ������ �̱�� ���� 

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
6. ���� ���ڸ� ������ ��, �̹� ���õǾ��ų� ���� ���� ���ڸ� �����ϸ� ���� �޽����� ����ϰ� �ٽ� ���ڸ� �Է� ���� */


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
 int bingo[N][N]; //���� �迭 ���� 
 int i, j ; //��� �� ���� 
 int inputMe, inputCom ; //���� �Է��� ����, ��ǻ�Ͱ� �Է��� ���� 

 /*�Լ�*/ 
 int initiate_bingo(int bingo[N][N]) { //���� ���̺��� �ʱ⿡ ����� �� 

	srand((int)time(NULL)); //���� �Լ�
	int count = 1;
	
	/*�迭�� 1���� N*N �ֱ�*/ 
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			bingo[i][j] = count++;
		}
	} 
 }
	
 void print_bingo(int bingo[N][N]) {  //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
 		/*������ ���*/
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			printf("%2d ", bingo[i][j]);
		}
		printf("\n");
	} 
 }

 int get_number_byMe() { //���� ���� ��ȣ �Է� ����

	int inputMe=0; //�Է¹��� ����
	  
	printf("���ڸ� �Է��ϼ���. : ");
	scanf("%d", &inputMe);

	/*1~N*N ���� �Է½�*/ 
	if (inputMe>=1 && inputMe<=(N*N)) {
		for (i=0 ; i<N ; i++) {
			for (j=0 ; j<N ; j++){
				if(bingo[i][j]==inputMe) { //�Է°��� ���� ���� �� 
					bingo[i][j] = -1 ; //-1�� ġȯ
					break; 
				}
			}
		}
	} 
	
	/*���� �Է��� ���ڿ� ��ǻ�Ͱ� �Է��� ���ڰ� ���� ��*/ 
	else if (inputMe == inputCom) {
		printf("�̹� ���õ� �����Դϴ�. �ٽ� ������ �ּ���. : ");
		scanf("%d", &inputMe); 
		
	}
	
	/*1~N*N ���� �Է��� �ƴҽ�*/ 
	else {
		printf("�߸��Է��Ͽ����ϴ�. �ٽ� �Է����ּ���. : ");
		scanf("%d", &inputMe); 
	}
 }
 
 int get_number_byCom() { //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
	inputCom = rand()% N*N+1;
 }
 
 int process_bingo(int bingo[N][N], int inputMe, int inputCom) { //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̵� ĭ�� ä��
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if(bingo[i][j] == inputMe || bingo[i][j] == inputCom) 
				bingo[i][j] = -1;
		}
	}
 }
 
 
 int count_bingo(int bingo[N][N]) { //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
	
	int sumbingo[N+N+2] = {0}; //�ʱ�ȭ 
	int count = 0; //���� �� ����
	
	/* ��� *�� �̻��ϴϱ� �ٽ� Ȯ��*/
	 
	//����
	for (i=0 ; i<N ; i++) {
		for(j=0 ; j<N ; j++) {
			if (bingo[i*N+j] == 35 ) //�갡 �� �̻���; 
				sumbingo[i]++;
			
		}
	}
	
	//����
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if(bingo[j*N+i] == 35)
				sumbingo[i+N]++;
		}
	} 
	 
	//�밢��(����>>������)
	for (i=0 ; i<N ; i++) {
		for (j=i ; j<=i ; j++) {
			if(bingo[i*5+j] == 35)
				sumbingo[N+N]++;
		}
	} 
	
	//�밢��(������>>����)
	for (i=(N-1) ; i>=0 ; i--) {
		for (j=(N-1) ; j>=4-i ; j--) {
			if (bingo[i*5+j] == 35)
				sumbingo[N+N+1]++;
		}
	} 
	
	//������
	for(i=0 ; i<(N+N+2) ; i++)
		if (sumbingo[i] == -N)
			count++;
			
	return count; 
	
 }
 

int main(int argc, char *argv[]) {
	
	srand((int)time(NULL)); //���� �Լ�
	int k, temp; //���� ����
	int count = 1;
	int ran_row = rand()%N; //���� ����
	int ran_col = rand()%N; //���� ����
	int bingoMe[N][N], bingoCom[N][N] ; //�� ������, ��ǻ�� ������ 
	
	printf("=====���� ������ ��������=====\n");  
	
	initiate_bingo(bingoMe[N][N]); //initiate_bingo �Լ��� ����� �� ������ �ҷ�����
	initiate_bingo(bingoCom[N][N]); //initiate_bingo �Լ��� ����� ��ǻ���� ������ �ҷ����� 
	
	/*�� �����Ǽ���*/
	for (k=0 ; k<N ; k++){
		for (i=0 ; i<N ; i++){
			for (j=0 ; j<N ; j++) {
				temp = bingoMe[i][j];
				bingoMe[i][j] = bingoMe[ran_row][ran_col];
				bingoMe[ran_row][ran_col] = temp;
			}
		}
	} 
	
	/*��ǻ�� �����Ǽ���*/ 
	for (k=0 ; k<N ; k++){
		for (i=0 ; i<N ; i++){
			for (j=0 ; j<N ; j++) {
				temp = bingoCom[i][j];
				bingoCom[i][j] = bingoCom[ran_row][ran_col];
				bingoCom[ran_row][ran_col] = temp;
			}
		}
	} 
	
	print_bingo(bingoMe[N][N]) ; //�� ������ ���
	
	printf("\n") ;
	
	print_bingo(bingoCom[N][N]) ; //��ǻ�� ������ ��� 
	
	return 0;
}

 
