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
#include <queue>
#include <functional> 

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

int main(){
    //大きいものは大きい者同士で組んで，それに加えて一番小さいものをペアにするイメージ
    ll N;
    cin >> N;

    vector<ll > P(3 * N, 0);

    for(ll i = 0; i < 3 * N; i++){
        cin >> P[i];
    }


    sort(P.rbegin(), P.rend());

    /*for(ll i = 0; i < 3 * N; i++){
        cout << P[i] << " ";
    }
    cout << endl;
     */
    ll ans = 0;
    for(ll i = 1; i < 2 * N; i += 2){
        //cout << P[i] << endl;
        ans += P[i];
    }

    cout << ans << endl;


} 