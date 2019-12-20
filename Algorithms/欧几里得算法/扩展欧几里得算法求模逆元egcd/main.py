def egcd(a, b):
    if b == 0:
        return 1, 0, a
    x, y, q = egcd(b, a%b)
    x, y = y, x - a // b * y
    return x, y, q

def mod_inv(a, c):
    return egcd(a, c)[0] % c # 最小正整数

if __name__ == "__main__":
    while True:
        a = int(input("a: "))
        c = int(input("c: "))
        # mod_inv(37, 840) = 613
        print("a^-1 mod c =", mod_inv(a, c))
