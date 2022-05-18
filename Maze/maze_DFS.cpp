// Stack�� ����� DFS
/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>


#pragma warning(disable: 6031)
#define M 100
#define N 100

int main() {
	int i = 0, j = 0, cnt = 0;
	char Map[M][N];

	char Stack[N] = {0,};
	int SP = 0;	//stack Pointer

	int x, y;
	scanf("%d %d", &x, &y);

	for (int m = 1; m < x+1; m++) {		// Map[1][1]~Map[x][y]���� ������
		for (int n = 1; n < y+1; n++) {
			scanf(" %c", &Map[m][n]);
		}
	}
	printf("\n");

	int ip = 0, jp = 0;	// ip�� �� ���� i ��ǥ, jp�� �� ���� j ��ǥ�� �ǹ���

	printf("<<< ���� �� �Էµ� Map ��� >>>\n");
	for (int m = 1; m < x + 1; m++) {
		for (int n = 1; n < y + 1; n++) {
			printf("%c ", Map[m][n]);
		}
		printf("\n");
	}
	printf("\n");

	if (i == 1 && j == 1) {
		Map[i][j] = '*';
	}

	while (1) {

		// �ִ� �Ÿ��� ���� ���̱� ������ �١��֡��آ� ������ ���캸��
		if (Map[i + 1][j + 1] == '0') {		// ��
			ip = i + 1;
			jp = j + 1;
		}
		else if (Map[i][j + 1] == '0') {	// ��
			ip = i;
			jp = j + 1;
		}
		else if (Map[i + 1][j] == '0') {	//��
			ip = i + 1;
			jp = j;
		}
		else if (Map[i - 1][j + 1] == '0') {	//��
			ip = i - 1;
			jp = j + 1;
		}
		else if (Map[i - 1][j] == '0') {	//��
			ip = i - 1;
			jp = j;
		}
		else if (Map[i][j - 1] == '0') {	//��
			ip = i;
			jp = j - 1;
		}
		else if (Map[i - 1][j - 1] == '0') {	//��
			ip = i - 1;
			jp = j - 1;
		}
		else if (Map[i + 1][j - 1] == '0') {	//��
			ip = i + 1;
			jp = j - 1;
		}

		// ��� �鿡 0�� ���� ��
		else {
			ip = -100;
		}

		cnt++;	// �ܰ�


		if (ip != -100 || (i == x && j == y)) {		//������
			Stack[SP++] = i;
			Stack[SP++] = j;
			i = ip;
			j = jp;
			Map[i][j] = '*';

			if (i == x && j == y) {
				break;
			}
		}
		else if (ip == -100) {	// ����
			if (i == 1 && j == 1) {
				printf("���̻� ������ �� �ִ� ������ ���� ���α׷��� �����մϴ�.\n");
				break;
			}
			
			while (i != 1 || j != 1) {
				Map[i][j] = 'X';
				j = Stack[--SP];
				i = Stack[--SP];
			}
		}

		// �ܰ躰 ���
		printf("<<< %d �ܰ� Map ��� >>>\n", cnt);
		for (int m = 1; m < x + 1; m++) {
			for (int n = 1; n < y + 1; n++) {
				printf("%c ", Map[m][n]);
			}
			printf("\n");
		}
		printf("\n");

	}
	
	// ���� ���
	printf("<<< ���� Map ��� >>>\n", cnt);
	for (int m = 1; m < x + 1; m++) {
		for (int n = 1; n < y + 1; n++) {
			printf("%c ", Map[m][n]);
		}
		printf("\n");
	}
	printf("\n");
}*/