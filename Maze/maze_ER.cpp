/*
// Stack�� ����� DFS

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

#pragma warning(disable: 6031)
#define M 100

int main() {
	int i = 0, j = 0, cnt = 0;
	char Map[M][M];
	char check[M][2] = { {0,0}, };
	char Stack[M][M] = {{0,},};
	int SP = 0;	//stack Pointer

	int x, y;
	printf("0���� ������� ����? �Է��� Equivalence relation ���� �� ����: ");
	scanf("%d %d", &x, &y);

	for (int m = 0; m < x; m++) {		// Map[1][1]~Map[x][y]���� ������
		for (int n = 0; n < x; n++) {
			Map[m][n] = 0;	// �ϴ� 0���� �Է¹ޱ�
		}
	}
	printf("\n");

	for (int quit = 0; quit < y; quit++) {
		printf("Equivalence relation ���� �� �Է�: ");
		scanf("%d %d", &check[quit][0], &check[quit][1]);
	}

	printf("<<< �Է� ���� Stack >>>\n");
	for (int k = 0; k < x; k++) {
		printf("%d %d\n", check[k][0], check[k][1]);
	}

	printf("<<< ���� �� �Էµ� Map ��� >>>\n");
	for (int m = 0; m < x; m++) {		// Map[1][1]~Map[x][y]���� ������
		for (int n = 0; n < x; n++) {
			printf("%d ", Map[m][n]);
		}
		printf("\n");
	}
	printf("\n");

	while (check[j][0] != 0 && check[j][1] != 0) {

		Map[check[j][0] - 1][check[j][1] - 1] = 1;
		Map[check[j][1] - 1][check[j][0] - 1] = 1;
		j++;
		cnt++;

		// �ܰ躰 ���
		printf("<<< %d �ܰ� Map ��� >>>\n", cnt);
		for (int m = 0; m < x; m++) {		// Map[1][1]~Map[x][y]���� ������
			for (int n = 0; n < x; n++) {
				printf("%d ", Map[m][n]);
			}
			printf("\n");
		}
		printf("\n");

	}

	for (int m = 0; m < x; m++) {
		int k = 0;
		Stack[m][k] = m + 1;
		for (int i = 0; i < x; i++) {
			if (Map[m][i] == 1) {
				k++;
				Stack[m][k] = i + 1;
			}
		}
	}

	// ���� ���
	printf("<<< ���� Map ��� >>>\n");
	for (int m = 0; m < x; m++) {		// Map[1][1]~Map[x][y]���� ������
		for (int n = 0; n < x; n++) {
			printf("%d ", Map[m][n]);
		}
		printf("\n");
	}
	printf("\n");

	printf("<<< ���� Stack ��� >>>\n");
	for (int m = 0; m < x; m++) {
		for (int n = 0; n < x; n++){
			if (Stack[m][n] != 0) {
				printf("%d ", Stack[m][n]);
			}
		}
		printf("\n");
	}
	printf("\n");
}*/