#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N;
    cin >> N;

    vector<ll > vec(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> vec[i];
    }

    ll ans = 0;
    ll g_ans = 0;
    ll k_ans = 0;
    ll sum = 0;

    //奇数番目を正に揃える
    bool flg = true;
    for(ll i = 0; i < N; i++){
        sum += vec[i];
        if(flg == true){
            if(sum <= 0){
                //cout << i << " " << sum << " " << abs(1 - sum) << endl;
                k_ans += abs(sum) + 1;
                sum = 1;
            }
            flg = false;
        }else{
            if(sum >= 0){
                //cout << i << " " << sum << " " << abs(-1 - sum) << endl;
                k_ans += abs(sum) + 1;
                sum = -1;
            }
            flg = true;
        }
    }

    //cout << k_ans << endl;
    //奇数番目を負に揃える
    flg = true;
    sum = 0;
    for(ll i = 0; i < N; i++){
        sum += vec[i];
        //cout << sum << endl;
        if(flg == false){
            if(sum <= 0){
                //cout << i << " " << sum << " " << abs(sum - vec[i]) << endl;
                g_ans += abs(sum) + 1;
                sum = 1;
            }
            flg = true;
        }else{
            if(sum >= 0){
                //cout << i << " " << sum << " " << abs(sum - vec[i]) << endl;
                g_ans += abs(sum) + 1;
                sum = -1;
            }
            flg = false;
        }
    }
    
    ans = min(k_ans, g_ans);

    cout << ans << endl;


}