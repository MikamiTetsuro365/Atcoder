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

    ll N, K;
    cin >> N >> K;

    //入力
    priority_queue<pi > que;
    for(ll i = 0; i < N; i++){
        ll t, d;
        cin >> t >> d;
        que.push(make_pair(d, t));
    }
    //選んだネタとその個数を記録
    //mapで管理するのはよくないほんとよくない
    //map<ll, ll > mp;
    set<ll > st;
    //美味しいさが大きい順に選ぶ
    ll sum = 0;
    priority_queue<pi , vector<pi >, greater<pi > > kouho;
    for(ll i = 0; i < K; i++){
        ll t = que.top().second;
        ll d = que.top().first;
        que.pop();
        sum += d;

        if(st.find(t) != st.end()) kouho.push(make_pair(d, t));
        st.insert(t);
    }

    //選び直し，食べる寿司の種類を増やしてみた時，ポイントが増えますか？
    ll ans = sum + st.size() * st.size();
    for(ll i = 0; i < N; i++){
        if(kouho.empty() || que.empty()) break;

        ll t = que.top().second;
        ll d = que.top().first;
        que.pop();
        //cout << ans - (type * type) - kouho.top().first.first + d + (type+1) * (type+1) << endl;
        if(st.find(t) != st.end()) continue;
        
        sum = sum - kouho.top().first + d;
        st.insert(t);
        kouho.pop();

        ans = max(ans, (ll)(sum + st.size() * st.size()));
        //cout << ans << endl;
    }

    cout << ans << endl;

    

}