#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
//最大の価値の硬貨でどんよくにとる→罠にかかりましたこれはN=12のような例で間違う
//N = 12 わいのやりかただと10→1→1となるが本当は6+6が正しい...
int main(){

    ll N;
    cin >> N;

    //vector<ll > ans(n, 0);
    ll t_value = 0;
    ll num = 1;
    ll mx = pow(10,7);
    vector<ll > value;
    while(t_value <= N){
        t_value = num * (num + 1) / 2;
        num++;
        if(t_value <= N) {
            //cout << num << " " << t_value << endl;
            value.push_back(t_value);
        }
    }

    reverse(value.begin(), value.end());
    
    vector<vector<ll > > dp(5000, vector<ll >(value.size(), 0));
    dp[1][0] = value[0];
    
    for(ll i = 1; i < 5000; i++){
        //cout << i << endl;
        for(ll j = 0; j < value.size(); j++){
            //cout << j << endl;
            if(dp[i][j] == 0) continue;
            if(dp[i][j] == N){
                cout << i << endl;
                return 0;    
            }
            for(ll k = 0; k < value.size(); k++){
                if(dp[i][j] + value[k] > N){
                    //cout << dp[i][j] << endl;
                    continue;
                }
                if(dp[i][j] + value[k] == N){
                    cout << i + 1 << endl;
                    return 0;
                }
                //cout << value[k] << endl;
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + value[k]);
            }

        }
    }

}