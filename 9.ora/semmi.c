#include <stdio.h>

int main(){
	int a, b;
	printf("Add meg a-t:");
	scanf("%d", &a);
	printf("Add meg b-t:");
	scanf("%d", &b);
	printf("a/b=%f, egészekben %d\n", (double)a/b, a/b);
	return 0;
}
