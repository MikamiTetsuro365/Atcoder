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

    ll N;
    cin >> N;
    if(N == 1){
        cout << 0 << endl;
        return 0;
    }
    N--;
    ll ans =  N * (N + 1);
    ans /= 2;
    cout << ans << endl;

}