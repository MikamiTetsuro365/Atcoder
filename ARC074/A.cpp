#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

//数学的に解こうとするとハマった
//制約を見ると全探査でも良さそう
//とりあえず適当な場所で折ると2等分問題になる
//2等分はなるべく真中付近で折ると良い
int main(){

    ll H, W;
    cin >> H >> W;
    //3の倍数ならそりゃうまくいく
    if(H % 3 == 0 || W % 3 == 0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = INF;
    //とりあえず縦に割る
    for(ll k = 0; k < 2; k++){
        for(ll i = 1; i <= H - 1; i++){
            //縦縦
            ll t1 = ((H - i) / 2) * W;
            ll t2 = ((H - i) / 2 + (H - i) % 2)  *  W;
            ll tmx = max(W * i, max(t1, t2));
            ll tmn = min(W * i, min(t1, t2));
            ans = min(ans, tmx - tmn);
            
            //縦横
            ll w1 = (H - i) * (W / 2);
            ll w2 = (H - i) * (W / 2 + W % 2);
            ll wmx = max(W * i, max(w1, w2));
            ll wmn = min(W * i, min(w1, w2));
            //cout << wmx - wmn << endl;
            ans = min(ans, wmx - wmn);

        }
        swap(H , W);
    }

    //横に割る
    /*
    for(ll i = 1; i <= W - 1; i++){
        //横横
        ll t1 = ((W - i) / 2) * H;
        ll t2 = ((W - i) / 2 + (W - i) % 2)  *  H;
        ll tmx = max(H * i, max(t1, t2));
        ll tmn = min(H * i, min(t1, t2));
        ans = min(ans, tmx - tmn);
        //cout << tmx - tmn << endl;
        
        //縦縦
        ll w1 = (W - i) * (H / 2);
        ll w2 = (W - i) * (H / 2 + H % 2);
        ll wmx = max(H * i, max(w1, w2));
        ll wmn = min(H * i, min(w1, w2));
        //cout << wmx - wmn << endl;
        ans = min(ans, wmx - wmn);

    }
    */

    cout << ans << endl;

}