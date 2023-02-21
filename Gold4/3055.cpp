/**
프로그램명 : 3055.cpp
설명 : 탈출
작성일시 : 2023.02.21
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
using namespace std;

int n, m;
char board[50][50];
bool gisit[50][50];	// 고슴도치의 방문 체크
bool wisit[50][50];	// 물의 방문 체크

// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> gq;	// 고슴도치 큐
queue<pair<int, int>> wq;	// 물 큐

void BFS() {
	int cnt = 0;

	// 큐가 빌 때까지 반복
	while (!gq.empty()) {
		cnt++;

		int wize = wq.size();
		int gize = gq.size();

		for (int i = 0; i < wize; i++) {
			int wr = wq.front().first;
			int wc = wq.front().second;

			wq.pop();

			for (int j = 0; j < 4; j++) {
				int r = wr + dr[j];
				int c = wc + dc[j];

				// 범위를 벗어나면 continue
				if (r < 0 || c < 0 || r >= n || c >= m) continue;
				// 방문한 적이 있으면 continue
				if (wisit[r][c]) continue;
				// 돌이면 continue
				if (board[r][c] == '#') continue;
				// 비버 굴이면 continue
				if (board[r][c] == 'o') continue;

				wq.push({ r,c });
				wisit[r][c] = 1;
				board[r][c] = '#';
			}
		}

		for (int i = 0; i < gize; i++) {
			int gr = gq.front().first;
			int gc = gq.front().second;

			gq.pop();

			for (int j = 0; j < 4; j++) {
				int r = gr + dr[j];
				int c = gc + dc[j];

				// 범위를 벗어나면 continue
				if (r < 0 || c < 0 || r >= n || c >= m) continue;
				// 방문한 적이 있으면 continue
				if (gisit[r][c]) continue;
				// 돌이면 continue
				if (board[r][c] == '#') continue;

				// 도착하면 출력 후 종료
				if (board[r][c] == 'o') {
					cout << cnt;
					return;
				}
				gq.push({ r,c });
				gisit[r][c] = 1;
			}
		}
	}
	cout << "KAKTUS";
	return;
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];

			// 물 입력 시 물 큐에 추가, 돌과 같이 갈 수 없는 공간으로 취급
			if (board[i][j] == '*') {
				wq.push({ i, j });
				wisit[i][j] = 1;
				board[i][j] = '#';
			}

			// 고슴도치 입력 시 고슴도치 큐에 추가
			else if (board[i][j] == 'S') {
				gq.push({ i, j });
				gisit[i][j] = 1;
				board[i][j] = '.';
			}

			// 돌
			else if (board[i][j] == 'X') board[i][j] = '#';

			// 비버 굴
			else if (board[i][j] == 'D') board[i][j] = 'o';
		}

	BFS();
}

/**
실행 결과
3 3
D.*
...
.S.
-----
3
**/
