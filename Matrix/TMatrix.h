// ------------------------------------------------
// A matrix template class.
//
//
// ------------------------------------------------
#ifndef __MATRIX_TEMPLATE__H_
#define __MATRIX_TEMPLATE__H_

#include <iostream>
#include <stdexcept>


namespace tobechanged {

    template<typename T>class Matrix
    {
    public:


    private:
         T** const m_data;
         const unsigned int m_row_s;
         const unsigned int m_col_s;

    public:

        // ----------------------------------------
        // Ctors
        // ----------------------------------------

        // ctor
        Matrix(unsigned int row, unsigned int col) : 
            m_data(new T*[row]), 
            m_row_s(row), 
            m_col_s(col)
        {
            
            if (row == 0 || col == 0) {
                throw std::out_of_range("Can not create a matrix with 0 size."); 
            }

            for (unsigned int i = 0; i < row; i++) {
                m_data[i] = new T[col];
            }
        }

        // destructor
        ~Matrix() {
            // delete row arrays
            for (unsigned int i = 0; i < m_row_s; ++i) {
                delete[] m_data[i];
            }

            // delete original array
            delete[] m_data;
        }

        // copy ctor
        Matrix<T>(const Matrix<T>& lhs) : 
            m_row_s(lhs.m_row_s),
            m_col_s(lhs.m_col_s),
            m_data(new T*[lhs.m_row_s])
        {
            for (unsigned int i = 0; i < m_row_s; i++) {
                m_data[i] = new T[m_col_s];
            }
            
            for (unsigned int r = 0; r < m_row_s; ++r) {
                for (unsigned int c = 0; c < m_col_s; ++c) {
                    m_data[r][c] = lhs(r,c);
                }
            }  
        }

       
        // ----------------------------------------------------------------
        // operators
        // ----------------------------------------------------------------


        // assignment
        Matrix<T>& operator=(const Matrix<T>& rhs){
             
            if (rhs.m_col_s != m_col_s || rhs.m_row_s != m_row_s) {
                throw std::range_error("Cannot assign incompatible matrices.");
            }

            for (unsigned int r = 0; r < m_row_s; ++r) {
                for (unsigned int c = 0; c < m_col_s; ++c) {
                    m_data[r][c] = rhs(r, c);
                }
            }
            return *this;
        }

        // addressing
        T& operator()(unsigned int row, unsigned int col) const {
            if (col < m_col_s && row < m_row_s) {
                return m_data[row][col];
            }
            else{ 
                throw std::out_of_range("Matrix range exceeded."); 
            }
        }

        // addition
        Matrix<T> operator+(Matrix<T>& rhs) {
            
            if (row_number() != rhs.row_number() || col_number() != rhs.col_number()) {
                throw std::range_error("Can not add not compatible matrices.");
            }

            Matrix<T> temp(m_row_s, m_col_s);

            for (unsigned int i = 0; i < row_number(); ++i) {
                for (unsigned int j = 0; j < col_number(); ++j) {
                    temp(i, j) = m_data[i][j] + rhs(i, j);
                }
            }
            return temp;
        }

        // substraction
        Matrix<T> operator-(Matrix<T>& rhs) {
            
            if (row_number() != rhs.row_number() || col_number() != rhs.col_number()) {
                throw std::range_error("Can not substract not compatible matrices.");
            }

            Matrix<T> temp(m_row_s, m_col_s);

            for (unsigned int i = 0; i < row_number(); ++i) {
                for (unsigned int j = 0; j < col_number(); ++j) {
                    temp(i, j) = m_data[i][j] - rhs(i, j);
                }
            }
            return temp;
        }

        // product
        Matrix<T> operator*(const Matrix<T>& operand_2) {
        
            if (m_col_s != operand_2.m_row_s) {
                throw std::range_error("Can not multiply not compatible matrices.");
            }

            Matrix<T> temp(m_row_s, operand_2.m_col_s);

            // address result matrix
            for (unsigned int i = 0; i < temp.m_row_s; ++i) {
                for (unsigned int j = 0; j < temp.m_col_s; ++j) {

                    // set initial value
                    temp(i, j) = (m_data[i][0]) * (operand_2.m_data[0][j]); ;

                    // add remaining data
                    for (unsigned int k = 1; k < m_col_s; ++k) {                    
                        temp(i, j) += (m_data[i][k]) * (operand_2.m_data[k][j]);
                    }
                }
            }

            return temp;
        
        }

        // --------------------------------------------------------
        // Common member funcs
        // --------------------------------------------------------

        // init all matix elements to the given value
        void init_all(T value = 0) {
            for (unsigned int r = 0; r < m_row_s; ++r) {
                for (unsigned int c = 0; c < m_col_s; ++c) {
                    m_data[r][c] = value;
                }
            }
        }

        // prints out the data in the matrix
        void print_out() const {

            T** temp = m_data;
            std::cout << "Printing matrix [" << m_row_s << " x " << m_col_s << "]\n";

            for (unsigned int r = 0; r < m_row_s; ++r) {
                std::cout << "\n";
                for (unsigned int c = 0; c < m_col_s; ++c) {
                    std::cout << "\t" << m_data[r][c] << "\t";
                }
            }

            std::cout << "\n\n";
        }


        const unsigned int& row_number() {
            return m_row_s;
        }

        const unsigned int& col_number() {
            return m_col_s;
        }



    private:
        // def. ctor is hidden
        Matrix() {}

     
    };
}


#endif // __MATRIX_TEMPLATE__H_