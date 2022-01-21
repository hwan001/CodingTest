#include "header.h"

/*
*  ch�� �������� str�� ������ vector�� �����
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

/*
* �Ҽ� ���� Ȯ��
*/
int is_prime_number_custom(ll input)
{
    if (input < 2) {
        return 0;
    }

    for (ll j = 2; j <= (ll)(input / j); j++)
    {
        if (input % j == 0)
        {
            return 0;
        }
    }

    return 1;
}