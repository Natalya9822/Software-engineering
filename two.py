import sys
sys.setrecursionlimit(100000)
import time


def algoritm1(b, n):
    itog = 1
    for i in range(n):
        itog = itog*b
    return itog


def algoritm1_recursion(b, n):
    if n == 0:
        return 1
    else:
        return b*algoritm1_recursion(b, n-1)

def algoritm2(b, n):
    itog = 1
    while n:
        if n % 2:
            itog *= b
            n -= 1
        else:
            b *= b
            n >>= 1
    return itog

def algoritm2_recursion(b, n):
    if n == 0:
        return 1
    else:
        if not n % 2:
            one = algoritm2_recursion(b, n//2)
            return one * one
        else:
            return b * algoritm2_recursion(b, n-1)



def main(b, n):
    print("число 500 в степени "+ str(n))
    start_time = time.time()
    algoritm1(b, n)
    print(" Время работы 1-го алгоритма --- %s секунд ---" % (time.time() - start_time))

    start_time = time.time()
    algoritm1_recursion(b, n)
    print(" Время работы 1-го алгоритма с рекурсией --- %s секунд ---" % (time.time() - start_time))

    start_time = time.time()
    algoritm2(b, n)
    print(" Время работы 2-го алгоритма --- %s секунд ---" % (time.time() - start_time))

    start_time = time.time()
    algoritm2_recursion(b, n)
    print(" Время работы 2-го алгоритма с рекурсией --- %s секунд ---" % (time.time() - start_time))

# степень 3100 и 70000
main(500,3100)
