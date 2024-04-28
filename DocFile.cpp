#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "SanPham.cpp"
using namespace std;

void DocFileSP(vector<SanPham> &DS_SanPham)
{
	ifstream filein("cuahangcp.csv");
	if(!filein.is_open())
	{
		cerr << "Khong the mo file cuahangcp.csv !" << endl;
		return;
	}
	string line;
	getline(filein, line); // Bo qua dong tieu de
	// Doc tung dong trong file cuahangdp.csv va them vao DS_SanPham
	while(getline(filein, line))
	{
		SanPham sp;
		stringstream ss(line);
		string stt, hang, tensp, gia, soluong;
			
		getline(ss, stt, ',');
		getline(ss, hang, ',');
		getline(ss, tensp, ',');
		getline(ss, gia, ',');
		getline(ss, soluong, '\n');
		
		sp.setSTT(stt);
		sp.setHang(hang);
		sp.setTenSanPham(tensp);
		sp.setGia(stoi(gia));
		sp.setSoLuong(stoi(soluong));
			
		DS_SanPham.push_back(sp);
	}
	filein.close();
}

void GhiThongTinMuaHang(const string &stt, string tensp, int soluong, long long gia)
{
    // Open the file in append mode
    ofstream fileout("thongtinmua.csv", ios::app);
    if (!fileout.is_open())
    {
        cerr << "Khong the mo file de ghi!" << endl;
        return;
    }

    // Check if the file is empty, if so, add a header
    ifstream filecheck("thongtinmua.csv");
    if (filecheck.peek() == ifstream::traits_type::eof())
    {
        fileout << "STT,TEN SAN PHAM,SO LUONG,GIA" << endl;
    }
    filecheck.close();

    // Append the purchased item information to the file
    fileout << stt << "," << tensp << "," << soluong << "," << gia << endl;
    fileout.close();
}
 
void UpdateFile(vector<SanPham> &DS_SanPham)
{
	ifstream filein;
	ofstream fileout;
	filein.open("cuahangcp.csv");
	fileout.open("cuahangcpnew.csv", ios::out);
	
	if(!fileout.is_open())
	{
		cerr << "Khong ton tai file cuahangcp.csv !" << endl;
		return;
	}
	
	fileout << "STT,HANG,TEN SAN PHAM,GIA,SO LUONG";
		
	for(SanPham &sp : DS_SanPham)
	{
		fileout << sp.getSTT() << ',' << sp.getHang() << ',' << sp.getTenSanPham() << ',' << sp.getGia() << ',' << sp.getSoLuong() << '\n';
	}
	
	cout << "Da cap nhat du lieu thanh cong vao file cuahangcp.csv thanh cong !" << endl;
	filein.close();
	fileout.close();
	remove("cuahangcp.csv");
	rename("cuahangcpnew.csv", "cuahangcp.csv");
}

void DangKi()
{
	cout << "-------- MOI BAN DANG KI TAI KHOAN --------";
	string un, pw;
	cout << "Ten dang nhap: " ;
	cin.ignore();
	getline(cin, un);
	
	ifstream filein;
	filein.open("data.csv");
	if(!filein.is_open())
	{
		cerr << "Khong ton tai file data.csv !" << endl;
		return;
	}	
	
	string line;
	bool kt = false;
	while(getline(filein, line))
	{
		stringstream ss(line);
		string uname;
		getline(ss, uname, ',');
		if(uname == un)
		{
			kt = true;
			break;
		}
	}
	
	filein.close();
	
	if(kt)
	{
		cout << "Ten dang nhap da ton tai ! " << endl;
		cout << "vui long nhap lai ! " << endl;
	}
	
	cout << "Mat khau: " ;
	getline(cin, pw);
	
	ofstream fileout;
	fileout.open("data.csv", ios::app);
	
	if(!fileout.is_open())
	{
		cerr << "Khong the tao tai khoan !" << endl;
	}
	
	fileout << un << "," << pw << endl;
	cout << "Tao tai khoan thanh cong !" << endl;
	
	fileout.close();
}

void DangNhap()
{
	cout << " ------- MOI BAN DANG NHAP TAI KHOAN ------- ";
	string un, pw;
	cout << "Ten dang nhap: ";
	cin.ignore();	
	getline(cin, un);
	cout << "Ten dang ki: ";
	getline(cin, pw);
	
	ifstream filein;
	filein.open("data.csv");
	
	if(!filein.is_open())
	{
		cerr << "Tai khoan hoac mat khau khong dung ! ";
		cerr << "Vui long dang nhap lai ! ";
	}
	
	string line;
	bool kt = false;
	while(getline(filein, line))
	{
		stringstream ss(line);
		string uname, pword;
		getline(ss, uname, ',');
		getline(ss, pword, '\n');
			
		if(uname == un && pword == pw)
		{
			kt = true;
		}
			
	}
	
	filein.close();
	
	if(!kt)
	{
		cout << "Ten tai khoan khong ton tai !" << endl;
	}
	else
	{
		cout << "Dang nhap thanh cong !" << endl;
	}
}





