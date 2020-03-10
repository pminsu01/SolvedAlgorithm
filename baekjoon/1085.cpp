#include<stdio.h>

using namespace std;

int min(int x, int y) {


	int temp = x < y ? x : y;

	return temp;

}
int main() {

	int x = 0;
	int y = 0;
	int RX = 0;
	int RY = 0;
	int result = 0;

	scanf("%d %d %d %d", &x, &y, &RX, &RY);
	int temp = x;
	int temp1 = y;
	int temp2 = RX - x;
	int temp3 = RY - y;

	result = min(min(temp, temp1), min(temp2, temp3));

	printf("%d\n", result);
}
