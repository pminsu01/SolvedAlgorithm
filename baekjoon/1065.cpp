#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>

using namespace std;

int *divide(int number) {

	int *p = new int[3];
	int i = 0;
	while (1) {

		if (number == 0)break;
		p[i] = number % 10;
		//cout << i<<"번쨰 값 : " <<p[i] << endl;
		number = number / 10;
		i++;

	}

	return p;


}

void dn(string str_number) {

	int result = 0;



	if (str_number=="1000") {

		str_number = "999";
	}

	if (str_number.size() == 1 || str_number.size() == 2) {

		result = atoi(str_number.c_str());
	}

	if (str_number.size() == 3) {

		int flag = atoi(str_number.c_str());
		int start_point = 100;

		result = 99;
		while(start_point <= flag) {

			int *q = new int[3];
			q=divide(start_point);


			if (q[0] + q[2] == 2*q[1]) {

				result++;

			}

			start_point++;
		}




	}



	cout << result;






}



int main() {

	string str_number;
	//int result;
	cin >> str_number;

	dn(str_number);

}
