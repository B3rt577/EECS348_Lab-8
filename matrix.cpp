#include "matrix.hpp"  // Include the Matrix class header
#include <iostream>    // For input/output operations
#include <fstream>     // For file operations
#include <iomanip>     // For output formatting (setw)

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// Constructor that creates an N x N matrix initialized with zeros
Matrix::Matrix(size_t N) : size(N), mat(N, std::vector<int>(N)) {}

// Default constructor - creates an empty matrix
Matrix::Matrix() : size(0) {}

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"
// Reads matrix data from a file
void Matrix::read_from_file(const std::string& filename) {
    std::ifstream in(filename);  // Open input file
    if (!in) {  // Check if file opened successfully
        std::cerr << "Error opening file.\n";
        return;
    }

    in >> size;  // Read matrix size (dimension) from file
    // Initialize matrix with read size
    mat = std::vector<std::vector<int>>(size, std::vector<int>(size));

    // Read first matrix from file
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            in >> mat[i][j];  // Read each element

    print_matrix();  // Display the first matrix

    // Read second matrix from file (overwrites the first)
    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < size; ++j)
            in >> mat[i][j];

    std::cout << "\nSecond Matrix:\n";
    print_matrix();  // Display the second matrix
}

// Prints the matrix with formatted output
void Matrix::print_matrix() const {
    for (const auto& row : mat) {  // Iterate through each row
        for (int val : row)       // Iterate through each element in row
            std::cout << std::setw(4) << val;  // Format output with width 4
        std::cout << "\n";  // Newline after each row
    }
}

// Static method to add two matrices
Matrix Matrix::add(const Matrix& A, const Matrix& B) {
    Matrix result(A.size);  // Create result matrix of same size
    for (size_t i = 0; i < A.size; ++i)
        for (size_t j = 0; j < A.size; ++j)
            result.mat[i][j] = A.mat[i][j] + B.mat[i][j];  // Element-wise addition
    return result;
}

// Static method to multiply two matrices
Matrix Matrix::multiply(const Matrix& A, const Matrix& B) {
    Matrix result(A.size);  // Create result matrix
    for (size_t i = 0; i < A.size; ++i)
        for (size_t j = 0; j < A.size; ++j)
            for (size_t k = 0; k < A.size; ++k)
                result.mat[i][j] += A.mat[i][k] * B.mat[k][j];  // Dot product
    return result;
}

// Calculates sum of main diagonal (top-left to bottom-right)
int Matrix::sum_main_diagonal() const {
    int sum = 0;
    for (size_t i = 0; i < size; ++i)
        sum += mat[i][i];  // Add elements where row == column
    return sum;
}

// Calculates sum of secondary diagonal (top-right to bottom-left)
int Matrix::sum_secondary_diagonal() const {
    int sum = 0;
    for (size_t i = 0; i < size; ++i)
        sum += mat[i][size - i - 1];  // Add elements where row + column = size-1
    return sum;
}

// Swaps two rows in the matrix
void Matrix::swap_rows(size_t row1, size_t row2) {
    if (row1 >= size || row2 >= size) return;  // Bounds checking
    std::swap(mat[row1], mat[row2]);  // Swap entire rows
}

// Swaps two columns in the matrix
void Matrix::swap_columns(size_t col1, size_t col2) {
    if (col1 >= size || col2 >= size) return;  // Bounds checking
    for (size_t i = 0; i < size; ++i)
        std::swap(mat[i][col1], mat[i][col2]);  // Swap elements column-wise
}

// Updates a specific element in the matrix
void Matrix::update_element(size_t row, size_t col, int value) {
    if (row >= size || col >= size) return;  // Bounds checking
    mat[row][col] = value;  // Assign new value
}

// Returns the size (dimension) of the matrix
size_t Matrix::get_size() const {
    return size;
}

// Returns the value at a specific matrix position
int Matrix::get_element(size_t row, size_t col) const {
    return mat[row][col];  // Direct access to element
}
