import urllib2

st = set()
li = [list()] * 20


def dfs(arr, dep, total, num):
    if dep == len(arr):
        if num > 0:
            li[num].append(total)
            st.add(total)
        return
    dfs(arr, dep + 1, total, num)
    dfs(arr, dep + 1, total + arr[dep], num + 1)


url = 'https://projecteuler.net/project/resources/p105_sets.txt'
content = urllib2.urlopen(url).read()
ans = 0
for line in content.split():
    print line
    arr = map(int, line.split(','))
    st.clear()
    for le in range(len(li)):
        li[le] = list()
    dfs(arr, 0, 0, 0)
    arr.sort()
    if len(st) == (1 << len(arr)) - 1:
        ok = True
        for i in range(2, len(arr) + 1):
            if len(li[i]) > 0 and min(li[i]) < max(li[i - 1]):
                ok = False
        if ok:
            ans += max(st)
print ans