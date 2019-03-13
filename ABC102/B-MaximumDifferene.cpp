#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;

ll N = 0;

int main(){

    cin >> N;

    vector<ll > A;

    ll t  = 0;
    ll m  = 0;

    for(int i = 0; i < N; i++){
        cin >> t;
        A.push_back(t);
    }

    ll min = *std::min_element(A.begin(), A.end());
    ll max = *std::max_element(A.begin(), A.end());
    m = abs(min - max);

    cout << m << endl;
}