/*****************************************************************
Name : 
Date : 2016/12/24
By   : CharlotteHonG
Final: 2016/12/25
*****************************************************************/
#ifndef GAU_ELIM_HPP
#define GAU_ELIM_HPP


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
    void forward(size_t n){
        // �̶��h���h
        for(unsigned i = 0; i < n; ++i) {
            this->sub(n, i);
            this->info();
        }
        this->nlz(n);
    }
    // �ϦV�a�J
    void reverse(size_t n){
        size_t len = this->matrix.size();
        for(unsigned i = n+1; i < len; ++i) {
            this->sub(n, i);
            this->info();
        }
        this->nlz(n);
    }
    // �L�X
    void info(){
        for(auto&& j : matrix) {
            for(auto&& i : j) {
                cout << setw(priw) << i;
            }cout << endl;
        }cout << endl;
    }
private:
    // ���W��(�̰������²��1)
    void nlz(size_t n){
        // ��J���~
        if (n>=this->matrix.size())
            return;
        // �̰�����
        size_t idx = this->high(n);
        // �w�g����²���}
        if (this->matrix[n][idx]==1)
            return;
        // ��²
        this->zoom(n, 1, matrix[n][idx]);
        this->info();
        return;
    }
    // �۴� a-b (b�A��a)
    void sub(size_t a, size_t b, int idx=-1){
        // ��J���~
        size_t len = this->matrix.size();
        if (a>=len or b>=len)
            return;
        // ��b�̰�����
        if (idx < 0 or idx >= (int)this->matrix[0].size())
            idx = this->high(b);
        // �̰�����ۮt����v
        double ratio = matrix[a][idx] / matrix[b][idx];
        // �q����۴�
        for (unsigned i = 0; i < matrix[0].size(); ++i)
            this->matrix[a][i] -= this->matrix[b][i]*ratio;
    }
    // ��̰�����
    size_t high(size_t n){
        for (unsigned i = 0; i < this->matrix[0].size(); ++i)
            if (matrix[n][i] != 0)
                return i;
        // �^�Ǫ��ת�ܿ��~
        return this->matrix[0].size();
    }
    // �վ㭿�v
    void zoom(size_t n, double in=1, double out=1){
        for (unsigned i = 0; i < this->matrix[n].size(); ++i){
            if (this->matrix[n][i]==0)
                ++i;
            this->matrix[n][i] *= (in/out);
        }
    }
    // ����
    vector<vector<double>> matrix;
};
} // gau


#endif
