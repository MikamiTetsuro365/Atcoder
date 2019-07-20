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
    ll X, Y;
    cin >> X >> Y;
    ll x = X;
    ll y = Y;

    if(X < Y){
        swap(X, Y);
        swap(x, y);
        swap(A, B);
    }

    ll ans = 0;
    for(ll i = 0; i < max(X, Y); i++){
        if(y == 0){
            break;
        }
        if(A + B > 2 * C && x > 0 && y > 0){
            ans += 2 * C;
        }else{
            ans += A + B;
        }

        x--;
        y--;
    }

    for(ll i = 0; i < x; i++){
        if(A > 2 * C){
            ans += 2 * C;
        }else{
            ans += A;
        }
    }

    cout << ans << endl;

} 