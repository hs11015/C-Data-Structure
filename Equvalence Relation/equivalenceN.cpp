#define _CRT_SECURE_NO_WARNINGS

// 아예 한 번에 #include <bits/stdc++.h> 써줘도 됨
// C++에서 자주 쓰는 library들을 모아놓은 라이브러리
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;

vector<int> MAP[1000];	// vector library

int Stack[10000];
int SP;

void Push(int x) {
	Stack[SP++] = x;
	return;
}

int Pop() {
	return Stack[--SP];
}

int IsEmpty() {
	return (SP == 0);
}


void SetLink(int x, int y) {
	MAP[x].push_back(y);
	return;
}

int LastForward[1000];

int NextForward(int x) {
	LastForward[x]++;
	if (LastForward[x] < MAP[x].size()) {
		return MAP[x][LastForward[x]];
	}
	else {
		return -1;
	}
}

int Visited[1000];
int LastStart = 0;

int IsMarked(int x) {
	return Visited[x];
}

void Mark(int x) {
	Visited[x] = 1;
}

int NextStart() {
	LastStart++;
	while (LastStart <= n) {
		if (IsMarked(LastStart) == 0) {
			return LastStart;
		}
		else
			LastStart++;
	}
	return -1;
}


int main() {
	int i, x, y, cur, s;
	for (i = 0; i < 1000; i++) {
		LastForward[i] = -1;
	}
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		SetLink(x, y);
		SetLink(y, x);
	}
	while ((cur = NextStart()) != -1) {
		printf("%d", cur);
		Mark(cur);
		while (1) {
			if ((s = NextForward(cur)) != -1) {
				if (IsMarked(s) == 0) {
					printf(" %d", s);
					Mark(s);
					Push(cur);
					cur = s;
				}
				else {
					;
				}
			}

			else {
				if (IsEmpty() == 1) {
					break;
				}
				else {
					cur = Pop();
				}

			}
		}
		printf("\n");
	}
	return 0;
}


/*

10 7
1 3
3 9
6 2
5 10
7 3
4 9
8 10


20 20
13 17
1 5
1 13
13 1
5 6
6 5
7 7
19 20
18 19
19 4
15 16
16 2
4 8
8 10
9 15
19 11
7 17
8 19
19 20
1 19

*/