#chương trình tính xếp loại sinh viên dựa trên điểm thang 4
#nhập điểm chung bình chung tích lũy

numA = 2.39

if(numA >= 3.60 and numA <= 4.00):
    print(numA," - Loai Xuat Sac :0")
elif(numA >= 3.20 and numA < 3.59):
    print(numA," - Loai Gioi ;)")
elif(numA >= 2.50 and numA < 3.19):
    print(numA," - Loai Kha :)")
elif(numA >= 2.00 and numA < 2.49):
    print(numA," - Loai Trung Binh :|")
elif(numA < 2.00):
    print(numA," - Loai Yeu :(")