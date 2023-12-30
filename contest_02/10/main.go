package main

import "fmt"

func shift(data []int, s int) {
	var arr_ [10]int
	s = (s%10 + 10) % 10
	for i := 0; i < 10; i++ {
		arr_[(i+s)%10] = data[i]
	}
	copy(data, arr_[:])
}

func main() {
	var steps int
	fmt.Scan(&steps)

	var data [10]int
	for index := range data {
		fmt.Scan(&data[index])
	}

	shift(data[:], steps)
	for _, value := range data {
		fmt.Printf("%d ", value)
	}
}
