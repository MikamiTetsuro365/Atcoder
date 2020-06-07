#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N, L;
    cin >> N >> L;

    //調整
    L *= 2;

    //ジャンプ中は除く
    vector<ll > ans(219191, INF);
    //ジャンプ中
    vector<ll > ans2(219191, INF);
    //ハードルの位置
    vector<ll > H(219191, 0);

    for(ll i = 0; i < N; i++){
        ll x;
        cin >> x;
        x *= 2;
        H[x] = -1;
    }

    ll T1, T2, T3;
    cin >> T1 >> T2 >> T3;

    ans[0] = 0;

    for(ll i = 0; i < 200100; i++){
        //行動1
        if(H[i+2] == -1){
            ans[i+2] = min(ans[i+2], ans[i]+T1+T3);
        }else{
            ans[i+2] = min(ans[i+2], ans[i]+T1);
        }
        //行動2
        //途中で立ち寄れるところ(ジャンプ中)
        ans2[i+2] = min(ans2[i+2], ans[i]+ T1/2 + T2/2);
        //着地点
        if(H[i+4] == -1){
            ans[i+4] = min(ans[i+4], ans[i]+ T1 + T2 + T3);
        }else{
            ans[i+4] = min(ans[i+4], ans[i]+ T1 + T2);
        }
        //行動3
        //途中で立ち寄れるところ(ジャンプ中)
        ans2[i+2] = min(ans2[i+2], ans[i]+ T1/2 + T2/2);
        ans2[i+4] = min(ans2[i+4], ans[i]+ T1/2 + T2/2*3);
        ans2[i+6] = min(ans2[i+6], ans[i]+ T1/2 + T2/2*5);
        if(H[i+8] == -1){
            ans[i+8] = min(ans[i+8], ans[i]+ T1 + T2*3 + T3);
        }else{
            ans[i+8] = min(ans[i+8], ans[i]+ T1 + T2*3);
        }
    }

    cout << min(ans[L],ans2[L]) << endl;

}