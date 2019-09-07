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
#include <map>

using namespace std;
typedef long long int ll;

int main(){

    ll N = 0;
    cin >> N;
    vector<ll > p(N + 1);
    for(ll i = 0; i < N; i++){
        cin >> p[i];
    }
    p[N] = -1;

    ll ans = 0;

    ll s = 1;
    for(ll i = 0; i < N; i++){
        if(p[i] == s){
            if(p[i + 1] == s + 1){
                i++;
                s++;
            }
            ans++;
        }
        s++;
    }

    cout << ans << endl;

} 