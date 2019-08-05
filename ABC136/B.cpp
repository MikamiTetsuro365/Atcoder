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

    ll N;

    cin >> N;
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        string s = to_string(i);
        if(s.length() % 2 == 1){
            ans++;
        }
    }

    cout << ans << endl;




} 