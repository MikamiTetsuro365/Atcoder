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
    int N;
    cin >> N;

    vector<int > l(N, 0);

    for(int i = 0; i < N; i++){
        cin >> l[i];
    }

    int ans = 1;
    int f = 0;
    for(int i = 1; i < N; i++){
        int t = l[i];
        int f = 0;
        for(int j = i - 1; j >= 0; j--){
            //cout << l[j] << endl;
            if(t < l[j]){
                f = 1;
                break;
            }
        }

        if(f != 1){
            ans++;
        }
        
    }
    cout << ans << endl;
} 