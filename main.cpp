#include "SanPham.cpp"
#include "User.cpp"
#include "DocFile.cpp"
#include <iostream>


using namespace std;

int main()
{
    vector<SanPham> DS_SanPham;
    DocFileSP(DS_SanPham);

    User us;
	us.us1(DS_SanPham);
	string stt;
	cout << "stt: " ;
	getline(cin, stt);
	int soluong;
	cout << "So luong: ";
	cin >> soluong;
	us.Mua(DS_SanPham, stt, soluong);
	us.us4();
	UpdateFile(DS_SanPham);
	us.us1(DS_SanPham);
    return 0;
}






