#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;

using namespace std;

ll getNum(ll A){
    //Aまでで3または9の倍数がいくつあるか
    //ketaDp[桁数][未満フラグ][3または9の倍数フラグ]
    vector<vector<vector<ll>>> ketaDp(40, vector<vector<ll>>(2, vector<ll>(2, 0)));
    ketaDp[0][0][0] = 1;

    string S = to_string(A);
    //上位桁から走査
    for(ll i = 0; i < S.length(); i++){
        ll D = S[i] - '0';
        for(ll j = 0; j < 2; j++){
            for(ll k = 0; k < 2; k++){
                //更新 A（制限）を超えるような更新の仕方はできない
                //true->1 false->0
                //未満ならj=1 未満でないならj=0
                //3か9の倍数ならk=1 違うならk=0
                for(ll d = 0; d <= (j ? 9 : D); d++){
                    //未満から未満へ 1->1
                    //ぴったりから未満へ 0->1
                    //ぴったりからぴったり 0->0
                    //の3つに遷移できる
                   ketaDp[i+1][j || (d < D)][k || d == 4 || d == 9] += ketaDp[i][j][k];
                }
            }
        }
    }

    return ketaDp[S.length()][0][1] + ketaDp[S.length()][1][1];

}

int main(){

    ll A, B;
    //A < B
    cin >> A >> B;

    cout << getNum(B) - getNum(A-1) << endl;

}