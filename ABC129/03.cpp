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
ll sum = 0;


bool rekkyo(ll goal, vector<ll > a){
    if(goal == 0){
        sum++;
        return true;
    }else if(goal < 0){
        return false;
    }
    //踏み抜き防止チェック
    for(ll i = 0; i < a.size(); i++){
        if(goal == a[i]){
            return false;
        }
    } 
    rekkyo(goal - 1, a);
    rekkyo(goal - 2, a);
    return true;

}

int main(){
    ll N, M;
    ll waru = 1000000007;
    cin >> N >> M;
    vector <ll > a(M, 0);

    for(ll i = 0; i < M; i++){
        cin >> a[i];
    }
    rekkyo(N , a);
    cout << sum % waru << endl;

} 