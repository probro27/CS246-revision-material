#include <iostream>

template <typename T>
class Matrix {
    int _numRows, _numCols;
    T ** _matrix;

public:
    class Iterator {
        int _curRow, _curCol;
        int _numRow, _numCol;
        int **_matrix;
        public:
            explicit Iterator(int numRows, int numCols, int **matrix);

            Iterator &operator++();
            T &operator*(); 
            bool &operator==(const Iterator &other);
            bool &operator!=(const Iterator &other);
    };
    Matrix();

    Matrix(int dimensions);

    Matrix(const Matrix &other);

    Matrix(Matrix &&other) noexcept;

    void swap(Matrix m) noexcept;

    Matrix &operator=(const Matrix &other);

    Matrix &operator=(Matrix &&other) noexcept;

    void resize(int numRows, int numCols);

    int getNumRows() const;

    int getNumCols() const;

    T &get(int row, int col) const;

    void set(int row, int col, T value);

    Matrix operator+(const Matrix other);

    Iterator begin();

    Iterator end();

    ~Matrix();

    friend std::ostream &operator<<(std::ostream &out, const Matrix m);
    friend Iterator;
};

std::ostream &operator<<(std::ostream &out, const Matrix<int> m);
