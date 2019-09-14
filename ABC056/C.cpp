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

    ll X = 0;
    cin >> X;

    ll ans = 0;

    ll tmp = 0;
    while(X > tmp){
        if(tmp == X){
            cout << ans << endl;
            return 0;
        }
        tmp += ans;
        ans++;
    }

    cout << ans - 1 << endl;
    return 0;



}