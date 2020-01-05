#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//lower_boundをうまく使う必要があるのは分かる
int main() {

    ll A, B, Q;
    cin >> A >> B >> Q;

    vector<ll > s;
    vector<ll > t;
    vector<ll > q;
    //0＝寺 1=社
    for(ll i = 0; i < A; i++){
        ll x = 0; cin >> x;
        s.push_back(x);
    }
    for(ll i = 0; i < B; i++){
        ll x = 0; cin >> x;
        t.push_back(x);
    }

    //クエリQ
    for(ll i = 0; i < Q; i++){
        ll x = 0; cin >> x;
        q.push_back(x);
    }

    //番兵
    //matome.push_back(make_pair(-1,-1));
    //matome.push_back(make_pair(-1,INF));
    s.push_back(-INF);
    s.push_back(INF);
    t.push_back(-INF);
    t.push_back(INF);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    //sort(q.begin(), q.end());

    vector<ll > ans;
    for(ll i = 0; i < Q; i++){
        //答え
        ll t_ans = 0;
        //現在地
        ll n = q[i];

        //n以上になるindex
        ll tIdx = lower_bound(t.begin(), t.end(), n) - t.begin();
        ll sIdx = lower_bound(s.begin(), s.end(), n) - s.begin();

        //右の寺
        ll rightT = t[tIdx];
        //右の神社
        ll rightS = s[sIdx];

        //左の寺
        ll leftT = t[tIdx-1];
        //左の神社
        ll leftS = s[sIdx-1];

        //右寺右神社
        t_ans = max(rightT, rightS) - n;
        //左寺左神社
        t_ans = min(t_ans, n - min(leftT, leftS));
        //左の寺に行って右の神社に戻ってくるパターン
        //右の神社にいって左の寺に戻ってくるパターン
        if(rightT > rightS && leftT > leftS){
            t_ans = min(t_ans, rightS - leftT + min(rightS - n, n - leftT));
        }

        if(rightT < rightS && leftT < leftS){
            t_ans = min(t_ans, rightT - leftS + min(rightT - n, n - leftS));
        }

        cout << t_ans << endl;

    }


}