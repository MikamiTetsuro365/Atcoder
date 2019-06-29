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

using namespace std;
typedef long long ll;
ll N;

int main(){

    cin >> N;

    vector<pair<ll, ll > > cost;
    ll a, b;
    for(ll i = 0; i < N; i++){
        cin >> a >> b;
        cost.push_back(make_pair(a, b));
    }

    vector<ll > ans;  
 
    for(ll i = 0; i < N; i++){
        ans.push_back(cost[i].first + cost[i].second);
    }

    if(*std::max_element(ans.begin(), ans.end()) > 0){
        cout << *std::max_element(ans.begin(), ans.end()) << endl;
    }else{
        cout << "0" << endl;
    }

} 