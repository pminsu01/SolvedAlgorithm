#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main() {

	int term;
	cin >> term;

	while (term--) {

		int a, b;
		long answer=0;

		cin >> a >> b;


		int first[2] = {0,1};
		int second[5] = { 0,2,4,8,6 };
		int thirdth[5] = { 0,3,9,7,1 };
		int fourth[3] = { 0,4,6 };
		int fiveth[2] = { 0,5 };
		int sixth[2] = { 0,6 };
		int seventh[5] = { 0,7,9,3,1 };
		int eigth[5] = { 0,8,4,2,6 };
		int nineth[3] = { 0,9,1 };
		int tenth[2] = { 10,10 };

		if (b == 0) {

			answer = 1;
		}

		else {

		a = a % 10;
		//cout << "a의 값 : " << a << endl;

		switch (a) {

		case 1: {

			answer = first[1]; // 1가지
			break;
		};
		case 2: {

			b = b % 4; //4가지
			answer = second[b];
			if (b == 0) answer = second[4];
			break;
		}
		case 3: {

			b = b % 4; //4가지
			answer = thirdth[b];
			if (b == 0) answer = thirdth[4];
			break;
		}
		case 4: {

			b = b % 2; //2가지
			answer = fourth[b];
			if (b == 0) answer = fourth[2];
			break;
			}
		case 5: {

			answer = fiveth[1]; //1가지
			break;

			}
		case 6: {

			answer = sixth[1]; //1가지
			break;

			}
		case 7: {

			b = b % 4;
			answer = seventh[b]; //4가지
			if (b == 0) answer = seventh[4];
			break;


			}
		case 8: {

			b = b % 4;
			answer = eigth[b]; //4가지
			if (b == 0) answer = eigth[4];
			break;
			}
		case 9: {

			b = b % 2;
			answer = nineth[b]; //2가지
			if (b == 0) answer = nineth[2];
			break;
			}
		case 0: {

			answer = tenth[1];
			break;
			}

			default: break;

		}

		cout << answer << endl;


		}
		/*

		1
		2 4 8 6
		3 9 7 1
		4 6
		5
		6
		7 9 3 1
		8 4 2 6
		9 1
		0 0

		*/



	}
}
