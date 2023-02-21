/**
프로그램명 : 17498.cpp
설명 : 폴짝 게임
작성일시 : 2023.02.20
작성자 : abbiddo
**/

#include <iostream>
#include <limits>
using namespace std;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, d;	cin >> n >> m >> d;

	// 2차원 배열 동적 할당
	int** arr = new int* [n];
	int** dp = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		dp[i] = new int[m];
	}

	// 배열 초기화
	fill(dp[0], dp[0] + m, 0);
	for (int i = 1; i < n; i++) fill(dp[i], dp[i] + m, numeric_limits<int>::min());

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	// 지나온 길로부터 폴짝
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; k <= d; k++) {
				for (int l = 1; l <= k; l++) {
					int r = i - l;
					int c1 = j - (k - l);
					int c2 = j + (k - l);

					if (r < 0) continue;

					if (c1 >= 0) dp[i][j] = max(dp[i][j], dp[r][c1] + arr[r][c1] * arr[i][j]);
					if (c2 < m) dp[i][j] = max(dp[i][j], dp[r][c2] + arr[r][c2] * arr[i][j]);
				}
			}
		}
	}

	// 마지막 줄 중 최댓값
	int re = numeric_limits<int>::min();
	for (int i = 0; i < m; i++)
		re = max(re, dp[n - 1][i]);

	cout << re;
}

/**
실행 결과
2 2 2
100 100
-100 -100
-----
-10000
**/
