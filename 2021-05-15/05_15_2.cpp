#include <stdio.h> 

int function(int num) {
	if (num == 1) return 1;
	if (num == 2) return 1;
	else return function(num - 1) + function(num - 2);
}

int main() {
	int num = 0;
	scanf("%d", &num);

	printf("fibo index :%d and result = %d\n", num, function(num));

	return 0;
}
