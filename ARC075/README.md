# ABC095_Dに関して

- K回攻撃する＝全員にK*Bのダメージを等しく与える
    - 爆発の中心にいる人は追加でA-Bのダメージが与えられる

- INF回攻撃すると""必ず""全員倒せる
    - ダメージを与える回数には単調性があり，十分に大きいと必ず倒せる
        - では，必ず倒せる攻撃回数で最小は？を求める
            - 条件の境界値を探せるのが""2分探査""!!!!

- 少しハマったところ
    - INF回の設定値を大きくしすぎてしまったので基本ダメージK*Bの値がオーバーフローして1つWAが出た.


![Dの考え方](http://drive.google.com/uc?export=view&id=1qp-x1RFA14yaZPIr1QTa73Fp6khCeBAO)