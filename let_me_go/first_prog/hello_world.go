package main

import "fmt" // đây là thư viện format 

var num_a int = 10

var(
	num_c int = 30
	str_a string = "meo meo"
)

func tinh_tong(n int, m int) int {
	return n + m
}

func so_sanh(n int, m int) {
	if n < m {
		fmt.Print("less than")
	}
	if n > m {
		fmt.Print("more than")
	}
	if n == m {
		fmt.Print("equal")
	}
}


func main() {
	//num_b := 20
	//khai báo kiểu rút gọn này chỉ dùng trong hàm main

    fmt.Print(tinh_tong(num_a, num_c))
	fmt.Println(" Xin chao co chu xin chao cac ban!!!")
	so_sanh(num_a, num_c)
}