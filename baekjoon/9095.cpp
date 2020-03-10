/*
1, 2, 3 더하기
*/
#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

int answer(int number) {

	int result = 0;
	switch (number) {
	case 1: result = 1; break;
	case 2: result = 2; break;
	case 3: result = 4; break;
	default:
		result = answer(number - 1) + answer(number - 2) + answer(number - 3);

	}

	return result;

}

int main() {

	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {

		int input_number;
		int result_number=0;
		scanf("%d", &input_number);
		result_number = answer(input_number);

		printf("%d\n", result_number);

	}

	return 0;

}
