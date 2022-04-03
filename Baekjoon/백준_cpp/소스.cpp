#include "header.h"

void (*func)() = func_1032;

int main() {
	while(1) func();

	return 0;
}