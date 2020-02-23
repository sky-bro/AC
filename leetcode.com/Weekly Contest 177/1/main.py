import datetime

# ref: [(Python)计算两个日期时间的时间间隔](https://blog.csdn.net/weixin_42555131/article/details/84525665)


class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        d1 = datetime.datetime.strptime(date1, '%Y-%m-%d')
        d2 = datetime.datetime.strptime(date2, '%Y-%m-%d')

        d = d2 - d1

        return abs(d.days)
