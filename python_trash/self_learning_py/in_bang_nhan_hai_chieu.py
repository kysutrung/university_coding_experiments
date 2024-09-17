num_x = 3
num_y = 5

#khởi tạo list 2d có x hàng và y cột
list_a = [[None]*num_y for _ in range(num_x)]

#khởi tạo các giá trị trong bảng
for u in range (0, num_y):
    list_a[0][u] = u #khởi tạo giá trị hàng đầu tiên
    for p in range (0, num_x):
            list_a[p][0] = p #khởi tạo giá trị hàng đầu tiên
            if u > 0 and p > 0:
                list_a[p][u] = list_a[p][0] * list_a[0][u]
                
#in ra toàn bộ bảng
for i in range (0, num_x):
    print(list_a[i])