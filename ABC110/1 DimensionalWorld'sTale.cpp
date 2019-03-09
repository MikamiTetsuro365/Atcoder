#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;

int N, M, X, Y = 0;

int main(){

    cin >> N >> M >> X >> Y;

    vector<int > x;
    vector<int > y;

    for(int i = 0; i < N; i++){
        int t = 0;
        cin >> t;
        x.push_back(t);
    }

    for(int i = 0; i < M; i++){
        int t = 0;
        cin >> t;
        y.push_back(t);
    }

    //判定
    int flag = 0;
    int ans = 114514;
    for(int i = X + 1; i <= Y; i++){
        for(int j = 0; j < x.size(); j++){
            if(i <= x[j]){
                    //cout << "war" << endl;
                    flag = 1;
                    break;
            }
        }

        for(int j = 0; j < y.size(); j++){
            if(i > y[j]){
                //cout << "war" << endl;
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            flag = 0;
            continue;
        }

        ans = i;
    }
    
    if(ans == 114514){
        cout << "War" << endl;    
    }else{
        cout << "No War" << endl;    
    }
    
}