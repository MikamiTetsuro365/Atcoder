#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {

    string S;
    cin >> S;

    map<char, ll> mp;

    for(ll i = 0; i < S.length(); i++){
        mp[S[i]]++;
    }

    auto begin = mp.begin(), end = mp.end();
    ll tmp = 0;
    for (auto iter = begin; iter != end; iter++) {
        ll num = iter -> second;
        if(iter == begin){
            tmp = num;
            continue;
        }
        if(num != tmp){
            cout << "No" << endl;
            return 0;
        }
        tmp = num;
    }

    cout << "Yes" << endl;

}