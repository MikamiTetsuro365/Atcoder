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

//解法は合っていたがTLEが発生したコード

int main(){

    string S;
    cin >> S;
    
    vector<ll > posi(S.length(), 0); 

    vector<ll > table(S.length(), 0);

    ll count = 0;

    for(ll i = 0; i < S.length(); i++){
        //cout << S[i] << endl;
        ll count = 0;
        ll j = i;
        if(S[i] == 'R'){
            for(j = i; j < S.length(); j++){            
                if(S[j] == 'L'){
                    break;
                }
                count++;
            }

            if( count % 2 == 0){
                posi[j]++;
            }else{
                posi[j-1]++;
            }

        }else{
            for(j = i; j >= 0; j--){
                if(S[j] == 'R'){
                    break;
                }
                count++;
            }
            if( count  % 2 == 0){
                posi[j]++;
            }else{
                posi[j + 1]++;
            }
        }

    }

    for(ll i = 0; i < S.length() - 1; i++){
        cout << posi[i] << " ";
    }
    cout << posi[S.length() - 1] << endl;;



} 
