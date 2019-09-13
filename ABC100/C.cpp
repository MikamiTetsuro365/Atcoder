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
ll N;

int main(){

    ll N = 0;
    cin >> N;
    vector<ll > A(N);

    vector<ll > even;

    //偶数だけ取り出す
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        if(A[i] % 2 == 0){
            even.push_back(A[i]);
        }
    }

    
    sort(even.begin(), even.end());

    if(even.size() == 0){
        cout << "0" << endl;
        return 0;
    }

    ll ans = 0;
    ll three_count = 0;
    for(ll i = 0; i < even.size(); i++){
        ll cn = 0;
        for(ll j = even[i]; j > 0; j /= 2){
            if(j % 2 == 1){
                break;
            }
            cn++;         
        }
        ans += cn; 
    }

    cout << ans << endl;
    /* 
    ll cn = 0;
    for(ll i = 1000000000; i > 0; i /= 2){
        cn++;
    }
    cout << cn << endl;
    */
}