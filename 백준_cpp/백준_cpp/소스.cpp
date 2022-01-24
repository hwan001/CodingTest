#include "header.h"

void (*func)() = func_1002;

int main() {
	func();

	return 0;
}