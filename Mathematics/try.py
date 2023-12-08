import math
t = int(input())

while(t > 0):
    t-=1
    n = int(input())
    first_num = (math.sqrt(1 + 4 * 2 * n) + 1) / 2; 

    ans = (first_num) + (n - (first_num-1) * ((first_num) / 2))
    print(int(ans));