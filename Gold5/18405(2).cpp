/**
프로그램명 : 18405.cpp
설명 : 경쟁적 전염
작성일시 : 2023.01.29
작성자 : 정소영
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, x, y, k;
int board[200][200];
// 상하좌우 탐색을 위함
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	// <바이러스 번호, <행, 열>>
	vector<pair<int, pair<int, int>>> v;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			// 바이러스 번호가 존재한다면 벡터에 push
			if (board[i][j]) v.push_back({ board[i][j], { i, j } });
		}

	cin >> s >> x >> y;
	
	// s = 0일 때는 바로 출력 후 종료
	if (!s) {
		cout << board[x - 1][y - 1];
		return 0;
	}

	sort(v.begin(), v.end());

	for (int t = 0; t < s; t++) {
		// 한 타임에 한 칸만 움직일 수 있으므로 시작 전 벡터의 크기만큼만 반복
		// 벡터에 2개의 원소가 있었다면 2번만 반복, 반복문 안에서 push된 만큼 다음에 반복
		int cnt = v.size();
		for (int j = 0; j < cnt; j++) {
			int curx = v.front().second.first;
			int cury = v.front().second.second;
			int num = v.front().first;

			v.erase(v.begin());

			// 상하좌우 4방향 이동을 위함
			for (int i = 0; i < 4; i++) {
				int xx = curx + dx[i];
				int yy = cury + dy[i];

				// 범위를 벗어나면 continue
				if (xx >= n || xx < 0 || yy >= n || yy < 0) continue;

				// 값이 존재하지 않으면 바이러스가 이동, 벡터에 추가
				if (!board[xx][yy]) {
					board[xx][yy] = num;
					v.push_back({ board[xx][yy], { xx, yy } });
				}

				// 원하는 좌표에 바이러스가 전염됐다면 출력 후 종료
				if (xx == x - 1 && yy == y - 1) {
					cout << board[xx][yy];
					return 0;
				}
			}
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
