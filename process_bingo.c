#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#define N 5 //N�� ���� ���ڷ� ġȯ�Ѵ�. ������ ũ�� 
#define M 4//M�� ���� ���ڷ� ġȯ�Ѵ�. ������ �̱�� ���� 
#define L 25 //N*N�� ���� ���ڷ� ġȯ�Ѵ�.

//���� ���� 
 int checking [L] ;
 int bingoMe[N][N]; //�� ���� 
 int bingoCom[N][N]; //��ǻ�� ���� 
 int input; //�� �׸���  ��ǻ�Ͱ� �Է��� ���� 

void process_bingo(int bingo[N][N], int number) { //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̵� ĭ�� ä��
	int i,j;
	
	for (i=0 ; i<N ; i++) {
		for (j=0 ; j<N ; j++) {
			if(bingo[i][j] == input || bingo[i][j] == input) 
				bingo[i][j] = -1;
		}
	}
}
