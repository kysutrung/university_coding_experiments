"""Bài tập 2: Tìm số dài nhất trong danh sách các số nguyên
Yêu cầu: Viết hàm tim_so_dai_nhat(list_a) để tìm số có nhiều chữ số
nhất trong danh sách các số nguyên list_a."""

list_b = [1, 'aaaaa', 23, 6542, 828262]
def tim_so_dai_hon (list_a):
    max_val = 0
    max_index = 0
    for i in range (0, len(list_a)):
        if max_val < len(str(list_a[i])):
            max_val = len(str(list_a[i]))
            max_index = i
    print(list_a[max_index])

tim_so_dai_hon (list_b)
