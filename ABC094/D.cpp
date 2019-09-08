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

//最大の中央値に近いものを選ぶと最大になるぞいというお気持ち
int main(){

    ll N = 0;
    cin >> N;
    vector<double > A(N);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    double max =  A[A.size()-1];
    double center = max / 2;
    double sa = 1145141919;
    ll ans = A[0];
    //cout << center << endl;
    for(ll i = 0; i < N - 1; i++){
        if(abs(A[i] - center)  < sa){
            sa = abs(A[i] - center);
            ans = A[i];
        }
    }    

    cout << (ll)max << " " << (ll)ans << endl;

} 