/**
프로그램명 : 2206.cpp
설명 : 벽 부수고 이동하기
작성일시 : 2023.02.11
작성자 : abbiddo
**/

#include <iostream>
#include <queue>
using namespace std;

// 상하좌우 탐색을 위함
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int board[1000][1000];
/*
방문 검사 겸 결과 값 저장
visit[r][c][0]에 벽을 뚫고 가지 않은 경로 저장
visit[r][c][1][에 벽을 뚫고 간 경로 저장
*/
int visit[1000][1000][2];
int n, m;

struct wall {
    int r;
    int c;
    int ok; // 벽을 뚫은 적이 있는지 확인
};

int BFS() {
    queue<wall> q;

    q.push({ 0,0,0 });
    // 시작은 벽을 뚫지 않음
    visit[0][0][0] = 1;
    visit[0][0][1] = 0;

    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int ok = q.front().ok;

        q.pop();

        if (r == n - 1 && c == m - 1) {
            /*
            최단 경로를 구해야하고, BFS에서는 먼저 도착한 경로가 최단 경로 이므로
            도착했다면 벽을 뚫든 뚫지 않든 둘 중 하나는 0
            */
            if (visit[r][c][0]) return visit[r][c][0];
            else if (visit[r][c][1]) return visit[r][c][1];
            return -1;
        }

        for (int i = 0; i < 4; i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];

            // 범위를 벗어나면 continue
            if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;

            // 두 경로 모두 방문한 적이 있으면 continue
            if (visit[rr][cc][0] && visit[rr][cc][1]) continue;

            // 벽을 뚫은 적이 있다면
            if (ok == 1) {
                // 다음 칸이 벽이면 또 벽을 뚫을 수 없기에 continue
                if (board[rr][cc]) continue;

                // 다음 칸이 벽이 아니고 어떤 경로든 방문한 적이 없으면
                if (!board[rr][cc] && !visit[rr][cc][1] && !visit[rr][cc][0]) {
                    q.push({ rr, cc, 1 });
                    visit[rr][cc][1] = visit[r][c][1] + 1;
                }
            }

            // 벽으 뚫은 적이 없다면
            else {
                // 다음 칸이 벽이고 벽을 뚫고 방문한 적이 없으면
                if (board[rr][cc] && !visit[rr][cc][1]) {
                    q.push({ rr,cc,1 });
                    visit[rr][cc][1] = visit[r][c][0] + 1;
                }

                // 다음 칸이 벽이 아니고 (벽을 뚫지 않고) 방문한 적이 없으면
                if (!board[rr][cc] && !visit[rr][cc][0]) {
                    q.push({ rr, cc, 0 });
                    visit[rr][cc][0] = visit[r][c][0] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    // 입출력 속도를 단축시키기 위함
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;   cin >> s;
        for (int j = 0; j < m; j++)
            board[i][j] = s[j] - '0';
    }

    cout << BFS();
}

/**
실행 결과
6 4
0100
1110
1000
0000
0111
0000
-----
15
**/
