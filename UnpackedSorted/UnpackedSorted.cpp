#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

#pragma warning(disable: 6031)

using namespace std;

int A[100], B[100]; //A: �迭, B: ������ �Ⱦ������� ǥ���ϴ� marker
int S, lft, rght;  // S: ���� �迭�� ����ִ� ����, lft�� rght�� ���� ������ Binary Search�̱� ����
// left�� right�� using namespace std;�� �����Ǿ��־ ��ȣ�� ��ȣ��� ��

int srch(int x) {
    int start, end, middle;
    start = 0; end = S - 1;
    while (start <= end) {
        middle = (start + end) / 2;
        if (A[middle] == x) {
            lft = rght = middle;
            if (B[middle] == 1)  // ���� ���̸�
                return 1;
            else    // ���� �ʴ� ���̸�
                return -1;
        }
        else if (A[middle] > x) {
            end = middle - 1;
        }
        else {  //A[middle] < x
            start = middle + 1;
        }
    }
    lft = end; rght = start;
    return -1;
}

int insrt(int x) {
    int i, j;
    if (lft == rght)    //���� ���� ������ ���� ���� ��� == ���� ã�� ���
        B[lft] = 1;  //���� ��(1)�̶�� ǥ��
    else if (lft == -1) {   //������ ���̻� ���� ������ ���� �����ϴ� ���
        i = rght;
        while (B[i] == 1 && i < S)
            i++;
        if (i == S) {   //������ ������ �� ��Ȳ
            for (j = S - 1; j > rght; j--) {
                A[j + 1] = A[j];
                B[j + 1] = B[j];
            }
            A[rght] = x;    //������ ���µ��� �Ⱦ��� ���� �� ã�Ҵٸ� �� �����ʿ� �ش� ���� �־���
            B[rght] = 1;    //�ش� ���� ���� ��(1)��
            S++;    //���� �ϳ� �þ���Ƿ� S(����)�� 1�� �÷���
        }
        else {
            for (j = i - 1; j >= rght; j--) {
                A[j + 1] = A[j];
                B[j + 1] = B[j];
            }
            A[rght] = x;
            B[rght] = 1;
        }
    }
    
    else if (rght == S) {   //�������� ��ĭ�� ã�ư� ����
        i = lft;
        while (B[i] == 1 && i >= 0)
            i--;   
        if (i == -1) {  //���ڸ��� ���� ���
            A[S] = x;   //�����ʿ� �߰�
            B[S] = 1;   //���� ��(1) ó��
            S++;        //�迭�� ������ 1�� �þ
        }
        else {  //�ڸ��� �ִ� ��� �������� �и� ��
            for (j = i; j < rght; j++) {   //i�� ���ڸ���, ã��
                A[j] = A[j + 1];
                B[j] = B[j + 1];
            }
            A[rght - 1] = x;    //rght ���ʿ� x �߰�
            B[rght - 1] = 1;    //�ش� ���� ���� ��(1) ó��
        }
    }
    else {
        i = lft;
        while (B[i] == 1 && i >= 0)
            i--;
        if (i != -1) {  //�� ���ʿ� ���� �ʾ��� ��
            for (j = i; j < lft; j++) {
                A[j] = A[j + 1];
                B[j] = B[j + 1];
            }
            A[lft] = x; // x �ֱ�
            B[lft] = 1; // ���� ���ٰ� ǥ���ϱ�(1)
        }
        else {  //i == 1
            i = rght;
            while (B[i] == 1 && i < S)   //���� ��, i�� �迭���� ���� ���� ��
                i++;
            if (i != S) {
                for (j = i - 1; j >= rght; j--) {
                    A[j + 1] = A[j];
                    B[j + 1] = B[j];
                }
                A[rght] = x;    //rght index�� ������ ���� x �ֱ�
                B[rght] = 1;    //x�� ���ٴ� ǥ�ø� ���ֱ�
            }
            else {
                for (j = S - 1; j >= rght; j--) {
                    A[j + 1] = A[j];
                    B[j + 1] = B[j];
                }
                A[rght] = x;
                B[rght] = 1;
                S++;
            }
        }
    }
    return 0;
}

int dlte(int x) {
    B[lft] = 0; // ���� �ʴ´ٰ� ǥ�����ָ� ��
    return 0;
}

int main() {
    char c;
    int x, i;
    S = 0;
    while (true) {
        printf("S = %d\n", S);

        for (i = 0; i < S; i++)
            printf("%3d    ", i);
        printf("\n");

        for (i = 0; i < S; i++)
            printf("%3d    ", A[i]);
        printf("\n");

        for (i = 0; i < S; i++) //��Ŀ(���� �Ⱦ���), 0�̸� X, 1�̸� O�� ǥ��
            printf("%3d    ", B[i]);
        printf("\n");

        scanf(" %c", &c);

        if (c == 's') { // c�� Search�� ��
            scanf("%d", &x);
            if (srch(x) == -1 && lft != rght)    //���� ���� ������ ���� �ٸ��� ã�� ���� lft�� rght ���̿� �־����
                printf("%d Not Found. It Should be between %d and %d\n", x, lft, rght);   // x ���� ���� ��� ã�� ���� ���
            else if(srch(x) == -1 && lft == rght)   //���� ���� ������ ���� ������ ������ ���·� �����Ѵٴ� �Ͱ� ����
                printf("%d Not Found. It Stored as deleted value at %d\n", x, lft);   // x ���� ���� ��� ã�� ���� ���
            else // x�� �迭 �ȿ� �����ϴ� ���
                printf("%d Found at Index %d\n", x, lft);   // srch �Լ����� ã�� x�� ��ġ ��(index ��)�̶� lft == rght
        }
        else if (c == 'i') {    // c�� insert�� �� 
            scanf("%d", &x);
            if (srch(x) == -1) {
                insrt(x);       // x���� ���� ��� �ش� �� insert ���ֱ�
            }
        }
        else if (c == 'd') {     // c�� delete�� ��
            scanf("%d", &x);
            if (srch(x) == 1) {
                dlte(x);    //ã���� �� delete �ض�
            }
            printf("Delete\n");
        }
        else if (c == 'q') {    // c�� quit�� ��
            break;
        }
        else {  //c�� �ƹ��͵� �ƴ� ��
            printf("???\n");
        }
    }
    return 0;
}