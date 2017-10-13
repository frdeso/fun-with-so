#include <stdio.h>
#include <dlfcn.h>

int answer_to_everything()
{
	return 40+2;
}

//extern int my_variable;

void __attribute__((constructor)) so_ctor(void)
{
	int * my_variable_sym;
	 printf("%s: Constructor\n", __FILE__);

	void *obj = dlsym(NULL , "my_variable");
	if (obj == NULL) {
		printf("dlsym error\n");
		return;
	}
	my_variable_sym = (int *) obj;
	printf("my_variable = %d\n\n", *my_variable_sym);
//	*my_variable_sym = 18181818;
//	printf("my_variable = %d\n\n", my_variable);
}
void __attribute__((destructor)) so_dtor(void)
{
	 printf("%s: Destructor\n", __FILE__);
}
