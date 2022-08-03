#include <iostream>

template <typename T>
class Matrix {
    int _numRows, _numCols;
    T ** _matrix;

public:
    Matrix();

    Matrix(int dimensions);

    Matrix(const Matrix &other);

    Matrix(Matrix &&other);

    void swap(Matrix m) noexcept;

    Matrix &operator=(const Matrix &other);

    Matrix &operator=(Matrix &&other) noexcept;

    void resize(int numRows, int numCols);

    int getNumRows() const;

    int getNumCols() const;

    T &get(int row, int col) const;

    void set(int row, int col, T value);

    Matrix operator+(const Matrix other);

    ~Matrix();

    friend std::ostream &operator<<(std::ostream &out, const Matrix m);
};

std::ostream &operator<<(std::ostream &out, const Matrix<int> m);
