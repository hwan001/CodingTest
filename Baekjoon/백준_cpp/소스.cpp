#include "header.h"

void (*func)() = func_4963;

int main() {
	while(1) func();

	return 0;
}