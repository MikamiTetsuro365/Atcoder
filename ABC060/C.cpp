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
typedef long long ll;
ll N;

int main(){

    ll N, T;
    cin >> N >> T;

    vector<ll > t(N);

    for(ll i = 0; i < N; i++){
        cin >> t[i];
    }
    //バグらせ防止
    t.push_back((ll)114514191919);
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        //出る水はTを超えない t[i] - t[i-1]の秒数がTより大きかったらTまでしか流れない
        ans += min(T, t[i] - t[i-1]);
    }

    cout << ans << endl;

}