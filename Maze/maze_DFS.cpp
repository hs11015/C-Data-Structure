// Stack을 사용한 DFS
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

	for (int m = 1; m < x+1; m++) {		// Map[1][1]~Map[x][y]까지 존재함
		for (int n = 1; n < y+1; n++) {
			scanf(" %c", &Map[m][n]);
		}
	}
	printf("\n");

	int ip = 0, jp = 0;	// ip는 갈 곳의 i 좌표, jp는 갈 곳의 j 좌표를 의미함

	printf("<<< 시작 전 입력된 Map 출력 >>>\n");
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

		// 최단 거리를 구할 것이기 때문에 ↘→↓↗↑←↖↙ 순으로 살펴보기
		if (Map[i + 1][j + 1] == '0') {		// ↘
			ip = i + 1;
			jp = j + 1;
		}
		else if (Map[i][j + 1] == '0') {	// →
			ip = i;
			jp = j + 1;
		}
		else if (Map[i + 1][j] == '0') {	//↓
			ip = i + 1;
			jp = j;
		}
		else if (Map[i - 1][j + 1] == '0') {	//↗
			ip = i - 1;
			jp = j + 1;
		}
		else if (Map[i - 1][j] == '0') {	//↑
			ip = i - 1;
			jp = j;
		}
		else if (Map[i][j - 1] == '0') {	//←
			ip = i;
			jp = j - 1;
		}
		else if (Map[i - 1][j - 1] == '0') {	//↖
			ip = i - 1;
			jp = j - 1;
		}
		else if (Map[i + 1][j - 1] == '0') {	//↙
			ip = i + 1;
			jp = j - 1;
		}

		// 모든 면에 0이 없을 때
		else {
			ip = -100;
		}

		cnt++;	// 단계


		if (ip != -100 || (i == x && j == y)) {		//전진만
			Stack[SP++] = i;
			Stack[SP++] = j;
			i = ip;
			j = jp;
			Map[i][j] = '*';

			if (i == x && j == y) {
				break;
			}
		}
		else if (ip == -100) {	// 후진
			if (i == 1 && j == 1) {
				printf("더이상 움직일 수 있는 공간이 없어 프로그램을 종료합니다.\n");
				break;
			}
			
			while (i != 1 || j != 1) {
				Map[i][j] = 'X';
				j = Stack[--SP];
				i = Stack[--SP];
			}
		}

		// 단계별 출력
		printf("<<< %d 단계 Map 출력 >>>\n", cnt);
		for (int m = 1; m < x + 1; m++) {
			for (int n = 1; n < y + 1; n++) {
				printf("%c ", Map[m][n]);
			}
			printf("\n");
		}
		printf("\n");

	}
	
	// 최종 출력
	printf("<<< 최종 Map 출력 >>>\n", cnt);
	for (int m = 1; m < x + 1; m++) {
		for (int n = 1; n < y + 1; n++) {
			printf("%c ", Map[m][n]);
		}
		printf("\n");
	}
	printf("\n");
}*/