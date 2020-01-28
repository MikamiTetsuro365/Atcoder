#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll H, N;

int main() {

    ll N, K;
    string S;
    cin >> N >> K >> S;

    ll cn = 0;
    priority_queue<ll > que;

    for(ll i = 0; i < S.length(); i++){
        if(S[i] == '('){
            cn++;
        }
        if(S[i] == ')'){
            cn--;
        }
        // | は連続しては行けないけどバンズを挟めば別何でも良い
        que.push(cn);
    }

    ll ans = 0;
    for(ll i = 0; i < K; i++){
        ans += que.top();
        que.pop();
    }

    cout << ans << endl;

}