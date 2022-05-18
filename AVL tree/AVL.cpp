#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

class Node {
public:
	int a;
	int LLen, RLen;
	Node* L, * R;
};

class AVL {
public:
	AVL();
	Node* Search(int x);
	Node* SearchP(Node* N, int x);
	void Insert(int x);
	int InsertP(Node* N, int x, Node** RP);
	void Print();
	void PrintP(Node* N, int d, int LR);
	Node* Root;
};

AVL::AVL() {
	Root = new Node;
	Root->a = 999; Root->LLen = 0; Root->RLen = 0;
	Root->L = NULL;
	Root->R = NULL;
}

Node* AVL::Search(int x) {
	return SearchP(Root->L, x);
}

Node* AVL::SearchP(Node* N, int x) {
	if (N == NULL) return NULL;
	else {
		if (N->a < x) { return SearchP(N->R, x); }
		else if (N->a > x) { return SearchP(N->L, x); }
		else { printf("found!!\n"); return N; }
	}
}

void AVL::Insert(int x) {
	int Len;
	Len = InsertP(Root->L, x, &(Root->L));
	Root->LLen = Len;
}

int AVL::InsertP(Node* N, int x, Node** RP) {
	Node* NN; int Len;
	if (N == NULL) {
		NN = new Node;
		NN->a = x; NN->LLen = 0; NN->RLen = 0;
		NN->L = NN->R = NULL;
		*RP = NN;
		return 0;
	}
	else {
		if (N->a < x) { Len = InsertP(N->R, x, &(N->R)); N->RLen = Len + 1; }
		else if (N->a > x) { Len = InsertP(N->L, x, &(N->L)); N->LLen = Len + 1; }
		else;
	}
	return max(N->LLen, N->RLen);
}

void AVL::Print() {
	PrintP(Root, 0, 0);
}

void AVL::PrintP(Node* N, int d, int LR) {
	int i;
	if (LR == 1) for (i = 0; i < d; i++) printf("            ");
	printf(" |%2d|%4d|%2d| ", N->LLen, N->a, N->RLen);
	if (N->L == NULL) printf("\n");
	else PrintP(N->L, d + 1, 0);
	if (N->R == NULL);
	else PrintP(N->R, d + 1, 1);
}

int main() {
	char c;
	int x, i;
	AVL T;
	Node* RR;
	while (true) {
		T.Print();
		scanf(" %c", &c);
		if (c == 's') {
			scanf("%d", &x);
			if ((RR = T.Search(x)) == NULL)
				printf("%d Not Found.\n", x);
			else
				printf("%d Found at Adress %d\n", x, RR);
		}
		else if (c == 'i') {
			scanf("%d", &x);
			T.Insert(x);
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