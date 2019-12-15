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

    //最後に書き込まれた数字が最初のスレッドになっているので
    //最後に書き込まれた順に大>小でソート
    ll N, M; cin >> N >> M;
    vector<pi > ans;
    vector<ll > ans2;
    for(ll i = 0; i < N; i++){
        ans.push_back(make_pair(-1, i + 1));
    }
    for(ll i = 0; i < M; i++){
        ll a; cin >> a;
        ans[a-1].first = i;
    }

    sort(ans.rbegin(), ans.rend());

    //表示
    for(ll i = 0; i < N; i++){
        //最初から位置が変化しなかった奴ら
        if(ans[i].first == -1){
            ans2.push_back(ans[i].second);
        }else{
            cout << ans[i].second << endl;
        }
    }
    sort(ans2.begin(), ans2.end());
    for(ll i = 0; i < ans2.size(); i++){
        cout << ans2[i] << endl;
    }

}