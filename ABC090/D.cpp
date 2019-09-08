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

using namespace std;
typedef long long int ll;
//雑コードができあがってしまった．．．
int main(){

    ll N , K;
    cin >> N >> K;

    if(K == 0){
        cout << N * N << endl;
        return 0;
    }

    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        ll re = i - K;
        //あまりが現れない場合は除外
        if(re < 1) continue;
        //確実に取れるのは倍数分
        ans += (N / i) * re ;
        //あまりがあるときどれくらい取れるか
        if(N % i >= 1 && N % i >= i - re){
           //cout << i << endl;
           ans += N % i - (i - re - 1);
        }
        //cout << re << " " <<  ans << endl;
    }

    cout << ans << endl;
} 