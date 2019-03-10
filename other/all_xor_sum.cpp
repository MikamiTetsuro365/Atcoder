#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
int N = 0;

//桁ごとの1と0の数を数えて掛けて足してを繰り返すと良い感じになる
ll all_xor_sum(vector<ll > arr){

    ll sum = 0;

    for(int i = 0; i < 32; i++){
        ll zero = 0;
        ll one = 0;
        ll posi_sum = 0;

        for(int j = 0; j < arr.size(); j++){

            if(arr[j] % 2 == 0){
                zero++;
            }else{
                one++;
            }
            arr[j] = arr[j] / 2;
        }

        posi_sum = one * zero * (1 << i);

        sum += posi_sum;

    }

    return sum;
}

int main(){

    cin >> N;
    vector<ll > arr;

    ll num = 0;
    for(int i = 0; i < N; i++){
        cin >> num;
        arr.push_back(num);
    }

    cout << all_xor_sum(arr) << endl;

}