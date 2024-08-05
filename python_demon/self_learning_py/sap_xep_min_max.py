#Bài tập sắp xếp và in ra một dãy số theo thứ tự tăng dân
day_so = [9,8,7,10,5,6,33,2,1]

def min_to_max (list_a):
    for i in range(0, len(list_a)):
        for u in range(0, len(list_a)-1):
            if list_a[u] > list_a[u+1]:
                so_c = list_a[u]
                list_a[u] = list_a[u+1]
                list_a[u+1] = so_c

min_to_max(day_so)
print(day_so)