package main

import "fmt"

func fizz_buzz(){
	for u := 1; u < 101; u++ {
		if(u % 3 == 0){
			fmt.Print(u)
			fmt.Println(" Fizz")			
		}
		if(u % 5 == 0){
			fmt.Print(u)
			fmt.Println(" Buzz")			
		}
		if(u % 5 == 0 && u % 3 == 0){
			fmt.Print(u)
			fmt.Println(" FizzBuzz")			
		} else {
			fmt.Println(u)
		}
	}
}

func main(){
	fizz_buzz()
}