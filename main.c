#include <stdio.h>
#include <dlfcn.h>
#include "fcts.h"
int my_variable = 121212;
int main()
{
	void *handle;
	int (*bbb_answer)(void);
	int *my_variable_sym;


	printf("*aaa*\n");
	int soAnswer = answer_to_everything();
	printf("Answer = %d\n\n",soAnswer);


	printf("*bbb*\n");
	handle = dlopen("./libbbb.so", RTLD_LAZY);
	*(void **) (&bbb_answer) = dlsym(handle, "ImportantAnswer");

	printf("Answer = %d\n\n", bbb_answer());

	void *obj = dlsym(handle, "my_variable");
	my_variable_sym = (int *) obj;
	printf("my_variable = %d\n\n", *my_variable_sym);
	*my_variable_sym = 119191919;
	printf("my_variable = %d\n\n", *my_variable_sym);



	return 0;
}
