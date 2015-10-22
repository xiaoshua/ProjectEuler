import time

str_mat = '''7  53 183 439 863 497 383 563  79 973 287  63 343 169 583
627 343 773 959 943 767 473 103 699 303 957 703 583 639 913
447 283 463  29  23 487 463 993 119 883 327 493 423 159 743
217 623   3 399 853 407 103 983  89 463 290 516 212 462 350
960 376 682 962 300 780 486 502 912 800 250 346 172 812 350
870 456 192 162 593 473 915  45 989 873 823 965 425 329 803
973 965 905 919 133 673 665 235 509 613 673 815 165 992 326
322 148 972 962 286 255 941 541 265 323 925 281 601  95 973
445 721  11 525 473  65 511 164 138 672  18 428 154 448 848
414 456 310 312 798 104 566 520 302 248 694 976 430 392 198
184 829 373 181 631 101 969 613 840 740 778 458 284 760 390
821 461 843 513  17 901 711 993 293 157 274  94 192 156 574
 34 124   4 878 450 476 712 914 838 669 875 299 823 329 699
815 559 813 459 522 788 168 586 966 232 308 833 251 631 107
813 883 451 509 615  77 281 613 459 205 380 274 302  35 805'''

begin = time.time()

int_mat = [[int(cell) for cell in line.split()] for line in str_mat.split('\n')]
column_number = len(int_mat[0])
max_mask = 1 << column_number
row_number = len(int_mat)
dp = [[0] * max_mask for j in range(1 + row_number)]

for row_id in range(row_number):
    for mask in xrange(max_mask):
        if row_id != 0 and dp[row_id][mask] == 0:
            continue
        for column_id in xrange(column_number):
            if (mask & (1 << column_id)) == 0:
                new_mask = mask | (1 << column_id)
                dp[row_id + 1][new_mask] = max(dp[row_id + 1][new_mask], dp[row_id][mask] + int_mat[row_id][column_id])

end = time.time()
print(end - begin, dp[row_number][max_mask - 1])

