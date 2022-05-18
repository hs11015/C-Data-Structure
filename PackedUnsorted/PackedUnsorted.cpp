#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int A[100]; //배열
int S, loc;  // S: 현재 배열에 들어있는 개수, loc: 배열에서의 위치(인덱스값)

int srch(int x) {
    int i;
    for (i = 0; i < S; i++) {
        if (A[i] == x)
            break;
    }
    if (i == S)     // 배열 마지막까지 A[i] == x가 존재하지 않았을 경우
        return -1;
    else {      // 중간에 A[i] == x 값이 있어서 중간에 break 된 경우
        loc = i;    // loc(인덱스 값)에 현재 i 값을 넣어줌
        return 1;
    }
}

int insrt(int x) {
    A[S] = x; // 마지막 자리에 x를 넣어줌
    S++;    // 값 하나를 insert 했으니 S 값(전체 배열의 길이)을 하나 늘려줌
    return 0;
}

int dlte(int x) {
    A[loc] = A[S - 1];  // 배열의 맨 마지막에 위치해있던 문자를 삭제한 위치에 넣어주기
    S--;    // 배열에서 문자 하나를 삭제시켰으므로 배열의 길이를 1 줄여주는 것이 필요함
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

        if (c == 's') { // c가 Search일 떄
            scanf("%d", &x);
            if (srch(x) == -1)
                printf("%d Not Found\n", x);   // x 값이 없는 경우 찾지 못함 출력
            else // x가 배열 안에 존재하는 경우
                printf("%d Found at Index %d\n", x, loc);   // srch 함수에서 찾은 x의 위치 값(index 값)
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