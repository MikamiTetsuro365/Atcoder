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

    string w;
    cin >> w;

    map<char, ll> mp;

    for(ll i = 0; i < w.length(); i++){
        mp[w[i]]++;
    }

    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        if(iter->second % 2 == 1){
            cout << "No" << endl;
            return 0;
        }
    }    

    cout << "Yes" << endl;

}