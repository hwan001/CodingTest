#include "header.h"

void (*func)() = func_9012;

int main() {
	while(1) func();

	return 0;
}