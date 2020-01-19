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

    ll N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    //番兵
    S += '*';

    //どこを反転させても幸せ度は最大2しか変わらない
    //端っこを選ぶと1しか変わららない
    //なるべく真ん中をRかLに変更することを考えてみる
    //後は貪欲に向きを変更できるだけ変更する
    ll ans = 0;
    bool f = false;
    for(ll i = 1; i < S.length(); i++){
        if(S[i] == '*') break;
        if(S[i-1] == S[i]){
            ans++;
        }else{
            if(f == false){
                if(K > 0){
                    ans++;
                    K--;
                    f = true;
                }
            }else{
                f = false;
                ans++;
            }
        }
    }    

    cout << ans << endl;

}