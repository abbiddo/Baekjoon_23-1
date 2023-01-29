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

	int sum = 0;	// 최종 합
	int point = arr[0];		// 기준 점
	int index = 0;	// 기준 점의 인덱스

	/*
	기준 점보다 높은 줄이 없을 때 취소를 하긴 어려우므로 임시 합을 저장하는 변수
	높은 줄을 찾기 못하면 semi는 sum에 더하지 않음

	check는 semi를 구하고 sum에 더했는지,
	즉, 마지막 줄까지 계산이 되었는지 확인하는 변수
	*/
	int semi = 0;
	int check = 0;

	for (int i = 1; i < n; i++) {
		// 기준 점보다 높거나 같은 줄을 찾으면
		if (point <= arr[i]) {
			// 기준 점과 인덱스를 바꾸고 semi 계산
			point = arr[i];
			index = i;
			sum += semi;
			semi = 0;
			check = 1;
		}
		else {
			semi += (point - arr[i]);
			check = 0;
		}
	}

	/*
	가장 높은 줄이 마지막이 아니어서 계산이 덜 된 경우
	뒤에서부터 같은 방법으로 진행
	*/
	if (!check) {
		// semi 초기화, 기준 점 재설정
		semi = 0;
		point = arr[n - 1];
		for (int i = n - 1; i >= index; i--) {
			if (point <= arr[i]) {
				point = arr[i];
				sum += semi;
				semi = 0;
			}
			else semi += (point - arr[i]);
		}
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
