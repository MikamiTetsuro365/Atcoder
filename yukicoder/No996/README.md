## [No.966 引き算をして門松列(その1について)](https://yukicoder.me/problems/no/966)

- 条件分けは破滅への第一歩，もっと広い気持ちで考える
- Bがminかmaxに来れば良い
    - 加算はされないの，min-mid-maxと並んだ時にmidはmax未満，minはmid未満になるような操作ができればよい.
    - minとmaxがBのときのその他についてそのような操作ができるか全探査する