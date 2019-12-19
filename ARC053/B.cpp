#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//中身は0になっているはず
//ll dp[1919][1919][3019];

//配るDP
int main() {

    string s; cin >> s;
    map<char, ll> mp;

    //偶数の個数（厳密には同じ単語同士のペアの数）
    ll even = 0;
    priority_queue<ll ,vector<ll >, greater<ll > > K;

    for(ll i = 0; i < s.length(); i++){
        mp[s[i]]++;
    }

    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        ll num = iter->second;
        if(num % 2 == 1){
            K.push(1);
        }
        even += num / 2;
    }

    if(K.empty()){
        cout << s.length() << endl;
        return 0;
    }

    for(ll i = even; i >= 0; i--){
        ll tmp = K.top();
        K.pop();
        K.push(tmp + 2);
    }

    cout << K.top() << endl;

}