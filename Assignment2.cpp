#include <iostream>
#include <cmath>
using namespace std;

int countNumbersPerson(int smart, int power, int exp)
{
    if(exp==0)
        return 1;
    if(smart+exp<= power)   return 0;
    smart=smart+exp;
    int s=0;
    for (int i=0;i<exp;i++){
        if(smart>power){
            s++;
            smart--;
            power++;
        }
    }
    return s;
}
int main()
{
    cout << countNumbersPerson(5,3,5);
}
// =============================================
