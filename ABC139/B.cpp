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

int main(){

    ll A, B;

    cin >> A >> B;

    ll ans = 1;

    ll num = A;

    if(B == 1){
        cout << 0 << endl;
        return 0;
    }

    if(num >= B){
        cout << ans << endl;
        return 0;
    }

    for(ll i = 0; i < 100; i++){
        num--;
        num += A;

        ans++;
        if(num >= B){
            break;
        }
    }

    cout << ans << endl;
}