#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;


int main(){

    ll N, M; cin >> N >> M;
    map<ll, ll > mp;
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        //重複排除
        if(mp[t] != 0) continue;
        
        mp[t]++;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());
    //cout << " " << endl;
    //圧縮
    vector<ll > t_vec;
    ll cn = 1;
    //準備
    ll sum  = 0;
    //人が連続してきたときと人と人の隙間を求める
    priority_queue<ll > que;
    for(ll i = 1; i < vec.size();i++){
        if(vec[i-1] != vec[i]-1){
            //cout << vec[i] << endl;
            ll s = vec[i]-vec[i-1]-1;
            t_vec.push_back(cn);
            t_vec.push_back(s);
            //もしストーブを全期間でつけたときのコスト
            sum += cn;
            sum += s;
            que.push(s);
            cn = 1;
        }else{
            cn++;
        }
    }
    t_vec.push_back(cn);
    sum += cn;

    while(M-1 > 0 && !que.empty()){
        sum -= que.top();
        que.pop();
        M--;
    }

    cout << sum << endl;

}