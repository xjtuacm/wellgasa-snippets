/*
@title: 快速排序
@description: 递归实现
@arguments:
    A: 待排序数组的首指针
    p: 排序首地址
    r: 排序尾地址
@performance:
    Time:
        O(n log(n)) in expected
        O(n^2) in worst
    Space: O(n)
        Extra:
            O(log n) in expected
            O(n) in worst
@dependence:
    std::swap in "algorithm", exactly in 'move.h'
@note:
    函数后 保证 A 升序，可重载 < 号，改变顺序
    没有做随机化
    排序范围: A[p, r]
        因此对长度为n的数组排序调用: QuickSort(A, 0, n - 1);
*/
template <class T> void QuickSort(T *A, int p, int r) {
  int i = p, j = r, x = A[(p + r) / 2];
  while (i <= j) {
    while (A[i] < x) {
      i++;
    }
    while (x < A[j]) {
      j--;
    }
    if (i <= j) {
      std::swap(A[i++], A[j--]);
    }
  }
  if (p < j) {
    QuickSort(A, p, j);
  }
  if (i < r) {
    QuickSort(A, i, r);
  }
}