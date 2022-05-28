// 3x3 matrix solver
#include <iostream>
#include <cstdlib>
#include <limits> 
#include <iomanip>
#include <fstream>
#include <cmath>
#include<ctime>

// set matrix size to 3x3 matrix
const int rows = 3;
const int columns = 3;
typedef double matrix[rows][columns];

// function prototypes
void matrix_solver();
void printMatrix(const matrix &mat);
bool inputMatrix(matrix &mat);
void addMat(const matrix &mat1, const matrix &mat2, matrix &result);
void subtractMat(const matrix &mat1, const matrix &mat2, matrix &result);
void multiMat(const matrix &mat1, const matrix &mat2, matrix &result);
void determinant();
void getMatrix(int choice);
void defineMat();
bool inverse(int A[rows][columns], int inverse[rows][columns]);
void adjoint(int A[rows][columns],int adj[rows][columns]);
void transposeMat(int matrix[rows][columns]);
void quiz();

using namespace std;

// declare matrices:
matrix matA;
matrix matB;
matrix result;

int main()
{
    int choose;
    
    cout << "1 - Quiz\n"
         << "2 - Matrix solver\n"
         << "3 - Delete account\n\n";
	cout << "Choose the option:";

    while(!(cin >> choose)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "\nERROR: Please enter valid input!\n" 
				 << "Enter your choice again: ";
		}
        
	switch(choose){
		case 1:
			cout << "----Quiz-----\n";
			quiz();
			break;
		case 2:
			cout << "----Matrix Solver----\n";
			matrix_solver();
            break;
		case 3:
			cout << "----Delete account-----\n";
            //delete account code
            break;
        default:
            cout << "Wrong input.\n";
	}
    return 0;
}

