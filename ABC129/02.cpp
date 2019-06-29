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
    vector <ll > s(N, 0);
    ll s1 = 0;
    ll s2 = 0;
    for(ll i = 0; i < N; i++){
        cin >> s[i];
        s2 += s[i];
    }
    //sort(s.begin(), s.end());

    ll ans = s2;
    for(ll i = 0; i < N - 1; i++){
        s1 += s[i];
        s2 -= s[i];
        //cout << s1 << "," << s2 << endl;
        ans = min(abs(s1 - s2), ans);
        
    }

    cout << ans << endl;

} 