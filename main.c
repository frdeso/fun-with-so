#include <stdio.h>
#include <dlfcn.h>
#include "fcts.h"

int main()
{
	void *handle;
	int (*paraAnswer)(void);


	printf("*Significant other*\n");
	int soAnswer = Answer2Everything();
	printf("Answer = %d\n\n",soAnswer);


	printf("*Paramour*\n");
	handle = dlopen("./libparamour.so", RTLD_LAZY);
	 *(void **) (&paraAnswer) = dlsym(handle, "ImportantAnswer");

	printf("Answer = %d\n\n",paraAnswer());

	return 0;
}
