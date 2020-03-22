#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
/*

1) 수의 등장 횟수가 커지는 순으로 정렬할 것

2) 수의 등장 횟수가 똑같으면 수가 커지는 순으로 정렬한다.

20.03.23 solved  설명 덧 붙여서 깃 수정할 것.

*/

/*
HowNum 배열은 101번까지 : 숫자가 100넘기지 않는다고 했으므로 좀더 편하게 하기위해 직관적으로
100개 주소를 가지고 있는 배열에 나온 횟수를 대입했다.

map 배열은 정렬 된 결과의 배열
*/
int HowNum[101] = { 0 };
int map[101][101] = { 0, };


/*
tempvc : 어떤 숫자가 정렬 되었는지 확인하기 위한 vector -> 일일히 나온 수를 다시  for문을 돌리려면 복잡할 것 같아서 해당 방법 이용했다.

vc : <숫자, 숫자가 나온 횟수>의 벡터
r : x
c : y
k : 한 행 또는 한 열을 정렬할 때 차례대로 k k+1, k+2에 정렬된 값을 대입했다.
resultcount : 정렬 된 카웉ㄴ트
*/
vector<int> tempvc;
vector<pair<int, int>> vc;
int r;
int c;
int k;
int resultcount = 0;

// 숫자와 나온 횟수를 구조체로 정의한다.
struct numvalue {

	int number;
	int num;
};


/*
핵심 코드 : 정렬
first : 숫자
second : 숫자가 나온 횟수

1) 숫자가 나온 횟수가 커지는 순으로 정렬한다.
2) 숫자가 나온 횟수가 같았을 떄는 수가 커지는 순으로 정렬
: 즉 모두 오름차순 정렬이라는 것이다.
*/

bool compare(pair<int, int>a, pair<int, int> b) {

 //나온 횟수가 같으면 숫자가 커지는 순으로 정렬
	if (a.second == b.second) {
		return a.first < b.first;
	}

	else {
 	// 나오는 수가 커지는 정렬
		return a.second < b.second;
	}
}
void sort(int x, int y) {


	if (resultcount > 100) {
		return;
	}
	if (map[r][c] == k) {

		return;
	}



	/*
		R 연산일 때 (행의 갯수 >= 열의 갯수, x>=y)
		*/


	if (x >= y) {
		//cout << "r연산" << endl;
		int maxY = 0;

		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {

				/*
				행렬의 수가 0일 때는 그대로  continue
				행렬의 수가 0이 아니고 아직까지 횟수배열이 0인 값 : 한번도 배열에서 정렬하지 않은 수일때는
				tempvc에 대입했다.
				*/
				int temp = map[i][j];
				if (temp == 0) continue;

				if (HowNum[temp] == 0) {
					tempvc.push_back(temp);
				}

				HowNum[temp]++;

			}


			//tempvc 백터 : 정렬이 필요로 하는 숫자
			// HowNum 배열 : 나온 횟수를 넣은 배열
			for (int a = 0; a < tempvc.size(); a++) {
				int tempkey = tempvc.at(a);
				int tempvalue = HowNum[tempkey];
				vc.push_back(make_pair(tempkey, tempvalue));

			}

			sort(vc.begin(), vc.end(), compare);
			int k = 1;

			// r이 니까 행 초기화, c는 열 초기화 시켜준다.
			for (int a = 1; a <= y; a++) {
				map[i][a] = 0;
			}

			for (int a = 0; a < vc.size(); a++) {

				if (a == vc.size() - 1) {

					map[i][k++] = vc.at(a).first;
					if (k > 100) break;
					map[i][k] = vc.at(a).second;

				}

				else {

					map[i][k++] = vc.at(a).first;
					if (k > 100) break;
					map[i][k++] = vc.at(a).second;
					if (k > 100) break;
				}


			}

			//maxY값을 구해서 행 정렬 후 y값 부터 maxy까지는 0으로 대입한다.
			if (maxY < k) {
				maxY = k;
			}


			vc.clear();
			tempvc.clear();

			//나온 횟수(HowNum 배열) 초기화
			for (int i = 1; i <= 100; i++) {

				HowNum[i] = 0;
			}

		}


		resultcount++;
		sort(x, maxY);
	}



	/*
		 c 연산 일 때 (행의 갯수 < 열의 갯수, y<x)
		*/
	else {

		int maxX = 0;
		for (int j = 1; j <= y; j++) {
			for (int i = 1; i <= x; i++) {

				int temp = map[i][j];
				if (temp == 0) continue;
				if (HowNum[temp] == 0) {
					tempvc.push_back(temp);
				}

				HowNum[temp]++;

			}


			for (int a = 0; a < tempvc.size(); a++) {
				int tempkey = tempvc.at(a);
				int tempvalue = HowNum[tempkey];
				vc.push_back(make_pair(tempkey, tempvalue));

			}



			sort(vc.begin(), vc.end(), compare);

			for (int a = 1; a <= x; a++) {
				map[a][j] = 0;
			}
			int k = 1;
			for (int a = 0; a < vc.size(); a++) {

				if (a == vc.size() - 1) {

					map[k++][j] = vc.at(a).first;
					if (k > 100) break;
					map[k][j] = vc.at(a).second;

				}

				else {
					map[k++][j] = vc.at(a).first;
					if (k > 100) break;
					map[k++][j] = vc.at(a).second;
					if (k > 100) break;
				}
			}

			if (maxX < k) {
				maxX = k;
			}

			vc.clear();
			tempvc.clear();

			for (int i = 1; i <= 100; i++) {

				HowNum[i] = 0;
			}

		}



		resultcount++;
		sort(maxX, y);




	}




}
int main() {

	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	sort(3, 3);

	if (resultcount > 100) {
		cout << -1 << endl;
	}
	else {
	cout << resultcount << endl;
	}

}
