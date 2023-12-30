package main
import "fmt"
func main() {
	var N int 
	fmt.Scanln(&N)
	N5k:=N/5000
	N1k:=(N-5000*N5k)/1000
	N500:=(N-5000*N5k-1000*N1k)/500
	N200:=(N-5000*N5k-1000*N1k-500*N500)/200
	N100:=(N-5000*N5k-1000*N1k-500*N500-200*N200)/100
	fmt.Println(N5k, N1k, N500, N200, N100)
}