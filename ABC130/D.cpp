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

int main(){
    
    //cin >> N;
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N, 0);
    
    for(ll i = 0; i < N; i++){
        cin >> a[i];
    }

    ll right = 0;
    ll temp = 0;
    ll ans = 0;
    ll sum = 0;

    //しゃくとり方
    for(int left = 0; left < N; ++left){
        
        /* [left, right) の総和が x 以上となる最小の right を求める */
        while (right < N && sum < K) {
            sum += a[right];
            ++right;
            //cout << K << "=" << sum << " ";
            
        }

        if(sum >= K){
            ans += N - right + 1;
        }
    
        sum -= a[left];

    }

    cout << ans << endl; 



} 