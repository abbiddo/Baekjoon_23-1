/**
프로그램명 : 2573.cpp
설명 : 빙산
작성일시 : 2023.02.01
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int board[300][300];
int visit[300][300];
// 상하좌우 탐색을 위함
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int r, int c) {
	// <r, c>
	queue<pair<int, int>> q;

	visit[r][c] = 1;
	q.push({ r, c });
	
	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curr = q.front().first;
		int curc = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = curr + dx[i];
			int yy = curc + dy[i];

			// 범위를 벗어나거나 방문한 적 있으면 continue
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (visit[xx][yy]) continue;

			// 주위가 바다면 빙산 높이 줄이기
			if (board[xx][yy] == 0)
				board[curr][curc] -= 1;

			// 주위가 빙산이면 큐에 삽입
			else {
				q.push({ xx, yy });
				visit[xx][yy] = 1;
			}

			// 빙산의 높이가 음수라면 0으로 설정
			if (board[curr][curc] < 0) board[curr][curc] = 0;
		}
	}
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int cnt = 0;	// 햇수
	while (1) {
		memset(visit, false, sizeof(visit));
		int bfs = 0;	// 빙산 덩어리 수
		for (int i = 0 ; i < n;i++)
			for (int j = 0; j < m; j++) {
				if (board[i][j] && !visit[i][j]) {
					BFS(i ,j);
					bfs++;
				}
			}

		// 빙산이 두 덩이 이상으로 나눠졌다면 햇수 출력
		if (bfs > 1) {
			cout << cnt;
			return 0;
		}

		// 빙산이 모두 녹았다면 0 출력
		else if (bfs == 0) {
			cout << 0;
			return 0;
		}

		cnt++;
	}
}

/**
실행 결과
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0
-----
2
**/
