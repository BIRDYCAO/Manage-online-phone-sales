#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include "SanPham.cpp"
#include "DocFile.cpp"
#include "GiaoDien.cpp"

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
						SetColor(0, 12);
		                cout << "Da mua thanh cong " << soluong << " san pham " << sp.getTenSanPham() << endl;
						SetColor(0, 7);
		                GhiThongTinMuaHang(stt, sp.getTenSanPham(), soluong, sp.getGia());
		                UpdateFile(DS_SanPham);
		            }
		            else
		            {
		            	SetColor(0, 12);
		                cout << "So luong " << sp.getTenSanPham() << " khong du de mua ! " << endl;
		                SetColor(0, 7);
		            }
		            break;
		        }
		    }
		
		    if (!kt)
		    {
		    	SetColor(0, 12);
		        cout << "Khong tim thay san pham trong cua hang !" << endl;
		        SetColor(0, 7);
		    }
		}

		
		bool LoginUser(vector<User> DS_User, string un, string pw)
		{
			for(User& us : DS_User)
			{
				if(us.un == un && us.pw == pw)
				{
					SetColor(0, 12);
					cout << "Dang nhap thanh cong !" << endl;
					SetColor(0, 7);
					return true;
				}
			}
			SetColor(0, 12);
			cout << "Dang nhap that bai !" << endl;
			return false;
		}
		
		void us1(const vector<SanPham> &DS_SanPham)
		{
			SetColor(0, 10);
			cout << "\n\n-------------------------- DANH SACH SAN PHAM HIEN CO --------------------------" << endl;
			cout << endl;
			SetColor(0, 15);
			cout << "________________________________________________________________________________" << endl;
		    cout << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << setw(4) << "|" << endl;
		    cout << "________________________________________________________________________________" << endl;
		    for (const SanPham &sp : DS_SanPham)
		    {
		    	SetColor(0, 15);
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
		    SetColor(0, 15);
		    cout << "Ket qua tim kiem san pham " << tensp << " :" << endl;
		    SetColor(0, 10);
		    cout << "\n\n-------------------------- DANH SACH SAN PHAM HIEN CO --------------------------" << endl;
		    cout << endl;
		    SetColor(0, 15);
		    cout << "________________________________________________________________________________" << endl;
		    cout << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << setw(4) << "|" << endl;
		    cout << "________________________________________________________________________________" << endl;
		    for (const SanPham &sp : DS_SanPham)
		    {
		        string TenspHienCo = convert(sp.getTenSanPham()); 
		        if (TenspHienCo.find(tentim) != string::npos)
		        {
		        	SetColor(0, 15);
		            cout << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
		            cout << "________________________________________________________________________________" << endl;
		            kt = true;
		        }
		    }
		    if (!kt)
		    {
		    	SetColor(0, 12);
		        cout << "Khong tim thay san pham !" << endl;
		    }
		}

		
		void us3(vector<SanPham> &DS_SanPham, const string &hang)
		{	
			bool kt = false;
			string hangtim = convert(hang);
			SetColor(0, 15);
			cout << "Ket qua loc hang " << hang << " : ";
			SetColor(0, 10);
			cout << "\n\n-------------------------- DANH SACH SAN PHAM HIEN CO --------------------------" << endl;
			cout << endl;
			SetColor(0, 15);
			cout << "________________________________________________________________________________" << endl;
		    cout << setw(5) << "STT" << setw(4) << "|" << setw(9) << "Hang" << setw(4) << "|" << setw(26) << "Ten San Pham" << setw(4) << "|" << setw(10) << "Gia" << setw(4) << "|" << setw(10) << "So Luong" << setw(4) << "|" << endl;
		    cout << "________________________________________________________________________________" << endl;
		    for(const SanPham& sp : DS_SanPham)
			{
				string TenhangHienCo = convert(sp.getHang());
				if(TenhangHienCo == hang)
				{
					SetColor(0, 15);
					cout << setw(5) << sp.getSTT() << setw(4) << "|" << setw(9) << sp.getHang() << setw(4) << "|" << setw(26) << sp.getTenSanPham() << setw(4) << "|" << setw(10) << sp.getGia() << setw(4) << "|" << setw(10) << sp.getSoLuong() << setw(4) << "|" << endl;
					cout << "________________________________________________________________________________" << endl;
					kt = true;
				}
			}
			if(!kt)
			{
				SetColor(0, 12);
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
			SetColor(0, 12);
		    cout << " -------------------- THONG KE -------------------- " << endl;
		    SetColor(0, 15);
		    cout << "So luong san pham da mua: " << tongsoluong << " cai " << endl;
		    cout << "Tong tien phai thanh toan: " << tongtien << " vnd " << endl;
		
		    filein.close();
		
		    TongSoLuong = tongsoluong;
		    TongTien = tongtien;
		}
		
//		void us5(vector<User> &DS_User, const string &un, const string &newpw)
//		{
//		    bool kt = false;
//		    for (User &us : DS_User)
//		    {
//		        if (us.getUN() == un)
//		        {
//		            us.setPW(newpw);
//		            kt = true;
//		            cout << "Thay doi mat khau thanh cong !" << endl;
//		            break;
//		        }
//		    }
//		    if (!kt)
//		    {
//		        cout << "Khong tim thay ten dang nhap !" << endl;
//		    }
//		}
};

void MenuUser(User &us, vector<SanPham> DS_SanPham) 
{
	bool kt = true;
    do {
        system("cls");
        SetColor(0, 11);
        cout << "\n\n\t\t\t ---------------- MENU USER ---------------- " << endl;
		cout << "	   \t\t | 1. DANH SACH SAN PHAM HIEN CO           | " << endl;
		cout << "	   \t\t | 2. TIM KIEM TEN SAN PHAM                | " << endl;
		cout << "	   \t\t | 3. LOC DANH SACH SAN PHAM THEO HANG     | " << endl;
		cout << "	   \t\t | 4. THONG KE TONG SAN PHAM VA TONG TIEN  | " << endl;
		cout << "	   \t\t | 5. THAY DOI MAT KHAU                    | " << endl;
		cout << "    \t\t\t | 6. EXIT                                 | " << endl;
		cout << "	   \t\t ------------------------------------------- " << endl;

        int luachon;
        SetColor(0, 15);
        cout << "\n\t\t\t Moi ban nhap lua chon: " << endl;
        cout << "\t\t\t " << char(16) << " ";
        cin >> luachon;

        switch (luachon) 
		{
            case 1: 
			{
                us.us1(DS_SanPham);

				while(kt)
				{
					SetColor(0, 10);
					cout << endl;
	                cout << "--------------------------------------------------------------------------------" << endl;
	                cout << "1. Mua hang " << endl;                      
	                cout << "2. Tro ve MENU USER " << endl;
	                int chon;
	                SetColor(0, 15);
	                cout << "Moi ban nhap lua chon: " << endl;
	                cout << (char)16 << " " ;
	                cin >> chon;
	                
	                switch(chon)
	                {
	                	case 1: 
	                	{
		                	string stt;
		                	int soluong;
		                	SetColor(0, 10);
		                	cout << "Nhap stt san pham can mua: ";
		                	cin.ignore();
		                	getline(cin, stt);
		                	SetColor(0, 10);
		                	cout << "Nhap so luong can mua: ";
		                	cin >> soluong;
		                	us.Mua(DS_SanPham, stt, soluong);
		                	break;
						}
						case 2: 
						{
							system("cls");
							MenuUser(us, DS_SanPham);
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;	
						}
					}
					SetColor(0, 10);
					cout << "Ban co muon tiep tuc mua san pham ko ? " << endl;
					cout << "1. Co " << endl;
					cout << "2. Khong " << endl;
					SetColor(0, 15);
					cout << "Moi ban nhap lua chon: " << endl;
					cout << (char)16 << " " ;
					int tieptuc;
					cin >> tieptuc;
					
					switch(tieptuc)
					{
						case 1:
						{
							system("cls");
							us.us1(DS_SanPham);
							break;
						}
						case 2:
						{
							kt = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;
						}
					}
				}
        	}
        	break;
        	case 2:
        	{
        		string tentim;
        		SetColor(0, 15);
        		cout << "Nhap ten san pham can tim (iPhone, OPPO, realme, Xiaomi, Samsung): ";
        		cin.ignore();
        		getline(cin, tentim);
        		us.us2(DS_SanPham, tentim);
        		
				while(kt)
				{
					SetColor(0, 10);
					cout << endl;
	                cout << "--------------------------------------------------------------------------------" << endl;
	                cout << "1. Mua hang " << endl;                      
	                cout << "2. Tro ve MENU USER " << endl;
	                int chon;
	                SetColor(0, 15);
	                cout << "Moi ban nhap lua chon: " << endl;
	                cout << (char)16 << " " ;
	                cin >> chon;
	                
	                switch(chon)
	                {
	                	case 1: 
	                	{
		                	string stt;
		                	int soluong;
		                	SetColor(0, 10);
		                	cout << "Nhap stt san pham can mua: ";
		                	cin.ignore();
		                	getline(cin, stt);
		                	SetColor(0, 10);
		                	cout << "Nhap so luong can mua: ";
		                	cin >> soluong;
		                	us.Mua(DS_SanPham, stt, soluong);
		                	break;
						}
						case 2: 
						{
							system("cls");
							MenuUser(us, DS_SanPham);
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;	
						}
					}
					SetColor(0, 10);
					cout << "Ban co muon tiep tuc mua san pham ko ? " << endl;
					cout << "1. Co " << endl;
					cout << "2. Khong " << endl;
					SetColor(0, 15);
					cout << "Moi ban nhap lua chon: " << endl;
					cout << (char)16 << " " ;
					int tieptuc;
					cin >> tieptuc;
					
					switch(tieptuc)
					{
						case 1:
						{
							system("cls");
							us.us1(DS_SanPham);
							break;
						}
						case 2:
						{
							kt = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;
						}
					}
				}
			}
			break;
			case 3:
			{
				string tenhang;
				SetColor(0, 15);
				cout << "Nhap ten hang can tim (iPhone, OPPO, realme, Xiaomi, Samsung): ";
				cin.ignore();
				getline(cin, tenhang);
				us.us3(DS_SanPham, tenhang);
				
				while(kt)
				{
					SetColor(0, 10);
					cout << endl;
	                cout << "--------------------------------------------------------------------------------" << endl;
	                cout << "1. Mua hang " << endl;                      
	                cout << "2. Tro ve MENU USER " << endl;
	                int chon;
	                SetColor(0, 15);
	                cout << "Moi ban nhap lua chon: " << endl;
	                cout << (char)16 << " " ;
	                cin >> chon;
	                
	                switch(chon)
	                {
	                	case 1: 
	                	{
		                	string stt;
		                	int soluong;
		                	SetColor(0, 10);
		                	cout << "Nhap stt san pham can mua: ";
		                	cin.ignore();
		                	getline(cin, stt);
		                	SetColor(0, 10);
		                	cout << "Nhap so luong can mua: ";
		                	cin >> soluong;
		                	us.Mua(DS_SanPham, stt, soluong);
		                	break;
						}
						case 2: 
						{
							system("cls");
							MenuUser(us, DS_SanPham);
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;	
						}
					}
					SetColor(0, 10);
					cout << "Ban co muon tiep tuc mua san pham ko ? " << endl;
					cout << "1. Co " << endl;
					cout << "2. Khong " << endl;
					SetColor(0, 15);
					cout << "Moi ban nhap lua chon: " << endl;
					cout << (char)16 << " " ;
					int tieptuc;
					cin >> tieptuc;
					
					switch(tieptuc)
					{
						case 1:
						{
							system("cls");
							us.us1(DS_SanPham);
							break;
						}
						case 2:
						{
							kt = false;
							break;
						}
						default:
						{
							SetColor(0, 12);
							cout << "Vui long nhap lai lua chon ! " << endl;
							break;
						}
					}
				}
			}
			break;
			case 4:
			{
				us.us4();
				system("pause");
			}
			break;
//			case 5:
//			{
//				vector<User> DS_User;
//				string newpw;
//				cout << "Nhap mat khau moi: ";
//				cin.ignore();
//				getline(cin, newpw);
//				us.us5(DS_User, un, newpw);	
//			}
//			break;
			case 6:
			{
				kt = false;
				break;
			}
			break;
			default:
			{
				SetColor(0, 12);
				cout << "vui long nhap lai lua chon ! " << endl;
				system("pause");
				break;
			}
        }
    } while (kt); 
}






