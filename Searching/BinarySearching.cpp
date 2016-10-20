/*
 * @title: Binary Search (half-open)
 * @description:
 * @arguments:
 *    data: Random Accesses Iterator to an array
 *    n: the size of the array (caller grantees n > 0)
 *    x: the element to search
 *    l, r: exports [l, r) that x in [l, r) [alloc only]
 * @dependences:
 *    R: the order relation of data
 *      R should be strictly-week order
 * @return:
 *    pos: indicating that data[pos] == x (if pos >= 0)
 *         not found (if pos == -1)
 * @note:
 *    data must satisfy R order
 *    in any time, x in [l, r)
 * @assertion:
 *    l < mid && mid < r
 */
#define R(x, y) (x < y)
template <class T>
int BinarySearch(T *data, int n, const T &x, int &l, int &r) {
  l = 0, r = n;
  while (r - l > 1) {       // while remain at least 2 elements
    int mid = (r + l) >> 1; // l < mid && mid < r
    if (R(data[mid], x)) {
      l = mid; // DO NOT use l = mid + 1
    } else if (R(x, data[mid])) {
      r = mid;
    } else {
      // useless: l = mid, r = mid + 1;
      return mid;
    }
  }
  // exactly 1 element data[l]
  // assert(l + 1 == r);
  if (data[l] == x) {
    return l;
  }
  return -1; // not found
}
