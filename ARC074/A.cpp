#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    ll H, W;
    cin >> H >> W;
    //3の倍数ならそりゃうまくいく
    if(H % 3 == 0 || W % 3 == 0){
        cout << 0 << endl;
        return 0;
    }

    if(H == W){
        cout << H / 2 - 1 << endl;
        cout << (W * (H / 2 - 1)) - (W / 2 * (H / 2 + 1)) << endl;
        return 0;
    }

    ll ans = 0;
    //縦に割ってみる
    ll tH = H / 2;
    if(H % 2 == 1){
        tH++; 
    }
    ll Tmax = W * H / 2;
    //残り
    ll Tmin = (W / 2) * (tH);
    ans = Tmax - Tmin;

    //横に割ってみる
    ll tW = W / 2;
    if(W % 2 == 1){
        tW++; 
    }
    ll Wmax = W / 2 * H;
    //cout << Wmax << endl;
    ll Wmin = (tW) * (H / 2);

    //cout << tW << " " << H / 2 << endl;

    ans = min(ans, Wmax-Wmin);

    cout << ans << endl;

}