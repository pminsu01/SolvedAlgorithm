/*
코딩테스트 연습 > 해시 > 전화번호목록 > 42577
*/
#include <string>
#include <vector>
#include<algorithm>


using namespace std;

bool solution(vector<string> phone_book) {

	sort(phone_book.begin(),phone_book.end());
	for (int i = 0; i < phone_book.size(); i++) {
		for (int j = i; j < phone_book.size(); j++) {
            
            if(i == j) continue;
			int size = phone_book[i].size();
			string splitstr = phone_book[j].substr(0,size);

			if (phone_book[i] == splitstr) {
				
				return false;
			}
		}
	}
	return true;
}