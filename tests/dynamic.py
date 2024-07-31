import time
import timeit

def fib(n):
    if n <= 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)
    

def fib2(n, fibseq = [1, 1]):
    if n <= 2:
        return 1
    elif n <= len(fibseq):
            return fibseq[n - 1]
    else:
        if n == len(fibseq) + 1:
            fibseq.append(fibseq[-1]+fibseq[-2])
            return fib2(n - 1, fibseq) + fib2(n - 2, fibseq)
        else:
            return fib2(n - 1) + fib2(n - 2)
        

def gridTraveler(a, b, memo = {}):
    if a == 0 or b == 0:
        return 0
    elif a == 1 and b == 1:
        return 1
    elif ((a, b) or (b, a)) in memo:
        return memo[(a, b)]
    else:
        memo[(a, b)] = gridTraveler(a - 1, b, memo) + gridTraveler(a, b - 1, memo)
        return memo[(a, b)]


def canSum(target, array, memo = {}):
    if target == 0:
        return True
    elif target < 0:
        return False
    elif array == []:
        return False
    elif target in memo:
        return memo[target]
    else:
        for i in range(len(array)):
            memo[target] = canSum(target-array[i], array, memo)
            if memo[target]:
                return True

    return False


def howSum(target, array, combos = [], memo = {}):
    if target == 0:
        return combos
    elif target < 0:
        return None
    elif target in memo:
        return memo[target]
    else:
        for i in array:
            if type(howSum(target-i, array, combos, memo)) == list:
                combos.append(i)
                memo[target] = combos
                return memo[target]
                
        return None



print(howSum(100, [6, 7]))
