#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;
typedef long long ll;

ll A, B = 0;

int main(){
    clock_t start = clock();
    cin >> A >> B;

    ll loop = 0;

    loop = (B - A) % 4 ;
    cout << loop << endl;
    ll total = B;

    for(int i = 1; i < loop + 1; i++){
        total = total ^ (B - i);
    }

 
    cout << total << endl;

    int conf = 123 ^ 452 ;

    cout << conf << endl;

}