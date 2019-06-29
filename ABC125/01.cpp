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

using namespace std;
typedef long long ll;
double N;

int main(){

    ll ans = 0;

    ll a, b;
    cin >> a >> b >> N;
    if(N < a){
        cout << "0" << endl;
        return 0;
    }
    N += 0.5; 
    ll t = 1; 
    for(;;){
       ans += b;
       N -= t * a;
       t++;
        if(N < 0){
           cout << ans << endl;
           return 0;
       }
    }


} 