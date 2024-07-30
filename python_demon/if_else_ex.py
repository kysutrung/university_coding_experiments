#bài làm bài tập if else nhưng dùng lệnh elif cho nhanh
#bài này hoàn toàn có thể chỉ sử dụng if và else như bình thường

numA = int(input("Nhap diem cua ban: "))

if(numA >= 90 and numA <= 100):
    print("Loai Xuat Sac :0")
elif(numA >= 80 and numA < 90):
    print("Loai Gioi ;)")
elif(numA >= 70 and numA < 80):
    print("Loai Kha :)")
elif(numA >= 60 and numA < 70):
    print("Loai Trung Binh :|")
elif(numA < 60):
    print("Loai Kem :(")
