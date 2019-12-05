#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
//反省:方眼用紙を使えgi
int main(){

    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    ll A1 = t1 * a1;
    ll A12 = A1 + t2 * a2;
    ll B1 = t1 * b1;
    ll B12 = B1 + t2 * b2;

    //無限に続く
    if(A12 == B12){
        cout << "infinity" << endl;
        return 0;
    }

    if(A12 < B12){
        swap(A12, B12);
        swap(A1, B1);
    }

    ll ans = 0;
    if(A1 > B1){
        //永遠に交わらない
        cout << "0" << endl;
    }else if(A1 < B1){
        //何回BがAを追い越してAがBを追い越しての周期が繰り返せるか
        //1周期で2回の交点が生まれる
        ans = (B1-A1) / (A12-B12)  * 2 + 1;

        if((B1-A1) % (A12-B12) == 0){
             //ちょうど0になって終わるとその周期は1回しか交点が生まれないので
            ans--;
        }
        cout << ans << endl;
    }
}