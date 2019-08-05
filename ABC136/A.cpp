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

    ll A, B, C;

    cin >> A >> B >> C;

    ll ans = C - (A - B);
    if(ans < 0){
        cout << 0 << endl;
        return 0;
    }

    cout << ans << endl;
    

}