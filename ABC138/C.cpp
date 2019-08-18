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

int main(){

    double N;

    cin >> N;

    vector<double > a(N,0);
    double ans = 0;
    for(ll i = 0; i < N; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ans = a[0];
    for(ll i = 0; i < N - 1; i++){
        ans = (ans + a[i+1]) / 2;
    }
    
    cout << ans << endl;

}