void quiz(){
    std::cout << std::setprecision(2) << std::fixed;
	ifstream scheme_answer;
    scheme_answer.open("answer.txt", ios::in);
	char answer[10];
	char student[10];
    clock_t tStart = clock();
	// Quiz 1
	cout << "1.A, B and C are matrices: A ( B + C ) = AB + CA.\n\n";
	cout << "  A. Always true\n  B. Sometimes true\n  C. False\n\n";
	cout << "Please enter the answer: ";
	cin  >> answer[0];

	while(answer[0]!='A'&&answer[0]!='B'&&answer[0]!='C'){
		cout << "Invalid,please enter the answer:";
		cin  >> answer[0];
	}
	cout << "\n" << endl;

	// Quiz 2
	cout << "2.What is an identity matrix and why is it called an identity matrix?\n\n";
	cout << "  A. An identity matrix is a matrix with all diagonal entries as 1 and all non-diagonal entries as 0. It is called an\n     identity matrix as it would give a null matrix as a result when multiplied by other matrix.\n";
    cout << "  B. An identity matrix is a matrix with all diagonal entries as 1 and all non-diagonal entries as 0. It is called an\n     identity matrix as it would not change the original matrix when multiplied by it.\n";
    cout << "  C. An identity matrix is a matrix with all its entries as 0. It is called an identity matrix as it would give a null\n     matrix as a result when multiplied by any other matrix.\n";
    cout << "  D. An identity matrix is a matrix with all its entries as 0. It is called an identity matrix as it would not change\n     the original matrix when multiplied by it.\n\n";
    cout << "Please enter the answer: ";
	cin  >> answer[1];

	while(answer[1]!='A'&&answer[1]!='B'&&answer[1]!='C'&&answer[1]!='D'){
		cout << "Invalid,please enter the answer:";
		cin  >> answer[1];
    }
    cout << "\n" << endl;

	// Quiz 3
    cout << "3.Which of the following matrix operations is commutative?\n\n";
    cout << "  A. Addition of Matrice\n  B. Subtraction of Matrices\n  C. Multiplication of Matrices\n  D. Division of Matrices\n\n";
    cout << "Please enter the answer: ";
	cin  >> answer[2];
    while(answer[2]!='A'&&answer[2]!='B'&&answer[2]!='C'&&answer[2]!='D'){
		cout << "Invalid,please enter the answer:";
		cin  >> answer[2];
    }
    cout << "\n" << endl;

	// Quiz 4
    cout << "4.Which of the following is not a square matrix?\n\n";
    cout << "  A. (1)\n  B. (5 8) (9 2)\n  C. (4 9) (16 25) (36 49)\n  D. (2 8 7 6 9) (8 7 6 0 3) (7 6 8 3 4) (1 4 7 2 6) (7 8 2 3 0)\n\n";
    cout << "Please enter the answer: ";
	cin  >> answer[3];
	while(answer[3]!='A'&&answer[3]!='B'&&answer[3]!='C'){
		cout << "Invalid,please enter the answer:";
		cin  >> answer[3];
	}
	cout << "\n" << endl;

	// Quiz 5
	cout << "5.Which of the following is impossible?\n\n";
	cout << "  A. Scalar Multiplication\n  B. Matrix Multiplication\n  C. Scalar Division\n  D. Matrix Division\n\n";
	cout << "Please enter the answer: ";
	cin  >> answer[4];
	while(answer[4]!='A'&&answer[4]!='B'&&answer[4]!='C'){
		cout << "Invalid,please enter the answer:";
		cin  >> answer[4];
	}
	cout << "\n" << endl;

	// Quiz 6
	cout << "6.What is Scalar Multiplication?\n\n";
    cout << "  A. The constant used to multiply into a matrix.\n  B. The operation of multiplying the matrix by another matrix.\n  C. The operation of multiplying the scalar to a matrix using distribution\n\n";
    cout << "Please enter the answer: ";
	cin  >> answer[5];
	while(answer[5]!='A'&&answer[5]!='B'&&answer[5]!='C'){
		cout << "Invalid,please enter the answer:";
		cin  >> answer[5];
	}
	cout << "\n" << endl;

	// Quiz 7
	cout << "7.When can you add or subtract matrices?\n\n";
	cout << "  A. When they have the same numbers in each matrix.\n  B. Only when its an equal matrix.\n  C. Only when the dimensions are the same\n\n";
	cout << "Please enter the answer: ";
	cin  >> answer[6];
	while(answer[6]!='A'&&answer[6]!='B'&&answer[6]!='C'){
		cout << "Invalid,please enter the answer:";
		cin  >> answer[6];
	}
	cout << "\n" << endl;

	// Quiz 8
	cout << "8.Consider the following statement:\n\n  1.Every zero matrix is square matrix.\n  2.A matrix has a numerical value.\n  3.A unit matrix is diagonal matrix.\n\n  Which of the above is/are correct?\n\n";
    cout << "  A. 2 only\n  B. 3 only\n  C. 2 and 3\n  D. 1 and 3\n\n ";
    cout << "Please enter the answer: ";
	cin  >> answer[7];
	while(answer[7]!='A'&&answer[7]!='B'&&answer[7]!='C'&&answer[7]!='D'){
		cout << "Invalid,please enter the answer:";
		cin  >> answer[7];
	}
	cout << "\n" << endl;

	// Quiz 9
	cout << "9.If A is an invertible skew-symmetric matrix,then A^-1 is a:\n\n";
    cout << "  A. Symmetric matrix\n  B. Skew-symmetic matrix.\n  C. Zero matrix\n  D. Identity matrix\n\n";
    cout << "Please enter the answer: ";
	cin  >> answer[8];
	while(answer[8]!='A'&&answer[8]!='B'&&answer[8]!='C' &&answer[8] != 'D'){
		cout << "Invalid,please enter the answer:";
		cin  >> answer[8];
	}
	cout << "\n" << endl;

	// Quiz 10
	cout << "10.If A is skew symmetric matrix,then A^2 is a:\n\n";
    cout << "   A. null matrix\n   B. unitary matrix\n   C. skew symmetric\n   D. symmetric\n\n";
    cout << "Please enter the answer: ";
	cin  >> answer[9];
	while(answer[9]!='A'&&answer[9]!='B'&&answer[9]!='C' && answer[9] != 'D'){
		cout << "Invalid,please enter the answer:";
		cin  >> answer[9];
    }
    cout << "\n" << endl;
    double time_taken=((double)(clock() - tStart)/CLOCKS_PER_SEC);
    cout<<"Time taken:"<<time_taken<<"\n";

	//Calculate marks
	int a=0,b=0;
	cout << "A list of questions (correct): ";
	for(int i=0;i<10;i++){
		scheme_answer >> student[i];
		if (answer[i]==student[i]){
		a++;
		cout << i+1 << " ";}
		}
		cout << "\n";
		cout << "A list of questions (incorrect): ";
	for (int i=0;i<10;i++){
		scheme_answer >> student[i];
		if (answer[i]!=student[i]){
		b++;
		cout << i+1 << " ";}}
		cout << "\n";
	double percentage=100*(10-b)/10;
	cout << "The percentage of questions answered correctly: " << percentage;	
}

