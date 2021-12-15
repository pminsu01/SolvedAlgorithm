/*
코딩테스트 연습 > 동적계획법(Dynamic Programming) > 정수 삼각형

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b) {
    return a>b ? a:b; 
} 

int solution(vector<vector<int>> triangle) {
    
   // int triangle_size = triangle.size();
    int maxvalue[500][500];
    maxvalue[0][0] = triangle[0][0]; 
    if(triangle.size() == 1) {
        return triangle[0][0]; 
    }
    //maxvalue[1][0] = maxvalue[0][0] + triangle[1][0];
    //maxvalue[1][1] = maxvalue[0][0] + triangle[1][1];
    //maxvalue[2][0] = maxvalue[1][0] + triangle[2][0];
    //maxvalue[2][1] = max(maxvalue[1][0], maxvalue[1][1]) + triangle[2][1];
    //maxvalue[2][2] = maxvalue[1][1] + triangle[2][2];
    
    for(int i=1; i<triangle.size();i++) {
         
        maxvalue[i][0] = maxvalue[i-1][0] + triangle[i][0];
        maxvalue[i][i] = maxvalue[i-1][i-1] + triangle[i][i];
        
        for(int j=1; j<  triangle[i].size()-1;j++) {
            maxvalue[i][j] = max(maxvalue[i-1][j], maxvalue[i-1][j-1])  + triangle[i][j]; 
        }
    }
    
    int answer=0;
    vector<int> tempvc;
    for(int k=0; k<triangle.size();k++){
      if(maxvalue[triangle.size()-1][k] >answer){
          answer = maxvalue[triangle.size()-1][k];
      }
    }
    
    
    
    return answer;
}