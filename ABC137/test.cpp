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

using namespace std;
typedef long long ll;
ll N;

int main(){

    ll ans = 0;
    for(ll i = 0; i < 100000 ; i++){
        for(ll j = i + 1; j < 100000; j++){
            ans++;
        }

    }

    cout << ans << endl;

}