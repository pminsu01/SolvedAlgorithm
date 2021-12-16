/*
코딩테스트 연습 > 동적계획법 > 등교길
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int min(int a, int b) {
    
    return a<b? a:b;
}
int dx[] = {0,1};
int dy[] = {1,0};
int map[101][101] ={0,};
int minroute[101][101] ={100000,};
int solution(int m, int n, vector<vector<int>> puddles) {
    
    for(int i=0; i<puddles.size();i++) {
        int x = puddles[i][0];
        int y = puddles[i][1];
        map[x][y] =1;
    }

    
    minroute[1][0] = 1;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            
            if(map[i][j] == 1) {
              minroute[i][j] =0;
            }
            
            else{ // 그 다음 장소에 갈  경우의 수는 왼쪽, 위쪽칸의 경우의 수  합이다.
            minroute[i][j] = (minroute[i-1][j] +minroute[i][j-1] ) % 1000000007;
            }
        }
    }
    
    
 
    return minroute[m][n];
}