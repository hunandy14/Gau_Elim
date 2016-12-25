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
    // 建構子
    Gau_Elim(initializer_list<vector<double>> arr): matrix{arr} {}
    Gau_Elim(vector<vector<double>> arr): matrix{arr} {}
    // 正向消去
    void forward(size_t n);
    // 反向帶入
    void reverse(size_t n);
    // 印出
    void info();

private:
    // 正規化(最高次方化簡為1)
    void nlz(size_t n);
    // 相減 a-b (b適應a)
    void sub(size_t a, size_t b, int idx);
    // 找最高次方
    size_t high(size_t n);
    // 調整倍率
    void zoom(size_t n, double in, double out);

private:
    // 成員
    vector<vector<double>> matrix;
};
} // gau

#define GAU_ELIM_HPP
#endif