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
    // �غc�l
    Gau_Elim(initializer_list<vector<double>> arr): matrix{arr} {}
    Gau_Elim(vector<vector<double>> arr): matrix{arr} {}
    // ���V���h
    void forward(size_t n);
    // �ϦV�a�J
    void reverse(size_t n);
    // �L�X
    void info();

private:
    // ���W��(�̰������²��1)
    void nlz(size_t n);
    // �۴� a-b (b�A��a)
    void sub(size_t a, size_t b, int idx);
    // ��̰�����
    size_t high(size_t n);
    // �վ㭿�v
    void zoom(size_t n, double in, double out);

private:
    // ����
    vector<vector<double>> matrix;
};
} // gau

#define GAU_ELIM_HPP
#endif