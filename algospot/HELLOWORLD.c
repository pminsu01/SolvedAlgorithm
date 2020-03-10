#include<stdio.h>

int main() {

	int in = 0;
	char name[50];

	scanf("%d", &in);

	for (int i = 0; i < in; i++) {

		scanf("%s", name);
		printf("Hello, %s!\n", name);


	}


	return 0;
}
