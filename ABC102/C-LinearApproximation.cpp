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
    vector<ll > t_A;

    ll t = 0;

    for(int i = 0; i < N; i++){
        cin >> t;
        A.push_back(t);
        t = t - (i + 1);
        t_A.push_back(t);
    }

    sort(t_A.begin(), t_A.end());

    //中央値
    ll center = 0;
    if(t_A.size() % 2 == 1){
        //cout << A[A.size() / 2  ] << endl;
        center = t_A[t_A.size() / 2];
    }else{
        //cout << (A[A.size() / 2 - 1] + A[A.size() / 2]) / 2 << endl;
        center = (t_A[t_A.size() / 2 - 1] + t_A[t_A.size() / 2]) / 2;
    }
    //cout << center << endl;
    ll ans = 0;

    for(int i = 1; i <= N; i++){
        //cout << A[i - 1] << endl;
        ans += abs(A[i - 1] - (center + i));
    }    
    cout << ans << endl;

}