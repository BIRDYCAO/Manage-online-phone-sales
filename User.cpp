#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include "SanPham.cpp"
#include "DocFile.cpp"

using namespace std;

class User
{
	private:
		string un;
		string pw;
		int TongSoLuong;
		long long TongTien;
	public:
		User() {}
		
		User(string un, string pw)
		{
			this->un = un;
			this->pw = pw;
		}
		
		void setUN(string un)
		{
			this->un = un;
		}
		
		void setPW(string pw)
		{
			this->pw = pw;
		}
		
		void setTongSoLuong(int TongSoLuong)
		{
			this->TongSoLuong = TongSoLuong;
		}
		
		void setTongTien(int TongTien)
		{
			this->TongTien = TongTien;
		}
		
		string getUN() const
		{
			return un;
		}
		
		string getPW() const
		{
			return pw;
		}
		
		int getTongSoLuong() const
		{
			return TongSoLuong;
		}
		
		int getTongTien() const
		{
			return TongTien;
		}
		
		void Mua(vector<SanPham> &DS_SanPham, const string &stt, int soluong)
		{
		    bool kt = false;
		    for (SanPham &sp : DS_SanPham)
		    {
		        if (sp.getSTT() == stt)
		        {
		            kt = true;
		            if (soluong <= sp.getSoLuong())
		            {
		                int soluongmoi = sp.getSoLuong() - soluong;
		                sp.setSoLuong(soluongmoi);
		
		                TongSoLuong += soluong;
		                TongTien += sp.getGia() * soluong;
		
		                cout << "Da mua thanh cong " << soluong << " san pham " << sp.getTenSanPham() << endl;
		
		                GhiThongTinMuaHang(stt, sp.getTenSanPham(), soluong, sp.getGia());
		                
		                UpdateFile(DS_SanPham);
		            }
		            else
		            {
		                cout << "So luong " << sp.getTenSanPham() << " khong du de mua ! " << endl;
		            }
		            break;
		        }
		    }
		
		    if (!kt)
		    {
		        cout << "Khong tim thay san pham trong cua hang !" << endl;
		    }
		}

		
		bool LoginUser(vector<User> DS_User, string un, string pw)
		{
			for(User& us : DS_User)
			{
				if(us.un == un && us.pw == pw)
				{
					cout << "Dang nhap thanh cong !" << endl;
					return true;
				}
			}
			cout << "Dang nhap that bai !" << endl;
			return false;
		}
		
		void us1(const vector<SanPham> &DS_SanPham)
		{
			cout << "\n\n-------------------------- DANH SACH SAN PHAM HIEN CO --------------------------" << endl;
			cout << endl;
			cout << "________________________________________________________________________________" << endl;
		    cout << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << endl;
		    cout << "________________________________________________________________________________" << endl;
		    for (const SanPham &sp : DS_SanPham)
		    {
		        cout << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
		    }
		    cout << "________________________________________________________________________________" << endl;
		}
		
//		string convert(string s)
//		{
//			for(int i = 0; i <= s.length(); i++)
//			{
//				s[i] = tolower(s[i]);
//			}
//			return s;
//		}
		
		string convert(string s)
		{
			for(char &c : s)
			{
			    c = tolower(c);
			}
			return s;
		}

		
		void us2(const vector<SanPham> &DS_SanPham, const string &tensp)
		{
		    bool kt = false;
		    string tentim = convert(tensp); 
		    cout << "Ket qua tim kiem san pham " << tensp << " :" << endl;
		    cout << "\n\n-------------------------- DANH SACH SAN PHAM HIEN CO --------------------------" << endl;
		    cout << endl;
		    cout << "________________________________________________________________________________" << endl;
		    cout << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << endl;
		    cout << "________________________________________________________________________________" << endl;
		    for (const SanPham &sp : DS_SanPham)
		    {
		        string TenspHienCo = convert(sp.getTenSanPham()); 
		        if (TenspHienCo.find(tentim) != string::npos)
		        {
		            cout << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
		            cout << "________________________________________________________________________________" << endl;
		            kt = true;
		        }
		    }
		    if (!kt)
		    {
		        cout << "Khong tim thay san pham !" << endl;
		    }
		}

		
		void us3(vector<SanPham> &DS_SanPham, const string &hang)
		{	
			bool kt = false;
			string hangtim = convert(hang);
			cout << "Ket qua loc hang " << hang << " : ";
			cout << "\n\n-------------------------- DANH SACH SAN PHAM HIEN CO --------------------------" << endl;
			cout << endl;
			cout << "________________________________________________________________________________" << endl;
		    cout << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << endl;
		    cout << "________________________________________________________________________________" << endl;
		    for(const SanPham& sp : DS_SanPham)
			{
				string TenhangHienCo = convert(sp.getHang());
				if(TenhangHienCo == hang)
				{
					cout << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
					cout << "________________________________________________________________________________" << endl;
					kt = true;
				}
			}
			if(!kt)
			{
				cout << "Khong tim thay san pham !" << endl;
			}
		}
		
		void us4()
		{
		    ifstream filein("thongtinmua.csv");
		    if (!filein.is_open())
		    {
		        cerr << "Khong the mo file de doc!" << endl;
		        return;
		    }
		
		    int tongsoluong = 0;
		    long long tongtien = 0;
		    string line;
		
		    while (getline(filein, line))
		    {
		        stringstream ss(line);
		        string stt, tensp, soluong1, gia1;
		
		        getline(ss, stt, ',');
		        getline(ss, tensp, ',');
		        getline(ss, soluong1, ',');
		        getline(ss, gia1, ',');
		
		        int soluong = stoi(soluong1);
		        long long gia = stoll(gia1);
		        
		        tongsoluong += soluong;
		        tongtien += gia * soluong;
		    }
		
		    cout << " -------------------- THONG KE -------------------- " << endl;
		    cout << "So luong san pham da mua: " << tongsoluong << endl;
		    cout << "Tong tien phai thanh toan: " << tongtien << endl;
		
		    filein.close();
		
		    TongSoLuong = tongsoluong;
		    TongTien = tongtien;
		}
		
		void us5(vector<User> &DS_User, const string &un, const string &newpw)
		{
		    bool kt = false;
		    for (User &us : DS_User)
		    {
		        if (us.getUN() == un)
		        {
		            us.setPW(newpw);
		            kt = true;
		            cout << "Thay doi mat khau thanh cong !" << endl;
		            break;
		        }
		    }
		    if (!kt)
		    {
		        cout << "Khong tim thay ten dang nhap !" << endl;
		    }
		}
};






