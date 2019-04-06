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
string N;

int main(){
    
    cin >> N;
    vector<int > L(N.length());

    int i = 0;
    for(i = 0; i < N.length(); i++){
        L[i] = stoi(N.substr(i,1));
    }
    L.push_back(1145141919);

    if(N.length() == 1){
        cout << N << endl;
        return 0;
    }

    int ans = 0;
    int f = 0;
    for(i = 0; i < N.length(); i++){
        if(L[i] < 9){
            for(int j = i + 1; j < N.length(); j++){
                if(L[j] != 9){
                    ans += L[i] - 1;
                    f = 1;
                    break;
                }
            }
            if(f != 1){
                ans += L[i];
            }
            ans += (N.length() - (i + 1)) * 9;
            break;
        }else if(L[i] == 9){
            if(L[i+1] < 9){
                ans += L[i] - 1;
                ans += (N.length() - (i + 1)) * 9;
                break;
            }else{
                ans += 9;
            }
        }
    }

    cout << ans << endl;
} 