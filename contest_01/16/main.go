package main
import "fmt"
import "os"
func main() {
	var n int
	fmt.Fscan(os.Stdin, &n)
	var input []int=make([]int, n)
	var smooth []float64=make([]float64, n)
	for i:=0; i<n; i++{
		fmt.Fscan(os.Stdin, &input[i])
	}
	smooth[0]=float64(input[0])
	smooth[n-1]=float64(input[n-1])
	for j:=1; j<n-1;j++{
		smooth[j]=(float64(input[j-1])+float64(input[j])+float64(input[j+1]))/3.0
	}
	for k:=0; k<n; k++{
		fmt.Print(smooth[k])
		fmt.Print(" ")
	}
}