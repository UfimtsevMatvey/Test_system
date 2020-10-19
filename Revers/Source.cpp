#include <stdio.h>
void fo1()
{
	int a = 1, b = 10, c = 100;
}

void fo2()
{
	int a, b, c;
	printf("%d, %d, %d", a, b, c);
}

int main()
{
	int x;
	int y;
	int z;
	fo1();
	fo2();

	scanf("%d", &y);
	scanf("%d", &x);
	return 0;
}