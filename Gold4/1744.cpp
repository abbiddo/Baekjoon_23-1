/**
프로그램명 : 1744.cpp
설명 : 수 묶기
작성일시 : 2023.03.04
작성자 : abbiddo
**/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[50];

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j;  cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int re = 0;
    // 양수
    for (i = n - 1; i > 0; i--) {
        if (arr[i - 1] < 0) break;
        // 수 묶기 여부
        if (arr[i] * arr[i - 1] > arr[i] + arr[i - 1]) {
            re += arr[i] * arr[i - 1];
            i--;
        }
        else re += arr[i];
    }

    // 음수
    for (j = 0; j < i; j++) {
        // 수 묶기 여부
        if (arr[j] * arr[j + 1] > arr[j] + arr[j + 1]) {
            re += arr[j] * arr[j + 1];
            j++;
        }
        else re += arr[j];
    }

    if (j == i) re += arr[j];
    cout << re;
}

/**
실행 결과
5
-537
81
-435
257
157
-----
274025
**/
