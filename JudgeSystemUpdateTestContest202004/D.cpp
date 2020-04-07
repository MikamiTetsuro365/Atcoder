#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
vector<ll > A;
vector<ll > r_gcd;
ll N, Q;

//入れ替える＝別に重要じゃない
//累積ワGCDとSのGCDは↑と同じ意味になるので
ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

ll solve(ll S){
    ll l = 0; ll r = N;
 
    while(l + 1 < r){
        ll mid = (l + r) / 2;
        //cout << S << " " <<  l << " " << r << endl;
        if(gcd(S, r_gcd[mid]) == 1){
            r = mid;
        }else{
            l = mid;
        }
    }

    return l;
}

int main(){

    cin >> N >> Q;

    A.assign(N, 0);
    r_gcd.assign(N, 0);
    
    //前処理
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    for(ll i = 0; i < N; i++){
        if(i == 0) r_gcd[i] = A[i];
        else r_gcd[i] = gcd(r_gcd[i-1], A[i]);
        //cout << r_gcd[i] << endl;
    }
    r_gcd.push_back(1);

    for(ll i = 0; i < Q; i++){
        ll S; cin >> S;
        ll ans = solve(S);
        //cout << ans << endl;

        ll num = gcd(r_gcd[ans],S);
        if(ans+1 == N){
            if(num == 1) cout << ans+1 << endl;
            else cout << num << endl;
        }else{
            if(num == 1) cout << ans+1 << endl;
            else{
                ll num2 = gcd(r_gcd[ans],S);
                if(num2 == 1) cout << ans << endl;
                else cout << ans+2 << endl;
            }
        }

    }

}