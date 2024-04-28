#pragma once
#include <iostream>
using namespace std;

class SanPham
{
	private:
		string STT;
		string Hang;
		string TenSanPham;
		int Gia;
		int SoLuong;
	public:
		SanPham() {}
		
		SanPham(string STT, string Hang, string TenSanPham, int Gia, int SoLuong)
		{
			this->STT = STT;
			this->Hang = Hang;
			this->TenSanPham = TenSanPham;
			this->Gia = Gia;
			this->SoLuong = SoLuong;
		}
		
		void setSTT(string STT)
		{
			this->STT = STT;
		}
		
		void setHang(string Hang)
		{
			this->Hang = Hang;
		}
		
		void setTenSanPham(string TenSanPham)
		{
			this->TenSanPham = TenSanPham;
		}
		
		void setGia(int Gia)
		{
			this->Gia = Gia;
		}
		
		void setSoLuong(int SoLuong)
		{
			this->SoLuong = SoLuong;
		}
		
		string getSTT() const 
		{ 
			return STT; 
		}
		
    	string getHang() const
		{ 
			return Hang; 
		}
		
    	string getTenSanPham() const
		{ 
			return TenSanPham; 
		}
		
    	int getGia() const
		{ 
			return Gia; 
		}
		
    	int getSoLuong() const
		{ 
			return SoLuong; 
		}
};


