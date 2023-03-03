/**
프로그램명 : 2470.cpp
설명 : 두 용액
작성일시 : 2023.03.02
작성자 : abbiddo
**/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;  cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int gap = 2000000000, s = arr[0], m = arr[n - 1], l = 0, r = n - 1;

    while (l < r) {
        // 두 용액의 합
        int sum = arr[l] + arr[r];

        // 0과 더 가깝다면 업데이트
        if (gap > abs(sum)) {
            gap = abs(sum);
            s = arr[l]; m = arr[r];
        }

        // 두 용액의 합이 0이면 멈춤
        if (sum == 0) break;
        // 두 용액의 합이 음수면 더 큰 용액들을 더함
        else if (sum < 0) l++;
        // 두 용액의 합이 양수면 더 작은 용액들을 더함
        else r--;
    }

    cout << s << " " << m;
}

/**
실행 결과
4
999999995 999999996 999999997 1000000000
-----
999999995 999999996
**/
