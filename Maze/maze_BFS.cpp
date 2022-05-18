// Queue�� ����� BFS

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>


#pragma warning(disable: 6031)
#define M 100
#define N 100

int main() {
	int i = 0, j = 0, cnt = 0;
	char Map[M][N];

	char Queue[N*M] = { 0, };
	int head = 0, tail = 0;	//Queue Pointer

	int x, y;
	scanf("%d %d", &x, &y);

	for (int m = 1; m < x + 1; m++) {		// Map[1][1]~Map[x][y]���� ������
		for (int n = 1; n < y + 1; n++) {
			scanf(" %c", &Map[m][n]);
		}
	}
	printf("\n");


	printf("<<< ���� �� �Էµ� Map ��� >>>\n");
	for (int m = 1; m < x + 1; m++) {
		for (int n = 1; n < y + 1; n++) {
			printf("%c ", Map[m][n]);
		}
		printf("\n");
	}
	printf("\n");


	while (1) {

		// �١��֡��آ� ������ ������ 0�� cell�� ��� �����ϱ�
		// if ������ �޶����� Map�� ǥ�õǴ� '*'�� ��� �޶���

		if (Map[i + 1][j + 1] == '0') {		// ��
			Queue[head++] = i + 1;
			Queue[head++] = j + 1;
		}
		if (Map[i][j + 1] == '0') {	// ��
			Queue[head++] = i;
			Queue[head++] = j + 1;
		}
		if (Map[i + 1][j] == '0') {	//��
			Queue[head++] = i + 1;
			Queue[head++] = j;
		}
		if (Map[i - 1][j + 1] == '0') {	//��
			Queue[head++] = i - 1;
			Queue[head++] = j + 1;
		}
		if (Map[i - 1][j] == '0') {	//��
			Queue[head++] = i - 1;
			Queue[head++] = j;
		}
		if (Map[i][j - 1] == '0') {	//��
			Queue[head++] = i;
			Queue[head++] = j - 1;
		}
		if (Map[i - 1][j - 1] == '0') {	//��
			Queue[head++] = i - 1;
			Queue[head++] = j - 1;
		}
		if (Map[i + 1][j - 1] == '0' && (i < x + 1 && j > 0)) {	//��
			Queue[head++] = i + 1;
			Queue[head++] = j - 1;
		}

		if (tail == head && Map[i][j] == '*') {
			break;
		}

		else { // (tail != head) && (head_tmp != head) {		// ��������
			i = Queue[tail++];
			j = Queue[tail++];

			while (Map[i][j] == '*') {

				i = Queue[tail++];
				j = Queue[tail++];
			}
			Map[i][j] = '*';

			if ((i == x && j == y) || (i < 1 || j < 1)) {
				break;
			}
			printf("%d, %d\n", i, j);
			cnt++;
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
}