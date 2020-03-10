#include<stdio.h>
#include<algorithm>

using namespace std;
bool desc(int a, int b) {

	return a > b;
}

bool incre(int a, int b) {

	return a < b;
}
int main() {

	int Num = 0;
	scanf("%d", &Num);

	int Aarray[50];
	int Barray[50];

	int Number = 2;
	int count = 0;


		for (int i = 0; i < Num; i++) {

			int temp = 0;
			scanf("%d", &temp);
			Aarray[i] = temp;

		}

		for (int i = 0; i < Num; i++) {

			int temp = 0;
			scanf("%d", &temp);
			Barray[i] = temp;

		}





	sort(Aarray, Aarray + Num,desc );
	sort(Barray, Barray + Num, incre);

	for (int i = 0; i < Num; i++) {

		//printf("%d %d\n", Aarray[i], Barray[i]);
		int temp = Aarray[i] * Barray[i];
		count += temp;
	}
	//A는 내림차순 정리로 하고
	//B는 오름차순 정리로 하고
	//곱하면 제일 작은수



	printf("%d\n", count);

}
