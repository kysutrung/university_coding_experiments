"""Bài tập 4: Xoay vòng danh sách
Yêu cầu: Viết hàm xoay_vong_danh_sach(list_a, k) để xoay vòng 
danh sách list_a sang phải k vị trí."""

list_a = [1, 2, 3, 4, 5, 6, 7, 8]

def xoay_volume(list_b, num):
    list_e = [None]*len(list_a)
    for i in range(0, len(list_b)):
        new_index = i
        for u in range(0,num):
            new_index += 1
            if new_index > (len(list_b)-1):
                new_index = 0
        list_e[new_index] = list_b[i]
    print(list_e)

xoay_volume(list_a,5)

#cách này làm rất rắc rối, dùng slicing sẽ dễ hơn

    