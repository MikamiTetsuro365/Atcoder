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

    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    for(ll i = A; i <= B; i++){
        string s = to_string(i);
        if(s[0] == s[4] && s[1] == s[3]){
            ans++;
        }
    }

    cout << ans << endl;

} 