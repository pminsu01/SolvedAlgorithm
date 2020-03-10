/*
숫자의 개수
*/
define _CRT_SECURE_NO_WARNINGS


#include<iostream>


using namespace std;

void answer(int number) {


	int array_number[10] = { 0,0,0,0,0,0,0,0,0,0 };





	while (1) {

		int find_number = number % 10;

		int result = 0;

		//그 값이 존재 한다면

		if (array_number[find_number] >= 1) {

			int already_value = array_number[find_number];

			already_value++;

			array_number[find_number] = already_value;

		}
		// 그 값이 존재하지 않는다면

		else if(array_number[find_number]==0) {
			result++;
			array_number[find_number] = result;
		}

		number = number / 10;

		if (number == 0) break;


	}

	for (int i = 0; i < 10; i++) {


		cout << array_number[i] << endl;
	}


}

int main()
{
	int first;
	int second;
	int third;


	cin >> first >> second >> third;

	int result = first * second*third;

	answer(result);



	return 0;



}
	
