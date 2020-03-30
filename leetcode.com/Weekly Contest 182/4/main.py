# O(N * len(evil)) Solution with memorized DP & KMP algorithm
# ref: https://leetcode.com/problems/find-all-good-strings/discuss/554806/O(N-*-len(evil))-Solution-with-memorized-DP-and-KMP-algorithm


def getKmpNext(pattern):
    """ 
    get KMP next arrray
    next[i] is the biggest k s.t. pattern[:k] == pattern[:i + 1][-k:]
    """
    nextArr = [0] * len(pattern)
    i, j = 1, 0
    while i < len(pattern):
        while j and pattern[j] != pattern[i]:
            j = nextArr[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
        nextArr[i] = j
        i += 1
    return nextArr


class Solution:
    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        from functools import lru_cache

        m = len(evil)
        mod = int(1E9 + 7)
        nextArr = getKmpNext(evil)

        @lru_cache(None)
        def cnt(idx, pre1, pre2, preE):
            """
            we try to build target string each char.

            the basic idea is that we can get the count of valid string which begin with a special prefix.
            but if we use the prefix as a parameter, the DP space will be too big.
            so we just extract three params from the prefix: if it's prefix of s1 or s2 or evil.

            idx(int) is the index char of target to build.

            pre1(bool) means if the prefix of current position is a prefix of s1.
                if it is, the char we put here cannot greater than s1[idx].

            pre2(bool) means if the prefix of current position is a prefix of s2.
                if it is, the char we put here cannot less than s2[idx].

            preE(int) is the max length of commom prefix between current position and evil.
                if it is len(evil), we cannot build any string begin with current prefix.
                we use KMP algorithm to calculate it.
            """
            if preE == m:
                return 0
            if idx == n:
                return 1

            total = 0
            first = ord(s1[idx]) if pre1 else ord('a')
            last = ord(s2[idx]) if pre2 else ord('z')

            for ci in range(first, last + 1):
                c = chr(ci)

                _pre1 = pre1 and ci == first
                _pre2 = pre2 and ci == last

                # using KMP to calculate _preE
                _preE = preE
                while _preE and c != evil[_preE]:
                    _preE = nextArr[_preE - 1]
                if c == evil[_preE]:
                    _preE += 1

                total += cnt(idx + 1, _pre1, _pre2, _preE)
                total %= mod

            return total

        return cnt(0, True, True, 0)
