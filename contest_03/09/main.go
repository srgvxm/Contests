package main

import "fmt"
import "sort"
	
func main() {
	var n int
	var X int64
	var i int = 0
	fmt.Scan(&n, &X)
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	sort.SliceStable(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})
	n -= 1
	for true {
		if i == n {
			fmt.Println("0 0")
			break
		} else if (arr[i] + arr[n]) == X {
			fmt.Println(arr[i], arr[n])
			break
		} else if (arr[i] + arr[n]) < X {
			i += 1
		} else if (arr[i] + arr[n]) > X {
			n -= 1
		}
	}
}
