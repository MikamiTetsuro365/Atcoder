#include "bits/stdc++.h" 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
//ll MOD = 1000000007;
ll INF = 11451419194545;


ll tow_beki[40];
ll tow_beki_r[40];
ll fast_pow(ll a, ll n){
    if(n == 0) return 1;
    //べき数nが奇数, aを前にだして, a^n-1の気持ちに
    if(n % 2 == 1){
        return a * fast_pow(a, n - 1);
    }else{
        //べき数nが偶数のとき，べき数を半分にして, aをまとめる. べき数を半分にする
        return fast_pow(a * a, n / 2);
    }
}

int main() {

    ll T;
    cin >> T;
    //準備
    for(ll i = 0; i < 40; i++){
        tow_beki[i] = fast_pow(2, i);
        if(i == 0){
            tow_beki_r[0] = tow_beki[0];
        }else{
            tow_beki_r[i] = tow_beki_r[i-1] + tow_beki[i];
            //cout << tow_beki_r[i] << endl;
        }
    }

    vector<string > tans;
    for(ll i = 0; i < T; i++){
        ll a, b;
        cin >> a >> b;
        if(abs(a) == abs(b)){
            //cout << "Case #" << i+1 << ":" << " IMPOSSIBLE" << endl;
            tans.push_back("IMPOSSIBLE");
        }else{
            ll sum = abs(a) + abs(b);
            ll idx = 0;
            
            //どこで境界を超えるか
            for(ll j = 0; j < 40; j++){
                if(sum <= tow_beki_r[j]){
                    //cout << tow_beki[j] << endl;
                    idx = j;
                    break;
                }
            }

            //たどっていく
            //大きい方から引いていく
            ll ta, tb;
            ta = a;
            tb = b;
            string ans;
            while(idx >= 0){
                if(abs(ta) < abs(tb)){
                    if(tb > 0){
                        tb -= tow_beki[idx];
                        idx--;
                        ans += 'N';
                        //out << "S" << endl;
                    }else{
                        tb += tow_beki[idx];
                        idx--;   
                        ans += 'S'; 
                        //cout << "N" << endl;                    
                    }
                }else{
                    if(ta > 0){
                        ta -= tow_beki[idx];
                        idx--;
                        ans += 'E';
                        //cout << "E" << endl;
                    }else{
                        ta += tow_beki[idx];
                        idx--; 
                        ans += 'W';   
                        //cout << "W" << endl;                    
                    }                    
                }
            }
            
            if(ta != 0 || tb != 0){
                tans.push_back("IMPOSSIBLE");
            }else{
                reverse(ans.begin(), ans.end());
                tans.push_back(ans);
            }

            //cout << ta << " " << tb << endl;

            //cout << "Case #" << i+1 << ": " << ans << endl;
        }
    }

    for(ll i = 0; i < tans.size(); i++){
        cout << "Case #" << i+1 << ": " << tans[i] << endl;
    }

}