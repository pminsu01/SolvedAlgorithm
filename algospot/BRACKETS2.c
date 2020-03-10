#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000		// max 사이즈 설정
#define FALSE 0
#define TRUE 1

typedef int element;
typedef struct {					// 자체 참조 구조체
	element stack[MAX];
	int top;
} StackType;

void init(StackType *s) {			// 스택을 초기화 시킨다.
	s->top = -1;					// 초기화시 가장 밑에 있는 top은 -1을 가리킨다.
}

int is_empty(StackType *s) {		//비어 있는 경우에는
	return s->top == -1;			//stack 자리는 -1
}

int is_full(StackType *s) {			// 스택이 가득 차 있다면  -1 해주는이유는 -1부터 시작했기 때문에
	return s->top == MAX - 1;
}

void push(StackType *s, element item) {		// 집어 넣기
	if (is_full(s))
		exit(1);
	s->stack[++(s->top)] = item;
}

element pop(StackType *s) {				// 꺼내기
	if (is_empty(s))
		exit(1);
	return s->stack[(s->top)--];
}


int check_matching(char *in) {
	StackType s;
	char ch; // character from in
	char open_ch; // character from stack
	int i;
	int n = (int)strlen(in);
	init(&s);

	for (i = 0; i<n; i++) {
		ch = in[i];
		switch (ch) {
		case '(': case '{': case '[':
			push(&s, ch);
			break;
		case ')': case '}': case ']':
			if (is_empty(&s)) // condition 1, 3
				return FALSE;
			open_ch = pop(&s); // condition 2, 3
			if ((open_ch == '(' && ch != ')') ||
				(open_ch == '{' && ch != '}') ||
				(open_ch == '[' && ch != ']')) {
				return FALSE;
			}
			break;
		}
	}
	if (!is_empty(&s)) // condition 1
		return FALSE;
	return TRUE;
}

int main() {

	int method_num = 0;
	scanf("%d", &method_num);
	while (method_num) {

		char p[100000];
		scanf("%s", p);

		if (check_matching(p) == TRUE) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		method_num--;
	}
	return 0;
}
