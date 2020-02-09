#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//もっとシンプルに書けるはず！！！

ll v[500019][2];

int main() {

    string S;
    cin >> S;

    string tS;

    ll idx = 0;
    ll cn = 0;
    
    //反転させて判定すれば良いので↓2つもいらない気がする
    //頭から
    for(ll i = 0; i < S.length(); i++){
        if(S[i] == 'x'){
            cn++;
        }else{
            v[idx][0] = cn;
            v[idx+1][0] = S[i];
            cn = 0;
            idx+=2;
        }
    }
    if(S.back() == 'x') v[idx][0] = cn;

    idx = 0;
    cn = 0;
    //逆から
    for(ll i = S.length()-1; i >= 0; i--){
        if(S[i] == 'x'){
            cn++;
        }else{
            v[idx][1] = cn;
            v[idx+1][1] = S[i];
            cn = 0;
            idx+=2;
        }
    }
    if(S.front() == 'x') v[idx][1] = cn;

    ll ans = 0;
    for(ll i = 0; i <= 400000; i++){
        if(i % 2 == 1 && v[i][0] != v[i][1]){
            cout << -1 << endl;
            return 0;
        }else{
            ans += abs(v[i][0]-v[i][1]);
        }
    }

    cout << ans / 2 << endl;

}