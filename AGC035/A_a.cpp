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

bool hantei(ll a, ll b, ll c){
    ll xr = 0;
    if(a == 0){
        if(a >= c){
            xr = a / c * c + a % c;
        }else{
            xr = c - a;
        }

        if(xr == b){
            return true;
        }else{
            return false;
        }
    }else{
        if(c == b){
            return true;
        }else{
            return false;
        }
    }
        
}

int main(){
    
    cin >> N;
    vector<ll > a(N,0);
    for(ll i = 0; i < N; i++){
        cin >> a[i];
    }

    for(ll i = 1; i < N - 1; i++){
        if(hantei(a[i-1], a[i+1], a[i]) == false){
            cout << "No" << endl;
            return 0;
        }
    }

    if(hantei(a[N-1], a[1], a[0]) == false){
        cout << "No" << endl;
        return 0;
    }
    if(hantei(a[N-2], a[0], a[N-1]) == false){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

}