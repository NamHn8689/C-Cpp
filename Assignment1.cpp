#include<iostream>
#include<iomanip>
using namespace std;

void input1(double &x){
	cin >> x;
}
void input2(int &n){
	cin >> n;
}
void add(int &n){
	n++;
}
void tru(int &n){
	n--;
}
double p(double x,int n){
	double t=x,m=1,p=0;
	for (int i=1; i <= n; i++) {
		t *= x; m *= 3;
		p += t / m;
	}
	return p+2018*t;
}
long int p2(int m,int n){
	long int s = 0;
	int i = (m <= 6) ? 6 : m;
	for (; i <= n; i++){
		if (i % 2 == 0){
			s += i;
		}
	}
	return s;
}
int main() {
	double x;
	int m, n;
	cout << "x= ";input1(x);
	cout << "n= ";input2(n);
	cout << "m= ";input2(m);
	cout << "Luc nay \nn=" << n << "\nm=" << m << endl;
	add(n);add(m);
	cout << "Sau khi tang\nn=" << n << "\nm=" << m << endl;
	cout << "Gia tri cua P= " << fixed <<setprecision(5)<< p(x, n) << endl;
	cout << "Tong cac so chan lon hon 5 trong doan ["<<n<<","<<m<<"] la: " << fixed <<setprecision(5)<< p2(n, m);
}
