/**
프로그램명 : 2294.cpp
설명 : 동전 2
작성일시 : 2023.02.06
작성자 : abbiddo
**/

#include <iostream>
using namespace std;

int arr[100];
int dp[100001];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		// 입력 받는 값들은 항상 결과가 1
		dp[arr[i]] = 1;
	}

	for (int i = 1; i <= k; i++) {
		// 입력 받은 값들만 dp 값이 1이고 그 값들은 계산해 줄 필요 없음
		if (dp[i] == 1) continue;

		// 초기 값을 0으로 설정, 0으로 두면 아래 min에서 무조건 0으로 계산됨
		dp[i] = 1000000;

		// 입력 받은 값은 규칙이 없기 때문에 입력 받은 값의 배열을 탐색하기 위함
		for (int j = 0; j < n; j++) {
			// 범위를 벗어나면 continue
			if (i - arr[j] < 1) continue;

			// 값이 0이면 해당 숫자에 도달하는 방법이 없으므로 continue
			if (!dp[i - arr[j]]) continue;

			// 현재 값과 이전 값에 + 1더한 값 중 최솟값을 저장
			dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		}

		// 위의 반복문에서 모두 continue로 dp값을 변경하지 못했다면 초기값 0으로 되돌림
		if (dp[i] == 1000000) dp[i] = 0;
	}

	// 값이 있으면 출력, 아니면 -1 출력
	if (dp[k]) cout << dp[k];
	else cout << -1;
}

/**
실행 결과
3 15
1
5
12
-----
3
**/
