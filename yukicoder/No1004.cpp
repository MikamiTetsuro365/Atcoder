#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll a, b, x, N;
    cin >> a >> b >> x >> N;

    //高橋先手
    //x0が偶数の時
    //奇数→偶数→奇数．．．
    //x0が奇数の時
    //偶数→奇数→偶数．．．
    //偶数マスか奇数マスに止まり続ける
    //奇数マスに止まる方は，奇数→偶数（奇数＋奇数）→ 奇数(奇数＋偶数)となって必ずペアができる

    if(x % 2 == 0){
        cout << 0 << " " << N / 2 << endl;
    }else{
        cout << N / 2 << " " << 0 << endl;
    }

}