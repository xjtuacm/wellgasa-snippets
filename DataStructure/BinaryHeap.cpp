/*
@title: BinaryHeap 二叉堆
@description:
    一个普通的二叉堆
@structure:
    BinaryHeap:
      T *buffer: 数组首地址 - 1
      int size: 数组长度
@dependence:
    bool compare(int a, int b); // 给出比较关系
@note:
    需要手动指定 buffer, size
    指定 buffer 为 a[] 时 => buffer = a - 1;
*/
struct BinaryHeap {
  int *buffer;
  int size;
  // 转移函数 O(1)
  int parent(int index);
  int left(int index);
  int right(int index);
  // shiftDown
  // 对节点 n 进行下降操作
  // 将 buffer[n] 向下交换到叶子节点上。
  // 每次与孩子中较小的一个交换。 O(log(size))
  void shiftDown(int index);
  // insert
  // 插入元素 O(log(size))
  void insert(int key);
  // Find Min
  // 获取最小值 O(1)
  int findMin();
  // Remove
  // 删除 index 位置上的点 O(log(size))
  void remove(int index);
  // Delete Min
  // 删除最小值 O(log(size))
  void deleteMin();
  // Extract Min
  // 取最小值并弹出 O(log(size))
  int extractMin();
  // updateKey
  // 更新键值
  // shift down or shift up O(log(size))
  void updateKey(int index, int key);
  void IterativeMaintenance(int index);
  // 离线迭代建堆
  // Bottom-Up O(size)
  void IterativeHeapify();
};

inline int BinaryHeap::parent(int index) { return index >> 1; }
inline int BinaryHeap::left(int index) { return index << 1; }
inline int BinaryHeap::right(int index) { return (index << 1) + 1; }

void BinaryHeap::shiftDown(int index) {
  while (true) {
    if (right(index) <= size) { // left(n) < right(n) <= size
      if (compare(buffer[left(index)], buffer[right(index)])) {
        std::swap(buffer[index], buffer[left(index)]);
        index = left(index);
      } else {
        std::swap(buffer[index], buffer[right(index)]);
        index = right(index);
      }
    } else if (left(index) <= size) { // left(n) <= size < right(n)
      std::swap(buffer[index], buffer[left(index)]);
      index = left(index);
    } else { // size < left(n) < right(n)
      break;
    }
  }
}

void BinaryHeap::insert(int key) {
  int index = ++size;
  while (index > 1 && compare(key, buffer[parent(index)])) {
    buffer[index] = buffer[parent(index)];
    index = parent(index);
  }
  buffer[index] = key;
}

int BinaryHeap::findMin() { return buffer[1]; }

void BinaryHeap::remove(int index) {
  buffer[index] = buffer[size--];
  shiftDown(index);
}

void BinaryHeap::deleteMin() { remove(1); }

int BinaryHeap::extractMin() {
  int min = findMin();
  remove(1);
  return min;
}

void updateKey(int index, int key) {
  if (compare(buffer[index], key)) { // buffer[index] < key
    // increasing
    buffer[index] = key;
    IterativeMaintenance(index);
  } else if (compare(key, buffer[index])) { // key < buffer[index]
    buffer[index] = key;
    // shift up
    int p = parent(index);
    while (p >= 1) {
      if (compare(buffer[p], buffer[index])) {
        // 满足堆性质
        break;
      }
      std::swap(buffer[p], buffer[index]);
      index = p;
      p = parent(p);
    }
  } else {
    // buffer[index] == key, do nothing
  }
}

void BinaryHeap::IterativeHeapify() {
  for (int i = size; i > 0; i--) {
    IterativeMaintenance(i);
  }
}

void BinaryHeap::IterativeMaintenance(int index) {
  // heapify the heap whose root is index
  while (true) {
    if (right(index) <= size) { // left < right <= size
      if (compare(buffer[left(index)], buffer[right(index)])) {
        if (!compare(buffer[index], buffer[left(index)])) {
          std::swap(buffer[index], buffer[left(index)]);
          index = left(index);
        } else {
          break;
        }
      } else {
        if (!compare(buffer[index], buffer[right(index)])) {
          std::swap(buffer[index], buffer[right(index)]);
          index = right(index);
        } else {
          break;
        }
      }
    } else if (left(index) <= size) { // left <= size < right
      if (!compare(buffer[index], buffer[left(index)])) {
        std::swap(buffer[index], buffer[left(index)]);
        index = left(index);
        // the next one must be leaf, so we can break it
        // break;
      } else {
        break;
      }
    } else { // size < left < right: leaf
      break;
    }
  }
}