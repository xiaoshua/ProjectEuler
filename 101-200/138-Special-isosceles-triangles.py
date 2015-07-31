'''
h^2+(b/2)^2=L^2
B = b/2, h = b+-1
=>
5L^2-(5B+-2)^2=1
'''
(x0, y0) = (2, 1)
d = 5
ans = 0
cnt = 0
(newx, newy) = (x0, y0)
while True:
    (newx, newy) = (x0 * newx + newy * y0 * d, newx * y0 + x0 * newy)
    if newx % 5 == 2 or newx % 5 == 3:
        print(newx, newy)
        ans += newy
        cnt += 1
    if cnt == 12:
        break
print(ans)
