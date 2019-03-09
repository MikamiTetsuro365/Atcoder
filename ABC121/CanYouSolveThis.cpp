#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>


using namespace std;
typedef long long ll;

int N, M, C = 0;

int main(){

    cin >> N >> M >> C;

    vector<int > B;

    int t = 0;
    for(int i = 0; i < M; i++){
        cin >> t;
        B.push_back(t);
    } 


    int total = 0;
    int num = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> t;
            total += B[j] * t;
        } 
        if(total + C > 0){
            num++;
        }
        total = 0;
    } 

    cout << num << endl;
    
}