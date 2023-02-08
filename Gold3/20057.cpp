/**
프로그램명 : 20057.cpp
설명 : 마법사 상어와 토네이도
작성일시 : 2023.02.08
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 좌
int d1r[9] = { -2, -1, -1, -1, 0, 1, 1, 1, 2 };
int d1c[9] = { 0, -1, 0, 1, -2, -1, 0, 1, 0 };

// 하
int d2r[9] = { 0, 1, 0, -1, 2, 1, 0, -1, 0 };
int d2c[9] = { -2, -1, -1, -1, 0, 1, 1, 1, 2 };

// 우
int d3r[9] = { -2, -1, -1, -1, 0, 1, 1, 1, 2 };
int d3c[9] = { 0, 1, 0, -1, 2, 1, 0, -1, 0 };

// 상
int d4r[9] = { 0, -1, 0, 1, -2, -1, 0, 1, 0 };
int d4c[9] = { -2, -1, -1, -1, 0, 1, 1, 1, 2 };

// 비율
int ratio[9] = { 2, 10, 7, 1, 5, 10, 7, 1, 2 };
int board[500][500];

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, r, c, d = 1, re = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) cin >> board[i][j];

	// 토네이도 시작 값
	r = c = N / 2 + 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < i; k++) {
				// 한 칸 이동
				if (d == 1) c--;
				else if (d == 2) r++;
				else if (d == 3) c++;
				else if (d == 4) r--;

				int sand = board[r][c];		// 해당 칸 모래 저장
				int sum = 0;	// 흩어진 모래의 양 저장
				board[r][c] = 0;	// 토네이도가 도착한 칸은 모래가 사라짐

				// 흩어지는 좌표 확인
				for (int l = 0; l < 9; l++) {
					int rr, cc;
					if (d == 1) {
						rr = r + d1r[l];
						cc = c + d1c[l];
					}
					else if (d == 2) {
						rr = r + d2r[l];
						cc = c + d2c[l];
					}
					else if (d == 3) {
						rr = r + d3r[l];
						cc = c + d3c[l];
					}
					else if (d == 4) {
						rr = r + d4r[l];
						cc = c + d4c[l];
					}

					// 모래 양에 비율 계산
					int rat = sand * ratio[l] / 100;

					// 흩어진 모래양 합산
					sum += rat;

					// 범위를 벗어나면 결과값에 더하기
					if (rr < 1 || rr > N || cc < 1 || cc > N) {
						re += rat;
						continue;
					}

					// 범위를 벗어나지 않으면 해당 칸에 모래를 더하기
					board[rr][cc] += rat;
				}

				// 남은 모래를 a칸에 옮기기 위함
				int rr = r, cc = c;

				if (d == 1) cc = c - 1;
				else if (d == 2) rr = r + 1;
				else if (d == 3) cc = c + 1;
				else if (d == 4) rr = r - 1;

				// 범위 벗어나면 결과 값에 더하기
				if (rr < 1 || rr > N || cc < 1 || cc > N) re += (sand - sum);
				else board[rr][cc] += (sand - sum);

				// 1,1 에 도착하면 종료
				if (r == 1 && c == 1) {
					cout << re;
					return 0;
				}			
			}
			// 방향 전환
			d++;
			if (d > 4) d = 1;
		}
	}
}

/**
실행 결과
9
193 483 223 482 858 274 847 283 748
484 273 585 868 271 444 584 293 858
828 384 382 818 347 858 293 999 727
818 384 727 373 636 141 234 589 991
913 564 555 827 0 999 123 123 123
321 321 321 983 982 981 983 980 990
908 105 270 173 147 148 850 992 113
943 923 982 981 223 131 222 913 562
752 572 719 590 551 179 141 137 731
-----
22961
**/
