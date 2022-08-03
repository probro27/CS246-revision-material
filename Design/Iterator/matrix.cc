#include "matrix.h"
#include <utility>

using namespace std;

// template class Matrix<int>;

template <typename T>
Matrix<T>::Matrix(): _numRows{0}, _numCols{0}, _matrix{nullptr} {}

template <typename T>
Matrix<T>::Matrix(int dimensions): _numRows{dimensions}, _numCols{dimensions} {
    _matrix = new T*[dimensions]; // dimension rows
    for(int i = 0; i < dimensions; ++i) {
        _matrix[i] = new T[dimensions];
    }
}

template <typename T>
void Matrix<T>::swap(Matrix<T> other) noexcept {
    using std::swap;
    swap(_numCols, other._numCols);
    swap(_numRows, other._numRows);
    swap(_matrix, other._matrix);
}

template <typename T>
Matrix<T>::Matrix(Matrix<T> &&other) noexcept: _numCols{other._numCols}, _numRows{other._numRows}, _matrix{other._matrix}{
    other._numRows = 0;
    other._numCols = 0;
    other._matrix = nullptr;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &other): _numRows{other._numRows}, _numCols{other._numCols} {
    int ** matrix = new T*[_numRows];
    for(int i = 0; i < _numRows; ++i) {
        matrix[i] = new T[_numCols];
    }
    for(int i = 0; i < _numRows; ++i) {
        for(int j = 0; j < _numCols; ++j) {
            matrix[i][j] = other._matrix[i][j];
        }
    }
    _matrix = matrix;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other) {
    Matrix<T> temp = other;
    swap(temp);
    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&other) noexcept{
    swap(other);
    return *this;
}

template <typename T>
T &Matrix<T>::get(int row, int col) const {
    return _matrix[row][col];
}

template <typename T>
void Matrix<T>::resize(int numRows, int numCols) {
    for(int i = 0; i < _numRows; ++i) {
        delete[] _matrix[i];
    }
    _numCols = numCols;
    _numRows = numRows;
    _matrix = new T*[numRows];
    for(int i = 0; i < numRows; ++i) {
        _matrix[i] = new T[numCols];
    }
}

template <typename T>
void Matrix<T>::set(int row, int col, T value) {
    _matrix[row][col] = value;
}


template <typename T>
Matrix<T>::~Matrix() {
    for(int i = 0; i < _numRows; ++i){
        delete [] _matrix[i];
    }
    _numRows = 0;
    _numCols = 0;
    _matrix = nullptr;
}

template <typename T>
Matrix<T>::Iterator::Iterator(int numRows, int numCols, int **matrix): _curRow{0}, _curCol{0}, _numRow{numRows}, _numCol{numCols}, _matrix{matrix} {}

template <typename T>
typename Matrix<T>::Iterator &Matrix<T>::Iterator::operator++() {
    _curCol++;
    if(_curCol == _numCol) {
        if(_curRow != _numRow) {
            _curRow++;
            _curCol = 0;
        }
        else {
            _matrix = nullptr;
        }
    }
    return *this;
}

template <typename T>
T &Matrix<T>::Iterator::operator*() {
    return _matrix[_curRow][_curCol];
}

template <typename T>
bool Matrix<T>::Iterator::operator==(const Iterator &other) {
    return _matrix == other._matrix;
}

template <typename T>
bool Matrix<T>::Iterator::operator!=(const Iterator &other) {
    return !(*this == other);
}

template <typename T>
typename Matrix<T>::Iterator Matrix<T>::begin() {
    return Iterator{_numRows, _numCols, _matrix};
}

template <typename T>
typename Matrix<T>::Iterator Matrix<T>::end() {
    return Iterator{_numRows, _numCols, nullptr};
}
