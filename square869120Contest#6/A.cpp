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

int main(){
    int N, K;
    cin >> N >> K;
    vector<int > vec(N, 0);

    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }

    int nextLeft = 0;
    int nextRight = 0;

    int temp = 1;
    int ans = 0;
    int len = 0;

    int i = 0;
    while(nextRight < N){
        if(nextLeft == nextRight){
            nextRight++;
        }
        //右方向に伸ばす
        while(temp <= K){
            cout << nextRight << " ";
            temp *= vec[nextRight - 1];
            nextRight++;
            len++;
        }
        cout << endl;
        temp /= vec[nextLeft];
        len--;
        nextLeft++; 

        cout << temp << endl;
        
        ans = max(ans, len);

    }

    cout << ans << endl;


} 