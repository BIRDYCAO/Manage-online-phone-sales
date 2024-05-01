#include "SanPham.cpp"
#include "User.cpp"
#include "DocFile.cpp"
#include "GiaoDien.cpp"
#include <iostream>


using namespace std;

int main()
{
    vector<SanPham> DS_SanPham;
    DocFileSP(DS_SanPham);
	User us;
	MenuUser(us, DS_SanPham);
    return 0;
}






