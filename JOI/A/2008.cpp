#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){
    ll N; cin >> N;
    ll zan = 1000 - N;

    ll ans500 = zan / 500;

    if(zan - 500 * ans500 >= 0){
        zan -= 500 * ans500;
    }

    ll ans100 = zan / 100;

    if(zan - 100 * ans100 >= 0){
        zan -= 100 * ans100;
    }

    ll ans50 = zan / 50;

    if(zan - 50 * ans50 >= 0){
        zan -= 50 * ans50;
    }

    ll ans10 = zan / 10;

    if(zan - 10 * ans10 >= 0){
        zan -= 10 * ans10;
    }

    ll ans5 = zan / 5;

    if(zan - 5 * ans5 >= 0){
        zan -= 5 * ans5;
    }

    cout << ans500 + ans100 + ans50 + ans10 + ans5 + zan << endl;

}