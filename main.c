#include <stdio.h>
#include <stdlib.h>
#define N 5 //N�� ���� ���ڷ� ġȯ�Ѵ�. 
#define M //M�� ���� ���ڷ� ġȯ�Ѵ�. 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo(int row, int col)
{
	int i;
	int max = N*N;
	
	srand((unsigned)time(NULL));
	for(i=0 ; i<=max ; i++)
		printf("%d", 1+rand()%max);
		
	return 0;
 } 

int main(int argc, char *argv[]) {
	
	printf("���� ������ ��������\n"); 
	
	int bingo[N][N] = {0,}; //������ 2���� �迭�ϰ� 0���� �ʱ�ȭ
	int row; //��
	int col; //��
	
	printf("test");
	 
	 
	
	
	
	
	
	return 0;
}


/* ����ؾ� �� �Լ�
initiate_bingo():���� ���̺��� �ʱ⿡ �������
print_bingo():���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
get_number_byMe():���� ���� ��ȣ �Է� ����
get_number_byCom():��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
process_bingo():���õ� ���ڸ� �Ӥ��¹޾Ƽ� ���� ���̺� ĭ�� ä��
count_bingo():���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ */

 
