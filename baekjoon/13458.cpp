/*
시험 감독
*/

#include<stdio.h>
#include<iostream>
#include<cmath>

using namespace std;

long tester[1000001];
long result[1000001]; // 부감독관 명수
int main() {


	int place;
	//int tester;
	int first_command;
	int second_command;
	long answer = 0;


	cin >> place;

	for (int a = 1; a <= place; a++) {


		cin >> tester[a];

	}

	cin >> first_command >> second_command;

	for (int i = 1; i <= place; i++) {

		if (tester[i] - first_command <= 0) {

			result[i]=0;
		}
		else {
			result[i] = ceil((tester[i] - first_command) / double(second_command));
		}

		//printf("result 값은 : %d\n", result[i]);



	}

	for (int j = 1; j <= place; j++) {

		answer += result[j];
	}
	printf("%ld\n", answer + place);






}
