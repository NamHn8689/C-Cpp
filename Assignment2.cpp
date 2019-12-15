#include <iostream>
#include <fstream>
#include "iomanip"
#include "malloc.h"

using namespace std;

void Nhap(double *&a , int &n)
{
    cout<< "n=" ; cin>>n;
    a = new double [n];
    for(int i=0 ; i<n ; i++)
    {
        cout<< "a[" <<i <<"]=" ;
        cin>>a[i];
    }
}

void Sap(double *a , int n)
{
    for(int i=0 ; i<n ; i++)
        for(int j=i+1 ; j<n ; j++)
        {
            if(a[i]>a[j])
            {
                float tg=a[i];
                a[i]=a[j];
                a[j]=tg;
            }
        }
}

double Tong(double *a,int n)
{
    double T=0;
    for(int i=2 ; i<n ; i++)
        if(i%2==0) T=T+a[i];
    return T;
}

void Xuat(double *a, int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cout<<a[i]<<" ";
    }
}

void Ghitep(char *fn , double *a , int n)
{
    ofstream f(fn , ios::out);
    f<<n<<endl;
    for(int i=0 ; i<n ; i++)
    {
        f<<setprecision(2)<<a[i] <<" " ;
    }
    f<<endl;
    f<<"END";
    f.close();

}

void MAX1MAX2(double*a,int n)
{
    double M1 = a[0];
    for(int i=0; i<n; i++)
        if(a[i]>M1) M1=a[i];
    cout<<"Max 1 = "<<M1<<endl;



    int L=0;
    while(a[L]==M1 && L<n-1)    L++;
    if(L==n-1 && a[n-1]==M1)
            cout<<"Khong tin tai Max 2";
    else //Bat dau tim Max 2
    {
        double M2 = a[L];
        for(int i=0; i<n; i++)
            if(a[i]>M2 && a[i] !=M1) M2=a[i];
        cout<<"Max 2 = "<<M2<<endl;
    }
}

bool Check(double *a, int n)
{

    for(int i=0 ; i<n-2; i++)
       if(a[i]>0 && a[i+1]>0 && a[i+2]>0)
            return true;
    return false;
}

void Delete(double *&a, int &n)
{
    for(int i=0 ; i<n ; i++)
        while(a[i]>5 && i<n)
        {
            for(int j=i ; j<n-1 ; j++)
                 a[j]=a[j+1];
            n--;
        }
        a=(double*) realloc(a, n*sizeof(double));
}
int main()
{
    double *a; int n;
    Nhap(a, n);
    Sap(a, n);
    Xuat(a, n);
    cout<<endl<<"TONG="<<Tong(a, n)<<endl;
    Ghitep("assignment2.txt", a, n);
    MAX1MAX2(a, n);
    if(Check(a, n)) cout<<"MANG HOP LE"<<endl;
    else            cout<<"MANG KHONG HOP LE"<<endl;

    Delete(a, n);
    Xuat(a, n);
    return 0;
}
