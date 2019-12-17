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

    ll N, A, B; cin >> N >> A >> B;

    vector<pair<ll, string> > user;
    //先手で石が取り切れるなら先手が必勝
    if(N <= A){
        cout << "Takahashi" << endl;
        return 0;
    }
    //A==Bのとき
    //残っている石がA+1個だとその石を消費するには2ターン必ずかかる
    //つまり後手がかならず勝つ．この考えを利用する．
    //先手が取った石の数に対して後手がA+1になるような石の取り方が必ずある．
    //ここでNがA+1の倍数なら常に後手は自分の手番で先手と後手が取った石の数をA+1に調整しながら
    //取っていけるので後手が必ず勝てる.
    //次にNがA+1の倍数でなければ，先手はNがまずA+1の倍数になるように調整できる．
    //そして後手の取った石の数にたいして，先手は両者が取った石の合計をA+1に調整していくことで
    //最後には先手が必ず勝てる状態を作り出すことができる.
    //よって,N%(A+1)が0なら後手が勝つ，0でなければ先手が勝つ
    if(A == B){
        if(N % (A + 1) == 0){
            cout << "Aoki" << endl;
        }else{
            cout << "Takahashi" << endl;
        }
    }else if(A > B){
        //先手と後手のとった石をとったあと残りの医師がB+1の倍数かそれ以上になるように先手は調整することができる.
        //先手が負けるには残りの石がB個以内で後手に手番を譲る必要があるが，AはB+1個以上確実に取れるのでそんなことは怒らない
        //A > Bなので
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
}