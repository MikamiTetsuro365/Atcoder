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

    ll N;
    cin >> N ;

    vector<ll > t(N);

    for(ll i = 0; i < N; i++){
        cin >> t[i];
    }

    sort(t.rbegin(), t.rend());

    ll alice = 0;
    ll bob = 0;

    for(ll i = 0; i < N; i++){
        if(i % 2 == 0){
            alice += t[i];
        }else{
            bob += t[i];
        }
    }

    cout << alice - bob << endl;

}