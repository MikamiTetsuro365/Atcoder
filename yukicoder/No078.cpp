#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

//たかだか2回目までのシミュレーションで買う回数が決め打ちできるっぽい
//1箱目を買い切るだけで後はあたりだけで無限に買えるなら2箱目で買うタイミングは発生しない
//1箱目を買いきってもほそぼそと2箱目でも買う必要があるときもある
//なので1箱目と2箱目をシミレーションして買うタイミングと買わないタイミングを記憶しておく
//後はそれらを使って答えを出す
//境界値がめんどくさいゾ
int main(){

    ll N, K; cin >> N >> K;
    string s; cin >> s;
    
    ll buyCn1 = 0;
    ll buyCn2 = 0;
    ll freeGet = 0;

    //1回目シミュレート買うタイミングと無料で貰えるタイミングを記録
    vector<ll > onetime(N, 0);
    vector<ll > twotime(N, 0);
    
    for(ll i = 0; i < N; i++){
        if(freeGet == 0){
            buyCn1 += 1;
            onetime[i] = 1;
            if(s[i] == '1'){
                freeGet += 1;
            }else if(s[i] == '2'){
                freeGet += 2;
            }
        }else if(freeGet > 0){
            onetime[i] = 0;
            freeGet--;
            if(s[i] == '1'){
                freeGet += 1;
            }else if(s[i] == '2'){
                freeGet += 2;
            }           
        }
    }
    
    //確認
    /*
    for(ll i = 0; i < N; i++){
        cout << onetime[i] << endl;
    }
    */

    //2回目
    for(ll i = 0; i < N; i++){
        if(freeGet == 0){
            buyCn2 += 1;
            twotime[i] = 1;
            if(s[i] == '1'){
                freeGet += 1;
            }else if(s[i] == '2'){
                freeGet += 2;
            }
        }else if(freeGet > 0){
            twotime[i] = 0;
            freeGet--;
            if(s[i] == '1'){
                freeGet += 1;
            }else if(s[i] == '2'){
                freeGet += 2;
            }           
        }
    }
    
    //答え算出
    //境界値に注意

    if(buyCn2 == 0){
        //1箱目を買うと後は無限にあたりだけで手に入る時
        ll ans = 0;
        if(N > K){
            //何回買うタイミングがあるか
            for(ll i = 0; i < K; i++){
                if(onetime[i] == 1){
                    ans++;
                }
            }
            cout << ans << endl;
            return 0;
        }else{
            cout << buyCn1 << endl;
        }
    }else{
        //2箱目以降にほそぼそと買うタイミングがあるとき
        ll ans = 0;
        if(N > K){
            for(ll i = 0; i < K; i++){
                if(onetime[i] == 1){
                    ans++;
                }
            }
            cout << ans << endl;
            return 0;
        }else{
            //最初と中間の箱で買うタイミング
            ans += buyCn1 + (K - N) / N * buyCn2;
            //最後の箱で買うタイミング
            if((K - N) % N > 0){
                for(ll i = 0; i < (K - N) % N; i++){
                    if(twotime[i] == 1){
                        ans++;
                    }
                }                
            }

            cout << ans << endl;
        }
    }

    //確認
    /*
    for(ll i = 0; i < N; i++){
        cout << twotime[i] << endl;
    }
    */

}