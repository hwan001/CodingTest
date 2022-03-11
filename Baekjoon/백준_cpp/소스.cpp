#include "header.h"

void (*func)() = func_2164;

int main() {
	while(1) func();

	return 0;
}