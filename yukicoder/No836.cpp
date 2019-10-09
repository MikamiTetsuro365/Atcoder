#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll l, r, n;
    cin >> l >> r >> n;

    vector<ll > ans(n, 0);

    ll t_l =l + (n - l % n);
    ll t_r =r - (r % n);

    //cout << t_l << " " << t_r << endl;

    //半端なところを加算
    for(ll i = l; i < t_l; i++){
        ans[i % n]++;
    }
    for(ll i = t_r; i <= r; i++){
        ans[i % n]++;
    }
    //真ん中を加算→ちょうど計算される範囲ならここは更新されない
    for(ll i = 0; i < n; i++){
        ans[i] += (t_r - t_l) / n;
    }

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

}