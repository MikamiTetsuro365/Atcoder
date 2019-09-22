#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;


int main(){

    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;

    //クラスが1, 2, 3, 4と昇順になっている部分に当てはまっていたら
    //境界2*Mで余りが0になるとバグるので-1する
    ll classA = (X - 1) % (2 * M);
    ll classB = (Y - 1) % (2 * M);

    //クラスが4, 3, 2, 1と降順になっている部分に当てはまっていたら再計算
    if(classA >= M){
        classA = (2 * M - classA - 1) % M;
    }
    if(classB >= M){
        classB = (2 * M - classB - 1) % M;
    }

    //cout  << classA << ", " << classB << endl;

    if(classA == classB){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

} 