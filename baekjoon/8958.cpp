/*
OX퀴즈
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

void function() {
	char *input_str = new char[80];

	scanf("%[^\n]", input_str);


	int i = 0;
	int semi_count = 0;
	int count = 0;
	int result_count = 0;

	while (1) {

		if (input_str[i] == NULL) break;
		if (input_str[i] == 'X') {
			count = 0;
			semi_count = 0;
		}

		if (input_str[i] == 'O') {
			count = 1;
			semi_count += count;
			if (input_str[i - 1] == 'O') {

				count = semi_count;
			}
			result_count += count;

		}
		//cout << count << endl;
		i++;

	}

	cout << result_count << endl;
	cin.ignore();





}

int main() {

	int time;
	cin >> time;
	cin.ignore();
	while(1) {

		function();

		if (time == 1) break;
		time--;
	}
		return 0;


}
