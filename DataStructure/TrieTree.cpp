/*
@title: Configurable Trie Tree
@description:
    从串构造池式存储字典树
@configuration:
    [const int] Charset: 字符集大小
    [const int] Capacity: 字典树容量
    [type] StringType: 字典树串类型
    [bool] IterEnd(int iter): 迭代终止标记
        iter: 迭代器
    [int] order(StringType ch): ch 的序数
    [declare] SateliteData: 字典树节点卫星数据
    [void] NewNodeConstruction(int size): 新节点构造钩子
        size: 构造节点结束后的size
    [void] InsertFinish(int pos): 串构造结束钩子
        pos: 串末对应的字典树中的位置
    [void] InsertTranslate(int pos): 插入过程中的转移钩子
        pos: 下一个节点的位置
    [void] NotFound(): 查询时如果没有找到的钩子
    [void] Found(int pos): 查询时如果找到的钩子
        pos: 找到的节点的位置
@method:
    [void] insert(StringType *S): 从串S构造字典树的一条链
    [void] find(StringType *S): 在字典树中查找串S
    [void] clear(): 清空字典树
@note:
    在全局变量中静态定义字典树实例以保证初始化
    node[1] 是根节点
    size 包含根节点
*/
#define Charset 26
#define Capacity 1000000
#define StringType char
#define IterEnd(iter) (S[iter] == 0)
#define order(ch) (ch - 'a')
#define SateliteData int val
#define NewNodeConstruction(size) ;
#define InsertFinish(pos) ;
#define InsertTranslate(pos) node[cur].val++
#define NotFound() printf("0\n");
#define Found(pos) printf("%d\n", node[pos].val)

struct TrieTree {
  struct TrieNode {
    int next[Charset];
    SateliteData;
  } node[Capacity];
  int size;
  TrieTree() { size = 1; }
  void insert(StringType *S) {
    int cur = 1;
    for (int i = 0; !IterEnd(i); i++) {
      if (node[cur].next[order(S[i])] == 0) {
        node[cur].next[order(S[i])] = ++size;
        NewNodeConstruction(size);
      }
      cur = node[cur].next[order(S[i])];
      InsertTranslate(cur);
    }
    InsertFinish(cur);
  }
  void find(StringType *S) {
    int cur = 1;
    for (int i = 0; !IterEnd(i); i++) {
      if (node[cur].next[order(S[i])] == 0) {
        NotFound();
        return;
      }
      cur = node[cur].next[order(S[i])];
    }
    Found(cur);
  }
  void clear() {
    memset(this, 0, (size + 1) * sizeof(TrieNode));
    size = 1;
  }
};
