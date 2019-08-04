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

    ll N , M;
    cin >> N >> M;

    vector<ll > L(M);
    vector<ll > R(M);
    vector<ll > ans(N, 0);
    for(ll i = 0; i < M; i++){
        cin >> L[i] >> R[i];
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    if(L[M-1] > R[0]){
        cout << 0 << endl;
    }else{
        cout << R[0] - L[M-1] + 1 << endl;
    }

} 