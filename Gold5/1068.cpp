/**
프로그램명 : 1068.cpp
설명 : 트리
작성일시 : 2023.03.06
작성자 : abbiddo
**/

#include <iostream>
#include <vector>
using namespace std;

vector <int> v[51];
bool visit[51];
int n, d, root;
int cnt;

void dfs(int index) {
	// 방문한 적이 있으면 return
	if (visit[index]) return;
	// 방문 처리
	visit[index] = 1;

	// 단말 노드거나, 자식 노드가 한 개인데 삭제된 노드라면 카운트
	if (v[index].size() == 0 || (v[index].size() == 1 && v[index][0] == d)) cnt++;

	// 자식 노드 개수만큼 (삭제되지 않은 노드라면) dfs 실행
	for (int i = 0; i < v[index].size(); i++)
		if (v[index][i] != d) dfs(v[index][i]);
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;	cin >> a;
		// -1이 입력되면 루트임을 저장
		if (a == -1) root = i;
		// 그 외의 수가 들어오면 부모와 자식의 관계 저장
		else v[a].push_back(i);
	}

	cin >> d;
	// 루트 노드를 제거하는 경우 예외처리
	if (root == d) {
		cout << 0;
		return 0;
	}

	// 단말 노드 탐색
	dfs(root);
	cout << cnt;
}

/**
실행 결과
5
-1 0 0 1 1
0
-----
0
**/
