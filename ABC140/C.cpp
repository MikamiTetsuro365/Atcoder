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

    ll N = 0;
    cin >> N;
    vector<ll > B(N-1);

    for(ll i = 0; i < B.size(); i++){
        cin >> B[i];
        //cout << B[i] << endl;
    }

    //A0格納 
    ll ans = B[0];

    for(ll i = 0; i < B.size() - 1 ; i++){
        //cout << ans << endl;
        if(B[i] <= B[i + 1]){
            ans += B[i];
        }else{
            ans += B[i + 1];
        }
    }
    ans += B[B.size()-1];
    cout << ans << endl;

} 