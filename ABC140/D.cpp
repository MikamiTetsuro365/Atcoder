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
typedef long long int ll;

int main(){

    ll N, K;
    string S;
    cin >> N >> K >> S;
    vector <ll > packing;

    ll tmp = 0;
    for(ll i = 0; i < S.length(); i++){
        if(S[i] == 'L'){
            tmp++;
            if(S[i+1] == 'R'){
                packing.push_back(tmp);
                tmp = 0;
            }
        }
        //Rのときは-1に    
        if(S[i] == 'R'){
            tmp++;
            if(S[i+1] == 'L'){
                packing.push_back(-1 * tmp);
                tmp = 0;
            }
        }
    }
    packing.push_back(tmp);

    for(ll i = 0; i < packing.size(); i++){
        cout << packing[i] << endl;
    }

    

} 