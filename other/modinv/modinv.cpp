#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

pair<ll, ll > extgcd(ll a, ll b){
    ll s, t, sx, sy, tx, ty;
    s = a; t = b; sx = 1; sy = 0; tx = 0; ty = 1;

    while(s % t != 0){
        ll temp = s / t;
        ll u = s - t * temp;
        ll ux = sx - tx * temp;
        ll uy = sy - ty * temp;

        s = t;
        sx = tx;
        sy = ty;
        t = u;
        tx = ux;
        ty = uy;
    }

    //逆元
    return {tx, ty};
}

int main(){
    pair<ll, ll> xy;
    ll a = 111;
    ll b = 30;
    xy = extgcd(a, b);
    cout << xy.first << " " << xy.second << endl;
}