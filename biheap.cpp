template<typename T, T* biheap, typename Compare>
struct BiHeap{
  int cnt;
  Compare compare = Compare();
  BiHeap(int cnt = 0): cnt(cnt){}

  // 辅助函数
  inline int pre(int x){return x >> 1;}
  inline int lch(int x){return x << 1;}
  inline int rch(int x){return (x << 1) + 1;}

  // 对节点n进行下降操作
  void down(int n){
    T v = biheap[n];
    while (n <= cnt) {
      int to = 0;
      if(lch(n) <= cnt && compare(biheap[lch(n)],v)) to = lch(n);
      if(rch(n) <= cnt && compare(biheap[rch(n)],v) && compare(biheap[rch(n)],biheap[lch(n)])) to = rch(n);
      if(to != 0){
        biheap[n] = biheap[to];
        n = to;
      }
      else{
        biheap[n] = v;
        break;
      }
    }
  }

  // 插入
  void push(const T& x){
    int p = ++cnt;
    while(p > 1 && compare(x,biheap[pre(p)])){
      biheap[p] = biheap[pre(p)];
      p = pre(p);
    }
    biheap[p] = x;
  }

  // 取堆顶
  T top(){
    return biheap[1];
  }

  // 弹出堆顶
  void pop(){
    biheap[1] = biheap[cnt--];
    down(1);
  }

  // 清空
  void clear(){
    cnt = 0;
  }

  // 离线建堆
  // 前提: 设置好cnt，并在[1..cnt]中存好值
  void heapify(int n){
    if(lch(n) > cnt) return;
    if(lch(n) <= cnt) heapify(lch(n));
    if(rch(n) <= cnt) heapify(rch(n));
    down(n);
  }
};
