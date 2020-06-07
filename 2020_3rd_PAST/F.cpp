#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000000;
ll INF = 11451419194545;

int main(){

    ll N;
    cin >> N;

    vector<map<char, ll> > v;

    string ans;
    for(ll i = 0; i < N; i++){
        map<char, ll> mp;
        string S;
        cin >> S;
        for(ll j = 0; j < S.length(); j++){
            mp[S[j]]++;
        }
        v.push_back(mp);
    }

    for(ll i = 0; i < N / 2; i++){
        bool f = false;
        auto begin = v[i].begin(), end = v[i].end();
        for (auto iter = begin; iter != end; iter++) {
            char c = iter->first;
            if(v[N-1-i][c] > 0){
                ans += c;
                f = true;
                break;
            }
        }
        if(f == false){
            cout << -1 << endl;
            return 0;
        }
    }

    string rans = ans;
    reverse(rans.begin(), rans.end());
    if(N % 2 == 1){
        ans += v[N/2].begin()->first;
    }

    cout << ans << rans << endl;

}