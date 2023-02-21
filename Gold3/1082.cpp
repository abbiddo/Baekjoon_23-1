/**
프로그램명 : 1082.cpp
설명 : 방 번호
작성일시 : 2023.02.18
작성자 : abbiddo
**/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[50];
pair<int, int> num[10];
pair<int, int> numnum[10];
int n, m;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	if (a.first > b.first) return false;
	return a.second > b.second;
}

int main() {
	// 입출력 속도를 단축시키기 위함
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill_n(arr, 50, -1);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int money; cin >> money;
		num[i] = { money, i };
		numnum[i] = { money, i };
	}
	cin >> m;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	sort(num, num + n, cmp);

	int k = m / num[0].first;
	int nam = m % num[0].first;

	fill_n(arr, k, num[0].second);

	for (int i = 0; i < k; i++) {
		for (int j = n - 1; j > 0; j--) {
			int gap = numnum[j].first - num[0].first;
			if (gap <= nam) {
				arr[i] = numnum[j].second;
				nam -= gap;
				break;
			}
		}
		if (nam == 0) break;
	}

	// 0인 경우
	if (arr[0] == 0) {
		for (int j = n - 1; j > 0; j--) {
			int gap = numnum[j].first - num[0].first;
			if ((gap <= nam) && numnum[j].second != 0) {
				arr[0] = numnum[j].second;
				nam -= gap;
				break;
			}
		}

		if (arr[0] == 0 && k == 1) {
			cout << 0;
			return 0;
		}

		if (arr[0] == 0 && k != 1) {
			int kk = k;
			for (int i = 0; i < kk; i++) {
				k -= 1;
				nam += num[0].first;

				for (int j = n - 1; j > 0; j--) {
					int gap = numnum[j].first - num[0].first;
					if (gap <= nam && numnum[j].second != 0) {
						arr[0] = numnum[j].second;
						nam -= gap;
						break;
					}
				}

				if (arr[0] != 0) break;
			}
		}
		if (arr[0] == 0) {
			cout << 0;
			return 0;
		}

		if (arr[0] != 0 && k != 1) {
			for (int i = 1; i < k; i++) {
				for (int j = n - 1; j > 0; j--) {
					int gap = numnum[j].first - num[0].first;
					if (gap <= nam) {
						arr[i] = numnum[j].second;
						nam -= gap;
						break;
					}
				}
				if (nam == 0) break;
			}
		}
	}

	if (k == 0) {
		cout << 0;
		return 0;
	}
	sort(arr, arr + k);
	for (int i = k - 1; i >= 0; i--) cout << arr[i];
}

/**
실행 결과
3
5 23 24
30
-----
20
**/
