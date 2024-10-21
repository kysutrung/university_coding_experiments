//Tính tổng 1 slice

package main

import "fmt"

func sum(arr []int) int {
	tong := 0
	for num_1, num_2 := range arr {
		tong += num_2 + num_1
	}
	return tong
}

func main() {
	nums := []int{1, 2, 9, 4, 4}
	fmt.Println("Tong: ", sum(nums))
}
