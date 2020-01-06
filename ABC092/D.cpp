#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;


int main() {

    ll A, B;
    cin >> A >> B;

    //すべて白で初期化
    vector<vector<char > > grid(100, vector<char >(100, '.'));

    //初期化
    //半分黒，半分白の連結成分が1つずつの状態にする
    //100*100の中で最大500と500しか連結成分が現れないので適当に穴抜きにする
    for(ll row = 0; row < 100; row++){
        for(ll col = 50; col < 100; col++){
            grid[row][col] = '#';
        }
    }    
    
    //白は黒の領域を穴抜きにする
    ll cn = 1;
    for(ll row = 1; row < 99; row+=2){
        /*
        ll col;
        if(row % 2 == 0){
            col = 52;
        }else{
            col = 51;
        }
        */

        for(ll col = 51; col < 99; col+=2){
            //cout << col << endl;
            if(cn >= A){
                break;
            }
            grid[row][col] = '.';
            cn++;
        }
        if(cn >= A){
            break;
        }
    }

    //黒は白の領域を穴抜きにする
    cn = 1;
    for(ll row = 1; row < 99; row+=2){
        /*
        ll col;
        if(row % 2 == 0){
            col = 2;
        }else{
            col = 1;
        }
        */

        for(ll col = 1; col < 49; col+=2){
            if(cn >= B){
                break;
            }
            grid[row][col] = '#';
            cn++;
        }
        if(cn >= B){
            break;
        }
    }

    //表示
    cout << 100 << " " << 100 << endl;
    for(ll row = 0; row < 100; row++){
        for(ll col = 0; col < 100; col++){
            cout << grid[row][col];
        }
        cout << endl;
    }        


}