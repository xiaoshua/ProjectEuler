import time

N = 10000
pre_num = [-1] * N
pre_status = [-1] * N


def bfs(n):
    if n <= 2:
        return n / n

    q = list()
    for _ in xrange(n):
        pre_num[_] = pre_status[_] = -1
    for _ in xrange(1, 3):
        pre_num[_] = _
        q.append(_)
    head = 0
    ok = False
    while head < len(q):
        cur_status = q[head]
        head += 1
        for next_digit in xrange(3):
            next_status = (cur_status * 10 + next_digit) % n
            if pre_num[next_status] == -1:
                pre_num[next_status] = next_digit
                pre_status[next_status] = cur_status
                q.append(next_status)

            if next_status == 0:
                ok = True
                break
        if ok:
            break
    digits = list()
    status = 0
    while status != -1:
        digits.append(pre_num[status])
        status = pre_status[status]
    value = 0
    for digit in reversed(digits):
        value = value * 10 + digit
    return int(value) / n


def get_sum(n):
    return sum(bfs(i) for i in range(1, n + 1))


if __name__ == '__main__':
    begin = time.time()
    print(get_sum(100))
    print(get_sum(10000), time.time() - begin)
