num_need_check = 79 #nhập số cần check vào đây
var_a = 0
var_b = int(num_need_check ** 0.5)

for i in range(2, var_b+1):
    if(num_need_check % i == 0):
        var_a += 1

if(var_a == 0):
    print("Day la so nguyen to")
else:
    print("Day khong phai so nguyen to")