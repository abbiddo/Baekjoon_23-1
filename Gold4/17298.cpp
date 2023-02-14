/**
프로그램명 : 17298.cpp
설명 : 오큰수
작성일시 : 2023.02.13
작성자 : abbiddo
**/

#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int re[1000001];

stack<int> s;

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = n - 1; i >= 0; i--) {
		// 스택에 들어있는 수가 더 작으면 제거
		while (s.size() && arr[i] >= s.top()) s.pop();

		// 스택이 비어있으면 큰 수가 없는 것이므로 -1
		if (s.size() == 0) re[i] = -1;
		// 스택이 차있다면 맨 위에 있는 값이 큰 수 중 가장 오른쪽에 존재
		else re[i] = s.top();

		// 현재 값을 스택에 삽입
		s.push(arr[i]);
	}

	for (int i = 0; i < n; i++) cout << re[i] << " ";
}

/**
실행 결과
4
3 5 2 7
-----
5 7 7 -1
**/
