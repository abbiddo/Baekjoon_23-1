/**
프로그램명 : 12764.cpp
설명 : 싸지방에 간 준하
작성일시 : 2023.02.15
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
using namespace std;

// 오름차순 우선순위 큐
priority_queue<pair<int, int>, vector <pair<int, int>>, greater<pair<int,int >>> pq;
int arr[100000][2];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, sum = 0;	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		pq.push({ a, b });
	}

	for (int i = 0; i < n; i++) {
		int start = pq.top().first;
		int end = pq.top().second;
		pq.pop();

		int j = 0;

		// 비어있는 컴퓨터를 찾음 
		// [j][0]이 0이거나 값이 있어도 해당 사람의 시작 시간보다 작을 때 멈춤
		while (arr[j][0] && arr[j][0] > start) j++;

		arr[j][0] = end;
		arr[j][1]++;
	}

	// 사용한 컴퓨터 개수
	int k = 0;
	for (k; k < 100000; k++) 
		if (arr[k][1] == 0) break;

	cout << k << "\n";
	for (int i = 0; i < k; i++) cout << arr[i][1] << " ";
}

/**
실행 결과
5
20 50
10 100
30 120
60 110
80 90
-----
4
1 2 1 1
**/
