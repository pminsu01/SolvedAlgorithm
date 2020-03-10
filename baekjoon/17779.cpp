/*
게리맨더링 2
*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;



vector<int> vc;

struct inputArray {
	int value;
	int count;
};
struct inputArray map[21][21];
int num = 0;

int findMaxValue(int a, int b, int c, int d,int e) {

	int max = 0;
	max = (a > b) ? a : b;
	max = (max > c) ? max : c;
	max = (max > d) ? max : d;
	max = (max > e) ? max : e;
	return max;

}

int findMinValue(int a, int b, int c, int d, int e) {

	int min = 0;
	min = (a < b) ? a : b;
	min = (min < c) ? min : c;
	min = (min < d) ? min : d;
	min = (min < e) ? min : e;
	return min;
}
int find_an(int x, int y, int d1, int d2) {

	/*
	1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
	2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
	3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
	4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
	*/

	// x+y < x_value+y_value; : 1번 선거구
	// x+y > x_value+y_value+2d2; : 4번 선거구
	// x-y > (x_value-y_value) +2d1 : 3번 선거구
	// x-y < (x_value-y_value) : 2번 선거구

	int firstTemp = x + y;
	int fourTemp = x + y + (2 *d2);
	int thirdTemp = x - y + (2 * d1);
	int secondTemp = x - y;

	//cout << firstTemp << "," << secondTemp << "," << thirdTemp << "," << fourTemp << endl;




	for (int i = 1; i <=num; i++) {
		for (int j = 1; j <=num; j++) {

			map[i][j].count = 5;
			}
		}



	//1번 선거구:  1 ≤ r < x + d1, 1 ≤ c ≤ y
	for (int i = 1; i < (x + d1); i++) {
		for (int j = 1; j <= y; j++) {
			if ((i + j) < firstTemp) {
				map[i][j].count = 1;
			}
		}
	}
	// 2번 선거구: 1 ≤ r ≤ x + d2, y < c ≤ N
	for (int i = 1; i <= x + d2; i++) {
		for (int j = y+1; j <= num; j++) {
			if ((i - j) < secondTemp) {
				map[i][j].count = 2;;
			}
		}
	}
	//3번 선거구 x + d1 ≤ r ≤ N, 1 ≤ c < y - d1 + d2
	for (int i = (x + d1); i<=num; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {
			if ((i - j) > thirdTemp) {
				map[i][j].count=3;
			}
		}
	}
	//4번 선거구   x + d2 < r ≤ N, y - d1 + d2 ≤ c ≤ N
	for (int i = x + d2+1; i <= num; i++) {
		for (int j = (y - d1 + d2); j<=num; j++) {
			if (i + j > fourTemp) {
				map[i][j].count = 4;
			}

		}
	}

	int firstValue = 0;
	int secondValue = 0;
	int thirdValue = 0;
	int fourthValue = 0;
	int fivethValue = 0;

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			switch (map[i][j].count)
			{
			case 1: firstValue += map[i][j].value; break;
			case 2: secondValue += map[i][j].value; break;
			case 3: thirdValue += map[i][j].value; break;
			case 4: fourthValue += map[i][j].value; break;
			case 5: fivethValue += map[i][j].value; break;
			default:break;

			}
		}
	}

	int max = findMaxValue(firstValue, secondValue, thirdValue, fourthValue, fivethValue);
	int min = findMinValue(firstValue, secondValue, thirdValue, fourthValue, fivethValue);

	int gap = max - min;
	//cout << firstValue << "," << secondValue << "," << thirdValue << "," << fourthValue << "," << fivethValue << ": " << gap << endl << endl;

	return gap;


}



void findSelect() {

	for (int x = 1; x < (num - 1); x++) {
		for (int y = 2; y < num; y++) {
			//여기서 d1 <= y-1. d2<=num-y;
			for (int d1 = 1; d1 <= (y - 1); d1++) {
				for (int d2 = 1; d2 <= num - y; d2++) {
					if (d1 + d2 > (num - x)) continue;
					//cout << "x: " << x << "," << "y: "<<y << ", d1: " << d1 << ", d2: " << d2 << "일 때 : " << endl;
					int temp = find_an(x, y, d1, d2);
					vc.push_back(temp);

				}
			}
		}
	}

}

int main() {

	cin >> num;

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {

			int temp;
			cin >> temp;
			map[i][j].value = temp;
			map[i][j].count = 5;
		}
	}
	findSelect();
	int min = *min_element(vc.begin(), vc.end());


	cout << min << endl;
}
