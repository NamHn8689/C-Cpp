	#include <stdio.h>
	#include <iostream>
	#include <stdlib.h>
	#include <iomanip>
	#include <string.h>
	using namespace std;

	void swap(int &a, int &b)
	{
		int t = a;
		a = b;
		b = t;
	}
	void QS(int a[], int b[], int c[], int l, int r)
	{
		int i = l, j = r;
		int chot = a[(l + r) / 2];
		while (i <= j)
		{
			while (a[i] < chot)
				i++;
			while (a[j] > chot)
				j--;
			if (i <= j)
			{
				swap(a[i], a[j]);
				swap(b[i], b[j]);
				swap(c[i], c[j]);
				i++;
				j--;
			}
		}
		if (l < j)
			QS(a, b, c, l, j);
		if (i < r)
			QS(a, b, c, i, r);
	}
	int main()
	{
		int n; //soTienTrinh
		do
		{
			cout << "Nhap so tien trinh (n>=2): ";
			cin >> n;
			cout << "=================================================================" << endl;
			if (n <= 1)
				cout << "Hay nhap lai!!!" << endl;
		} while (n < 2);
		int timeThucHien[n];
		int timeXuatHien[n];
		int tenCacTienTrinh[n];

		int q;
		cout << "q= :";
		cin >> q;
		
		for (int i = 0; i < n; i++)
		{

			cout << "Nhap ten tien trinh: ";
			cin >> tenCacTienTrinh[i];
			cout << "Nhap thoi gian thuc hien: ";
			cin >> timeThucHien[i];
			cout << "Nhap thoi gian xuat hien: ";
			cin >> timeXuatHien[i];
			cout << "=================================================================" << endl;
		}

		QS(timeXuatHien, timeThucHien, tenCacTienTrinh, 0, n - 1);
		cout << setw(50) << "BANG THONG TIN TIEN TRINH" << endl;
		cout << setw(20) << "Process" << setw(20) << "time TH" << setw(20) << "time XH"
			<< "\n\n";
		for (int i = 0; i < n; i++)

		{
			cout << setw(20) << tenCacTienTrinh[i] << setw(20) << timeThucHien[i] << setw(20) << timeXuatHien[i] << endl;
		}

		cout << "Ket qua thuạt toan RR" << endl;
		int tongTimeThucHien = 0;
		for (int i = 0; i < n; i++) //tính tổng để biết nó chạy đến đâu
			tongTimeThucHien += timeThucHien[i];

		int hdz = 0;

		int soLanChay = 0;
		for (int i = 0; i < n; i++)
		{
			if (timeThucHien[i] % q == 0)
				soLanChay += timeThucHien[i] / q;
			else
				soLanChay += (timeThucHien[i] / q + 1);
		}

		int tenTienTrinh[soLanChay + 1], giaTriTienTrinh[soLanChay + 1];
		giaTriTienTrinh[0] = 0;
		int chiSo = 1;
		int tienTrinhSeSuDung[soLanChay];
		int Left = 0;
		int Right = 0;
		tienTrinhSeSuDung[0] = 0;
		bool ktraXuatHien[n];
		for (int i = 0; i < n; i++)
			ktraXuatHien[i] = false;
		int tongtimecho = 0;
		for (int i = 0; i < n; i++)
			tongtimecho = tongtimecho - timeThucHien[i] - timeXuatHien[i];

		while (hdz < tongTimeThucHien)
		{
			int rtemp = Right + 1;
			for (int i = Left; i <= Right; i++)
			{

				if (timeThucHien[tienTrinhSeSuDung[i]] >= q)
				{
					hdz += q;
					timeThucHien[tienTrinhSeSuDung[i]] -= q;
					tenTienTrinh[chiSo] = tenCacTienTrinh[tienTrinhSeSuDung[i]];
					giaTriTienTrinh[chiSo] = giaTriTienTrinh[chiSo - 1] + q;
					chiSo++;
				}
				else if (timeThucHien[tienTrinhSeSuDung[i]] > 0)
				{
					hdz += timeThucHien[tienTrinhSeSuDung[i]];
					tenTienTrinh[chiSo] = tenCacTienTrinh[tienTrinhSeSuDung[i]];
					giaTriTienTrinh[chiSo] = giaTriTienTrinh[chiSo - 1] + timeThucHien[tienTrinhSeSuDung[i]];
					timeThucHien[tienTrinhSeSuDung[i]] = 0;
					chiSo++;
				}
				for (int j = 1; j < n; j++)
				{
					if (timeXuatHien[j] < hdz && ktraXuatHien[j] == false)
					{
						ktraXuatHien[j] = true;
						tienTrinhSeSuDung[rtemp] = j;
						rtemp++;
					}
				}
				if (timeThucHien[tienTrinhSeSuDung[i]] > 0)
				{
					tienTrinhSeSuDung[rtemp] = tienTrinhSeSuDung[i];
					rtemp++;
				}
				for (int j = 1; j < n; j++)
				{
					if (timeXuatHien[j] == hdz && ktraXuatHien[j] == false)
					{
						ktraXuatHien[j] = true;
						tienTrinhSeSuDung[rtemp] = j;
						rtemp++;
					}
				}
			}
			Left = Right + 1;
			Right = rtemp - 1;
		}

		for (int i = 1; i <= soLanChay; i++)
		{
			cout << "P" << tenTienTrinh[i] << "   ";
		}
		cout << endl;
		for (int i = 0; i <= soLanChay; i++)
			cout << giaTriTienTrinh[i] << "   ";
		for (int i = 0; i < n; i++)
		{
			int j = soLanChay - 1;
			while (tienTrinhSeSuDung[j] != tenCacTienTrinh[i] - 1)
				j--;
			tongtimecho += giaTriTienTrinh[j + 1];
		}
		cout << endl
			<< "Thoi gian cho trung binh la : " << (float)tongtimecho / n;
		return 0;
	}
