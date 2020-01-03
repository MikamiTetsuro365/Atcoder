#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
//プライオリティキューを使うと要素を入れてだすだけで大きい順にK個揃う

int main() {

    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;

    vector<ll > A(X,0);
    vector<ll > B(Y,0);
    vector<ll > C(Z,0);

    for(ll i = 0; i < X; i++){
        cin >> A[i];
    }

    for(ll i = 0; i < Y; i++){
        cin >> B[i];
    }

    for(ll i = 0; i < Z; i++){
        cin >> C[i];
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    priority_queue<pair<ll ,vector<ll > > > que;
    //初期値
    //入力A,B,Cは降順にソートされているのでA=1,B=1,C=1が最大なのは既知
    que.push(make_pair(A[0]+B[0]+C[0], vector<ll >({0, 0, 0})));

    //プライオリティキューに一度入れてるかどうかのチェック用
    map<vector<ll >, ll > check;
    //初期値
    check[vector<ll >({0, 0, 0})] = 1;
    //それぞれの要素数チェック用
    vector<ll > XYZ = {X,Y,Z};

    for(ll i = 0; i < K; i++){
        cout << que.top().first << endl;
        //一番上は表示済みで用済みなので出す
        vector<ll > tmp = que.top().second;
        que.pop();
        //次の候補をキューに加える
        //候補はA,B,Cのindexをそれぞれ1加えたものなので3つある
        //先にキューに入っているものや外に出したものと重複が発生するのでそれらを除く
        for(ll j = 0; j < 3; j++){
            vector<ll > idx = tmp;
            idx[j] += 1;
            //使えない要素の位置を参照していたら飛ばす（バグのもと！）
            if(XYZ[j] <= idx[j]) continue;

            //すでに追加済みなら飛ばす
            //cout << idx[0] << " " << idx[1] << " " << idx[2] << endl;
            //cout << check[idx] << endl;
            if(check[idx] == 1) continue;

            check[idx] = 1;
            que.push(make_pair(A[idx[0]]+B[idx[1]]+C[idx[2]], idx));
            
            //cout << A[idx[0]]+B[idx[1]]+C[idx[2]] << endl;
        }
    }
}