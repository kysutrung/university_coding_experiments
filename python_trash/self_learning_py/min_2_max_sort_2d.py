"""Bài tập 1: Sắp xếp danh sách con bên trong danh sách 2D
Yêu cầu: Viết hàm sap_xep_danh_sach_2d(list_2d) để sắp xếp mỗi danh sách
con bên trong danh sách 2D theo thứ tự tăng dần."""

mang_2d = [[2, 3, 1], [15, 4, 5], [8, 9, 77]]

def min_to_max_sort (list_a):
    for i in range(0, len(list_a)):
        for u in range(0, len(list_a)-1):
            if list_a[u] > list_a[u+1]:
                so_c = list_a[u]
                list_a[u] = list_a[u+1]
                list_a[u+1] = so_c

def min_2_max_2d (list_2d):
    for i in range (0, len(list_2d)):
        list_b = list_2d[i]
        min_to_max_sort(list_b)
        list_2d[i] = list_b

min_2_max_2d(mang_2d)
print(mang_2d)
