#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int A[100]; //�迭
int S, loc;  // S: ���� �迭�� ����ִ� ����, loc: �迭������ ��ġ(�ε�����)

int srch(int x) {
    int i;
    for (i = 0; i < S; i++) {
        if (A[i] == x)
            break;
    }
    if (i == S)     // �迭 ���������� A[i] == x�� �������� �ʾ��� ���
        return -1;
    else {      // �߰��� A[i] == x ���� �־ �߰��� break �� ���
        loc = i;    // loc(�ε��� ��)�� ���� i ���� �־���
        return 1;
    }
}

int insrt(int x) {
    A[S] = x; // ������ �ڸ��� x�� �־���
    S++;    // �� �ϳ��� insert ������ S ��(��ü �迭�� ����)�� �ϳ� �÷���
    return 0;
}

int dlte(int x) {
    A[loc] = A[S - 1];  // �迭�� �� �������� ��ġ���ִ� ���ڸ� ������ ��ġ�� �־��ֱ�
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
                printf("%d Not Found\n", x);   // x ���� ���� ��� ã�� ���� ���
            else // x�� �迭 �ȿ� �����ϴ� ���
                printf("%d Found at Index %d\n", x, loc);   // srch �Լ����� ã�� x�� ��ġ ��(index ��)
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