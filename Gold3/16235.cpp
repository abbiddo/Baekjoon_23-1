/**
프로그램명 : 16235.cpp
설명 : 나무 재테크
작성일시 : 2023.02.06
작성자 : abbiddo
**/

#include <iostream>
#include <algorithm>
using namespace std;

int k, n, m;
int tree[10][10][2002];	// 나무
/*tree의 첫번째 칸은 나무의 개수를 저장하는데 사용
tree의 마지막 칸은 봄에 죽은 나무의 인덱스를 저장하는데 사용*/
int arr[10][10];	// 매년 증가하는 양분 수
int bab[10][10];	// 현재 양분 수

// 가을에 번식을 위함
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			bab[i][j] = 5;
		}

	for (int i = 0; i < m; i++) {
		int r, c, a;	cin >> r >> c >> a;
		tree[r - 1][c - 1][0] = 1;
		tree[r - 1][c - 1][1] = a;
	}

	for (int i = 0; i < k; i++) {
		// 봄
		for (int r = 0; r < n; r++)
			for (int c = 0; c < n; c++)
				if (tree[r][c][0]) {
					// 나이 어린 순으로 양분을 섭취하기 때문에 정렬
					if (tree[r][c][0] > 1)	sort(tree[r][c] + 1, tree[r][c] + tree[r][c][0] + 1);
					tree[r][c][2001] = 1;	// 죽은 나무의 위치를 파악하기 위함

					// 해당 칸에 있는 모든 나무를 검사
					for (int j = 1; j <= tree[r][c][0]; j++) {
						if (bab[r][c] >= tree[r][c][j]) {
							bab[r][c] -= tree[r][c][j];
							tree[r][c][j]++;
							tree[r][c][2001] = j + 1;
						}
						else break;
					}
				}

		// 여름
		for (int r = 0; r < n; r++)
			for (int c = 0; c < n; c++)
				if (tree[r][c][0]) {
					int cnt = tree[r][c][0];

					// 해당 칸의 죽은 나무들 처리
					for (int j = tree[r][c][2001]; j <= cnt; j++) {
						bab[r][c] += tree[r][c][j] / 2;
						tree[r][c][0]--;
					}
				}

		// 가을
		for (int r = 0; r < n; r++)
			for (int c = 0; c < n; c++)
				if (tree[r][c][0]) {

					// 해당 칸의 모든 나무들 탐색
					for (int j = 1; j <= tree[r][c][0]; j++) {
						if (tree[r][c][j] % 5 == 0) {

							// 8방향 탐색
							for (int l = 0; l < 8; l++) {
								int rr = r + dr[l];
								int cc = c + dc[l];

								// 범위를 벗어 나면 continue
								if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;

								tree[rr][cc][0]++;
								tree[rr][cc][tree[rr][cc][0]] = 1;
							}
						}
					}
				}

		// 겨울
		for (int r = 0; r < n; r++)
			for (int c = 0; c < n; c++)
				bab[r][c] += arr[r][c];
	}

	// tree의 [r][c][0]의 합으로 나무의 개수를 구할 수 있음
	int re = 0;
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			re += tree[r][c][0];

	cout << re;
}

/**
실행 결과
10 1 1000
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
1 1 1
-----
5443
**/
