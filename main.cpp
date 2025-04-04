#include "matrix.hpp"  // Include the Matrix class header file
#include <iostream>    // Standard input/output library

int main(int argc, char *argv[]) {
    // Check if correct number of command line arguments are provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;  // Return error code if incorrect usage
    }

    std::string filename = argv[1];  // Get input filename from command line
    std::ifstream in(filename);      // Open input file
    if (!in) {  // Check if file opened successfully
        std::cerr << "Error opening file.\n";
        return 1;  // Return error code if file can't be opened
    }

    size_t N;  // Variable to store matrix dimension
    in >> N;   // Read matrix dimension from file
    Matrix A(N), B(N);  // Create two NxN matrices

    // Read matrix A from file
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            in >> A.update_element(i, j, 0),  // Initialize element to 0
            in >> A.update_element(i, j, A.get_element(i, j) + std::stoi(argv[1]));  // Add command line argument value

    // Read matrix B from file
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            in >> B.update_element(i, j, 0),  // Initialize element to 0
            in >> B.update_element(i, j, B.get_element(i, j) + std::stoi(argv[1]));  // Add command line argument value

    // Print matrix A
    std::cout << "Matrix A:\n";
    A.print_matrix();

    // Print matrix B
    std::cout << "\nMatrix B:\n";
    B.print_matrix();

    // Calculate and print sum of A and B
    std::cout << "\nMatrix A + B:\n";
    Matrix sum = Matrix::add(A, B);
    sum.print_matrix();

    // Calculate and print product of A and B
    std::cout << "\nMatrix A * B:\n";
    Matrix product = Matrix::multiply(A, B);
    product.print_matrix();

    // Calculate and print sums of diagonals of A
    std::cout << "\nMain diagonal sum of A: " << A.sum_main_diagonal() << "\n";
    std::cout << "Secondary diagonal sum of A: " << A.sum_secondary_diagonal() << "\n";

    // Swap rows 0 and 1 in A and print result
    std::cout << "\nSwapping rows 0 and 1 in A:\n";
    A.swap_rows(0, 1);
    A.print_matrix();

    // Swap columns 0 and 1 in A and print result
    std::cout << "\nSwapping columns 0 and 1 in A:\n";
    A.swap_columns(0, 1);
    A.print_matrix();

    // Update element at (0,0) to 99 in A and print result
    std::cout << "\nUpdating element at (0,0) to 99 in A:\n";
    A.update_element(0, 0, 99);
    A.print_matrix();

    return 0;  // Successful program termination
}
