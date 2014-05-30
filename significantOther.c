#include <stdio.h>
int Answer2Everything()
{
	return 40+2;
}

void __attribute__((constructor)) so_ctor(void)
{
	 printf("libSignificantOther.so: Constructor\n");
}
void __attribute__((destructor)) so_dtor(void)
{
	 printf("libSignificantOther.so: Destructor\n");
}
