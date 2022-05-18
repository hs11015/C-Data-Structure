#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int A[100]; //배열
int S, lft, rght;  // S: 현재 배열에 들어있는 개수, lft와 rght를 쓰는 이유는 Binary Search이기 때문
// left와 right는 using namespace std;에 내포되어있어서 모호한 기호라고 뜸

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
        A[i + 1] = A[i];    // 오른쪽으로 한 칸씩 밀기
    A[rght] = x; // 마지막 자리에 x를 넣어줌
    S++;    // 배열에서 문자 하나를 insert 했으므로 배열의 길이를 1 늘려야함
    return 0;
}

int dlte(int x) {
    int i;
    for (i=lft; i<S; i++)
        A[i] = A[i+1];  // 삭제한 위치의 배열 다음에 위치하는 것부터 왼쪽으로 한 칸씩 당겨줌
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
                printf("%d Not Found. It Should be between %d and %d\n", x, lft, rght);   // x 값이 없는 경우 찾지 못함 출력
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