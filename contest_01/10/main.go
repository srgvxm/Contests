package main
import "fmt"
func main() {
	var swim, wing, neck string 
	fmt.Scanf("%s %s %s",&swim,&wing,&neck)
    if swim=="Нет" {
        if wing=="Нет" {
            if neck=="Нет" {
                fmt.Print("Кот")
            } else {
                fmt.Print("Жираф")
            }
        } else {
            if neck=="Нет" {
                fmt.Print("Курица")
            } else {
                fmt.Print("Страус")
            }
        }
    } else {
        if wing=="Нет" {
            if neck=="Нет" {
                fmt.Print("Дельфин")
            } else {
                fmt.Print("Плезиозавры")
            }
        } else {
            if neck=="Нет" {
                fmt.Print("Пингвин")
            } else {
                fmt.Print("Утка")
            }
        }
    }
}