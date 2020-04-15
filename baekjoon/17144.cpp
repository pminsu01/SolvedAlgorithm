/*
백준 17144문제
https://www.acmicpc.net/problem/17144

이 문제는 단순 시뮬레이션 문제였다.

1) 미세먼지가 퍼지는 것
2) 공기가 정화되는 두가지 경우의 수로 나뉜다.
그리고 정화되는 수는 반시계, 시계방향으로 나누어 해결하였다.


*/



#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int map[51][51] = { 0, };
int tempmap[51][51] = { 0, };
vector<pair<int,int>> vc; //공기 청정기
int mapx, mapy, time;

struct dust {
	int dustx;
	int dusty;
	int dustcount;
};

queue<dust> que;
queue<dust> tempque;
// 위, 아래, 왼쪽, 오른쪽
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

// 반시계, 시계 방향
int ccw[] = {3,0,2,1};
int cw[] = {3,1,2,0};

int upx, upy;
int downx, downy;



void cleanAir(int cleanX, int cleanY, int direction[]) {

	int x = cleanX;
	int y = cleanY+1;

	int tempcleanmap[51][51];

	for (int i = 1; i <= mapx; i++) {
		for (int j = 1; j <= mapy; j++) {
			tempcleanmap[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {

		while (true) {
			int nx = x + dx[direction[i]];
			int ny = y + dy[direction[i]];

			if (nx==cleanX && ny == cleanY + 1) {
				tempcleanmap[nx][ny] = 0; break;
			}
			if (nx < 1 || nx > mapx || ny < 1 || ny > mapy) break; //밖을 나가게 된다면!
			if (nx == cleanX && ny == cleanY) {
				map[nx][ny] = -1;
				break;
			}
			map[nx][ny] = tempcleanmap[x][y];
			x = nx;
			y = ny;
		}

	}

  //공기 청정기부터 나온 공기는 미세먼지가 0이다. 나온 공기는 무조건 오른쪽으로 진행하기 때문에 cleanY+1 항목에 저장한다.
  map[cleanX][cleanY + 1] = 0;

}




void bfs() {

	for (int i = 1; i <= mapx; i++) {
		for (int j = 1; j <= mapy; j++) {
			tempmap[i][j] = 0;
		}
	}

	while (!que.empty()) {

		int tempdustX = que.front().dustx;
		int tempdustY = que.front().dusty;
		int tempdustCount = que.front().dustcount;
		int count = 0;
		int spreadDust = 0;
		for (int i = 0; i < 4; i++) {

			int	nx = tempdustX + dx[i];
			int	ny = tempdustY + dy[i];

			if (map[nx][ny] == -1) {
				tempmap[nx][ny] = -1;
				continue;
			}

			if ((nx<1) || (nx>mapx) || (ny<1) ||(ny>mapy)) {
				continue;
			}

			spreadDust = (tempdustCount / 5);
			tempmap[nx][ny] += spreadDust;
			count++;


		}

		que.pop();
		tempmap[tempdustX][tempdustY] += tempdustCount - (spreadDust)*count;

	}


	//다시 원래 맵에 저장 한다.
	for (int i = 1; i <= mapx; i++) {
		for (int j = 1; j <= mapy; j++) {
			map[i][j] = tempmap[i][j];
		}
	}
	map[upx][upy] = -1;
	map[downx][downy] = -1;

}



int main() {


	cin >> mapx >> mapy >> time;
	int answer = 0;

	for (int i = 1; i <= mapx; i++) {
		for (int j = 1; j <= mapy; j++) {

			int temp;
			cin >> temp;
			map[i][j] = temp;
			if (temp == -1) {
				vc.push_back(make_pair(i,j)); // 공기청정기의 위치
			}
			if (temp != 0 && temp !=-1) {
				que.push({ i,j,temp }); //미세먼지 위치 알기.
			}
		}
	}

	upx = vc.at(0).first;
	upy = vc.at(0).second;
	downx = vc.at(1).first;
	downy = vc.at(1).second;




	while (time--) {
		bfs();
		cleanAir(upx, upy, ccw);
		cleanAir(downx, downy, cw);
    //공기 청정기 가동 후 미세먼지가 다시 퍼져야 하므로 queue에 저장.
		for (int i = 1; i <= mapx; i++) {
			for (int j = 1; j <= mapy; j++) {
				if (map[i][j] != -1 && map[i][j] != 0) {
					que.push({ i,j,map[i][j] });
				}
			}
		}
	}

	for (int i = 1; i <= mapx; i++) {
		for (int j = 1; j <= mapy; j++) {
			if (map[i][j] != -1) {
				answer += map[i][j];
			}
		}
	}

	cout << answer << endl;

}
