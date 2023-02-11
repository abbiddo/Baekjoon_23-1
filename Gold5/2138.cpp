/**
프로그램명 : 2138.cpp
설명 : 전구와 스위치
작성일시 : 2023.02.10
작성자 : abbiddo
**/

#include <iostream>
using namespace std;

int n, re = 1000000;
string Q, A;

void solve(int zero) {
	string input = Q;
	int cnt = 0;

	// 첫 번째 스위치 작동 여부
	if (zero) {
		input[0] = input[0] == '1' ? '0' : '1';
		input[1] = input[1] == '1' ? '0' : '1';
		cnt++;
	}

	for (int i = 1; i < n; i++) {
		// 바로 이전 전구가 다르다면 스위치 작동
		if (input[i - 1] != A[i - 1]) {
			for (int j = i-1; j <= i + 1 && j < n; j++)
				input[j] = input[j] == '1' ? '0' : '1';
			cnt++;
		}
	}
	
	if (input == A) re = min(re, cnt);
}

int main() {
	cin >> n >> Q >> A;
	solve(0);
	solve(1);
	if (re == 1000000) cout << -1;
	else cout << re;
}

/**
실행 결과
7
1101000
1111111
-----
3
**/
