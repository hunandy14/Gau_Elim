/****************************************************************
Name : 
Date : 2016/12/24
By   : CharlotteHonG
Final: 2016/12/25

�������h
1. ���W��
2. ���V���h
3. �ϦV�a�J
*****************************************************************/
#include <iostream>
#include "Gau_Elim.hpp"
using namespace std;
using namespace gau;
/*==============================================================*/
int main(int argc, char const *argv[]){
    Gau_Elim a{
        {2, 3, -1, -2}, 
        {1, -1, 1, 8}, 
        {3, -2, -9, 9}
    };
    // ���V���h
    cout << "forward" << endl;
    for(unsigned i = 0; i < 3; ++i) 
        a.forward(i);
    // �ϦV�a�J
    cout << "reverse" << endl;
    for(unsigned i = 3; i > 0; --i) {
        a.reverse(i-1);
    }
    return 0;
}
/*==============================================================*/