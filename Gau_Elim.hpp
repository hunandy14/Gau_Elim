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
    // 建構子
    Gau_Elim(initializer_list<vector<double>> arr): matrix{arr} {}
    Gau_Elim(vector<vector<double>> arr): matrix{arr} {}
public:
    // 正向消去
    void forward(size_type n);
    // 反向帶入
    void reverse(size_type n);
    // 印出
    void info();

private:
    // 正規化(最高次方化簡為1)
    void nlz(size_type n);
    // 相減 a-b (b適應a)
    void sub(size_type a, size_type b, int idx);
    // 找最高次方
    size_type high(size_type n);
    // 調整倍率
    void zoom(size_type n, double in, double out);

private:
    // 成員
    vector<vector<double>> matrix;
};
} // gau

#define GAU_ELIM_HPP
#endif