void matrix_solver(){
    int choice = -1;

    while(choice != 7) {
        cout << "When filling up matrices, separate individual elements \n"
			"by a space(e.g 2 4 1.4 56.3 ...) \n\n";
            system("CLS");

        cout << "\n** You choose from the following **\n\n"
            << "1 - Addition\n"
            << "2 - Substraction\n"
            << "3 - Multiplication\n"
            << "4 - Determinant\n"
            << "5 - Inverse\n"
            << "6 - Transpose\n"
            << "7 - Quit\n"
            << "Enter your choice: ";

		while(!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "\nERROR: Please enter valid input!\n" 
				 << "Enter your choice again: ";
		}
        
        cout << endl;

        switch(choice) {
        case 1 :
            defineMat();
            cout << "Matrix A:\n";
            printMatrix(matA);
            cout << "\nMatrix B:\n";
            printMatrix(matB);
            addMat(matA, matB, result);
            cout << "\nAddition of Matrix A and Matrix B is:\n";
            printMatrix(result);
            break;

        case 2 :
            defineMat();
            cout << "Matrix A:\n";
            printMatrix(matA);
            cout << "\nMatrix B:\n";
            printMatrix(matB);
            subtractMat(matA, matB, result);
            cout << "\nSubtraction of Matrix A and Matrix B is:\n";
            printMatrix(result);
            break;

        case 3 :
            defineMat();
            cout << "Matrix A:\n";
            printMatrix(matA);
            cout << "\nMatrix B:\n";
            printMatrix(matB);
            multiMat(matA, matB, result);
            cout << "\nMultiplication of Matrix A and Matrix B is:\n";
            printMatrix(result);
            break;

        case 4 :
            getMatrix(choice);
            break;

        case 5 :
            getMatrix(choice);
            break;
        
        case 6 :
            getMatrix(choice);

        case 7 :
            cout << "End the program...";
            break;

        default :
            cout << "Wrong input.\n";
        }

        cout << "\npress any key...\n";

		// clears input buffer and wait for input:
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        system("CLS");
    }
    cout << "Thank you.";
}

void defineMat()
{ 
    while(true) {
		cout << "input 9 elements into your 3x3 matrix A: \n";
		if(inputMatrix(matA))
			break;
	}
	
	while(true) {
		cout << "input 9 elements into your 3x3 matrix B: \n";
		if(inputMatrix(matB))
			break;
	}
}

void printMatrix(const matrix &mat)
{
    for(int i = 0; i < rows; i++) {
        cout << "[";
        for(int j = 0; j < columns; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "]" << endl;
    }
}

bool inputMatrix(matrix &mat)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cin >> mat[i][j];
			// terminates function on failure
            if(cin.fail()) {
                cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "\nERROR: Please enter valid input!\n" << endl;
                return false;
            }
        }
    }
	// trims the excess input from input buffer:
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return true;
}

void addMat(const matrix &mat1, const matrix &mat2, matrix &result)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMat(const matrix &mat1, const matrix &mat2, matrix &result)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiMat(const matrix &mat1, const matrix &mat2, matrix &result)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            for (int k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];  
            }
        }
    }
}

// Dimension of input square matrix
#define N 3
 
// Function to get cofactor of mat[p][q] in temp[][]. n is
// current dimension of mat[][]
void getCofactor(int mat[N][N], int temp[N][N], int p,
                 int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those
            //  element which are not in given row and
            //  column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
int determinant(int mat[N][N], int n)
{
    int D = 0; // Initialize result
 
    //  Base case : if matrix contains single element
    if (n == 1)
        return mat[0][0];
 
    int temp[N][N]; // To store cofactors
 
    int sign = 1; // To store sign multiplier
 
    // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinant(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}
// Function to get adjoint of mat[N][N] in adj[N][N].
void adjoint(int A[N][N],int adj[N][N])
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }
 
    // temp is used to store cofactors of A[][]
    int sign = 1, temp[N][N];
 
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, N);
 
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;
 
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}
 
// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(int A[N][N], int inverse[N][N])
{
    // Find determinant of A[][]
    int det = determinant(A, N);
    if (det == 0)
    {
        cout << "Singular matrix (determinant = 0), can't find its inverse";
        return false;
    }
 
    // Find adjoint
    int adj[N][N];
    adjoint(A, adj);
 
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inverse[i][j] = adj[i][j]/float(det);
 
    return true;
}

void display(int A[N][N])
{
   for(int i = 0; i < rows; i++) {
        cout << "[";
        for(int j = 0; j < columns; j++) {
            cout << A[i][j] << "\t";
        }
        cout << "]" << endl;
    }
}
 
// get matrix
void getMatrix(int choice)
{
    int mat[rows][columns];
    int adj[rows][columns]; // to store adjoint
    int inv[rows][columns]; // to store inverse
	cout << "input 9 elements into your 3x3 matrix: \n";
	for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cin >> mat[i][j];
        }
    }
    
    if (choice == 4) {
        // Function call to find determinant of matrix
        printf("Determinant of the matrix is : %d",
           determinant(mat, N)); }
           
    else if (choice == 5) {
        // Find adjoint
        cout << "The adjoint of the matrix is :" << endl;
        adjoint(mat, adj);
        display(adj);

        // Find inverse
        cout << "The inverse of the matrix is :" << endl;
        if (inverse(mat, inv))
            display(inv); }
    else if (choice == 6) {
        transposeMat(mat); }
    
}

// transpose function
void transposeMat(int matrix[rows][columns])
{
    int transpose[rows][columns];

    // Computing transpose of the matrix
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
      }
    
    cout << "Original Matrix:" << endl;
    display(matrix);
    
    cout << "\n Transpose of Matrix:" << endl;
    display(transpose);
}
