package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]string, n)
	var nums = map[string]int{}
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
		if val, ok := nums[arr[i]]; ok {
			nums[arr[i]] = val + 1
		} else {
			nums[arr[i]] = 1
		}
	}
	for key, value := range nums {
		if value%2 == 1 {
			fmt.Println(key)
		}
	}
}
