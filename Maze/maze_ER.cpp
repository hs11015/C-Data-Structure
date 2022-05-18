/*
// Stack을 사용한 DFS

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
	printf("0부터 몇까지의 정수? 입력할 Equivalence relation 정수 쌍 개수: ");
	scanf("%d %d", &x, &y);

	for (int m = 0; m < x; m++) {		// Map[1][1]~Map[x][y]까지 존재함
		for (int n = 0; n < x; n++) {
			Map[m][n] = 0;	// 일단 0으로 입력받기
		}
	}
	printf("\n");

	for (int quit = 0; quit < y; quit++) {
		printf("Equivalence relation 정수 쌍 입력: ");
		scanf("%d %d", &check[quit][0], &check[quit][1]);
	}

	printf("<<< 입력 받은 Stack >>>\n");
	for (int k = 0; k < x; k++) {
		printf("%d %d\n", check[k][0], check[k][1]);
	}

	printf("<<< 시작 전 입력된 Map 출력 >>>\n");
	for (int m = 0; m < x; m++) {		// Map[1][1]~Map[x][y]까지 존재함
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

		// 단계별 출력
		printf("<<< %d 단계 Map 출력 >>>\n", cnt);
		for (int m = 0; m < x; m++) {		// Map[1][1]~Map[x][y]까지 존재함
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

	// 최종 출력
	printf("<<< 최종 Map 출력 >>>\n");
	for (int m = 0; m < x; m++) {		// Map[1][1]~Map[x][y]까지 존재함
		for (int n = 0; n < x; n++) {
			printf("%d ", Map[m][n]);
		}
		printf("\n");
	}
	printf("\n");

	printf("<<< 최종 Stack 출력 >>>\n");
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