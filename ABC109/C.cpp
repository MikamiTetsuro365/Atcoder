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
typedef long long ll;
ll N;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

int main(){

    ll N, X;
    cin >> N >> X;

    vector<ll > p(N + 1, 0);
    p[0] = X;
    for(ll i = 1; i <= N; i++){
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    map<ll, ll> mp;

    for(ll i = 1; i <= N; i++){
        //cout << p[i]  << endl;
        mp[p[i] - p[i-1]]++;
    }

    ll ans = 0;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        if(iter == begin){
            ans = iter->first;
            //cout << "a" << endl;
        }else{
            ans = gcd(ans, iter->first);
        }
    }

    cout << ans << endl;


}