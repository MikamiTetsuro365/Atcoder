#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
ll D, N;

int main(){
    
    cin >> D >> N;

    vector<ll > temperature(D, 0);

    for(ll i = 0; i < D; i++){
        cin >> temperature[i];
    }

    vector<pair<ll, ll > > clo_temp;
    vector<pair<ll, ll > > clothes;

    for(ll i = 0; i < N; i++){
        ll a, b, c; cin >> a >> b >> c;
        clo_temp.push_back(make_pair(a, b));
        clothes.push_back(make_pair(c, i));
    }

    //前処理 最も小さいやつと最も大きいやつだけ集める
    //use[0]は余白
    vector<vector<ll > > use(D + 1, vector<ll >(3, 0));
    vector<ll > mn;
    vector<ll > mx;
    for(ll i = 0; i < D ; i++){
        vector<ll > tmp;
        ll t_mn = 114514;
        ll t_mx = -1;
        for(ll j = 0; j < N; j++){
            if(temperature[i] >= clo_temp[j].first && temperature[i] <= clo_temp[j].second){
                t_mn = min(t_mn, clothes[j].first);
                t_mx = max(t_mx, clothes[j].first);
            }
        }
        use[i + 1][1] = t_mn;
        use[i + 1][2] = t_mx;
    }
    //dp[day][前日]
    vector<vector<ll > > dp(D+1, vector<ll >(3, -1));
    dp[0][0] = 0;
    ll ans = 0;
    for(ll i = 0; i < D ; i++){
        for(ll j = 0; j < 3 ; j++){
            for(ll k = 1; k < 3 ; k++){
                if(dp[i][j] == -1)continue;
                if(i == 0){
                    //1日目は無視
                    dp[i + 1][k] = 0;
                    continue;
                } 
                //cout << dp[i][j] << " " << use[i][j]  << " " << use[i+1][k] << endl;
                //更新
                ll t = abs(use[i][j] - use[i+1][k]);
                dp[i + 1][k] = max(dp[i][j] + t, dp[i + 1][k]);
                ans = max(dp[i + 1][k], ans);
                //cout << dp[i + 1][k]  << endl;
            }      
        }    
    }
    
    /*
    for(ll i = 0; i <= D ; i++){
        for(ll j = 0; j < 3 ; j++){
            cout << dp[i][j] << " ";   
        }  
        cout << endl;  
    }
    */
    cout << ans << endl;

}