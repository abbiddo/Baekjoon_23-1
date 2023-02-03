/**
프로그램명 : 4179.cpp
설명 : 불!
작성일시 : 2023.02.03
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
using namespace std;

int n, m;
char board[1000][1000];
bool pisit[1000][1000];	// 사람의 방문 체크
bool fisit[1000][1000];	// 불의 방문 체크
// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> pq;	// 사람 큐
queue<pair<int, int>> fq;	// 불 큐

void BFS() {
	int cnt = 0;

	// 큐가 빌 때까지 반복
	while (!pq.empty()) {
		cnt++;

		int fize = fq.size();
		int pize = pq.size();

		for (int i = 0; i < fize; i++) {
			int fr = fq.front().first;
			int fc = fq.front().second;

			fq.pop();

			for (int j = 0; j < 4; j++) {
				int r = fr + dr[j];
				int c = fc + dc[j];

				// 범위를 벗어나면 continue
				if (r < 0 || c < 0 || r >= n || c >= m) continue;
				// 방문한 적이 있으면 continue
				if (fisit[r][c]) continue;
				// 벽이면 continue
				if (board[r][c] == '#') continue;

				fq.push({ r,c });
				fisit[r][c] = 1;
				board[r][c] = '#';
			}
		}

		for (int i = 0; i < pize; i++) {
			int pr = pq.front().first;
			int pc = pq.front().second;

			pq.pop();

			for (int j = 0; j < 4; j++) {
				int r = pr + dr[j];
				int c = pc + dc[j];

				// 범위를 벗어나면 continue
				if (r < 0 || c < 0 || r >= n || c >= m) continue;
				// 방문한 적이 있으면 continue
				if (pisit[r][c]) continue;
				// 벽이면 continue
				if (board[r][c] == '#') continue;

				// 탈출 가능하면 출력 후 종료
				if (board[r][c] == 'o') {
					cout << cnt + 1;
					return;
				}
				pq.push({ r,c });
				pisit[r][c] = 1;
			}
		}
	}
	cout << "IMPOSSIBLE";
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

			// 불 입력 시 불 큐에 추가, 벽과 같이 갈 수 없는 공간으로 취급
			if (board[i][j] == 'F') {
				fq.push({ i, j });
				fisit[i][j] = 1;
				board[i][j] = '#';
			}

			// 사람 입력 시 사람 큐에 추가
			else if (board[i][j] == 'J') {
				pq.push({ i, j });
				pisit[i][j] = 1;
			}

			// 테두리 중 벽이 아니라면 별도 표기로 출구임을 나타냄
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				if (board[i][j] == '.') board[i][j] = 'o';
				else if (board[i][j] == 'J') {
					cout << 1;
					return 0;
				}
			}
		}

	BFS();
}

/**
실행 결과
4 4
####
#JF#
#..#
#..#
-----
3
**/
