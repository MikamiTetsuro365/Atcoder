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
//きれいに書き直し
int main(){

    ll N , K;
    cin >> N >> K;

    //例外
    if(K == 0){
        cout << N * N << endl;
        return 0;
    }

    ll ans = 0;

    for(ll i = 1; i <= N; i++){
        // iの倍数間の塊でどれくらいK以上のあまりが発生するか
        ans += max((ll)0, i - K) * (N / i);
        //残りの中にどれくらいK以上が残されているか
        //+1＝以上だょ
        ans += max((ll)0, N % i - K + 1);
    }

    cout << ans << endl;
} 