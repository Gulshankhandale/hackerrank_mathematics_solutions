from fractions import Fraction


#q1, q2 = 756624603896972, 837574890139508
q1, q2 =  map(int, input().split())






a001203 = [3, 7, 15, 1, 292, 1, 1, 1, 2, 1, 3, 1, 14, 2, 1, 1, 2, 2, 2, 2, 1, 84,
           2, 1, 1, 15, 3, 13, 1, 4, 2, 6, 6, 99, 1, 2, 2, 6, 3, 5, 1, 1, 6, 8, 1,
           7, 1, 2, 3, 7, 1, 2, 1, 1, 12, 1, 1, 1, 3, 1, 1, 8, 1, 1, 2, 1, 6, 1, 1, 5,
           2, 2, 3, 1, 2, 4, 4, 16, 1, 161, 45, 1, 22, 1, 2, 2, 1, 4, 1, 2, 24, 1, 2,
           1, 3, 1, 2, 1]


def fraction_continue(f, a, i):
    ai = a[0] if i == 0 else a[1 + (i - 1) % (len(a) - 1)]
    if f == 0:
        return Fraction(ai)
    return ai + 1 / f

def calc_fraction_continue(a, k):
    f = Fraction(0)
    while k > 0:
        k -= 1
        f = fraction_continue(f, a, k)
    return f



P = calc_fraction_continue(a001203, 30) - 3

# find endpoints of Farey intervals
a, b, c, d = 0, 1, 1, 1
farey = [(a,b),(c,d)]

while True:
    f = b + d
    if f > q2 - q1: break

    e = a + c
    farey.append((e, f))
    if P < Fraction(e, f):
        c, d = e, f
    else:
        a, b = e, f

p_min = int(P * q1)

# increase p_min/min by fractions in farey
while q1 <= q2:
    c, d = 0, 0
    for a, b in farey:
        if q1 + b > q2: break
        if abs(Fraction(p_min + a, q1 + b).real - P) < abs(Fraction(p_min, q1).real - P):
            c, d = a, b
            break
    if d == 0:
        break
    p_min += c
    q1 += d

print("{}/{}".format(p_min + 3 * q1, q1))
