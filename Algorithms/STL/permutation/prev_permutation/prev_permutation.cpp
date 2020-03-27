template <typename _BidirectionalIterator, typename _Compare>
bool __prev_permutation(_BidirectionalIterator __first,
                        _BidirectionalIterator __last, _Compare __comp) {
  if (__first == __last) return false;
  _BidirectionalIterator __i = __first;
  ++__i;
  if (__i == __last) return false;
  __i = __last;
  --__i;

  for (;;) {
    _BidirectionalIterator __ii = __i;
    --__i;
    if (__comp(__ii, __i)) {
      _BidirectionalIterator __j = __last;
      while (!__comp(--__j, __i)) {
      }
      std::iter_swap(__i, __j);
      std::__reverse(__ii, __last, std::__iterator_category(__first));
      return true;
    }
    if (__i == __first) {
      std::__reverse(__first, __last, std::__iterator_category(__first));
      return false;
    }
  }
}