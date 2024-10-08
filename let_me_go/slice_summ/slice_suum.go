//Tính tổng 1 slice

package main

import "fmt"

func sum(arr []int) int {
	tong := 0
	for meo, gau := range arr {
		tong += gau
		fmt.Println(meo)
	}
	return tong
}

func main() {
	nums := []int{1, 2, 9, 4, 4}
	fmt.Println("Tong: ", sum(nums))
}
