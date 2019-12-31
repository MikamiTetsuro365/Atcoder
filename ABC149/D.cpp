#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<ll > ruiseki;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll N, M;

//3手先まで読んで判断する
//負けても減点にはならない
int main() {

    ll N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;

    map<char, ll > mp;
    mp['r'] = R;
    mp['s'] = S;
    mp['p'] = P;

    //R=ぐー　S=ちょき　P=ぱー
    string T;
    cin >> T;

    //自分の出した手
    vector<char > hoge(N);

    ll ans = 0;
    for(ll i = 0; i < K; i++){
        ll cn = 0;
        for(ll j = i; j < N; j += K){
            //cout << cn << endl;
            if(j != i){
                //cout << "koko" << endl;
                if(T[j] == T[j-K]){
                    if(cn % 2 == 1){
                        hoge[j] = '*';
                        //cout << "same" << endl;
                        cn++;
                        continue;
                    }
                }else{
                    cn = 0;
                }
            }
            if(T[j] == 'r'){
                //グーを出されたらパーで勝つ
                ans += P;
                hoge[j] = 'p';
            }else if(T[j] == 's'){
                //チョキを出されたらグーで勝つ
                ans += R;
                hoge[j] = 'r';
            }else if(T[j] == 'p'){
                //パーを出されたらチョキで勝つ
                ans += S;
                hoge[j] = 's';
            }
            cn++;
        }
    }

    ll ans2 = 0;
    for(ll i = 0; i < N; i++){
        //cout << hoge[i] << " ";
        ans2 += mp[hoge[i]];
    }
    //cout << endl;

    cout << ans2 << endl;

}
