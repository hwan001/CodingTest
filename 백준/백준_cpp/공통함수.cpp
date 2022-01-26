#include "header.h"

/*
*  input : string str(��ü ���ڿ�), char ch(������)
*  output : vector<string> (�����ڷ� �и��� ���ڿ����� ����)
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
*  input : ll input (����)
*  output : int (1 or 0)
*  unsigned long long ������ ������ ������ �ش� ���� �Ҽ����� ���θ� �˷��ش�.
*  �Ҽ� �Ǻ� custom ����
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

/*
*  input : ll input (����)
*  output : int (1 or 0)
*  unsigned long long ������ ������ ������ �ش� ���� �Ҽ����� ���θ� �˷��ش�.
*  �Ҽ� �Ǻ� sqrt ����
*/
int is_prime_number_sqrt(ll input)
{
    if (input < 2) {
        return 0;
    }

    for (ll j = 2; j <= sqrt(input); j++)
    {
        if (input % j == 0)
        {
            return 0;
        }
    }

    return 1;
}

/*
* input : ll m
* output : 1���� m������ �Ҽ� ���θ� sizeof(bool) * (m+1)ũ���� bool * ���·� ��ȯ�Ѵ�.
* ��� �� ��ȯ�� bool array�� �ش� �ڿ����� ��ȸ�ϸ� �Ҽ� ���θ� �� �� �ִ�.
*/
bool *Sieve_of_Eratosthenes(ll m) {
    bool* arr = new bool[m + 1];

    memset(arr, 1, sizeof(bool) * (m+1));
    arr[0] = false;
    arr[0] = false;

    for (ll i = 2; i < m + 1; i++) {
        if (arr[i] == true) {
            for (ll j = i * 2; j < m + 1; j += i) {
                arr[j] = false;
            }
        }
    }

    return arr;
}

/*
*  input : -
*  output : double ������ Pi ��
*  ��ȯ���� double ���� ���� ��Ʈ�� %.10f �� ���� ���·� �Ҽ����� ���ϴ� �ڸ����� �� ���
*/
double const_pi() {
    return atan(1) * 4;
}

