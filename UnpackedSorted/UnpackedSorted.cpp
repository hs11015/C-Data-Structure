#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

#pragma warning(disable: 6031)

using namespace std;

int A[100], B[100]; //A: 배열, B: 쓰는지 안쓰는지를 표현하는 marker
int S, lft, rght;  // S: 현재 배열에 들어있는 개수, lft와 rght를 쓰는 이유는 Binary Search이기 때문
// left와 right는 using namespace std;에 내포되어있어서 모호한 기호라고 뜸

int srch(int x) {
    int start, end, middle;
    start = 0; end = S - 1;
    while (start <= end) {
        middle = (start + end) / 2;
        if (A[middle] == x) {
            lft = rght = middle;
            if (B[middle] == 1)  // 쓰는 값이면
                return 1;
            else    // 쓰지 않는 값이면
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
    if (lft == rght)    //왼쪽 값과 오른쪽 값이 같은 경우 == 값을 찾은 경우
        B[lft] = 1;  //쓰는 값(1)이라고 표시
    else if (lft == -1) {   //왼쪽은 더이상 없고 오른쪽 값만 존재하는 경우
        i = rght;
        while (B[i] == 1 && i < S)
            i++;
        if (i == S) {   //오른쪽 끝까지 간 상황
            for (j = S - 1; j > rght; j--) {
                A[j + 1] = A[j];
                B[j + 1] = B[j];
            }
            A[rght] = x;    //끝까지 갔는데도 안쓰는 값을 못 찾았다면 맨 오른쪽에 해당 값을 넣어줌
            B[rght] = 1;    //해당 값은 쓰는 값(1)임
            S++;    //값이 하나 늘어났으므로 S(개수)를 1개 늘려줌
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
    
    else if (rght == S) {   //왼쪽으로 빈칸을 찾아갈 것임
        i = lft;
        while (B[i] == 1 && i >= 0)
            i--;   
        if (i == -1) {  //빈자리가 없는 경우
            A[S] = x;   //오른쪽에 추가
            B[S] = 1;   //쓰는 값(1) 처리
            S++;        //배열의 개수가 1개 늘어남
        }
        else {  //자리가 있는 경우 왼쪽으로 밀면 됨
            for (j = i; j < rght; j++) {   //i가 빈자리때, 찾기
                A[j] = A[j + 1];
                B[j] = B[j + 1];
            }
            A[rght - 1] = x;    //rght 왼쪽에 x 추가
            B[rght - 1] = 1;    //해당 값은 쓰는 값(1) 처리
        }
    }
    else {
        i = lft;
        while (B[i] == 1 && i >= 0)
            i--;
        if (i != -1) {  //맨 왼쪽에 닿지 않았을 때
            for (j = i; j < lft; j++) {
                A[j] = A[j + 1];
                B[j] = B[j + 1];
            }
            A[lft] = x; // x 넣기
            B[lft] = 1; // 값을 쓴다고 표시하기(1)
        }
        else {  //i == 1
            i = rght;
            while (B[i] == 1 && i < S)   //쓰는 값, i가 배열보다 작은 값일 때
                i++;
            if (i != S) {
                for (j = i - 1; j >= rght; j--) {
                    A[j + 1] = A[j];
                    B[j + 1] = B[j];
                }
                A[rght] = x;    //rght index를 가지는 곳에 x 넣기
                B[rght] = 1;    //x를 쓴다는 표시를 해주기
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
    B[lft] = 0; // 쓰지 않는다고만 표시해주면 됨
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

        for (i = 0; i < S; i++) //마커(쓴다 안쓴다), 0이면 X, 1이면 O로 표시
            printf("%3d    ", B[i]);
        printf("\n");

        scanf(" %c", &c);

        if (c == 's') { // c가 Search일 떄
            scanf("%d", &x);
            if (srch(x) == -1 && lft != rght)    //왼쪽 값과 오른쪽 값이 다르면 찾는 값은 lft와 rght 사이에 있어야함
                printf("%d Not Found. It Should be between %d and %d\n", x, lft, rght);   // x 값이 없는 경우 찾지 못함 출력
            else if(srch(x) == -1 && lft == rght)   //왼쪽 값과 오른쪽 값이 같으면 지워진 상태로 존재한다는 것과 같음
                printf("%d Not Found. It Stored as deleted value at %d\n", x, lft);   // x 값이 없는 경우 찾지 못함 출력
            else // x가 배열 안에 존재하는 경우
                printf("%d Found at Index %d\n", x, lft);   // srch 함수에서 찾은 x의 위치 값(index 값)이라 lft == rght
        }
        else if (c == 'i') {    // c가 insert일 때 
            scanf("%d", &x);
            if (srch(x) == -1) {
                insrt(x);       // x값이 없는 경우 해당 값 insert 해주기
            }
        }
        else if (c == 'd') {     // c가 delete일 때
            scanf("%d", &x);
            if (srch(x) == 1) {
                dlte(x);    //찾았을 때 delete 해라
            }
            printf("Delete\n");
        }
        else if (c == 'q') {    // c가 quit일 때
            break;
        }
        else {  //c가 아무것도 아닐 때
            printf("???\n");
        }
    }
    return 0;
}