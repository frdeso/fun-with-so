#include <stdio.h>
int ImportantAnswer()
{
	return 1337;
}

void __attribute__((constructor)) para_ctor(void)
{
	 printf("%s: Constructor\n", __FILE__);

}
void __attribute__((destructor)) _para_dtor(void)
{
	 printf("%s: Destructor\n", __FILE__);
}
