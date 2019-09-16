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

    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<ll > A(Q);

    for(ll i = 0; i < Q; i++){
        cin >> A[i];
    }

    vector<ll > s(N, K);

    ll sum = 0;
    for(ll i = 0; i < Q; i++){
        s[A[i]- 1]++;
        sum++;
    }

    for(ll i = 0; i < N; i++){
        s[i] -= sum;
        if(s[i] <= 0){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }


} 