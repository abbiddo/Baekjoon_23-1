/**
프로그램명 : 20925.cpp
설명 : 메이플스토리
작성일시 : 2023.02.22
작성자 : abbiddo
**/

#include <iostream>
#include <cstring>
using namespace std;

int dp[1001][200];
int t[200][200];
int c[200], e[200];
int n, m;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	// 경험치 입력을 받으면서 입장에 필요한 경험치가 0인 곳 체크
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> e[i];
		if (c[i] == 0) dp[0][i] = e[i];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> t[i][j];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 경험치가 없다면 continue
			if (!dp[i][j]) continue;

			for (int k = 0; k < n; k++) {
				// 방학 기간을 넘어서면 continue
				if (i + t[j][k] > m) continue;
				// 경험치가 입장에 필요한 최소 경험치보다 적으면 continue
				if (c[k] > dp[i][j]) continue;
				// 이동한거랑 안 한 거 중 어떤게 이득인지 판단
				dp[i + t[j][k]][k] = max(dp[i + t[j][k]][k], dp[i][j]);
			}

			// 1분 후 움직이지 않는 경우 따로 고려
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + e[j]);
		}
	}

	int re = 0;
	for (int i = 0; i < n; i++) re = max(re, dp[m - 1][i]);
	cout << re;
}

/**
실행 결과
2 10
0 10
50 100
0 2
2 0
-----
350
**/
