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

    ll N = 0;
    cin >> N;
    
    vector<ll > p(N,0);
    for(ll i = 0; i < N; i++){
        cin >> p[i];
    }

    sort(p.begin(),p.end());

    ll total = 0;
    for(ll i = 0; i < N-1; i++){
        total += p[i];
    }  
    total += p[p.size()-1] / 2;

    cout << total << endl;


}