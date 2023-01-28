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
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> q;
	arr[x][y] = 0;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = cur.first + dx[i];
			int yy = cur.second + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (!arr[xx][yy]) continue;

			arr[xx][yy] = 0;
			q.push(make_pair(xx, yy));
			cnt++;
		}
	}
	if (cnt)	return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	int cnt = 0;
	int max = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
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
