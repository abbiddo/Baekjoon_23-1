/**
프로그램명 : 16234.cpp
설명 : 인구 이동
작성일시 : 2023.01.31
작성자 : 정소영
**/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, l, r;
int board[50][50];
int visit[50][50];
// 상하좌우 탐색을 위함
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> save; // 인접한 국가를 기록하기 위한 큐

	q.push({ x, y });
	visit[x][y] = 1;
	int sum = board[x][y];
	int cnt = 1;

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;

		q.pop();
		save.push({ curx, cury });

		// 상하좌우 4방향 탐색을 위함
		for (int i = 0; i < 4; i++) {
			int xx = curx + dx[i];
			int yy = cury + dy[i];

			// 범위를 벗어나면 continue
			if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
			
			// 방문한 적이 있으면 continue
			if (visit[xx][yy]) continue;

			// 인접한 두 국가의 인원수 차이
			int gap = abs(board[curx][cury] - board[xx][yy]);
			
			// 인원수 차이가 범위에 적합하다면
			if (gap <= r && gap >= l) {
				q.push({ xx, yy });
				visit[xx][yy] = 1;
				cnt++;
				sum += board[xx][yy];
			}
		}
	}

	// cnt가 1이면 국경선이 열리지 않으므로 0 return
	if (cnt == 1) return 0;

	// 인접한 국가들의 인원 수를 변경하기 위함
	while (!save.empty()) {
		int people = sum / cnt;
		int curx = save.front().first;
		int cury = save.front().second;

		save.pop();

		board[curx][cury] = people;
	}

	return cnt;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> board[i][j];

	int cnt = 0;

	while (1) {
		int a = -1;
		int k = 0;

		// visit 함수를 0으로 초기화하기 위함
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				// 국경선이 열렸는지 판단하기 위함
				if (!visit[i][j]) a = BFS(i, j);
				if (!a) k++;
			}

		// 모든 국경선이 열리지 않았다면 break;
		if (k == n * n) break;
		cnt++;
	}

	cout << cnt;
}

/**
실행 결과
4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10
-----
3
**/
