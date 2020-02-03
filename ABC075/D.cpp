#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 9223372036854775807;

//x座標の組み合わせで左右の長さが決まる
//y座標の組み合わせで上下の長さ決まる
//たかだかそのへんの組み合わせ分だけの長方形を考えると良さそう
//それらの組み合わせの中に内包されている座標はいくつ？
//5重ループ！！くそ
//XとY独立して考えないとだめだった
//統一して考えると選んだ2点のXとYが必ず左上右下とは限らない

//入力
ll N, K;
vector<ll > X;
vector<ll > Y;
ll check(ll x1, ll x2, ll y1, ll y2){
    ll cn = 0;
    for(ll k = 0; k < N; k++){
        ll xk = X[k];
        ll yk = Y[k];
        if(xk >= x1 && xk <= x2 && yk >= y1 && yk <= y2){
            cn++;
        }        
    }
    return cn;
}

int main(){

    cin >> N >> K;

    for(ll i = 0; i < N; i++){
        ll a, b; cin >> a >> b;
        X.push_back(a);
        Y.push_back(b);
    }
    //ソートしたら位置関係崩れる！(キレ)
    //sort(X.begin(), X.end());
    //sort(Y.begin(), Y.end());

    ll ans = INF;
    for(ll x1 = 0; x1 < N; x1++){
        for(ll x2 = x1 + 1; x2 < N; x2++){
            for(ll y1 = 0; y1 < N; y1++){
                for(ll y2 = y1 + 1; y2 < N; y2++){
                    ll tx1 = X[x1];
                    ll tx2 = X[x2];
                    ll ty1 = Y[y1];
                    ll ty2 = Y[y2];

                    //位置関係は判定のために統一しましょう
                    if(tx1 > tx2) swap(tx1, tx2); 
                    if(ty1 > ty2) swap(ty1, ty2); 
                    
                    ll cn = check(tx1, tx2, ty1, ty2);
                    if(cn >= K) ans = min(ans, (tx2-tx1)*(ty2-ty1));
                }
            }
        }
    }

    cout << ans << endl;

}