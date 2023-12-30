package main

import "fmt"

type Matrix struct {
	data [][]int
}

func NewMatrix(rows, cols, value int) Matrix {
	data := make([][]int, rows)
	for i := range data {
	 data[i] = make([]int, cols)
	 for j := range data[i] {
	  data[i][j] = value
	 }
	}
	return Matrix{data: data}
   }
   
   func (m *Matrix) Rows() int {
	return len(m.data)
   }
   
   func (m *Matrix) Cols() int {
	if m.Rows() == 0 {
	 return 0
	}
	return len(m.data[0])
   }
   
   func (m *Matrix) Set(row, col, value int) {
	m.data[row][col] = value
   }
   
   func (m *Matrix) Get(row, col int) int {
	return m.data[row][col]
   }
   
   func (m *Matrix) Convolution(core *Matrix) Matrix {
	   nrows := m.Rows() - core.Rows() + 1
	   ncols := m.Cols() - core.Cols() + 1
	   newMat := NewMatrix(nrows, ncols, 0)
	   for i := 0; i < nrows; i++ {
		   for j := 0; j < ncols; j++ {
			   for k := 0; k < core.Rows(); k++ {
				   for l := 0; l < core.Cols(); l++ {
					   newMat.data[i][j] += m.data[i+k][j+l] * core.data[k][l]
				   }
			   }
		   }
	   }
	   return newMat
   }
   
   func (a *Matrix) Multiplication(b *Matrix) *Matrix {
	result := NewMatrix(a.Rows(), b.Cols(), 0)
	for i := 0; i < a.Rows(); i++ {
	 for j := 0; j < b.Cols(); j++ {
	  for k := 0; k < a.Cols(); k++ {
	   result.data[i][j] += a.data[i][k] * b.data[k][j]
	  }
	 }
	}
	return &result
   }
   
   func (m *Matrix) AddRow(value int) {
	m.data = append(m.data, make([]int, m.Cols()))
	for i := range m.data[m.Rows()-1] {
	 m.data[m.Rows()-1][i] = value
	}
   }
   
   func (m *Matrix) AddCol(value int) {
	for i := range m.data {
	 m.data[i] = append(m.data[i], value)
	}
   }
   
   func (m *Matrix) String() string {
	var result string
	for _, row := range m.data {
	 for _, val := range row {
	  result += fmt.Sprintf("%d ", val)
	 }
	 result += "\n"
	}
	return result
   }

func main() {
	var rowsFirst, colsFirst, firstInitVal,
		rowsCore, colsCore int

	fmt.Scan(&rowsFirst, &colsFirst, &firstInitVal)
	first := NewMatrix(rowsFirst, colsFirst, firstInitVal)
	for i := 0; i < first.Rows(); i++ {
		for j := 0; j < first.Cols(); j++ {
			var t int
			fmt.Scan(&t)
			first.Set(i, j, t)
		}
	}

	fmt.Scan(&rowsCore, &colsCore)
	core := NewMatrix(rowsCore, colsCore, 0)
	for i := 0; i < core.Rows(); i++ {
		for j := 0; j < core.Cols(); j++ {
			var t int
			fmt.Scan(&t)
			core.Set(i, j, t)
		}
	}

	conv := first.Convolution(&core)

	conv.AddRow(1)
	conv.AddCol(1)
	conv.AddCol(1)

	mult := conv.Multiplication(&first)

	fmt.Print(mult)
}
