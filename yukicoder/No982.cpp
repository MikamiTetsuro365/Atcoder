#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

//互いに素な整数同士はax+by=Nであらゆる整数を作れちゃう
//https://examist.jp/mathematics/integer/axby-kouzou/
//(1)aとbが互いに素(GCDが1)のときab+1以上の全ての自然数(1,2,3...)Nはax+byで表せれる
//(1)のとき表せない最大の自然数はab
//(a-1)(b-1)以上の全ての自然数Nは0以上の整数でax+byで表せれる
ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){

    ll A, B;
    cin >> A >> B;

    //非負整数(0以上の整数)
    //つまり(a-1)(b-1)以上の整数は全て作れる
    //作れない整数はaとbの倍数を除いたもの

    if(gcd(A, B) == 1){
        cout << (A-1)*(B-1)/2 << endl;
    }else{
        cout << -1 << endl;
    }

}