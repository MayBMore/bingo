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

 int get_number_byMe(int sth) { //���� ���� ��ȣ �Է� ����
	int x, retry; //??
	
	do {
		retry = 0;
		if (sth == 0) { //0:��, 1:��ǻ�� 
			printf("1~L ������ ���ڸ� �Է��ϼ���. : ");
			scanf("%d", &input);
			if (input<1 || input>N*N) {
				retry = 1; //retry=1�̸� �Է¿���. �ٽ� �Է� 
			}
			else { //��ǻ�Ͱ� �Է� 
				get_number_byCom(input); 
			} 
			
		if (retry == 0) {
			for (x=0 ; x<count ; x++) {
				if (checking[x] == input) { //���� �Է��ϰų� ��ǻ�Ͱ� �Է��Ѱ� ������ Ȯ��. �׳� �������� �������� 
					retry = 1;
					break; 
				}
			}
		}	
 }
} while (retry == 1); //retry=1�̸� �ٽ� �Է��ؾ��ϹǷ� do �������� ���ư��� ��

checking[count++] = input;

			if (sth == 0) {

				printf(">����ڰ� '%d'�� �����߽��ϴ�. \n", input);

			} 

			else {

				printf(">��ǻ�Ͱ� '%d'�� �����߽��ϴ�. \n \n", input);

			}
			
}
