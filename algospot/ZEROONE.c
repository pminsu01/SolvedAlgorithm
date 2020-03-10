#include<stdio.h>
#define MAX 1000000

  int main() {

    char num[MAX];
    int count[1000000];//초기화
    int method_num = 0;
    int first = 0;
    int last  = 0;


    int cnt = 0;	// 증가한 값의 변수 설정 1000000


    scanf("%s", num);								//배열 받는다.
    scanf("%d", &method_num);

    for (int i = 0; i < MAX; i++) {
      if (num[i] == '\0')
        break;

      count[i] = cnt;
      if (num[i] != num[i + 1])
        cnt++;





    }

    while(method_num) {			//method_num 이 0이 될 때 실행 x

      scanf("%d%d", &first, &last);

      if (first > last) {
        int temp;
        temp = first;
        first = last;
        last = temp;
      }


      if(count[first] == count[last]) {

        printf("Yes\n");

      }

      else  {

        printf("No\n");
      }

    method_num--;
  }

    return 0;


}
