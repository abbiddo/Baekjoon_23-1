/**
프로그램명 : 17143.cpp
설명 : 낚시왕
작성일시 : 2023.02.12
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct shark {
	int r, c, s, d, z;
};

int ddr[5] = { 0, -1, 1, 0 ,0 };
int ddc[5] = { 0, 0, 0, 1, -1 };

vector<shark> bada[101][101];
queue<shark> q;

int main() {
	int R, C;	cin >> R >> C;
	int n;	cin >> n;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		int a, b, c, d, e;	cin >> a >> b >> c >> d >> e;
		bada[a][b].push_back({ a,b,c,d,e });
		q.push({ a,b,c,d,e });
	}

	// 낚시왕 이동
	for (int T = 1; T <= C; T++) {
		int dc = -1, dr = -1;
		// 상어 잡기
		for (int i = 1; i <= R; i++) {
			if (bada[i][T].size() > 0) {
				sum += bada[i][T][0].z;
				bada[i][T].clear();
				dc = T;
				dr = i;
				break;
			}
		}

		// 상어 이동
		int qize = q.size();
		for (int i = 0; i < qize; i++) {
			int r = q.front().r;
			int c = q.front().c;
			int s = q.front().s;
			int d = q.front().d;
			int z = q.front().z;
			q.pop();

			// 상어가 잡혔으면 continue
			if (bada[r][c].size() == 0 || (dc == c && dr == r)) continue;

			// 상어 이동 전 자리는 비우기
			bada[r][c].erase(bada[r][c].begin());
			
			int rr = r, cc = c;

			// (R-1)*2만큼 움직이면 제자리에 도착. 즉, 나머지만큼만 움직이면 됨
			if (d == 1 || d == 2) s = s % ((R - 1) * 2);
			else s = s %( (C - 1) * 2);

			// 위에서 구한 나머지만큼 이동 반복
			for (int j = 0; j < s; j++) {
				rr += ddr[d];
				cc += ddc[d];

				// 범위 벗어나면
				if (rr < 1 || rr > R || cc < 1 || cc > C) {
					// 한 칸 되돌리고
					rr -= ddr[d];
					cc -= ddc[d];

					// 방향 바꾸고
					if (d % 2 == 1) d++;
					else d--;

					// 바꾼 방향으로 한 칸 이동
					rr += ddr[d];
					cc += ddc[d];
				}
			}
			bada[rr][cc].push_back({ rr,cc,s,d,z });
		}

		// 상어 정리
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				// 벡터 사이즈가 1이면 바로 큐에 push
				if (bada[i][j].size() == 1) q.push(bada[i][j][0]);
				
				// 벡터 사이즈가 1보다 크면 상어 크기 최댓값 탐색
				else if (bada[i][j].size() > 1) {
					shark maxi = bada[i][j][0];
					int bize = bada[i][j].size();
					for (int k = 1; k < bize; k++)
						if (maxi.z < bada[i][j][k].z) maxi = bada[i][j][k];
					
					// 벡터 비워주고 최댓값 상어만 남기기
					bada[i][j].clear();
					bada[i][j].push_back(maxi);
					q.push(maxi);
				}
			}
		}
	}
	cout << sum;
}

/**
실행 결과
4 6 8
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4
3 3 1 2 7
1 5 8 4 3
3 6 2 1 2
2 2 2 3 5
-----
22
**/
