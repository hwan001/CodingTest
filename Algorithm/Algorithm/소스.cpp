#include "header.h"

#define EXIT -1
#define ALGO1 0
#define ALGO2 1
#define ALGO3 2
#define ALGO4 3
#define ALGO5 4

int main() {
	int sel;

	while (true) {
		cin >> sel;

		switch (sel) {
		case ALGO1:
			cout << "function " << sel << "\n";
			break;

		case ALGO2:
			cout << "function " << sel << "\n";
			break;

		case ALGO3:
			cout << "function " << sel << "\n";
			break;

		case ALGO4:
			cout << "function " << sel << "\n";
			break;

		case EXIT:
			exit(0);

		default:
			cout << "no function";
			break;

		}
	}

	return 0;
}