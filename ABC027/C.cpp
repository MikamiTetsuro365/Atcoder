#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//無理また考える
int main() {

    ll N;
    cin >> N;

    ll a = 1;
    ll b = 1;

    ll cn = 0;
    while(!(a <= N && b >= N)){
        a *= 2;
        b *= 2;
        b++;
        cout << a << " " << b << endl;
        cn++;
        cout << cn << endl;
    }


    if(cn % 2 == 0){
        cout << "Aoki" << endl;
    }else{
        cout << "Takahashi" << endl;
    }

}