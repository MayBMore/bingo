#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#define N 5 //N�� ���� ���ڷ� ġȯ�Ѵ�. 
#define M //M�� ���� ���ڷ� ġȯ�Ѵ�. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
 /*��������*/ 
 int bingo[N][N];
 int i, j ; //��� �� ���� 
 int inputMe, inputCom ; //���� �Է��� ����, ��ǻ�Ͱ� �Է��� ���� 

 /*�Լ�*/ 
 int initiate_bingo(int bingo[N][N]); //���� ���̺��� �ʱ⿡ ����� �� 
	
 void print_bingo(int bingo[N][N]); //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���

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
 
 int get_number_byCom(); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
 
 int process_bingo(); //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̵� ĭ�� ä��
 
 int count_bingo(int bingo[N][N]) { //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
	
	int sumbingo[N+N+2] = {0}; //�ʱ�ȭ 
	int count = 0; //���� �� ����
	
	//����
	 
 	
	
	
 }
 

int main(int argc, char *argv[]) {
	
	srand((int)time(NULL)); //���� �Լ�
	int bingo[N][N]; //���� �迭 ����
	int k, temp; //���� ����
	int count = 1;
	
	printf("=====���� ������ ��������=====\n"); 
	
	int ran_row = rand()%N; //���� ����
	int ran_col = rand()%N; //���� ����
	
	/*�迭�� 1���� N*N �ֱ�*/ 
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			bingo[i][j] = count++;
		}
	} 
	
	/*�����Ǽ���*/
	for (k=0 ; k<N ; k++){
		for (i=0 ; i<N ; i++){
			for (j=0 ; j<N ; j++) {
				temp = bingo[i][j];
				bingo[i][j] = bingo[ran_row][ran_col];
				bingo[ran_row][ran_col] = temp;
			}
		}
	} 
	
	/*������ ���*/
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			printf("%2d ", bingo[i][j]);
		}
		printf("\n");
	} 
	
	/*��ǻ���� ������*/
	printf("\n \n");
	printf("�̰��� ��ǻ���� ������\n");
	
	int Cran_row = rand()%N; //���� ����
	int Cran_col = rand()%N; //���� ����
	
	/*�迭�� 1���� N*N �ֱ�*/ 
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			bingo[i][j] = count++;
		}
	} 
	
	/*�����Ǽ���*/
	for (k=0 ; k<N ; k++){
		for (i=0 ; i<N ; i++){
			for (j=0 ; j<N ; j++) {
				temp = bingo[i][j];
				bingo[i][j] = bingo[Cran_row][Cran_col];
				bingo[Cran_row][Cran_col] = temp;
			}
		}
	} 
	
	/*������ ���*/
	for (i=0 ; i<N ; i++){
		for (j=0 ; j<N ; j++){
			printf("%2d ", bingo[i][j]);
		}
		printf("\n");
	}  
	 
	 
	
	
	
	
	
	return 0;
}

 
