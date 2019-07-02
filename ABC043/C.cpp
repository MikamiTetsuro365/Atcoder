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

int main(){

    ll N = 0;
    cin >> N;
    vector<ll > a(N);
    for(ll i = 0; i < N; i++){
        cin >> a[i];
    }

    ll cost = 0;
    ll ans = 1145141919;
    for(ll i = -100; i <= 100; i++){
        for(ll j = 0; j < N; j++){
            cost += pow(a[j] - i, 2);
        }
        //cout << cost << endl;
        ans = min(cost, ans);
        cost = 0;
    }

    cout << ans << endl;

} 