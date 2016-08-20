// biheap.cpp 二叉大项堆实现
#include <limits.h>
using namespace std;

const int maxn = 100010; // 最大元素个数
int biheap[maxn + 1];    // 堆
int cnt = 0;             // 堆的大小

// 辅助函数
inline int pre(int x){return x >> 1;}
inline int lch(int x){return x << 1;}
inline int rch(int x){return (x << 1) + 1;}
inline void down(int n){
  int v = biheap[n];
  while (n <= cnt) {
    int to = INT_MAX;
    if(lch(n) <= cnt && biheap[lch(n)] > v) to = lch(n);
    if(rch(n) <= cnt && biheap[rch(n)] > v && biheap[rch(n)] > biheap[lch(n)]) to = rch(n);
    if(to != INT_MAX){
      biheap[n] = biheap[to];
      n = to;
    }
    else{
      biheap[n] = v;
      break;
    }
  }
}

// 重新初始化
inline void init(){
  cnt = 0;
}

// 插入
void insert(int x){
  int p = ++cnt;
  while(p > 1 && x > biheap[pre(p)]){
    biheap[p] = biheap[pre(p)];
    p = pre(p);
  }
  biheap[p] = x;
}

// 删除堆顶
int pop(){
  int ans = biheap[1];
  biheap[1] = biheap[cnt--];
  down(1);
  return ans;
}

// 离线建堆
void heapify(int n){
  if(lch(n) > cnt) return;
  if(lch(n) <= cnt) heapify(lch(n));
  if(rch(n) <= cnt) heapify(rch(n));
  down(n);
}

// 示例: poj1338
#include <cstdio>
int main(){
  scanf("%d", &cnt);
  for(int i = 1; i <= cnt; i++){
    scanf("%d", &biheap[i]);
  }
  heapify(1);
  while (cnt) {
    printf("%d\n", pop());
  }
  return 0;
}
