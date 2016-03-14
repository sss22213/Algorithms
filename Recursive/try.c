#include <stdlib.h>
int *f() {
	int *p;

	p=malloc(4);
	return p;
}

int main()
{
	int *p1;

	p1=f();
	free(p1);

	return 0;
}
