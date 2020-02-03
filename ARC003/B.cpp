#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 9223372036854775807;
//reverseは要素を反転させてもとの変数に戻すもの！
//mp[reverse]というように横着するのはだめ！
int main(){

    ll N;
    cin >> N;

    map<string , ll> mp;
    
    vector<string > input;
    for(ll i = 0; i < N; i++){
        string s; cin >> s;
        reverse(s.begin(), s.end());
        mp[s]++;
    }

    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        string s = iter->first;
        reverse(s.begin(), s.end());
        cout << s << endl;
    }

}