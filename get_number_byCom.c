#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#define N 5 //N�� ���� ���ڷ� ġȯ�Ѵ�. ������ ũ�� 
#define M 4//M�� ���� ���ڷ� ġȯ�Ѵ�. ������ �̱�� ���� 
#define L 25 //N*N�� ���� ���ڷ� ġȯ�Ѵ�.

//���� ���� 
 int checking [L] ;
 int count = 0;
 int bingoMe[N][N]; //�� ���� 
 int bingoCom[N][N]; //��ǻ�� ���� 
 int input; //�� �׸���  ��ǻ�Ͱ� �Է��� ���� 

 int get_number_byCom(int sth) { //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
	input = rand()%L+1; 
 }
