#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int A[100]; //�迭
int S, lft, rght;  // S: ���� �迭�� ����ִ� ����, lft�� rght�� ���� ������ Binary Search�̱� ����
// left�� right�� using namespace std;�� �����Ǿ��־ ��ȣ�� ��ȣ��� ��

int srch(int x) {
    int start, end, middle;
    start = 0; end = S - 1;
    while (start <= end) {
        middle = (start + end) / 2;
        if (A[middle] == x) {
            lft = rght = middle;
            return 1;
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
    int i;
    for (i = S - 1; i >= rght; i--)
        A[i + 1] = A[i];    // ���������� �� ĭ�� �б�
    A[rght] = x; // ������ �ڸ��� x�� �־���
    S++;    // �迭���� ���� �ϳ��� insert �����Ƿ� �迭�� ���̸� 1 �÷�����
    return 0;
}

int dlte(int x) {
    int i;
    for (i=lft; i<S; i++)
        A[i] = A[i+1];  // ������ ��ġ�� �迭 ������ ��ġ�ϴ� �ͺ��� �������� �� ĭ�� �����
    S--;    // �迭���� ���� �ϳ��� �����������Ƿ� �迭�� ���̸� 1 �ٿ��ִ� ���� �ʿ���
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

        scanf(" %c", &c);

        if (c == 's') { // c�� Search�� ��
            scanf("%d", &x);
            if (srch(x) == -1)
                printf("%d Not Found. It Should be between %d and %d\n", x, lft, rght);   // x ���� ���� ��� ã�� ���� ���
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