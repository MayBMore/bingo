#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#define N 5 //N�� ���� ���ڷ� ġȯ�Ѵ�. 
#define M //M�� ���� ���ڷ� ġȯ�Ѵ�. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int bingo[N][N];

int initiate_bingo(int grade[N][N]) //���� ���̺��� �ʱ⿡ ����� �� 
 {
	int i, j, temp = 0; //0���� �ʱ�ȭ 
	
	for (i=0 ; i<N ; i++) //1���� N���� ���� �ֱ� 
	{
		temp += bingo[i][j]; 
				}
	return temp;
 }
	
void print_bingo(int bingo[N][N]) //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
 {
	 int i,j; 
	 
	 for (i=0 ; i<N ; i++)
	 {
	 	for (j=0 ; j<N ; j++)
	 	{
	 		printf("%Nd", bingo[i][j]);
	 		if(j==N-1)
	 		printf("\n");
		 }
	 }
 }
 
 int get_number_byMe(); //���� ���� ��ȣ �Է� ����
 
 int get_number_byCom(); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
 
 int process_bingo(); //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̵� ĭ�� ä��
 
 int count_bingo(); //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
 

int main(int argc, char *argv[]) {
	
	int bingo[N][N]; //���� �迭 ����
	int i, j; //���� ����
	
	srand((int)time(NULL)); //���� �Լ�
	
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
			bingo[i][j] = rand()%(N*N)+1;
		}
	} 
	
	printf("=====���� ������ ��������=====\n"); 
	
	initiate_bingo(int bingo [N][N]); //������ �Լ� ȣ�� 
	
	
	print_bingo();
	 
	 
	
	
	
	
	
	return 0;
}

 
