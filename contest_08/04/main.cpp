#include <iostream>
#include <tuple>

int** new_matrix(int rows, int cols, int value=0);
std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows=3, int ccols=3);
std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols);
std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value=1);
std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value=1);
void delete_matrix(int*** matrix, int rows);
void print(int** matrix, int rows, int cols);

int main(){
    int rows_first, cols_first, first_init_val,
        rows_core, cols_core;
        
    std::cin >> rows_first >> cols_first >> first_init_val;
    int** first = new_matrix(rows_first, cols_first, first_init_val);
    for(int i=0; i < rows_first; i++)
        for(int j=0; j < cols_first; j++)
            std::cin >> first[i][j];

    std::cin >> rows_core >> cols_core;
    int** core = new_matrix(rows_core, cols_core);
    for(int i=0; i < rows_core; i++)
        for(int j=0; j < cols_core; j++)
            std::cin >> core[i][j];
    
    auto [conv, rows_conv, cols_conv] = convolution(first, rows_first, cols_first, core);
    
    std::tie(rows_conv, cols_conv) = add_row(&conv, rows_conv, cols_conv);
    std::tie(rows_conv, cols_conv) = add_col(&conv, rows_conv, cols_conv);
    std::tie(rows_conv, cols_conv) = add_col(&conv, rows_conv, cols_conv);
    
    auto [mult, rows_mult, cols_mult] = multiplication(conv, rows_conv, cols_conv, first, rows_first, cols_first);
    
    print(mult, rows_mult, cols_mult);
    
    delete_matrix(&first, rows_first);
    delete_matrix(&conv, rows_conv);
    delete_matrix(&mult, rows_mult);
}

int** new_matrix(int rows, int cols, int value) {
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        std::fill(matrix[i], matrix[i] + cols, value);
    }
    return matrix;
}

std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows, int ccols) {
    int nrows = mrows - crows + 1;
    int ncols = mcols - ccols + 1;
    int** new_mat = new_matrix(nrows, ncols);
    for(int i = 0; i < nrows; ++i)
        for(int j = 0; j < ncols; ++j)
            for(int m = 0; m < crows; ++m)
                for(int n = 0; n < ccols; ++n)
                    new_mat[i][j] += matrix[i + m][j + n] * core[m][n];
    return {new_mat, nrows, ncols};
}

std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols) {
    int** result = new_matrix(arows, bcols);
    for(int i = 0; i < arows; ++i)
        for(int j = 0; j < bcols; ++j)
            for(int k = 0; k < acols; ++k)
                result[i][j] += a[i][k] * b[k][j];
    return {result, arows, bcols};
}

std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value) {
    int** new_mat = new_matrix(rows + 1, cols, value);
    for(int i = 0; i < rows; ++i)
        std::copy((*matrix)[i], (*matrix)[i] + cols, new_mat[i]);
    delete_matrix(matrix, rows);
    *matrix = new_mat;
    return {rows + 1, cols};
}

std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value) {
    int** new_mat = new_matrix(rows, cols + 1, value);
    for(int i = 0; i < rows; ++i) {
        std::copy((*matrix)[i], (*matrix)[i] + cols, new_mat[i]);
        new_mat[i][cols] = value;
    }
    delete_matrix(matrix, rows);
    *matrix = new_mat;
    return {rows, cols + 1};
}

void delete_matrix(int*** matrix, int rows) {
    for(int i = 0; i < rows; ++i)
        delete[] (*matrix)[i];
    delete[] *matrix;
    *matrix = nullptr;
}

void print(int** matrix, int rows, int cols) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
}