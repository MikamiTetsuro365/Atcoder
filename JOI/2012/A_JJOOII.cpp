#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll N, M;

int main(){
    string S;
    cin >> S;
    //入力 前処理（圧縮）
    vector<pair<char, ll > > t_S;
    for(ll i = 0; i < S.size();){
        ll j = i;
        while(j < S.size() && S[i] == S[j]){
            j++;
        }
        t_S.push_back(make_pair(S[i], j - i));
        i = j;
    }
    //判定 Oの数とその両端のJとIの数を監視
    ll ans = 0;
    if(t_S.size() < 2) {
        cout << 0 << endl;
        return 0;
    }
    for(ll i = 1; i < t_S.size()-1; i++){
        if(t_S[i].first != 'O') continue;
        if(t_S[i-1].first == 'J' && t_S[i+1].first == 'I' && t_S[i-1].second >= t_S[i].second && t_S[i+1].second >= t_S[i].second ){
            ans = max(ans, t_S[i].second);
        }
    }

    cout << ans << endl;

}