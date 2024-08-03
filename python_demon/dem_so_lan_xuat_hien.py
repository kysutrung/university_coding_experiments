#Bài tập đếm số lần xuất hiện của kí tự N trong một chuỗi

count = 0
char_n = "d"
str_1 = "dddditmemay"

for i in str_1:
    if i == char_n:
        count += 1

print(count)