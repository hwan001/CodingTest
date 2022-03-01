#include "header.h"

void (*func)() = func_1019;

int main() {
	while(1) func();

	return 0;
}