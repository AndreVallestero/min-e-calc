#include <stdio.h>

#define EFL_BETA_API_SUPPORT 1

#include <Efl_Core.h>

void efl_main(void *data EINA_UNUSED, const Efl_Event *ev EINA_UNUSED) {
	printf("Hello, World!\n");
	efl_exit(0);
}

EFL_MAIN()
