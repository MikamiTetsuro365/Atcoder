# Atcoder
Atcoder関連はここにまとめます(精進)

# テンプレ
**bitsフォルダをコピペして以下を貼り付け**
```cpp
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

}
```

# 多次元ベクター(下は二次元)
```cpp
ll n_rows = 5;
ll n_cols = 5;
ll value = 0;
vector<vector<ll > > vec(n_rows, vector<ll >(n_cols, value));
```

# map全列挙
```cpp

map<ll, ll> mp;
//ここになにか入力
auto begin = mp.begin(), end = mp.end();
for (auto iter = begin; iter != end; iter++) {
    cout << iter -> first << " " <<  iter -> second << endl;
}

```

# Priority queue(優先度付きQueue)
```cpp
priority_queue<ll > que;
//昇順にしたい時
//priority_queue<ll ,vector<ll >, greater<ll > > que;

que.push(1);
que.push(2);
que.push(3);

while(!que.empty()){
    cout << que.top() << endl;
    que.pop()
}
```

# 最大公倍数
**N個の最大公倍数=最大公倍数の最大公倍数の最大公倍数(ry**
```cpp
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
```

```cpp
ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}
```
**どちゃくそくそバカでかい数字同士のGCDを取れと言われたら？多言語(Pythonとか)を使うか,考察がんばるか...[No442和と積](https://yukicoder.me/problems/no/442)**


# 最小公倍数

# 立っているビットをカウント
**GCCの__builtin関数[ここ](https://qnighy.hatenablog.com/entry/20090921/1253551047)**
```cpp
ll n;
cin >> n;
ll bit_count = __builtin_popcount(n);
```

# 約数
**約数を返します**
```cpp
vector<ll > divisor(ll n) {
  vector< ll > div;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      div.push_back(i);
      //重複許すマジ
      if(i * i != n) div.push_back(n / i);
    }
  }
  sort(div.begin(), div.end());
  return (div);
}
```


# 木やグラフ
**辺に重みも設定できます**
```cpp
//to (行き先), weight の順で設定
vector<vector<pair<ll, ll > > > G;
vector<ll > ans;
int main(){
    ll N;
    cin >> N;
    
    //初期化
    G.assign(N, vector<pair<ll, ll > >());
    ans.assign(N, 0);
 
    //グラフ入力
    for(ll i = 0; i < N-1; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
}
```

# dfs
**グラフや木を作って実行してくれい.[ABC070_D](https://atcoder.jp/contests/abc070/tasks/abc070_d) [ABC_067_D](https://atcoder.jp/contests/abc067/tasks/arc078_b)←忘れた頃にもう一度解け**
```cpp
void dfs(ll idx, ll from = -1){
 
    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //同じだったらもう処理しない
        //頂点に戻ってきたら
        //後戻りを許さない
        if(to == from){
            continue;
        }

        //下は例です．この跡に色々処理を書いて幸せになりましょう
        /*    
        if(G[idx][i].second % 2 == 0){
            ans[to] = ans[idx];
        }else{
            ans[to] = 1 - ans[idx];
        }
        */
 
        dfs(to, idx);
 
    }
}

int main(){
    //グラフを作る
    //dfs 実行
    dfs(0);
}
```

# 橋
**とてもわかり易い説明.特に6段目がよさみあふれる[ここ1](http://kagamiz.hatenablog.com/entry/2013/10/05/005213) [ここ２](https://ei1333.github.io/luzhiled/snippets/graph/lowlink.html) [ここ3](https://www.slideshare.net/chokudai/arc045)**

# 累積和
**基本的なイメージはここよぉ[paiza](https://paiza.hatenablog.com/entry/2015/01/21/%E3%80%90%E7%B4%AF%E7%A9%8D%E5%92%8C%E3%80%81%E3%81%97%E3%82%83%E3%81%8F%E3%81%A8%E3%82%8A%E6%B3%95%E3%80%91%E5%88%9D%E7%B4%9A%E8%80%85%E3%81%A7%E3%82%82%E8%A7%A3%E3%82%8B%E3%82%A2%E3%83%AB%E3%82%B4)**

## まとめる処理
**たまに数列とかを同じ者同士でまとめる必要があるので**

```cpp
for(ll i = 0; i < s.size();){
    ll j = i;
    //一緒の間ループを回し続けて，切れ目を探す
    while(j < s.size() && s[j] == s[i]){
        ++j;
    }
    vec.push_back(j - i);
    //次の始点へすっ飛ばす
    i = j;
}
```

## 累積和のメイン処理
**合計を順番にとっていく,leftとrightを操作しながらある区間の合計を取っていく**
```cpp
//先頭は必ず0からスタート
vector<ll > sum(vec.size() + 1, 0);
for(ll i = 0; i < vec.size(); i++){
    //1つ前との合計を取っていく
    sum[i + 1] = sum[i] + vec[i];
}

//累積和メイン
ll ans = 0;
for(ll left = 0; left < sum.size(); left += 2){
    //K * 2 + 1の部分を合計を取りたい任意の区間の要素数に合わせる
    ll right = left + K * 2 + 1;
    //バグらせ防止, rightが伸びきったらもう動かさない終端でleftが上がってくるのを待つ
    if(right >= sum.size()){
        right = sum.size() - 1;
    }
    //sum[right] - sum[left]である区間の合計がわかります.
    ans = max(ans, sum[right] - sum[left]);
}
```

# 尺取り法
**ニョキニョキ**
```cpp

```

# 気持ちの良いDP
**VectorでDPテーブルを作ってしまうと膨大なメモリ空間にアクセスする必要があるのでTLE必須→Mapで頑張った[ARC073_B](https://atcoder.jp/contests/abc060/tasks/arc073_b)**

# 整数と小数の判定
**クソどうでも良いけど...ceil(切り上げ)とfloor(切り捨て)で同じだと整数(少数ではない)**
```cpp
double ans;
cin >> ans;
//cout << ans << endl;
if(ceil(ans) != floor(ans)){
    cout << "No" << endl;
}else{
    cout << "Yes" << endl;
}
```

# next_permutation
**順列を生成する便利な奴[アルゴリズム](https://scrapbox.io/ganariya/%E8%BE%9E%E6%9B%B8%E5%BC%8F%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%AB%E3%81%A4%E3%81%84%E3%81%A6)**
**この考え方が役に立った問題[AGC022_A](https://atcoder.jp/contests/agc022/tasks/agc022_a)**
```cpp
ll N;
cin >> N;
//数列入力
vector<ll > A(N, 0);
for(ll i = 0; i < N; i++){
    cin >> A[i];  
}

do{
    for(ll i = 0; i < A.size(); i++){
        cout << A[i];
    }
    cout << endl;
}while(next_permutation(A.begin(), A.end()));

```

# エラトステネスの篩
**高速に素数を求める[ABC084-D](https://atcoder.jp/contests/abc084/submissions/7647316)**
```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;

vector<bool > prime;

//primeListには素数は入ってません
void isPrime(ll N){
    prime[0] = false;
    prime[1] = false;

    //ルートN以下まで繰り返す
    for(ll i = 2; i < ceil(sqrt(N)) ; i++){
        //素数になりえないとき
        //cout << i << endl;
        if(prime[i] == false) continue;
        
        //Nまでのi(素数)の倍数を斑入り落とす
        for(ll j = i * i; j < N; j += i){
            prime[j] = false;
        }    
    }
}

int main(){

    cin >> N;
    prime.assign(N + 1, true);
    isPrime(N);

    for(ll i = 0; i < prime.size(); i++){
        cout << prime[i] << endl;
    }
} 
```

# 素因数分解
**素因数分解の気持ち**
```cpp
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

map<ll, ll> primeFactor(ll num){

    //素因数と指数部の並び
    map<ll, ll > PF;

    ll i = 2;

    while(num >= i * i){
        if(num % i == 0){
            PF[i]++;
            num /= i;
        }else{
            i++;
        }
    }
    //1は素因数分解できない
    if(num != 1){
        PF[num]++;
    }
    
    return PF;
}

int main(){

    ll num;
    cin >> num;

    map<ll, ll> PF = primeFactor(num);

    auto begin = PF.begin(), end = PF.end();
    for (auto iter = begin; iter != end; iter++) {
        //ここで出力
    }
}
```

# 高速な累乗計算
**早い.べき数を半分に分けてまとめていく気持ち**
```cpp
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

ll fast_pow(ll a, ll n){
    if(n == 0) return 1;
    //べき数nが奇数, aを前にだして, a^n-1の気持ちに
    if(n % 2 == 1){
        return a * fast_pow(a, n - 1) % mod;
    }else{
        //べき数nが偶数のとき，べき数を半分にして, aをまとめる. べき数を半分にする
        return fast_pow(a * a % mod, n / 2) % mod;
    }
}

int main(){
    ll A, N;
    cin >> A >> N;
    fast_pow(A, N)
    cout << fast_pow(A, N) << endl;
} 
```

# ダイクストラ法
**ある頂点から他の頂点までの最短経路を求める．ただし辺の長さ(重み)は正に限る．計算量はヒープを使ってO((V+E)+logV)**
```cpp
#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
ll N, M, L;
ll ans = 0;

vector<vector<pair<ll, ll> > > G;
vector<ll > prever;
 
vector<ll > dijkstra(ll start){
    //準備
    vector<bool > used(N, false);
    vector<ll > dist(N, INFINITY);
    prever.assign(N, -1);
    priority_queue<pair<ll, ll > , vector<pair<ll, ll > >, greater<pair<ll, ll > > > que;
    //初期化
    que.push(make_pair(0, start));
 
    //cout << que.top().first << endl;
 
    while(!que.empty()){
        //距離
        ll d = 0;
        //次の頂点
        ll t_v = 0;
        d = que.top().first;
        t_v = que.top().second;
        //topから削除
        que.pop();
        //探査済みなら処理しない
        if(used[t_v] == true) continue;
        //探査済みにする
        used[t_v] = true;
        //キューの上には既に最小距離が来ているので
        dist[t_v] = d;
        
        //次探査する頂点はt_vなのでt_vから更に次にの頂点の繋がりをキューにいれる
        for(ll i = 0; i < G[t_v].size(); i++){
            //もし探査済みの頂点で，そこまでの累積距離より今更新しようとしている距離が
            //大きいときは更新しない
            ll to = G[t_v][i].first;
            ll cost = d+G[t_v][i].second;
            if(dist[to] <= cost) continue;
            prever[to] = t_v;
            //累積距離と次の頂点
            que.push(make_pair(cost, to));
            //仮dist
            dist[to] = cost;
        }
        //cout << endl;
    }   
    
    return dist;
 
}

vector<ll > get_path(ll t){
    vector<ll > path;
    for(; t != -1; t = prever[t]){
        //cout << prever[t] << endl;
        path.push_back(t);
    }
    //reverse(path.begin(), path.end());
    return path;
}
 
 
int main() {
    //頂点数
    cin >> N >> M >> L;

    G.assign(N, vector<pair<ll, ll > >());
 
    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));    
    }

    dijkstra(0);
    //頂点0からget_path(ある頂点)までの経路
    vector<ll > ans = get_path(4);
    for(ll i=0; i < ans.size();i++){
        cout << ans[i]+1 << endl;
    }
}
```


# あばばば
**概要**
```cpp

```


