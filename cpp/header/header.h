#include <iostream>

#include <vector>
#include <stack> 
#include <queue> 
#include <deque> 
#include <map> 

#include <cstring> // memset, string
#include <string>
#include <algorithm> // sort
#include <utility>  // pair
#include <sstream> 
#include <cmath> 
#include <numeric>
#include <functional> 
#include <locale>
#include <cctype>

using namespace std;

typedef unsigned long long ll;

void init(int argc, char* argv[]);
vector<string> split(string, char);
int is_prime_number_custom(ll);
int is_prime_number_sqrt(ll);
bool *Sieve_of_Eratosthenes(ll);
double const_pi();
ll gcd_recusion(ll, ll);

extern void (*func)();

struct FuncEntry {
    const char* name;
    void (*func_ptr)();
};

void func_2557(); 
void func_10718(); 
void func_10171(); 
void func_10172(); 
void func_1000(); 
void func_1001(); 
void func_10998(); 
void func_1008(); 
void func_10869(); 
void func_10430(); 
void func_2588(); 
void func_10926(); 
void func_18108(); 


void func_1330(); 
void func_9498(); 
void func_2753(); 
void func_14681(); 
void func_2884(); 

void func_2525(); 
void func_2480(); 

void func_2739(); 
void func_10950(); 
void func_8393(); 
void func_15552(); 
void func_2741(); 
void func_2742(); 
void func_11021(); 
void func_11022(); 
void func_2438(); 
void func_2439(); 
void func_10871(); 

void func_10952(); 
void func_10951(); 
void func_1110(); 

void func_10818(); 
void func_2562(); 
void func_2577(); 
void func_3052(); 
void func_1546(); 
void func_8958(); 
void func_4344(); 

void func_15596(); 
void func_4673(); 
void func_1065(); 

void func_1157(); 
void func_2675(); 
void func_1152(); 
void func_2908(); 
void func_5622(); 
void func_2941(); 
void func_1316(); 

void func_1712(); 
void func_2292(); 
void func_1193(); 
void func_2869(); 
void func_10250(); 
void func_2775(); 
void func_2839(); 
void func_10757(); 
void func_1011(); 

void func_1978(); 
void func_2581(); 
void func_11653(); 
void func_1929(); 
void func_4948(); 
void func_9020(); 
void func_1085(); 
void func_3009(); 
void func_4153(); 
void func_3053(); 
void func_1002(); 

void func_10872(); 
void func_10870(); 
void func_2447(); 
void func_11729(); 

void func_2798(); 
void func_2231(); 
void func_7568(); 
void func_1018(); 
void func_1436(); 

void func_2750(); 
void func_2751(); 
void func_10989(); 
void func_2108(); 
void func_1427(); 
void func_11650(); 
void func_11651(); 
void func_1181(); 
void func_10814(); 
void func_18870(); 

void func_1003(); 
void func_9184(); 
void func_1904(); 
void func_9461(); 
void func_12865(); 

void func_11047(); 
void func_1931(); 
void func_11399(); 

void func_1260(); 
void func_2606(); 
void func_2667(); 
void func_1012(); 
void func_2178(); 
void func_7576(); 

void func_1009(); 
void func_2475(); 
void func_2920(); 
void func_1259(); 
void func_11050(); 
void func_15829(); 
void func_1032(); 

void func_15965(); 
void func_1004(); 
void func_1697(); 
void func_2164(); 
void func_11866(); 
void func_18111(); 
void func_10773(); 
void func_9012(); 
void func_2609(); 
void func_18258(); 
void func_1463(); 
void func_1920(); 
void func_4963(); 
void func_11726(); 
void func_11724(); 
void func_10816(); 
void func_4949(); 
void func_10828(); 
void func_10845(); 
void func_10866(); 
void func_1966(); 
void func_1874(); 
void func_1654(); 
void func_2805(); 
void func_1926(); 

void func_1019(); 
void func_10026(); 
void func_2206(); 
void func_1753(); 
void func_1300(); 
void func_9663(); 
void func_6593(); 
void func_2573(); 

void func_CHAC_A(); 
void func_CHAC_B(); 
void func_CHAC_D(); 

void func_13460(); 
void func_12100(); 
void func_3190(); 
void func_13458(); 
void func_14499(); 
void func_14500(); 
void func_14501(); 
void func_14502(); 
void func_14503(); 
void func_14888(); 
void func_14889(); 
void func_14890(); 
void func_14891(); 
void func_15683(); 
void func_15684(); 
void func_15685(); 
void func_15686(); 
void func_5373(); 
void func_16234(); 
void func_16235(); 
void func_16236(); 
void func_17144(); 
void func_17143(); 
void func_17140(); 
void func_17142(); 
void func_17779(); 
void func_17837(); 
void func_17822(); 
void func_17825(); 
void func_20061(); 
void func_19236(); 
void func_19237(); 
void func_19238(); 
void func_20055(); 
void func_20056(); 
void func_20057(); 
void func_20058(); 
void func_21608(); 
void func_21609(); 
void func_21610(); 
void func_21611(); 
void func_23288(); 
void func_23289(); 
void func_23290(); 
void func_23291(); 
