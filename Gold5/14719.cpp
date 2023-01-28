/**
프로그램명 : 14719.cpp
설명 : 빗물
작성일시 : 2023.01.27
작성자 : 정소영
**/

#include <iostream>
using namespace std;

int arr[501];
int main() {
	int n;		cin >> n >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int sum = 0;
	
	// 양 끝 줄을 제외한 줄 순회
	for (int i = 1; i < n - 1; i++) {
		int maxl = 0, maxr = 0, max;
		
		// 해당 줄 기준으로 왼쪽의 높이 최댓값
		for (int j = i; j >= 0; j--)
			if (maxl < arr[j]) maxl = arr[j];
		
		// 해당 줄 기준으로 오른쪽의 높이 최댓값
		for (int j = i; j < n; j++)
			if (maxr < arr[j]) maxr = arr[j];

		// 양쪽 최댓값 중 작은 값을 선택
		max = maxr < maxl ? maxr : maxl;

		// max값과 해당 줄의 높이 차를 합산
		sum += (max - arr[i]);
	}
	cout << sum;
}

/**
실행 결과
4 8
3 1 2 3 4 1 1 2
-----
5
**/
