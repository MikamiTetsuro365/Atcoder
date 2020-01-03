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
    string s;
    cin >> s;
    ll K;
    cin >> K;
    
    map<string, ll > mp;
    ll len = s.length();
    for(ll i = 0; i < min(len , 5LL); i++){
        for(ll j = 0; j < len - i; j++){
            mp[s.substr(j, i + 1)]++;
            //cout << s.substr(j, i + 1) << endl;
        }        
    }

    ll cn = 0;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        if(cn == K - 1){
            cout << iter->first << endl;
            return 0;
        }
        cn++;
    }
}