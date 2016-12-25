/*****************************************************************
Name : 
Date : 2016/12/25
By   : CharlotteHonG
Final: 2016/12/25
*****************************************************************/
#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <vector>
using namespace std;

#define len v[0].size()
#define lay v.size()
/*==============================================================*/
class Gau_Elim{
public:
    Gau_Elim(initializer_list<vector<double>> arr): v(arr){}
    void forward(size_t n){
        for(unsigned i = 0; i < n; ++i) {
            this->sub(n, i);
        }this->nlz(n);
    }
    void reverse(size_t n){
        for(unsigned i = n+1; i < lay; ++i) {
            this->sub(n, i);
        }this->nlz(n);
    }
    void info(){
        for(auto&& j : v) {
            for(auto&& i : j) {
                cout << setw(6) << i;
            }cout << endl;
        }cout << endl;
    }
private:
    void nlz(size_t n){
        this->zoom(n, 1, v[n][this->high(n)]);
    }
    void sub(size_t a, size_t b){
        size_t idx = this->high(b);
        double ratio = v[a][idx]/ v[b][idx];
        for(unsigned i = 0; i < len; ++i) {
            v[a][i] -= v[b][i]*ratio;
        }
    }
    size_t high(size_t n){
        for(unsigned i = 0; i < len; ++i) {
            if (v[n][i]!=0){
                return i;
            }
        }return len;
    }
    void zoom(size_t n, double in, double out){
        for(unsigned i = 0; i < len; ++i) {
            if (v[n][i]==0)
                ++i;
            v[n][i] *= (in/out);
        }
    }
private:
    vector<vector<double>> v;  
};
//----------------------------------------------------------------
int main(int argc, char const *argv[]){
    Gau_Elim a{
        {2, 3, -1, -2}, 
        {1, -1, 1, 8}, 
        {3, -2, -9, 9}
    };
    // 正向消去
    for(unsigned i = 0; i < 3; ++i) 
        a.forward(i);
    a.info();
    // 反向帶入
    for(unsigned i = 3; i > 0; --i)
        a.reverse(i-1);
    a.info();
    return 0;
}