/**
프로그램명 : 5014.cpp
설명 : 스타트링크
작성일시 : 2023.01.28
작성자 : 정소영
**/

#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int visit[1000000];

int BFS() {
	// <층 수, cnt>
	queue<pair<int, int>> q;

	// 현재 층 기록
	q.push(make_pair(s, 0));
	visit[s] = 1;

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int cur = q.front().first;
		int count = q.front().second;
		q.pop();

		int up = cur + u;
		int down = cur - d;

		// 위, 아래 층으로 갔을 때 원하는 층이면 리턴
		if (up == g || down == g) return count + 1;

		// 건물의 층을 넘지 않고 방문한 적이 없으면
		if (up <= f && !visit[up]) {
			visit[up] = 1;
			q.push(make_pair(up, count + 1));
		}
		// 1층 이상이고 방문한 적이 없으면
		if (down > 0 && !visit[down]) {
			visit[down] = 1;
			q.push(make_pair(down, count + 1));
		}
	}

	// 큐가 비어버리면 엘리베이터로 갈 수 없으므로 0 리턴
	return 0;
}

int main() {
	cin >> f >> s >> g >> u >> d;

	// 현재 층과 목적지 층이 같다면 바로 종료
	if (s == g) {
		cout << 0;
		return 0;
	}

	int cnt = BFS();
	
	if (cnt) cout << cnt;
	else cout << "use the stairs";
}

/**
실행 결과
100 2 1 1 0
-----
use the stairs
**/
