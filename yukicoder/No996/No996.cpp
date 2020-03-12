#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//ふわっと！！！ふわっと！！全探査！
int main(){

    ll T;
    cin >> T;

    vector<ll > ans;
    for(ll i = 0; i < T; i++){
        vector<ll > ABC(3, 0);
        cin >> ABC[0] >> ABC[1] >> ABC[2];
        //順列生成の準備
        vector<ll > J(3, 0);
        J[0] = 0; J[1] = 1; J[2] = 2;
        
        ll mn = INF;
        do{
            ll ans = 0;
            //真ん中は最小か最大のポジションにつかないといけない
            if(J[1] == 1) continue;
            else if(J[0] == 1){
                //Bを最小に揃える
                //B<*<* 右端から揃えていく
                if(ABC[J[2]] <= 2) continue;
                ans += max(0LL, ABC[J[1]]-ABC[J[2]]+1);
                ll nxt = ABC[J[1]] - ans;
                if(nxt <= 1) continue;
                ans += max(0LL, ABC[1]   -nxt      +1);
            }else if(J[2] == 1){
                //Bを最大に揃える
                //*<*<B 右端から揃えていく
                if(ABC[1] <= 2) continue;
                ans += max(0LL, ABC[J[1]]-ABC[1]+1);
                ll nxt = ABC[J[1]] - ans;
                if(nxt <= 1) continue;
                ans += max(0LL, ABC[J[0]]-nxt   +1);    
            }

            //cout << ans << endl;
            mn = min(mn, ans);

        }while(next_permutation(J.begin(), J.end()));   

        if(mn == INF) cout << -1 << endl;
        else cout << mn << endl; 

    }

}