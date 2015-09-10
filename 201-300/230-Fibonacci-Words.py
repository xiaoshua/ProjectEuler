def d(a, b, str_len):
    if str_len <= len(a):
        return int(a[str_len - 1])
    elif str_len <= len(b):
        return int(a[str_len - 1])
    str_list = [a, b]
    len_list = [len(a), len(b)]
    for _ in xrange(1000):
        len_list.append(len_list[-1] + len_list[-2])
        if len_list[-1] >= str_len:
            break
    else:
        print(-1)
    cur_id = len(len_list) - 1
    cur_len = str_len
    while cur_id > 1:
        if cur_len <= len_list[cur_id - 2]:
            cur_id -= 2
        else:
            cur_len -= len_list[cur_id - 2]
            cur_id -= 1
    return int(str_list[cur_id][cur_len - 1])


if __name__ == '__main__':
    print(d('1415926535', '8979323846', 35))
    ret = 0
    for n in xrange(18):
        ret += (10 ** n) * d(
            '1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679',
            '8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196',
            (7 ** n) * (127 + 19 * n))
    print(ret)
