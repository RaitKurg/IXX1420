#ifndef BASE_MATH_H
#define BASE_MATH_H

#include <iostream>

template <class T>
class Matrix
{

    public:
        Matrix() {}

        Matrix(int rows, int cols)
        {
            m_values = new T[rows*cols];
            for (int i = 0; i < rows*cols; i++) {
                m_values[i] = 0;
            }
            m_rows = rows;
            m_cols = cols;
        }

        ~Matrix()
        {
            delete [] m_values;
        }

        T get(int r, int c)
        {
            return m_values[c + r*m_cols];
        }

        void set(int r, int c, T value)
        {
            m_values[c + r*m_cols] = value;   
        }

        void print()
        {
            int offset = 0;
            for (int r = 0; r < m_rows; r++) {
                for (int c = offset; c < offset + m_cols; c++) {
                    std::cout << m_values[c] << "\t";
                }
                std::cout << "\n";
                offset += m_cols;
            }
        }

        Matrix<T> operator + (Matrix<T>& B)
        {
            Matrix<T> C(m_rows, m_cols);
            for (int i = 0; i < m_rows*m_cols; i++) {
                C.m_values[i] = m_values[i] + B.m_values[i];
            }
            return C;
        }

        Matrix<T> operator - (Matrix<T>& B)
        {
            Matrix<T> C(m_rows, m_cols);
            for (int i = 0; i < m_rows*m_cols; i++) {
                C.m_values[i] = m_values[i] - B.m_values[i];
            }
            return C;
        }

        void operator += (Matrix<T>& B)
        {
            for (int i = 0; i < m_rows*m_cols; i++) {
                m_values[i] = m_values[i] + B.m_values[i];
            }
        }

        void operator -= (Matrix<T>& B)
        {
            for (int i = 0; i < m_rows*m_cols; i++) {
                m_values[i] = m_values[i] - B.m_values[i];
            }
        }

    private:
        T * m_values;
        int m_rows;
        int m_cols;

};
    
#endif