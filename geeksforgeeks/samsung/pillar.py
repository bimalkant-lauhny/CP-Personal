from collections import defaultdict

def max_equal_sum(E):
    D=defaultdict(int)            # Map from abs difference to largest sum
    D[0]=0                        # Start with a sum and difference of 0
    print(D)
    for a in E:                   # Iterate over each element in the array
        D2=D.copy()               # Can keep current sum and diff if element is skipped
        for d,s in D.items():     # d is difference, s is sum
            s2 = s+a              # s2 is new sum
            for d2 in [d-a,d+a]:  # d2 is new difference
                D2[abs(d2)] = max(D2[abs(d2)],s2) # Update with largest sum
        D=D2
        print(D)
    return D[0]/2                 # Answer is half the sum of A+B for a difference of 0

l = [int(x) for x in input().split()]
print(max_equal_sum(l))
