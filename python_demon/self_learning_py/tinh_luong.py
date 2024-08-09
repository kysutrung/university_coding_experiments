luong_tieu_chuan_theo_gio = 30
luong_nhan_duoc = 0.0
gio_lam = [None]*4
for tuan in range(0,4):
    print("Nhap so gio lam tuan thu", tuan+1, ":", end=" ")
    gio_lam[tuan] = int(input())
    if gio_lam[tuan] > 44:
        luong_nhan_duoc += 44 * luong_tieu_chuan_theo_gio
        luong_nhan_duoc += (gio_lam[tuan] - 44) * luong_tieu_chuan_theo_gio * 1.5
    else:
        luong_nhan_duoc += gio_lam[tuan] * luong_tieu_chuan_theo_gio
print("Luong cua ban la: ", luong_nhan_duoc*1000)