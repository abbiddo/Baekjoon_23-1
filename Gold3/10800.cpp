/**
프로그램명 : 10800.cpp
설명 : 컬러볼
작성일시 : 2023.02.12
작성자 : abbiddo
**/

#include <iostream>
#include <algorithm>
using namespace std;

struct ball {
    int size, color, index;
};

ball arr[200001];
int color[200001];
int re[200001];

// 정렬에 이용되는 함수 (정렬 기준)
bool cmp(ball& b1, ball& b2) {
    return b1.size < b2.size;
}

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, s;   cin >> c >> s;
        arr[i] = { s, c, i };
    }

    sort(arr + 1, arr + n + 1, cmp);

    int sum = 0, j = 1;
    // 전체 탐색
    for (int i = 1; i <= n; i++) {
        // i번째 전 까지만 탐색하되, 공의 사이즈가 같으면 멈춤
        for (j; j < i && arr[i].size > arr[j].size; j++) {
            // 사이즈의 누적 합과 색깔 별 사이즈 누적 합을 구함
            sum += arr[j].size;
            color[arr[j].color] += arr[j].size;
        }
        re[arr[i].index] = sum - color[arr[i].color];
    }

    for (int i = 1; i <= n; i++)
        cout << re[i] << "\n";
}

/**
실행 결과
4
1 10
3 15
1 3
4 8
-----
8
21
0
3
**/
