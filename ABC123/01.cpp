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
    int a,b,c,d,e,k;
    vector<ll > aa(5);
    for(int i = 0; i < 5; i++){
        cin >> aa[i];
    } 
    cin >> k;
    
    for(ll i = 0; i < 5; i++){
        for(ll j = i + 1; j < 5; j++){
            if(abs(aa[i] - aa[j]) > k){
                cout << ":(" << endl;
                return 0;
            }
        }
    }
     cout << "Yay!" << endl;


} 