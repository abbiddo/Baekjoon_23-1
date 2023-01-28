/**
프로그램명 : 1926.cpp
설명 : 그림
작성일시 : 2023.01.27
작성자 : 정소영
**/

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[500][500];
// 상하좌우 탐색을 위한 좌표
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int x, int y) {
	int cnt = 1;	// 그림의 크기를 구하기 위한 변수
	queue<pair<int, int>> q;

	// 처음 방문 구간
	arr[x][y] = 0;
	q.push(make_pair(x, y));

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		// 상하좌우 4번 탐색을 하기 위함
		for (int i = 0; i < 4; i++) {
			int xx = cur.first + dx[i];
			int yy = cur.second + dy[i];

			// 좌표가 범위를 벗어날 경우 continue
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			// 방문한 적이 있으면 continue
			if (!arr[xx][yy]) continue;

			// 방문 표기 후, 큐에 push
			arr[xx][yy] = 0;
			q.push(make_pair(xx, yy));
			cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	int cnt = 0;	// 그림의 개수
	int max = 0;	// 그림의 최대 크기

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			// 배열의 값이 1이면 BFS 실행
			if (arr[i][j]) {
				int a = BFS(i, j);
				if (max < a) max = a;
				cnt++;
			}

	cout << cnt << "\n" << max;
}

/**
실행 결과
6 5
1 1 0 1 1
0 1 1 0 0
0 0 0 0 0
1 0 1 1 1
0 0 1 1 1
0 0 1 1 1
-----
4
9
**/
