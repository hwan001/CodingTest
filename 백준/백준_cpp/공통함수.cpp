#include "header.h"

/*
*  input : string str(전체 문자열), char ch(구분자)
*  output : vector<string> (구분자로 분리된 문자열들의 벡터)
*  ch를 기준으로 str을 나눠서 vector에 담아줌
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
*  input : ll input (정수)
*  output : int (1 or 0)
*  unsigned long long 형태의 정수를 넣으면 해당 수가 소수인지 여부를 알려준다.
*  소수 판별 custom 버전
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
*  input : ll input (정수)
*  output : int (1 or 0)
*  unsigned long long 형태의 정수를 넣으면 해당 수가 소수인지 여부를 알려준다.
*  소수 판별 sqrt 버전
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
* output : 1부터 m까지의 소수 여부를 sizeof(bool) * (m+1)크기의 bool * 형태로 반환한다.
* 사용 시 반환된 bool array에 해당 자연수를 조회하면 소수 여부를 알 수 있다.
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
*  output : double 형태의 Pi 값
*  반환받은 double 값을 포맷 스트링 %.10f 와 같은 형태로 소수점을 원하는 자리까지 찍어서 사용
*/
double const_pi() {
    return atan(1) * 4;
}

