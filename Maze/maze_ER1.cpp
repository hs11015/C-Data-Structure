// Stack�� ����� DFS
/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

#pragma warning(disable: 6031)
#define M 100

int main() {
	int i = 0, j = 0, cnt = 0;
	char Map[M][M] = { {0,0}, };	// �ʱ�ȭ
	char check[M][2] = { {0,0}, };
	char linked_node[M][M] = {{0,},};
	char Stack[M]={0,};
	int SP = 0;	//linked_node Pointer


	int x, y;
	printf("0���� ������� ����? �Է��� Equivalence relation ���� �� ����: ");
	scanf("%d %d", &x, &y);

	for (int quit = 0; quit < y; quit++) {
		printf("Equivalence relation ���� �� �Է�: ");
		scanf("%d %d", &check[quit][0], &check[quit][1]);
	}


	printf("<<< ���� �� �Էµ� Map ��� >>>\n");
	for (int m = 0; m < x; m++) {		// Map[1][1]~Map[x][y]���� ������
		for (int n = 0; n < x; n++) {
			printf("%d ", Map[m][n]);
		}
		printf("\n");
	}
	printf("\n");


	// Map�� ǥ���ϱ�
	while (j<y) {

		Map[check[j][0] - 1][check[j][1] - 1] = 1;
		Map[check[j][1] - 1][check[j][0] - 1] = 1;
		j++;
		cnt++;

		// �ܰ躰 ���
		printf("<<< %d �ܰ� Map ��� >>>\n", cnt);
		for (int m = 0; m < x; m++) {		// Map[0][0]~Map[x][x]���� ������
			for (int n = 0; n < x; n++) {
				printf("%d ", Map[m][n]);
			}
			printf("\n");
		}
		printf("\n");

	}

	// Map���� �� node�� ����� node�� ��� ���
	printf("<<< ���� linked node ��� >>>\n");
	for (int m = 0; m < x; m++) {
		int k = 0;
		linked_node[m][k] = m + 1;
		printf("%d\t", linked_node[m][k]);
		for (int n = 0; n < x; n++) {
			if (Map[m][n] == 1) {
				k++;
				linked_node[m][k] = n + 1;
				printf("%d\t", linked_node[m][k]);
			}
		}
		printf("\n");
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
	int ip = 0, jp = 0;
	i = 0, j = 0;
	while (1) {

		if (linked_node[ip][0] < x+1) {		// linkednode �� ���� ���ڶ�� ���� �� ���� ���� ���.
			jp = j + 1;
			while (linked_node[ip][jp] < x+1) {
				jp++;
				if (jp < sizeof(linked_node)) {
					linked_node[ip][0] = '*';
					break; 
				}
			}

			if (jp < sizeof(linked_node)) {		//������
				Stack[SP++] = linked_node[ip][jp];
				i = ip;
				ip = linked_node[i][jp];
				linked_node[i][jp] = '*';
				i = 0, j = 0;
			}
		}

		// linked_node �� ���� '*'�̶�� �̹� �� ����� ���� ����
		else {
			if (ip == 1) {
				printf("\nStack�� �ʱ�ȭ�մϴ�.\n");
			}

			while (ip != 1) {
				ip = Stack[--SP];
			}
		}



		// �ܰ躰 ���
		printf("\nstack\n");
		for (int m = 0; m < x + 1; m++) {
			printf("%d ", Stack[m]);
		}
		printf("\n");
	}


	for (int m = 0; m < x; m++) {
		i = 0;
		for (int n = 0; n < x; n++) {
			if (linked_node[m][n] != 0) {
				Stack[i++] = linked_node[m][n];
				linked_node[m][n] = '*';
				printf("%d\t", Stack[i - 1]);
			}
		}
		printf("\n");
	}
	printf("\n");
}*/