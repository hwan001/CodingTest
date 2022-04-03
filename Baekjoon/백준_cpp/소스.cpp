#include "header.h"

void (*func)() = func_10026;

int main() {
	while(1) func();

	return 0;
}