/**
프로그램명 : 18405.cpp
설명 : 경쟁적 전염
작성일시 : 2023.01.29
작성자 : 정소영
**/

#include <iostream>
#include <queue>
using namespace std;

int n, s, x, y, k;
int board[200][200];
// 상하좌우 탐색을 위함
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS() {
	// <바이러스 번호, <행, 열>, 오름차순>
	priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			// 바이러스가 존재하면 우선순위 큐에 삽입
			if (board[i][j]) q.push(make_pair(board[i][j], make_pair(i, j)));

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curx = q.top().second.first;
		int cury = q.top().second.second;
		int num = q.top().first;

		q.pop();

		// 상하좌우 4방향 이동을 위함
		for (int i = 0; i < 4; i++) {
			int xx = curx + dx[i];
			int yy = cury + dy[i];

			// 범위를 벗어나면 continue
			if (xx >= n || xx < 0 || yy >= n || yy < 0) continue;

			// 값이 존재하지 않으면 바이러스가 이동
			if (!board[xx][yy]) board[xx][yy] = num;

			// 원하는 좌표에 바이러스가 전염됐다면 바이러스 번호 리턴
			if (xx == x - 1 && yy == y - 1) return board[xx][yy];
		}
	}
	return 0;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> board[i][j];

	cin >> s >> x >> y;

	// s = 0일 때는 바로 출력 후 종료
	if (!s) {
		cout << board[x - 1][y - 1];
		return 0;
	}

	for (int i = 0; i < s; i++) {
		int re = BFS();
		if (re) {
			cout << re;
			return 0;
		}
	}
	cout << 0;
}

/**
실행 결과
3 3
1 0 2
0 0 0
3 0 0
2 3 2
-----
3
**/
