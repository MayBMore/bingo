#include <stdio.h>
#include <stdlib.h>
#include <time.h> //���� 
#define N 5 //N�� ���� ���ڷ� ġȯ�Ѵ�. ������ ũ�� 
#define M 4//M�� ���� ���ڷ� ġȯ�Ѵ�. ������ �̱�� ���� 
#define L 25 //N*N�� ���� ���ڷ� ġȯ�Ѵ�.
 
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
 int checking [L] ;
 int count = 0;
 int bingoMe[N][N]; //�� ���� 
 int bingoCom[N][N]; //��ǻ�� ���� 
 int input; //�� �׸���  ��ǻ�Ͱ� �Է��� ���� 

 //�Լ�����

 void initiate_bingo(); // ���� ���̺��� �ʱ⿡ �������
 void print_bingo(int bingo[N][N]); //���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���
 int get_number_byMe(int sth); //���� ���� ��ȣ �Է� ����
 int get_number_byCom(int sth); //��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
 void process_bingo(int bingo[N][N], int number); //���õ� ���ڸ� �Է¹޾Ƽ� ���� ���̺� ĭ�� ä��
 int count_bingo(int bingo[N][N]); //���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
 void set_rand(int*bingo);
 void swap(int*x, int*y);
 
 
 void main() {
 	
	int num;
	int winMe, winCom; //���� �̰��� �� ����, ��ǻ�Ͱ� �̰��� �� ����
	int sth; //get number�� �ִ� ���� 
	
	initiate_bingo(); //�������̺� ��ȯ 
	
	printf("=====���� ������ ��������=====\n");  
	
	do {
		
		printf("===�� ������===\n"); //�� ������ ��� 
		print_bingo(bingoMe);
		
		num = get_number_byMe(input); //���� ��ȣ ����
		
		process_bingo(bingoMe, num); //������ ���� -1�� ��ȯ 
		process_bingo(bingoCom, num);
		
		num =  get_number_byCom(input); //��ǻ�Ͱ� ��ȣ ����
		
		process_bingo(bingoMe, num); //������ ���� -1�� ��ȯ 
		process_bingo(bingoCom, num);
		
		winMe = count_bingo(bingoMe); //���� Ȯ�� 
		winCom = count_bingo(bingoCom);
		
	} while ((winMe==0)&&(winCom==0)); //0:�ºΰ� ���� ���� 1:���� �ϼ� ��.
	
	printf("===���� ���==="); //�� ������ ��� 
	print_bingo(bingoMe);
	
	printf("===��ǻ���� ���==="); //��ǻ���� ������ ���
	print_bingo(bingoCom); 
	
	switch (winCom*2+winMe) { //���� �˷��� 
		case 1 : //���� �̱�
			printf("���� �̰���ϴ�.\n");
			break;
		case 2 : //��ǻ�Ͱ� �̱�
			printf("��ǻ�Ͱ� �̰���ϴ�.\n");
			break;
		case 3 : //���
			 printf("�����ϴ�.\n");
			 break;
		default : //���� 
			printf("Error\n");
			break;
	}
	
}

			



/* �ؾ��� ��
1. �ϴ� ���ư���
2. M���� ���� �ϼ��Ǹ� ���� ��ġ��
3. ���ڸ� ���ϸ鼭 ���°�� ���� �̰峪 ���ϱ�
4. ���� �̸� �ٲٱ�
5. �ּ��ޱ�*/ 
