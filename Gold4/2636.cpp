/**
프로그램명 : 2636.cpp
설명 : 치즈
작성일시 : 2023.01.30
작성자 : 정소영
**/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, cnt;
int board[100][100];
int visit[100][100];
// 상하좌우 탐색을 위함
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS() {
	int ccnt = 0;
	queue<pair<int, int>> q;

	// (0, 0)은 항상 공기
	q.push({ 0,0 });
	visit[0][0] = 1;
	
	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;

		q.pop();

		// 상하좌우 4방향 이동을 위함
		for (int i = 0; i < 4; i++) {
			int xx = curx + dx[i];
			int yy = cury + dy[i];

			// 범위를 벗어나면 continue
			if (xx >= n || xx < 0 || yy >= m || yy < 0) continue;

			// 방문한 적이 있으면 continue
			if (visit[xx][yy]) continue;

			// 공기면 큐에 push
			if (!board[xx][yy]) {
				q.push({ xx, yy });
				visit[xx][yy] = 1;
			}

			// 치즈면 공기로 바꿔줌, 치즈 count
			else if (board[xx][yy]) {
				board[xx][yy] = 0;
				visit[xx][yy] = 1;
				ccnt++;
			}
		}
	}
	return ccnt;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> board[i][j];

	int cheese, before;
	while (1) {
		// visit 함수를 0으로 초기화하기 위함
		memset(visit, false, sizeof(visit));
		cheese = BFS();
		cnt++;	// 치즈가 모두 녹기까지의 시간 체크를 위함

		// 다 녹아서 0을 반환했다면 출력 후 종료
		if (!cheese) {
			cout << cnt - 1 << "\n" << before;
			break;
		}

		// 이전 치즈 크기를 기억하기 위함
		before = cheese;
	}
}

/**
실행 결과
13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
-----
3
5
**/
