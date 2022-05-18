// Queue를 사용한 BFS

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

	for (int m = 1; m < x + 1; m++) {		// Map[1][1]~Map[x][y]까지 존재함
		for (int n = 1; n < y + 1; n++) {
			scanf(" %c", &Map[m][n]);
		}
	}
	printf("\n");


	printf("<<< 시작 전 입력된 Map 출력 >>>\n");
	for (int m = 1; m < x + 1; m++) {
		for (int n = 1; n < y + 1; n++) {
			printf("%c ", Map[m][n]);
		}
		printf("\n");
	}
	printf("\n");


	while (1) {

		// ↘→↓↗↑←↖↙ 순서로 주위에 0인 cell은 모두 저장하기
		// if 순서가 달라지면 Map에 표시되는 '*'의 양상도 달라짐

		if (Map[i + 1][j + 1] == '0') {		// ↘
			Queue[head++] = i + 1;
			Queue[head++] = j + 1;
		}
		if (Map[i][j + 1] == '0') {	// →
			Queue[head++] = i;
			Queue[head++] = j + 1;
		}
		if (Map[i + 1][j] == '0') {	//↓
			Queue[head++] = i + 1;
			Queue[head++] = j;
		}
		if (Map[i - 1][j + 1] == '0') {	//↗
			Queue[head++] = i - 1;
			Queue[head++] = j + 1;
		}
		if (Map[i - 1][j] == '0') {	//↑
			Queue[head++] = i - 1;
			Queue[head++] = j;
		}
		if (Map[i][j - 1] == '0') {	//←
			Queue[head++] = i;
			Queue[head++] = j - 1;
		}
		if (Map[i - 1][j - 1] == '0') {	//↖
			Queue[head++] = i - 1;
			Queue[head++] = j - 1;
		}
		if (Map[i + 1][j - 1] == '0' && (i < x + 1 && j > 0)) {	//↙
			Queue[head++] = i + 1;
			Queue[head++] = j - 1;
		}

		if (tail == head && Map[i][j] == '*') {
			break;
		}

		else { // (tail != head) && (head_tmp != head) {		// 꺼내쓰기
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
}