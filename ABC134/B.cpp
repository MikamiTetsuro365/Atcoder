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

    ll N, D;
    cin >> N >> D;
    
    ll ans = N / ((D + D) + 1);


    if(N % ((D + D) + 1) > 0){
        ans++;
    }

    cout << ans << endl;

}