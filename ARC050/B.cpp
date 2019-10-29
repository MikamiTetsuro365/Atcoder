#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 9223372036854775807;

bool check(ll R, ll B, ll x, ll y, ll mid){
    //作ろうとしている個数=mid
    ll sum = (R - mid) / (x - 1) + (B - mid) / (y - 1); 
    //個数がおかしくなるのでマイナスになったらやめる
    if(R - mid < 0 || B - mid < 0 ) return false;
    //cout << sum << endl;
    if(sum >= mid) return true;

    return false;
}

int main(){

    ll R, B, x, y; cin >> R >> B >> x >> y;

    ll left = 0; ll right = INF;

    //作れる花束の最大値を求める
    //leftをmidにそろえていく
    while(left + 1 < right){
        ll mid = (left + right) / 2;
        if(check(R, B, x, y ,mid)){
            left = mid;
        }else{
            right = mid;
        }
    }

    cout << left << endl;
}