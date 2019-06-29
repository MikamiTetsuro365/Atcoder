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
    vector <int > s(3, 0);
    cin >> s[0] >> s[1] >> s[2];
    sort(s.begin(), s.end());
    ll ans = s[0] + s[1];

    cout << ans << endl;

} 