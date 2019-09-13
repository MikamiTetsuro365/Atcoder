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
    //ll P , Q , R;
    //cin >> P >> Q  >> R;

    ll r, D , x;
    cin >> r >> D >> x;
    vector<ll > X;
    X.push_back(x);
    for(ll i = 0; i < 10; i++){
        cout << r * X[i] - D << endl;
        X.push_back(r * X[i] - D);
    }
}