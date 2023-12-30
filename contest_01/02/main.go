package main

import "fmt"
import "math"

func main() {
    fmt.Println(365 * 0.5, math.Ceil(365 * 0.5 / 32), math.Ceil(365 * 0.5 / 20))
}