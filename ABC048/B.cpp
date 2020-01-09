#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//境界値が糞
//a==bならbが割り切れるかどうかだけ気にすると良い
//それ以外は bまでで割り切れる数からa-1までで割り切れう数を引く
//a-1が0になるときに気をつける
int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    if(a == b){
        //bが割り切れるなら1割り切れないなら0
        if(b % x == 0){
            cout << 1 << endl;
            return 0;
        }else if(b % x > 0){
            cout << 0 << endl;
            return 0;
        }
        
        return 0;
    }
    
    if(a <= 0){
        cout << b / x + 1 << endl;
    }else{
        a--;
        cout << (b / x) - (a / x) << endl;
    }

}