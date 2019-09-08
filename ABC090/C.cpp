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

    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    if(N == 1 && M == 1){
        cout << 1 << endl;
        return 0;
    }
    if(N > M){
        swap(N, M);
    }
    ans = N * M - N * 2 - min((ll)1, N - 1) * max((ll)0, (M - 2) * 2);

    cout << ans << endl;

} 