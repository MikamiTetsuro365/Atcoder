#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N;
    cin >> N;

    map<vector<char >, ll> mp;

    for(ll i = 1; i <= N; i++){
        string num = to_string(i);
        if(num.length() == 1) mp[vector<char >{num[0],num[0]}]++;
        else mp[vector<char >{num[0],num[num.length()-1]}]++;
    }

    ll ans = 0;

    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        char a = iter->first[0];
        char b = iter->first[1];
        ll num = iter-> second;
        ans += num * mp[vector<char >{b, a}];
        //cout << a << " " << b << " " << num << endl;
    }    

    cout << ans << endl;

}