package main
import (
	"bufio"
	"fmt"
	"os"
)

func isLucky(a string) bool {
	var first, second int
	for i := 0; i < 3; i++ {
		first += int(a[i])
		second += int(a[i+3])
	}
	return first == second
}

func main() {
	number, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isLucky( number[:len(number)-1] ){
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
