#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#define N 5 //N�� ���� ���ڷ� ġȯ�Ѵ�. 
#define M //M�� ���� ���ڷ� ġȯ�Ѵ�. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo() //���� ���̺��� �ʱ⿡ ����� �� 
 {
	int bingo[N][N]={0,};
	int i, j;
	
	srand((int)time(NULL)); //�����Լ�
	
	for (i=0 ; i<N ; i++) //1���� N���� ���� �ֱ� 
	{
		for (j=0 ; j<N ; j++)
		{
			bingo[i][j] = rand()%(N*N)+1;
		}
		
	}
 }
	
 int print_bingo() //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
 {
 	int bingo[N][N];
	 int i,j; 
	 
	 for (i=0 ; i<N ; i++)
	 {
	 	for (j=0 ; j<N ; j++)
	 	{
	 		printf("%Nd", bingo[i][j]);
		 }
		printf("\n");
	 }
 }
 
 int get_number_byMe(); //���� ���� ��ȣ �Է� ����
 
 int get_number_byCom(); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
 
 int process_bingo(); //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̵� ĭ�� ä��
 
 int count_bingo(); //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
 

int main(int argc, char *argv[]) {
	
	printf("=====���� ������ ��������=====\n"); 
	
	initiate_bingo();
	print_bingo();
	 
	 
	
	
	
	
	
	return 0;
}

 
