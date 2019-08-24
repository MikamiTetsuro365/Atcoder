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

using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;
    vector<ll > A;

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll temp = 0;
        cin >> temp;
        A.push_back(temp);
        if(i == 0) continue;
        for(ll j = 0; j < A.size() - 1; j++){
            if(A[j] > temp){
                ans++;
            }
        }
        
    }
    /* 
    ll O = 0;
    for(ll i = 1; i <= 2000; i++){
        //cout << i << endl;
        O += i;
    }
    */
    //sort(A.begin(), A.end());

    //while(!que.empty)
    cout << ans << endl;

    ll num = 0;
    for(ll i = 1; i <= K; i++){
        num += (ans * i) % 1000000007;
    }  

    cout << num << endl;

}