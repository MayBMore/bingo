#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#define N 5 //N�� ���� ���ڷ� ġȯ�Ѵ�. 
#define M //M�� ���� ���ڷ� ġȯ�Ѵ�. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int bingo[N][N];

 int initiate_bingo(int bingo[N][N]); //���� ���̺��� �ʱ⿡ ����� �� 
	
 void print_bingo(int bingo[N][N]); //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���

 int get_number_byMe(); //���� ���� ��ȣ �Է� ����
 
 int get_number_byCom(); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
 
 int process_bingo(); //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̵� ĭ�� ä��
 
 int count_bingo(); //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
 

int main(int argc, char *argv[]) {
	
	srand((int)time(NULL)); //���� �Լ�
	int bingo[N][N]; //���� �迭 ����
	int i, j, k, temp; //���� ����
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
	 
	 
	
	
	
	
	
	return 0;
}

 
