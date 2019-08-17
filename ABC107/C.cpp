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
typedef long long ll;
ll N;
ll M;
string s;

int main(){
    
    cin >> N >> M;

    vector<ll > x(N, 0);

    //cin >> x[0];
    ll sunuke = 0;
    
    for(ll i = 0; i < N; i++){
        cin >> x[i];
    }
    
    
    ll distance = 11451419191919;
    for(ll i = 0; i < N - M + 1; i++){
        //cout << i << endl;
        //distance = min(distance, min(abs(x[i]), abs(x[i+M-1])) + x[i+M-1] - x[i]);
        ll left = x[i];
        ll right = x[i + M - 1];
        //左端へいって右へ戻ってくるか右端へいって左へ戻ってくるか
        distance = min(min(abs(left), abs(right)) + right - left, distance);

        /* 
        if(right > sunuke){
            
        }
        if(left < sunuke){
            distance = min((sunuke - left) + (right - left), distance);
        }  
        */
    }

    cout << distance << endl;

} 