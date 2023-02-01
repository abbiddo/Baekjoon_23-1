/**
프로그램명 : 16973.cpp
설명 : 직사각형 탈출
작성일시 : 2023.02.01
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
using namespace std;

int n, m, h, w, sx, sy, fx, fy;
int board[1001][1001];
// 상하좌우 탐색을 위함
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool check(int x, int y, int i) {
	// 상
	if (i == 0) {
		for (int i = y; i < y + w; i++)
			if (board[x][i] == -1) return 0;
	}
	
	// 우
	else if (i == 1) {
		if (y + w - 1 > m) return 0;
		for (int i = x; i < x + h; i++)
			if (board[i][y + w - 1] == -1) return 0;
	}

	// 하
	else if (i == 2) {
		if (x + h - 1 > n) return 0;
		for (int i = y; i < y + w; i++)
			if (board[x + h - 1][i] == -1) return 0;
	}

	// 좌
	else {
		for (int i = x; i < x + h; i++)
			if (board[i][y] == -1) return 0;
	}

	return 1;
}

int BFS(int x, int y) {
	// <x, y>
	queue<pair<int, int>> q;

	board[x][y] = 1;
	q.push({ x, y });
	
	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = curx + dx[i];
			int yy = cury + dy[i];

			// 도착지에는 확실히 직사각형이 들어갈 수 있으므로 검사 전 반환
			if (xx == fx && yy == fy) return board[curx][cury];

			// 범위를 벗어나거나 방문한 적 있으면 continue
			if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
			if (board[xx][yy]) continue;

			// 직사각형이 차지하는 너비에 벽이 없는지 확인
			if (check(xx, yy, i)) {
				q.push({ xx, yy });
				board[xx][yy] = board[curx][cury] + 1;
			}
		}
	}
	return -1;
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j]) board[i][j] = -1;
		}

	cin >> h >> w >> sx >> sy >> fx >> fy;

	cout << BFS(sx, sy);
}

/**
실행 결과
6 7
0 0 0 0 0 0 0
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0
0 0 0 0 0 0 0
2 3 1 1 5 5
-----
8
**/
