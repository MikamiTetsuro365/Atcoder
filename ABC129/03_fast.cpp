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

using namespace std;
typedef long long ll;
ll sum = 0;

int main(){
    ll N, M;
    ll waru = 1000000007;
    cin >> N >> M;
    //範囲外にぶっとばないように
    vector <ll > a(N + 2, 0);

    ll m = 0;
    for(ll i = 0; i < M; i++){
        cin >> m;
        a[m] = -1;
    }

    //vector<vector<ll > > dp(N, vector<ll >(N + 1, -1));
    a[0] = 1;

    for(ll i = 0; i < N; i++){
        if(a[i] == -1){
            continue;
        }
        if(a[i + 1] != -1){
            a[i + 1] += a[i];
            a[i + 1] %= waru;
        }
        if(a[i + 2] != -1){
            a[i + 2] += a[i];
            a[i + 2] %= waru;
        }
    }

    cout << a[N] << endl;

} 