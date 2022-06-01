/*
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int n;

int A[1000];

int Find(int a) {
	int r, p, q;
	p = a;
	while (A[p] != 0) {
		p = A[p];
	}
	r = p;
	p = a;
	while (A[p] != 0) {
		q = p;
		p = A[p];
		A[q] = r;
	}
	return p;
}

void Union(int a, int b) {
	int p, q;
	p = Find(a);
	q = Find(b);
	if (p != q)
		A[q] = p;
	return;
}

void Print() {
	int i;
	for (i = 1; i <= n; i++)
		printf("%4d", A[i]);
	printf("\n");
	return;
}

int main() {
	char c;
	int a, b;
	printf("Size? ");
	scanf("%d", &n);
	while (true) {
		Print();
		scanf(" %c", &c);
		if (c == 'u') {
			scanf("%d %d", &a, &b);
			Union(a, b);
		}
		else if (c == 'f') {
			scanf("%d", &a);
			printf("%d belongs to group %d\n", a, Find(a));
		}
		else if (c == 'q') {
			break;
		}
		else {
			printf("???\n");
		}
	}
	return 0;
}
*/