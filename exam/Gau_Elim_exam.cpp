/*****************************************************************
Name :
Date : 2016/12/26
By   : CharlotteHonG
Final: 2016/12/26
*****************************************************************/
#include <iostream>
#include <vector>
#include <initializer_list>
#include <iomanip>
using namespace std;
//----------------------------------------------------------------
class Gau_Elim {
public:
#define len this->v[0].size()
#define lay this->v.size()
    using size_type = typename vector<double>::size_type;
    Gau_Elim(initializer_list<vector<double>> arr): v(arr) {}
public:
    void forward(size_type n) {
        for(unsigned i = 0; i < n; ++i) {
            sub(n, i);
        } nlz(n);
    }
    void reverse(size_type n) {
        for(unsigned i = n+1; i < lay ; ++i) {
            sub(n, i);
        } nlz(n);
    }
    void info() {
        for(auto&& j : v) {
            for(auto&& i : j) {
                cout << setw(6) << i;
            } cout << endl;
        } cout << endl;
    }
private:
    void sub(size_type n, size_type n2) {
        double ratio = v[n][max(n2)]/v[n2][max(n2)];
        for(unsigned i = 0; i < len; ++i)
            v[n][i] -= v[n2][i]*ratio;
    }
    void nlz(size_type n) {
        zoom(n, 1, v[n][max(n)]);
    }
    void zoom(size_type n, double in, double out) {
        for(unsigned i = 0; i < len; ++i)
            v[n][i] *= (in/out);
    }
    size_type max(size_type n) {
        for(unsigned i=0; i<len ; ++i)
            if(v[n][i]!=0)
                return i;
        return len;
    }
private:
    vector<vector<double>> v;
};
//----------------------------------------------------------------
int main(int argc, char const *argv[]) {
    Gau_Elim a{
        {2, 3, -1, -2},
        {1, -1, 1, 8},
        {3, -2, -9, 9}
    }; a.info();
    // 正向消去
    for(unsigned i = 0; i < 3; ++i) {
        a.forward(i);
    } a.info();
    // 反向代入
    for(unsigned i = 3; i > 0; --i) {
        a.reverse(i-1);
    } a.info();
    return 0;
}