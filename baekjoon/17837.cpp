/*
백준 17837문제
https://www.acmicpc.net/problem/17837

해당 문제는 vector의 pop_back 쓰는 방법을 배울 수 있엇다.
문제 유형은 시뮬레이션 문제인 것 같다.


*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int Num; //Map의 크기
int k; //말의 갯수
int stateMap[14][14]; // Map의 상태	4<=Num<=12
pair<int, int> locatePoint[11]; // 점의 좌표 위치 (x,y) 4<=k<=10
vector<int> Map[14][14]; // Map에 넣어진 숫자.
queue<pair<int, int>> que; // (Number, Direction)

int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };

void goGame() {

	int term = 0;
	while (term<=1000) {

		vector<int> vc;
		int index = 0; //숫자 Index

		int PointNumber = que.front().first; // 이동할 숫자
		int PointDirection = que.front().second; // 이동할 숫자 방향
		if (PointNumber == 1) term++; //1번차례일 때 1턴이 끝난 것이다.
		que.pop();

		int PointX = locatePoint[PointNumber].first; // 이동할 숫자의 X좌표
		int PointY = locatePoint[PointNumber].second; // 이동할 숫자의 Y좌표

		vc = Map[PointX][PointY]; // Map에 넣어진 숫자 리스트


		//vector의 index 찾기
		for (int i = 0; i < vc.size(); i++) {
			if (vc.at(i) == PointNumber) {
				index = i;
				break;
			}
		}

		int nx = PointX + dx[PointDirection];
		int ny = PointY + dy[PointDirection];
		//cout << "PointX: " << PointX << " , " << "PointY : " << PointY << " PointNumber: " << PointNumber << " , " << "PointDirection : " << PointDirection << endl;

		/*
		1) 움직이는 칸이 흰색이다.
		2) 해당하는 말과 그 위에 있는 순서는 유지된다. (방향도 바꾸지 않는다.)
		*/
		if (stateMap[nx][ny] == 0) {

			if (index == 0) Map[PointX][PointY].clear();
			else Map[PointX][PointY].erase(Map[PointX][PointY].begin() + index, Map[PointX][PointY].end()); //기존 Map에 남아있는 수는 없앤다. erase(n,m) n 번부터 m-1까지 모두 지운다.

			for (int i = index; i <vc.size(); i++) {
				Map[nx][ny].push_back(vc.at(i));	   // 위에 쌓여져 있는 숫자들 push하기
				locatePoint[vc.at(i)] = make_pair(nx, ny); // 올라간 수의 X좌표 Y좌표 변경
			}
		}

		/*
		1) 움직일 칸이 빨간색이다.
		2) 해당하는 말과 그위에 있는 순서를 반대로 바꾼다. (방향은 바꾸지 않는다.)
		*/
		else if (stateMap[nx][ny] == 1) {

			//if (index == 0)	Map[PointX][PointY].clear();
			//else Map[PointX][PointY].erase(Map[PointX][PointY].begin() + index, Map[PointX][PointY].end());  //기존 Map에 남아있는 수는 없앤다. erase(n,m) n 번부터 m-1까지 모두 지운다.

			for (int i = vc.size()-1; i >= index; i--) {
				Map[nx][ny].push_back(vc.at(i));	   // 위에 올라간 숫자들 역순으로 push하기.
				Map[PointX][PointY].pop_back();
				locatePoint[vc.at(i)] = make_pair(nx, ny); // 올라간 수의 X좌표 Y좌표 변경
			}

		}
		/*
		방향 1: 오른쪽, 2:왼쪽, 3: 위, 4:아랫쪽
		0 :  흰색, 1: 빨간색, 2:파란색
		1) 움직인 칸이 파란색이다.
		2) 방향을 바꾼다
		3) 움직인 칸으로 부터 바꾼 방향으로 한칸을 이동한다.
		4) 이동방향을 반대로 하고 한칸 이동한다. 단 이동한 칸이 파란색인 경우 이동하지 않고 방향만 반대로 바꾼다.
		*/
		else if (stateMap[nx][ny] == 2) {

			switch (PointDirection) {
			case 1: {
				PointDirection = 2;
				ny = PointY+ dy[PointDirection]; //해당 로직 때문에 4번 튕겼음. 빨간색일 때는 방향이 바뀐 뒤 그 자리에서 PointDirection에 따라 움직인다.
				if (stateMap[nx][ny] == 2) {
					ny = PointY;
				}
				break;
			}
			case 2: {
				PointDirection = 1;
				ny = PointY+dy[PointDirection];
				//ny = PointY+1;
				if (stateMap[nx][ny] == 2) {
					ny = PointY;
				}
				break;
				}
			case 3: {
				PointDirection = 4;
				nx =PointX+dx[PointDirection];
				if (stateMap[nx][ny] == 2) {
					nx = PointX;
				}
				break;
			}
			case 4: {
				PointDirection = 3;
				nx = PointX+ dx[PointDirection];
				if (stateMap[nx][ny] == 2) {
					nx = PointX;
				}
				break;
			}
			default: break;
			}

			//움직였을 때 stateMap 상태별로 값 Push
			if (stateMap[nx][ny] == 0) {

				if (index == 0) Map[PointX][PointY].clear();
				else Map[PointX][PointY].erase(Map[PointX][PointY].begin() + index, Map[PointX][PointY].end()); //기존 Map에 남아있는 수는 없앤다. erase(n,m) n 번부터 m-1까지 모두 지운다.

				for (int i = index; i < vc.size(); i++) { //위에 쌓여져 있는 숫자들 index ~ size()-1
					Map[nx][ny].push_back(vc.at(i));
					locatePoint[vc.at(i)] = make_pair(nx, ny); // 올라간 수의 X좌표 Y좌표 변경
				}

			}

			else if (stateMap[nx][ny] == 1) {

				for (int i = vc.size()-1; i >= index; i--) {
					Map[nx][ny].push_back(vc.at(i));
					Map[PointX][PointY].pop_back();
					locatePoint[vc.at(i)] = make_pair(nx, ny); // 올라간 수의 X좌표 Y좌표 변경
				}
			}


		}

		if (Map[nx][ny].size() >= 4) {
			cout << term << endl;
			return;
		}
		//cout << "nx: " << nx << " , " << "ny : " << ny << " PointNumber : " << PointNumber << " 바뀐 PointDirection : " << PointDirection << endl<<endl;
		que.push(make_pair(PointNumber, PointDirection));
	}

	cout << -1 <<endl;

}
int main() {

	cin >> Num >> k;

	for (int i = 1; i <= Num; i++) {
		for (int j = 1; j <= Num; j++) {

			int temp;
			cin >> temp;
			stateMap[i][j] = temp;

		}
	}

	//경계선은 모두 Blue로 표시 하기.
	for (int i = 0; i <= Num + 1; i++) {
		stateMap[i][0] = 2;
		stateMap[0][i] = 2;
		stateMap[Num + 1][i] = 2;
		stateMap[i][Num + 1] = 2;
	}


	for (int i = 1; i <= k; i++) {
		int tempX, tempY, tempDirection;
		cin >> tempX >> tempY >> tempDirection;

		locatePoint[i] = make_pair(tempX, tempY);
		Map[tempX][tempY].push_back(i);
		que.push(make_pair(i, tempDirection));
	}


	goGame();
}
