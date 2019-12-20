def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

if __name__ == "__main__":
    while True:
        a = int(input("a: "))
        b = int(input("b: "))
        print("gcd:", gcd(a, b))
