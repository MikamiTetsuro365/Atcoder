#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//どっちかに寄せれば最大になるだろう的な発想
//"区間ごとに"どちらかに寄せる！
int main() {

    ll N, D;
    cin >> N >> D;

    set<ll > R;
    R.insert(0);
    set<ll > RR;
    R.insert(0);
    set<ll > RRR;
    R.insert(0);
    set<ll > L;
    L.insert(0);
    set<ll > LL;
    L.insert(0);

    for(ll i = 0; i < N; i++){
        ll x; char d;
        cin >> x >> d;
        if(d == 'R'){
            R.insert(x);
            RR.insert(x);
            RRR.insert(x);
        }
        else{
            L.insert(x);
            LL.insert(x);
        }
    }
    R.insert(D+1);
    L.insert(D+1);
    RR.insert(D+1);
    RRR.insert(D+1);
    LL.insert(D+1);


    //右に飛べるウサギを右の行けるところまで全て動かす->左のウサギを左へ
    ll ans1 = 0;
    for(auto i = R.rbegin(); i != R.rend(); i++){
        if(*i == 0 || *i == D+1) continue;
        ll d = *L.lower_bound(*i);
        ans1 += (d-1) - *i;
        R.erase(*i);
        R.insert(d-1);
        //1つ障害物が増える
        L.insert(d-1);
    }

    // for(auto i = R.begin(); i != R.end(); i++){
    //     cout << *i << endl;
    // }

    for(auto i = LL.begin(); i != LL.end(); i++){
        if(*i == 0 || *i == D+1) continue;
        auto d = R.lower_bound(*i);
        d--;
        ans1 += *i - (*d+1);
        //障害物が増える
        R.insert(*d+1);
    }
    //cout << ans1 << endl;

    //左に飛べるウサギを右の行けるところまで全て動かす->右のウサギを右へ
    ll ans2 = 0;

    for(auto i = LL.begin(); i != LL.end(); i++){
        if(*i == 0 || *i == D+1) continue;
        auto d = RR.lower_bound(*i);
        d--;
        ans2 += *i - (*d+1);
        LL.erase(*i);
        LL.insert(*d+1);
        //障害物が増える
        RR.insert(*d+1);
        //cout << *i << endl;
    }

    for(auto i = RRR.rbegin(); i != RRR.rend(); i++){
        if(*i == 0 || *i == D+1) continue;
        auto d = LL.lower_bound(*i);
        ans2 += (*d-1) - *i;
        LL.insert(*d-1);
    }

    //cout << ans2 << endl;

    cout << max(ans1, ans2) << endl;

}