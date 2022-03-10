#include "header.h"

void (*func)() = func_1697;

int main() {
	while(1) func();

	return 0;
}