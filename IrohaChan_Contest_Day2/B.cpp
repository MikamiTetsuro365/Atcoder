#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//直線の交差判定
//ある直線を堺に2点の符号が逆転していれば交差している
//符号が同じなら交差していない
//直線の方程式から導出できる（当然

bool check(ll x1, ll x2, ll y1, ll y2, ll tx1, ll tx2, ll ty1, ll ty2){
    ll ta = (x1-x2)*(ty1-y1)+(y1-y2)*(x1-tx1);
    ll tb = (x1-x2)*(ty2-y1)+(y1-y2)*(x1-tx2);

    if(ta * tb < 0){
        //交差してる
        return true;
    }else{
        //交差してない
        return false;
    }
}

int main() {

    ll X, Y, A, B, sx, sy, tx, ty;
    cin >> X >> Y >> A >> B >> sx >> sy >> tx >> ty;

    if(check(0, X, A, B, sx, tx, sy, ty)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


}