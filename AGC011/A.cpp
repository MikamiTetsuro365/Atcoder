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

    ll N, C , K;
    cin >> N >> C >> K;
    vector<ll > T(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> T[i];  
    }
    sort(T.begin(), T.end());

    ll ans = 0;    

    for(ll i = 0; i < N;){
        ans++;
        ll s = i;
        //K分経つか, バスの上限乗客C人集まったら出発
        while(i < N && T[i] - T[s] <= K && i - s < C){
            i++;
        }
    }


    cout << ans << endl;


} 