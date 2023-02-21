/**
프로그램명 : 2560.cpp
설명 : 짚신벌레
작성일시 : 2023.02.16
작성자 : abbiddo
**/

#include <iostream>
using namespace std;

long long dp[1000001];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, d, N;		cin >> a >> b >> d >> N;

	for (int i = 0; i < a; i++) dp[i] = 1;

	for (int i = a; i <= N; i++) {
		if (i < b) dp[i] = (dp[i - 1] + dp[i - a]) % 1000;
		else dp[i] = (dp[i - 1] + dp[i - a] - dp[i - b] + 1000) % 1000;
	}

	if (N >= d) cout << (dp[N] - dp[N - d] + 1000) % 1000;
	else cout << dp[N];
}


/**
실행 결과
3 5 7 20000
-----
609
**/
