import math

n = int(input())

h = int((-1 + math.sqrt(1 + 8 * n)) / 2)
max_n = h * (h + 1) // 2

if n < max_n:
    h -= 1

print(h)
