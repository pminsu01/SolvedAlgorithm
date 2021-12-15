#include<iostream>

using namespace std;
int min(int a, int b) {

	return a < b ? a : b;
}

int main() {

	int Num;
	cin >> Num;

	int Numarray[1000001];

	Numarray[1] = 0;
	Numarray[2] = 1; // 2/2 , 2-1
	Numarray[3] = 1; // 3/3
	/*
	Numarray[4] = 2; // 4/2, 2/2
	Numarray[5] = 3;// 5-1 = 4,
	Numarray[6] = 2;// 6/3, 2/2
	Numarray[7] = 3; //7-1, 6(2)
	Numarray[8] = 3; // 8/2, 4(2) : 3
	Numarray[9] = 2; // 9/3, 3(1) :2
	Numarray[10] = 3; // 10/2, 5(4), : 4 |  10-1 =9
	*/

	for (int i = 4; i <= Num; i++) {

		// 초기화
		int temp1 = 100001;
		int temp2 = 100001;
		int temp3 = 100001;

		if (i % 3 == 0) {
			temp1 = Numarray[i / 3] + 1;
		}

		if (i % 2 == 0) {
			temp2 = Numarray[i / 2] + 1;
		}


		temp3 = Numarray[i - 1] + 1;
		//cout << i << endl;


		Numarray[i] = min(min(temp1, temp2), temp3);

	}

	cout << Numarray[Num] << endl;
}
