/*****************************************************************
Name : 
Date : 2016/12/24
By   : CharlotteHonG
Final: 2016/12/25
*****************************************************************/
#ifndef GAU_ELIM_HPP
#include <iostream>
#include <vector>
#include <iomanip>
#include <initializer_list>

using namespace std;
#define priw 6

namespace gau {
class Gau_Elim{
public:
    #define len this->matrix[0].size()
    #define lay this->matrix.size()
    using size_type=typename vector<double>::size_type;
    // �غc�l
    Gau_Elim(initializer_list<vector<double>> arr): matrix{arr} {}
    Gau_Elim(vector<vector<double>> arr): matrix{arr} {}
public:
    // ���V���h
    void forward(size_type n);
    // �ϦV�a�J
    void reverse(size_type n);
    // �L�X
    void info();

private:
    // ���W��(�̰������²��1)
    void nlz(size_type n);
    // �۴� a-b (b�A��a)
    void sub(size_type a, size_type b, int idx);
    // ��̰�����
    size_type high(size_type n);
    // �վ㭿�v
    void zoom(size_type n, double in, double out);

private:
    // ����
    vector<vector<double>> matrix;
};
} // gau

#define GAU_ELIM_HPP
#endif