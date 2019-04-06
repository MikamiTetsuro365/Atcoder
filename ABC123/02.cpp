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
vector<ll > input1;  
vector<vector <ll > > input2;

int main(){
    
    //cin >> N;
    vector<pair<ll, ll> > aa;
    ll t = 0;
    for(int i = 0; i < 5; i++){
        cin >> t;
        if(t % 10 >= 0){
            if(t % 10 == 0){
                aa.push_back(make_pair((t % 10), t));
            }else{
                aa.push_back(make_pair(10 - (t % 10), t));
            }
        }
        
    } 
    
    sort(aa.begin(),aa.end());

    int ans = 0;
    for(ll i = 0; i < 5; i++){
        //cout << aa[i] << endl;
        ans += aa[i].second;
        if(aa[i].first > 0 && i < 4){
            ans += aa[i].first;
        }

    }
     cout << ans << endl;


} 