#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <sstream>
#include <istream>
#include <iomanip>
#include <typeinfo>
#include <stack>
#include <map> 
#include <queue>

using namespace std;
typedef long long ll;
ll N, M;

//数列の最大公約数を最大にするには
//数列上の任意の数字を一つ取り除いたときの数列の最大公約数が最大になればよい

ll GCD(ll a, ll b){
    return b ? GCD(b, a % b) : a;
}

int main(){

    cin >> N;
    vector<ll > v(N, 0);


    for(ll i = 0; i < N; i++){
        cin >> v[i];
    }

    vector<ll > left(N + 1, 0);
    vector<ll > right(N + 1, 0);
    
    //GCDを左右から求める
    //left[0] = 0 left[1] = 0 と　数列v[0]の最大公約数つまりv[0]
    //left[2] = GCD(v[0], v[1])
    for(ll i = 0; i < N; i++){
        left[i + 1] = GCD(left[i], v[i]);
        //cout << v[i] << endl;
    }
    //leftの反対
    for(ll i = N - 1; i >= 0; i--){
        right[i] = GCD(right[i + 1], v[i]);
        //cout << v[i] << endl;
    }  


    ll ans = 0;
    //GCD(left[0], left[1]) >>> v[0]を穴あきにしたときの数列の最大公約数を調べる
    //GCD(left[1], left[2]) >>> v[1]を穴あきにしたときの数列の最大公約数を調べる
    for(ll i = 0; i < N; i++){
        ans = max(ans, GCD(left[i], right[i + 1]));
    }

    cout << ans << endl;


}