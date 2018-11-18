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
 int get_number_byMe(int input); //���� ���� ��ȣ �Է� ����
 int get_number_byCom(); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
 void process_bingo(int bingo[N][N], int number); //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��
 int count_bingo(int bingo[N][N]); //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
 
 void main() {
 	
	int num;
	int winMe, winCom; //���� �̰��� �� ����, ��ǻ�Ͱ� �̰��� �� ���� 
	
	initiate_bingo; //�������̺� ��ȯ 
	
	
	
	
	
	printf("=====���� ������ ��������=====\n");  
	
	return 0;
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
 		/*������ ���*/
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			printf("%2d ", bingo[i][j]);
		}
		printf("\n");
	} 
 }

 int get_number_byMe(int input) { //���� ���� ��ȣ �Է� ����

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
 
 void process_bingo(int bingo[N][N], int number) { //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̵� ĭ�� ä��
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
 
