class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = [int(x) for x in version1.split('.')]
        v2 = [int(x) for x in version2.split('.')]
        while v1 and v1[-1] == 0:
            v1.pop()
        while v2 and v2[-1] == 0:
            v2.pop()
        if v1 < v2:
            return -1
        elif v1 > v2:
            return 1
        else:
            return 0