#Bài tập in ra màn hình bảng cửu chương từ 1 đến 10
"""Bảng cửu chương sẽ có dạng A x B = C"""

num_a = 0
num_b = 0

for i in range(1, 11):
    num_a = i
    for u in range(1, 11):
        num_b = u
        num_c = num_a * num_b
        print(num_a, " X ", num_b, " = ", num_c)
    print(" ")

