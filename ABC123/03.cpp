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
double N;
ll M;
string s;
vector<ll > input1;  
vector<vector <ll > > input2;

int main(){
    
    cin >> N;
    vector<pair<double, double > > aa;
    ll t = 0;
    for(int i = 0; i < 5; i++){
        cin >> t;
        aa.push_back(make_pair(t, i));
        
    } 
    sort(aa.begin(), aa.end());

    if(aa[0].first > N){
        cout << "5" << endl;
        return 0;
    }
    ll ans =  ceil(N / aa[0].first) + 4;
    
    cout << ans << endl;


} 