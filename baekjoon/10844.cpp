/*
쉬운 계단 수
*/

#include<iostream>
#include<stdio.h>

using namespace std;

int main() {

	int final_result=0;
	int length_number; // 입력 N의 갯수
	scanf("%d", &length_number);

	long result[101] = { 0 };


	long many_number[101][10] = { 0 };

	many_number[1][0] = 0;

	for (int i = 1; i < 10; i++) {

		many_number[1][i] = 1;

	}



	for (int i = 2; i <= length_number; i++) {


		many_number[i][0] = (many_number[i - 1][1]);
		many_number[i][9] = (many_number[i - 1][8]);

		for (int j = 1; j < 9; j++) {

			many_number[i][j] = ((many_number[i - 1][j - 1] + many_number[i - 1][j + 1])%1000000000);

		}
	}


		for (int k = 0; k <10; k++) {

			int index = ((many_number[length_number][k])%1000000000);
			//printf("%d\n", index);
			final_result += index;
			final_result = final_result % 1000000000;
			//result[length_number] = result[length_number] % 1000000000;

		}




	//printf("%ld\n", result[length_number]);
	printf("%d\n", final_result%1000000000);


}
