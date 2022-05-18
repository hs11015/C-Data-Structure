// Stack을 사용한 DFS
/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

#pragma warning(disable: 6031)
#define M 100

int main() {
	int i = 0, j = 0, cnt = 0;
	char Map[M][M] = { {0,0}, };	// 초기화
	char check[M][2] = { {0,0}, };
	char linked_node[M][M] = {{0,},};
	char Stack[M]={0,};
	int SP = 0;	//linked_node Pointer


	int x, y;
	printf("0부터 몇까지의 정수? 입력할 Equivalence relation 정수 쌍 개수: ");
	scanf("%d %d", &x, &y);

	for (int quit = 0; quit < y; quit++) {
		printf("Equivalence relation 정수 쌍 입력: ");
		scanf("%d %d", &check[quit][0], &check[quit][1]);
	}


	printf("<<< 시작 전 입력된 Map 출력 >>>\n");
	for (int m = 0; m < x; m++) {		// Map[1][1]~Map[x][y]까지 존재함
		for (int n = 0; n < x; n++) {
			printf("%d ", Map[m][n]);
		}
		printf("\n");
	}
	printf("\n");


	// Map에 표시하기
	while (j<y) {

		Map[check[j][0] - 1][check[j][1] - 1] = 1;
		Map[check[j][1] - 1][check[j][0] - 1] = 1;
		j++;
		cnt++;

		// 단계별 출력
		printf("<<< %d 단계 Map 출력 >>>\n", cnt);
		for (int m = 0; m < x; m++) {		// Map[0][0]~Map[x][x]까지 존재함
			for (int n = 0; n < x; n++) {
				printf("%d ", Map[m][n]);
			}
			printf("\n");
		}
		printf("\n");

	}

	// Map에서 한 node에 연결된 node들 모두 출력
	printf("<<< 최종 linked node 출력 >>>\n");
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
	int ip = 0, jp = 0;
	i = 0, j = 0;
	while (1) {

		if (linked_node[ip][0] < x+1) {		// linkednode 맨 앞이 숫자라면 아직 다 쓰지 않은 노드.
			jp = j + 1;
			while (linked_node[ip][jp] < x+1) {
				jp++;
				if (jp < sizeof(linked_node)) {
					linked_node[ip][0] = '*';
					break; 
				}
			}

			if (jp < sizeof(linked_node)) {		//전진만
				Stack[SP++] = linked_node[ip][jp];
				i = ip;
				ip = linked_node[i][jp];
				linked_node[i][jp] = '*';
				i = 0, j = 0;
			}
		}

		// linked_node 맨 앞이 '*'이라면 이미 다 사용한 노드라 후진
		else {
			if (ip == 1) {
				printf("\nStack을 초기화합니다.\n");
			}

			while (ip != 1) {
				ip = Stack[--SP];
			}
		}



		// 단계별 출력
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