package main
import "fmt"
func main() {
 var x int 
 fmt.Scanln(&x)
 st:=0
 for x!=1 {
     if x%2==0 {
         x=x/2
         st++
     } else {
         x=3*x+1
         st++
     }
 }
 fmt.Print(st)
}