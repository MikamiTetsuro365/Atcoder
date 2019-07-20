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

    ll N;
    cin >> N ;
    vector<pair<ll , ll>> A(N);
    //cout << 3 * pow(A,2) << endl;

    for(int i = 0; i < N; i++){
        ll a = 0;
        cin >> a;
        A[i] = make_pair(a, i);
    }
    sort(A.rbegin(), A.rend());
    
    for(int i = 0; i < N; i++){
        if(A[0].second == i){
            cout << A[1].first << endl;
        }else{
            cout << A[0].first << endl;
        }
        
    }


}