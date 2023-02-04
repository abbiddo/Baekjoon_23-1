/**
프로그램명 : 2146.cpp
설명 : 다리 만들기
작성일시 : 2023.02.04
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, mini = 10001;
int board[1000][1000];
bool visit[1000][1000];

// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

// 섬(덩어리)을 구분해주기 위한 BFS
void BFS(int g, int r, int c) {
	// <r, c>
	queue<pair<int, int>> q;

	board[r][c] = g;
	q.push({ r, c });

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curr = q.front().first;
		int curc = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int rr = curr + dr[i];
			int cc = curc + dc[i];			

			// 범위를 벗어나면 continue
			if (rr < 0 || cc < 0 || rr >= n || cc >= n) continue;
			
			// 육지가 아니거나 이미 탐색한 섬이라면 continue
			if (board[rr][cc] != 1) continue;

			board[rr][cc] = g;
			q.push({ rr, cc });
		}
	}
}

// 가장 짧은 다리를 찾기 위한 함수
void search(int r, int c) {
	// <length, <r, c>>
	queue<pair<int, pair<int, int>>> q;

	q.push({ 0, {r, c} });
	visit[r][c] = 1;

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curr = q.front().second.first;
		int curc = q.front().second.second;
		int move = q.front().first;

		q.pop();

		// 이동 횟수가 최솟값 이상이라면 함수 종료
		if (move >= mini) return;

		for (int i = 0; i < 4; i++) {
			int rr = curr + dr[i];
			int cc = curc + dc[i];

			// 범위를 벗어나면 continue
			if (rr < 0 || cc < 0 || rr >= n || cc >= n) continue;
			
			// 방문한 적이 있으면 continue
			if (visit[rr][cc]) continue;
			
			// 파라미터로 받은 섬과 움직이는 곳의 섬이 같은 섬이면 continue
			if (board[rr][cc] == board[r][c]) continue;

			// 본인의 섬 숫자보다 큰 섬에 도착했다면 종료
			if (board[rr][cc] > board[r][c]) {
				// 이동 횟수 (다리 길이)가 앞서 구한 최소값보다 작으면 저장
				if (move < mini) mini = move;
				return;
			}

			q.push({ move + 1, {rr, cc} });
			visit[rr][cc] = 1;
		}
	}
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	// 섬을 구분하기 위함
	int g = 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] == 1) BFS(g++, i, j);

	// 다리 길이의 최솟값을 찾기 위함
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			memset(visit, false, sizeof(visit));
			if (board[i][j]) search(i, j);
		}

	cout << mini;
}

/**
실행 결과
10
1 1 1 0 0 0 0 1 1 1
1 1 1 1 0 0 0 0 1 1
1 0 1 1 0 0 0 0 1 1
0 0 1 1 1 0 0 0 0 1
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
-----
3
**/
