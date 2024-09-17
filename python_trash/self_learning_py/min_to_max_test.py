"""Bài tập 5: Kiểm tra danh sách có phải là dãy số tăng dần hoặc giảm dần
Yêu cầu: Viết hàm kiem_tra_tang_giam(list_a) để kiểm tra xem danh sách 
list_a có phải là dãy số tăng dần hoặc giảm dần hay không."""

list_a = [1,2,3,4,8,10]
list_b = [2,3,51,4,6]

def min_to_max_test(list_c):
    bool_a = True
    for i in range(0,len(list_c)-1):
        if list_c[i] > list_c[i+1]:
            bool_a = False
    if bool_a:
        print('this is a min to max list')
    else:
        print('this is not a min to max list')

min_to_max_test(list_a)
min_to_max_test(list_b)
