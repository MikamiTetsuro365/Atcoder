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

    map<string, ll> mp;

    ll mx = -1;
    for(ll i = 0; i < N; i++){
        string s;
        cin >> s;
        mp[s]++;
        mx = max(mp[s], mx);
    }

    ll cn = 0;
    ll idx = 0;
    //ここになにか入力
    map<string, ll> mp2;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
           if(iter->second == mx){
                mp2[iter->first]++;
            }
        idx++;
    }  

    //cout << 0 << endl;
    auto begin2 = mp2.begin(), end2 = mp2.end();
    for (auto iter = begin2; iter != end2; iter++) {
        cout << iter->first << endl;
    } 





}
