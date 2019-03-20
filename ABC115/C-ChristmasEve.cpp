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


using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;
    vector<ll > h;
    
    ll t = 0;

    for(ll i = 0; i < N ; i++){
        cin >> t;
        h.push_back(t);
    }
    sort(h.begin(),h.end());
    ll mn = h[K-1] - h[0];
    for(ll i = K - 1; i < N ; i++){
        //cout << h[i] << ":" << h[i-K+1] << endl;
        if(mn > h[i] - h[i-K+1]) mn = h[i] - h[i-K+1];
    }

    cout << mn << endl;


}