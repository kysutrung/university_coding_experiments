package main

import "fmt" // đây là thư viện format 

var num_a int = 10

var(
	num_c int = 30
	str_a string = "meo meo"
)

func find_min_max(arr [5]int){
	var min_var int = arr[0]
	var max_var int = arr[0]

	for i := 0; i < 5; i++ {
		if min_var > arr[i] {
			min_var = arr[i]
		}
		if max_var < arr[i] {
			max_var = arr[i]
		}
	}

	fmt.Print("Max = ")
	fmt.Println(max_var)
	fmt.Print("Min = ")
	fmt.Println(min_var)
}

func main() {
	fmt.Println("Hello World!!!")
	fmt.Println("I found them :v")
	var arr_a [5]int
	arr_a[0] = 21
	arr_a[1] = 41
	arr_a[2] = 31
	arr_a[3] = 0
	arr_a[4] = 99

	find_min_max(arr_a)
}