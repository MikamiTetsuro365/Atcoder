#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//中学高校受験でよくあるN！に対して0はいくつ続くかという問題の類題
//今回はN!ではなくN(N-2)(N-4)みたいに2個飛ばしになっている
//つまり，2，4，6...を2で割ってみるとN/2!であることがわかるので
//あとは2と5の素因数の指数の個数の少ない方を取る
//ただし，よく考えると絶対に2の指数部のほうが多くなるので5の指数部の数だけみる
int main() {

    ll N = 0;
    cin >> N;

    //奇数のときは2の素因数が現れなくて10が作れないので駄目
    if(N % 2 == 1){
        cout << 0 << endl;
        return 0;
    }

    N /= 2;

    ll ans = 0;
    //N/2までで5で割れるものがいくつあるか...5^2は...5^3は...
    while(N > 0){
        N /= 5;
        ans += N;
    }

    /*
    ll waru = 5;
    while(N / waru != 0){
        ans += waru;
        waru *= 5;
    }
    */

    cout << ans << endl;
}