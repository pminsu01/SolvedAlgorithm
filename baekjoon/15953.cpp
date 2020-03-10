/*
상금 헌터
*/
#include<stdio.h>
using namespace std;

// 본선 진출을 못했거나, 상 받을 수 있는 순위를 넘어 갔을 때는 0원 (조건)
int SevenPeople[6] = { 1,2,3,4,5,6 };
int SevenAward[6] = { 500,300,200,50,30,10 };

int EightPeople[5] = {1,2,4,8,16 };
int EightAward = 512;

int Reward(int Num,int Rank) {

	int count = 0;
	int result = 0;

	if (Rank == 0) {

		return result;
	}
	if (Num == 7) {

		for (int i = 0; i < 6; i++) {

			count += SevenPeople[i];
			if (count >= Rank) {
				result = SevenAward[i];
				//printf("7th Rank : %d, 7th reward : %d\n", i, result);
				break;
			}

		}

	}

	else {
		for (int i = 0; i <5; i++) {


			count += EightPeople[i];
			if (count >= Rank) {

				result = EightAward/EightPeople[i];

				//printf("Eight people th %d\n", EightPeople[i]);
				//printf("8th Rank : %d, 8th reward : %d\n", i, result);
				break;
			}

		}

	}

	return result;

}
int main() {


	int money = 10000;

	int term = 0;

	scanf("%d", &term);

	while (term--) {

		int Seventh, Eighth;
		int SevenReAward = 0;
		int EightReAward = 0;
		scanf("%d %d", &Seventh, &Eighth);

		SevenReAward = Reward(7, Seventh);
		EightReAward = Reward(8, Eighth);

		printf("%d\n",(SevenReAward + EightReAward)*money);






	}
}
