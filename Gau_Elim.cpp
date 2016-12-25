/*****************************************************************
Name : 
Date : 2016/12/25
By   : CharlotteHonG
Final: 2016/12/25
*****************************************************************/
#include "Gau_Elim.hpp"

namespace gau {
    // 正向消去
    void Gau_Elim::forward(size_type n){
        // 依階層消去
        for(unsigned i = 0; i < n; ++i) {
            this->sub(n, i, -1);
            this->info();
        }
        this->nlz(n);
    }
    // 反向帶入
    void Gau_Elim::reverse(size_type n){
        for(unsigned i = n+1; i < lay; ++i) {
            this->sub(n, i, -1);
            this->info();
        }
        this->nlz(n);
    }
    // 印出
    void Gau_Elim::info(){
        for(auto&& j : matrix) {
            for(auto&& i : j) {
                cout << setw(priw) << i;
            }cout << endl;
        }cout << endl;
    }

    
    // 正規化(最高次方化簡為1)
    void Gau_Elim::nlz(size_type n){
        // 輸入錯誤
        if (n>=lay)
            return;
        // 最高次方
        size_type idx = this->high(n);
        // 已經為最簡離開
        if (this->matrix[n][idx]==1)
            return;
        // 化簡
        this->zoom(n, 1, matrix[n][idx]);
        this->info();
        return;
    }
    // 相減 a-b (b適應a)
    void Gau_Elim::sub(size_type a, size_type b, int idx=-1){
        // 輸入錯誤
        if (a>=lay or b>=lay)
            return;
        // 找b最高次方
        if (idx < 0 or idx >= (int)len)
            idx = this->high(b);
        // 最高次方相差的比率
        double ratio = matrix[a][idx] / matrix[b][idx];
        // 通分後相減
        for (unsigned i = 0; i < len; ++i)
            this->matrix[a][i] -= this->matrix[b][i]*ratio;
    }
    // 找最高次方
    Gau_Elim::size_type Gau_Elim::high(size_type n){
        for (unsigned i = 0; i < len; ++i)
            if (matrix[n][i] != 0)
                return i;
        // 回傳長度表示錯誤
        return len;
    }
    // 調整倍率
    void Gau_Elim::zoom(size_type n, double in=1, double out=1){
        for (unsigned i = 0; i < len; ++i){
            if (this->matrix[n][i]==0)
                ++i;
            this->matrix[n][i] *= (in/out);
        }
    }
    
} // gau