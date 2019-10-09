#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;

    //開店日 0と1で表されるので2進数から10進数になおしておく
    vector<ll > store_day;
    for(ll i = 0; i < N; i++){
        ll tmp = 0;
        for(ll j = 0; j < 10; j++){
            ll in; cin >> in;
            tmp += in * pow(2, j);
        }
        store_day.push_back(tmp);
    }

    //点数, 他の店と開店日が被ってない～すべて被っているがあるので入力は11個
    vector<vector<ll > > point;
    for(ll i = 0; i < N; i++){
        vector<ll > tmp;
        for(ll j = 0; j < 11; j++){
            ll in; cin >> in;
            tmp.push_back(in);
        }
        point.push_back(tmp);
    }    

    //全探査
    ll ans = -1 * INFINITY;
    
    //1日以上は回転していないとイケないので
    for(ll open_day = 1; open_day < pow(2, 10); open_day++){
        ll t_ans = 0;
        for(ll i = 0; i < N; i++){
            ll bit_num = __builtin_popcount(store_day[i] & open_day);
            //cout << bit_num << endl;
            t_ans += point[i][bit_num];
        }
        ans = max(ans, t_ans);
    }

    cout << ans << endl;

}