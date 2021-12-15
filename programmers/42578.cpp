/*
코딩테스트 연습 > 해시 > 위장 > 42578
*/

#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool compare(vector<string> svc, vector<string> svc2){
    
    return svc[1] > svc2[1];
    
}
int solution(vector<vector<string>> clothes) {
    
    int answer=0;
    int numclothes[31] ={0,};
    int Numclothes=0;
    
    string tempclothes ="";
    sort(clothes.begin(),clothes.end(),compare);
   
    for(int j=0; j<clothes.size();j++){     
        cout<<clothes[j][0] <<" , "<<clothes[j][1]<<endl;
    }

    
    for(int i=0; i<clothes.size();i++) {
        
        string detailclothes = clothes[i][0];
        string kindclothes = clothes[i][1];
       
        if(kindclothes != tempclothes) {
            tempclothes = kindclothes;  
            Numclothes++;
        }
        numclothes[Numclothes]++;        
    }
    
    
    int kind =0;
    long long multisum=1;
     cout<<"Num :" <<Numclothes<<endl;
    if(Numclothes == 1) {
        answer = numclothes[1];
        return answer;
    }
    
    for(int i=1; i<=Numclothes; i++) {
        cout<<numclothes[i] << endl;
        if(numclothes[i] ==0) continue;
        multisum *= (numclothes[i]+1);
        //cout<<multisum<<endl;
    }
    
    
    return multisum-1; //아무것도 안입었을 경우의 수 -1
}