#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//問題読み間違えた．．．
int main(){

    ll N, K;
    cin >> N >> K;
    //奇数同士を選ぶと最大の選び方ができる
    if(N / 2 + N % 2 >= K){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}