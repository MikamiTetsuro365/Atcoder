#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll A, B, C;
    cin >> A >> B >> C;

    ll i = 0;
    ll ans = 0;
    while(C > 0){
        ans++;
        i++;
        if(i == 7){
            C -= B;
            i = 0;
        }
        C -= A;
    }

    cout << ans << endl;

}