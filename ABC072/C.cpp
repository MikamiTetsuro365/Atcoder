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
    vector<ll > a(N);
    map<ll, ll > mp;
    for(ll i = 0; i < N; i++){
        cin >> a[i];
        mp[a[i]]++;
        mp[a[i] + 1]++;
        mp[a[i] - 1]++;
    }
    //一番数が多いのを探す
    ll ans = 0;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        ans = max(ans, iter->second);
    }
    

    cout << ans << endl;

} 