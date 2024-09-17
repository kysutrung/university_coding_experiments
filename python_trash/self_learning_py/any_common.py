"""Bài tập 3: Tìm các phần tử chung giữa hai danh sách
Yêu cầu: Viết hàm tim_phan_tu_chung(list_a, list_b) để tìm các phần 
tử chung giữa hai danh sách list_a và list_b."""

list_a = [1, 3, 5, 6, 8, 4, 9, 'a', 'c', 'h']
list_b = [22, 5, 13, 6, 0, 22, 10, 'j', 'c', 'l']

def any_common (list_c, list_d):
    list_e = []
    for i in range(0, len(list_c)):
        for u in range(0, len(list_d)):
            if list_c[i] == list_d[u]:
                list_e.append(list_c[i])
    if not list_e:
        print('khong co phan tu giong nhau')
    else:
        print(list_e)

any_common(list_a, list_b)