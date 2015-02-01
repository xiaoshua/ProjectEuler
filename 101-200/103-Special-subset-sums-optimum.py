import itertools


def power_set(items):
    subsets = [[]]
    for item in items:
        subsets.extend([subset + [item] for subset in subsets])
    return [set(x) for x in subsets]


def has_unique_subset_sums(items):
    subsets = power_set(items)
    sums = set(sum(subset) for subset in subsets)
    return len(sums) == (1 << len(items))


def sum_check(items):
    (l, r) = (1, len(items) - 1)
    (s1, s2) = (items[0], 0)
    while l <= r:
        (s1, s2) = (s1 + items[l], s2 + items[r])
        l += 1
        r -= 1
        if s1 < s2:
            return False
    return True


def is_increase(items):
    pre = -1
    for c in candidate:
        if c <= pre:
            return False
        pre = c
    return True


base_result = [20, 31, 38, 39, 40, 44, 46]
best_sum = sum(base_result)
for candidate in itertools.product(*[list(range(x - 3, x + 4)) for x in base_result]):
    # print candidate
    if sum(candidate) >= best_sum:
        continue
    elif not is_increase(candidate):
        continue
    elif not is_increase:
        continue
    elif not sum_check(candidate):
        continue
    elif not has_unique_subset_sums(candidate):
        continue
    best_sum = sum(candidate)
    best_result = ''.join(str(item) for item in candidate)
print(best_result)

