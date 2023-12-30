package main

import "fmt"

const rows int = 9
const cols int = 9

func isValidSudoku(bord [9][9]int) bool {
	var arr_1, arr_2 [10]int8 = [10]int8{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, [10]int8{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			arr_1[bord[i][j]] += 1
			arr_2[bord[j][i]] += 1
		}
		if arr_1 != [10]int8{0, 1, 1, 1, 1, 1, 1, 1, 1, 1} || arr_2 != [10]int8{0, 1, 1, 1, 1, 1, 1, 1, 1, 1} {
			return false
		}
		arr_1 = [10]int8{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		arr_2 = [10]int8{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	}
	for i := 1; i < 8; i += 3 {
		for j := 1; j < 8; j += 3 {
			arr_1[bord[i][j]] += 1
			arr_1[bord[i][j-1]] += 1
			arr_1[bord[i][j+1]] += 1
			arr_1[bord[i+1][j]] += 1
			arr_1[bord[i+1][j+1]] += 1
			arr_1[bord[i+1][j-1]] += 1
			arr_1[bord[i-1][j]] += 1
			arr_1[bord[i-1][j+1]] += 1
			arr_1[bord[i-1][j-1]] += 1
			if arr_1 != [10]int8{0, 1, 1, 1, 1, 1, 1, 1, 1, 1} {
			    return false
		    }
		    arr_1 = [10]int8{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		}
	}
	return true
}

func main() {
	var bord [rows][cols]int

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			fmt.Scanf("%c", &bord[row][col]) // Считываем один символ
			bord[row][col] -= '0'            // Чтобы из ASCII кода символа получить цифру
		}
		fmt.Scanf("\n")
	}

	if isValidSudoku(bord) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
