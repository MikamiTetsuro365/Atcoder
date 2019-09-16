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
#include <queue>

using namespace std;
typedef long long int ll;

int main(){

    ll N;
    cin >> N;
    vector<ll > A(2 * N, 0);
    for(ll i = 0; i < 2 * N; i++){
        cin >> A[i];  
    }
    sort(A.rbegin(), A.rend());
    
    ll ans = 0;
    //大きいやつは大きいやつと組ませるとお得
    for(ll i = 1; i < 2 * N; i+=2){
        ans += A[i];  
    }

    cout << ans << endl;


} 