/*
#pragma once
#include "stack_queue_header.h"

#define M 100
#define N 100

char Map[M][N];
int i, j;	// 현재 위치

// Stack 관련
int Stack[N];
int SP;	//stack Pointer

int init_s() {
	SP = 0;
	return 0;
}

int isEmpty_s() {
	return SP == 0;
}

int Push_s(int x) {
	Stack[SP++] = x;
	return 0;
}

int Pop_s() {
	return Stack[--SP];
}


// Queue 관련
int Queue[N];
int Head, Tail;

int init_q() {
	Head = Tail = 0;
}

int isEmpty_q() {
	return Head == Tail;
}

int insert_q(int x) {
	Queue[Head] = x;
	Head = (Head + 1) % N;
	return 0;
}

int delete_q() {
	int RetVal;
	RetVal = Queue[Tail];
	Tail = (Tail + 1) % N;
	return RetVal;
}
*/