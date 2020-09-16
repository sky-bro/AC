class Solution:
    def toGoatLatin(self, S: str) -> str:
        words = S.split()
        res = []
        a_cnt = 1
        for word in words:
            if word[0] in 'aeiouAEIOU':
                res.append(word+'ma'+'a'*a_cnt)
            else:
                res.append(word[1:] + word[0]+'ma'+'a'*a_cnt)
            a_cnt += 1
        return " ".join(res)
