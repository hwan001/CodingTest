#include "header.h"

void (*func)();

FuncEntry func_list[] = {
    {"2557", func_2557}, 
    {"10718", func_10718}, 
    {"10926", func_10926}, 
    {"18108", func_18108}, 
    {"2525", func_2525}, 
    {"2480", func_2480}, 
    {"15596", func_15596}, 
    {"4673", func_4673}, 
    {"1065", func_1065}, 
    {"1157", func_1157}, 
    {"2675", func_2675}, 
    {"1152", func_1152}, 
    {"2908", func_2908}, 
    {"5622", func_5622}, 
    {"2941", func_2941}, 
    {"1316", func_1316}, 
    {"1712", func_1712}, 
    {"2292", func_2292}, 
    {"1193", func_1193}, 
    {"2869", func_2869}, 
    {"10250", func_10250}, 
    {"2775", func_2775}, 
    {"2839", func_2839}, 
    {"10757", func_10757}, 
    {"1011", func_1011}, 
    {"1978", func_1978}, 
    {"2581", func_2581}, 
    {"11653", func_11653}, 
    {"1929", func_1929}, 
    {"4948", func_4948}, 
    {"9020", func_9020}, 
    {"1085", func_1085}, 
    {"3009", func_3009}, 
    {"4153", func_4153}, 
    {"3053", func_3053}, 
    {"1002", func_1002}, 
    {"10872", func_10872}, 
    {"10870", func_10870}, 
    {"2447", func_2447}, 
    {"11729", func_11729}, 
    {"2798", func_2798}, 
    {"2231", func_2231}, 
    {"7568", func_7568}, 
    {"1018", func_1018}, 
    {"1436", func_1436}, 
    {"2750", func_2750}, 
    {"2751", func_2751}, 
    {"10989", func_10989}, 
    {"2108", func_2108}, 
    {"1427", func_1427}, 
    {"11650", func_11650}, 
    {"11651", func_11651}, 
    {"1181", func_1181}, 
    {"10814", func_10814}, 
    {"18870", func_18870}, 
    {"1003", func_1003}, 
    {"9184", func_9184}, 
    {"1904", func_1904}, 
    {"9461", func_9461}, 
    {"12865", func_12865}, 
    {"11047", func_11047}, 
    {"1931", func_1931}, 
    {"11399", func_11399}, 
    {"1260", func_1260}, 
    {"2606", func_2606}, 
    {"2667", func_2667}, 
    {"1012", func_1012}, 
    {"2178", func_2178}, 
    {"7576", func_7576}, 
    {"1009", func_1009}, 
    {"2475", func_2475}, 
    {"2920", func_2920}, 
    {"1259", func_1259}, 
    {"11050", func_11050}, 
    {"15829", func_15829}, 
    {"1032", func_1032}, 
    {"15965", func_15965}, 
    {"1004", func_1004}, 
    {"1697", func_1697}, 
    {"2164", func_2164}, 
    {"11866", func_11866}, 
    {"18111", func_18111}, 
    {"10773", func_10773}, 
    {"9012", func_9012}, 
    {"2609", func_2609}, 
    {"18258", func_18258}, 
    {"1463", func_1463}, 
    {"1920", func_1920}, 
    {"4963", func_4963}, 
    {"11726", func_11726}, 
    {"11724", func_11724}, 
    {"10816", func_10816}, 
    {"4949", func_4949}, 
    {"10828", func_10828}, 
    {"10845", func_10845}, 
    {"10866", func_10866}, 
    {"1966", func_1966}, 
    {"1874", func_1874}, 
    {"1654", func_1654}, 
    {"2805", func_2805}, 
    {"1926", func_1926}, 
    {"1019", func_1019}, 
    {"10026", func_10026}, 
    {"2206", func_2206}, 
    {"1753", func_1753}, 
    {"1300", func_1300}, 
    {"9663", func_9663}, 
    {"6593", func_6593}, 
    {"2573", func_2573}
};


void init(int argc, char* argv[]) {
    // 함수 이름을 문자열과 함수 포인터로 매핑
    std::map<std::string, void(*)()> func_map;

    // 배열을 순회하며 함수들을 맵에 자동 등록
    for (const auto& entry : func_list) {
        func_map[entry.name] = entry.func_ptr;
    }

    // 명령줄 인수가 있으면 해당 함수 실행, 없으면 기본 함수 실행
    if (argc > 1) {
        std::string input_func_name = argv[1];
        if (func_map.find(input_func_name) != func_map.end()) {
            func = func_map[input_func_name];  // 입력된 함수 이름에 맞는 함수 포인터로 변경
        } else {
            std::cout << "Unknown function: " << input_func_name << std::endl;
        }
    }
    else {
        func = func_2675;
    }
}

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


/*
*   input : ll a, b;
*   output : ll c;
*   GCD(�ִ�����)�� ��Ŭ���� ȣ����, ��ͷ� ����
*/
ll gcd_recursion(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd_recursion(b, a % b);
    }
}