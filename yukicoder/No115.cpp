#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//a円の商品を買ったと仮定した時，残りの金額D-a円と購入数K-1を使って
//a+1~N円の商品をちょうどK-1個買えますか？を調べる
//そもそも金額が小さい順にK個買った時にD円を超えると適切な選び方はないし
//大きい順に買ってもD円を超えなければ適切な選び方はない
//↑の2つの制限を守れば，自由に条件を満たすようなとり方ができる
//http://sugarknri.hatenablog.com/entry/2016/04/22/215308
ll N, D, K;

bool check(ll p, ll d, ll k){
    //下限
    ll mn = 0;
    //上限
    ll mx = 0;

    for(ll i = 0; i < k; i++){
        mn += p + i;
        mx += N - i;
    }

    if(mn <= d && mx >= d) return true;
    else return false;
}

int main() {

    cin >> N >> D >> K;
    ll k = K;
    vector<ll > ans;
    if(check(1, D, k)){
        for(ll i = 1; i <= N; i++){
            if(K <= 0) break;
            if(check(i+1, D-i, k-1)){
                ans.push_back(i); 
                D -= i;
                k -= 1;
            }
        }
        //表示
        for(ll i = 0; i < K; i++){
            cout << ( i ? " " : "" ) << ans[i];
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }


    return 0;

    // for(ll k = 1; k <= N; k++){
    //     bool f = false;
    //     vector<ll > ans;
    //     ll cn = 0;
    //     ll DD = D;
    //     for(ll i = k; i <= N; i++){
    //         if(cn < K-2){
    //             ans.push_back(i);
    //             DD -= i;
    //             cn++;
    //         }else{
    //             //cout << D << " " << i << endl;
    //             if(DD - i > i && DD - i <= N ){
    //                 ans.push_back(i);
    //                 ans.push_back(DD-i);
    //                 cn += 2;
    //                 f = true;
    //                 break;
    //             }
    //         }
    //     }
    //     if(f == true){
    //         for(ll i = 0; i < K; i++){
    //             cout << ( i ? " " : "" ) << ans[i];
    //         }
    //         cout << endl;
    //         return 0;
    //     }
    // }


    // cout << -1 << endl;
    // return 0;

}