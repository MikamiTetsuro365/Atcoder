#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <time.h>

using namespace std;
typedef long long ll;
ll N;

int main(){
    
    ll test = 0b1010101010101010101010101010;
    ll test2 = 0b0101010101010101010101010101;
    clock_t start = clock();
    for(ll i = 0; i < 100000; i++){
        ll ans = test ^ test2;
    }
    clock_t end = clock();
    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    printf("time %lf[ms]\n", time);
    return 0;

}