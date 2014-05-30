#include <stdio.h>
int ImportantAnswer()
{
	return 1337;
}

void __attribute__((constructor)) para_ctor(void)
{
	 printf("libParamour.so: Constructor\n");
}
void __attribute__((destructor)) _para_dtor(void)
{
	 printf("libParamour.so: Destructor\n");
}
