#include "header.h"

void (*func)() = func_2108;

int main() {
	while(1) func();

	return 0;
}