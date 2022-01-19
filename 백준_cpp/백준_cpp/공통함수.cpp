#include "header.h"

/*
*  Custom Function
*/
vector<string> split(string str, char ch) {
	stringstream ss(str);
	string tmp;
	vector<string> res;

	while (getline(ss, tmp, ch)) {
		if (tmp.size() > 0) {
			res.push_back(tmp);
		}
	}

	return res;
}