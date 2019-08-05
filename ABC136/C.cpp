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

int main(){

    ll N;
    cin >> N;

    vector<ll > H(N);

    for(ll i = 0; i < N; i++){
        cin >> H[i];
    }

    if(N == 1){
        cout << "Yes" << endl;
        return 0;
    }else if(N == 2){
        if(H[0] > H[1] ){
            if(H[0] - H[1] == 1){
                cout << "Yes" << endl;
                return 0;
            }else{
                cout << "No" << endl;
                return 0; 
            }

        }else{
            cout << "Yes" << endl;
            return 0;          
        }
    }

    if(H[0] > H[1] && H[0] - H[1] == 1){
        //まだ１大きいだけならなんとかなる
        if(H[0] != 1){
            H[0]--;
        }  
    }else if(H[0] == H[1]){
        //一緒でもなんとかなる
        if(H[0] != 1){
            H[0]--;
        }  
    }else if(H[0] < H[1]){
        if(H[0] != 1){
            H[0]--;
        }  
    }else{
        //無理
        cout << "No" << endl;
        return 0;
    }

    for(ll i = 1; i < N - 1; i++){
        if(H[i] > H[i-1]){
            if(H[i] > H[i + 1] && H[i] - H[i + 1] == 1){
                if(H[i] != 1){
                    H[i]--;
                }  
            }else if(H[i] == H[i + 1] || H[i] < H[i + 1]){
                if(H[i] != 1){
                    H[i]--;
                }  
            }else{
                //無理
                cout << "No" << endl;
                return 0;                
            }
        }else if(H[i] == H[i - 1]){
            //この場合は低くできない
            if(H[i] > H[i + 1]){
                //無理
                cout << "No" << endl;
                return 0;               
            }
        }
        //cout << i << endl;
    }

    cout << "Yes" << endl;



} 
