#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#define N 3 //N�� ���� ���ڷ� ġȯ�Ѵ�. ������ ũ�� 
#define M 2//M�� ���� ���ڷ� ġȯ�Ѵ�. ������ �̱�� ���� 
#define L N*N //N*N�� ���� ���ڷ� ġȯ�Ѵ�.

 //���� ���� 
 int bingoMe[N][N]; //�� ���� 
 int bingoCom[N][N]; //��ǻ�� ���� 
 
 void initiate_bingo(); // ���� ���̺��� �ʱ⿡ �������
 void set_rand(int*bingo);
 void swap(int*x, int*y);
 
 void initiate_bingo() { //���� ���̺��� �ʱ⿡ ����� �� 
	
	srand((unsigned int)time(NULL));  
	
	set_rand((int*)bingoMe);
	set_rand((int*)bingoCom);
}

 void set_rand(int*bingo) { 
	int i;
	
	for (i=0 ; i<L ; i++) {
		bingo[i] = i+1;
	}
	
	for (i=0 ; i<L ; i++) {
		swap(&bingo[i], &bingo[rand()%L]);
	}
}

 void swap(int*x, int*y) { 
	int temp; //�ӽú��� 
	
	temp = *x;
	*x = *y;
	*y = temp;
}
