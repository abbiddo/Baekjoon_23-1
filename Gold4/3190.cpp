/**
프로그램명 : 3190.cpp
설명 : 뱀
작성일시 : 2023.02.02
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
using namespace std;

int dummy[101][101]; // 뱀의 위치와 사과를 나타내기 위함 (사과1, 뱀2)
int snakes[101]; // 뱀이 움직이는 시간 저장
char snaked[100]; // 뱀이 움직이는 방향 저장

int main() {
	int n;		cin >> n;

	int a;	cin >> a;
	for (int i = 0; i < a; i++) {
		int x, y;		cin >> x >> y;
		dummy[x][y] = 1;
	}

	int s;		cin >> s;
	for (int i = 0; i < s; i++) 
		cin >> snakes[i] >> snaked[i];

	// 마지막 방향을 회전하고 앞으로 가야하기 때문에 보드 크기만큼 더해서 마지막에 저장
	snakes[s] = snakes[s - 1] + n;

	deque<pair<int, int>> q;
	q.push_back({ 1, 1 });
	dummy[1][1] = 2;

	int sec = 0;
	int d = 1;
	for (int i = 0; i <= s; i++) {
		for (int j = sec; j < snakes[i]; j++) {
			sec++;
			// 가장 나중에 큐에 삽입 된 원소 즉, 뱀의 머리
			pair<int, int> cur = q.back();

			int r, c;

			// 우
			if (d == 1) {
				r = cur.first;
				c = cur.second + 1;

				if (c > n) {
					cout << sec;
					return 0;
				}
			}

			// 하
			else if (d == 2) {
				r = cur.first + 1;
				c = cur.second;

				if (r > n) {
					cout << sec;
					return 0;
				}
			}

			// 좌
			else if (d == 3) {
				r = cur.first;
				c = cur.second - 1;

				if (c < 1) {
					cout << sec;
					return 0;
				}
			}

			// 상
			else if (d == 4) {
				r = cur.first - 1;
				c = cur.second;

				if (r < 1) {
					cout << sec;
					return 0;
				}
			}

			// 뱀이 벽에 부딪히지 않으면 push
			q.push_back({ r, c });

			// 움직인 자리가 사과라면 뱀의 위치만 저장해줌
			if (dummy[r][c] == 1) dummy[r][c] = 2;

			// 움직인 자리에 아무것도 없다면 뱀의 꼬리 한 칸 제거
			else if (dummy[r][c] == 0) {
				dummy[r][c] = 2;
				pair<int, int> tail = q.front();
				dummy[tail.first][tail.second] = 0;
				q.pop_front();
			}

			// 움직인 자리에 뱀이 있다면 (dummy[r][c] == 2) 종료
			else {
				cout << sec;
				return 0;
			}
		}
		
		// 임의로 방향을 시계방향으로 정했기 때문에 우측은 + 1 좌측은 - 1
		if (snaked[i] == 'L') {
			d--;
			if (d < 1) d = 4;
		}
		else {
			d++;
			if (d > 4) d = 1;
		}
	}
}

/**
실행 결과
10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L
-----
13
**/
