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
	for (int i = 0; i < n; i++)cin >> arr[i];

	int sum = 0;
	for (int i = 1; i < n - 1; i++) {
		int maxl = 0, maxr = 0, max;
		for (int j = i; j >= 0; j--) 
			if (maxl < arr[j]) maxl = arr[j];
		for (int j = i; j < n; j++)
			if (maxr < arr[j]) maxr = arr[j];

		max = maxr < maxl ? maxr : maxl;

		sum += (max - arr[i]);
	}

	cout << sum;
}

/**
실행 결과
/**
실행 결과
5 2
1 2 3 4 5
2 3 3 1
3 5 4 1
-----
8
**/
-----
5
10
**/
