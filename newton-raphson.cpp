#include <iostream>
#include <math.h> //pow,abs
#include <iomanip> //setw

using namespace std;

float fungsi(float x)
{
    return (pow(x,3))- (6*pow(x,2))+ (11*x) - 5.9;
}

float fungsi_turunan(float x)
{
     return 3*pow(x,2)- 12*x + 11;
}

float xplus (float x, float f_x, float f_xt)
{
    return x - (f_x/f_xt);
}

float errabs (float x, float x2)
{
    return abs((x2-x)/x2);
}

int main()
{
    int i=1;
    float x, x2, f_x, f_xt, error, err;
    cout << "==============================================" << endl;
    cout << "\t METODE NEWTON RHAPSON" << endl;
    cout << "==============================================" << endl;
    cout << " f(x) = x^3-6x^2+11x-5.9" << endl << endl;

    do
    {
        cout << " Masukkan nilai x sembarang     : ";cin >> x;
        cout << " Masukkan nilai toleransi error : ";cin >> error;
        cout << fungsi_turunan(x);

    }while (fungsi_turunan(x)== 0);

    system ("cls");

    cout << "================================================================================================" << endl;
    cout << "|   i   |       x       |       x+i       |     f(x)     |    f'(x)   |   f(x+i)   |   error   |" << endl;
    cout << "================================================================================================" << endl;
    do
    {
        f_x = fungsi(x);
        f_xt = fungsi_turunan(x);
        x2 = xplus(x,f_x,f_xt);

        cout << "|" << setw(7) << i;
        cout << "|" << setw(15) << fixed << setprecision(3) << x;
        cout << "|" << setw(17) << fixed << setprecision(3) << xplus(x,f_x,f_xt);
        cout << "|" << setw(14) << fixed << setprecision(3) << fungsi(x);
        cout << "|" << setw(12) << fixed << setprecision(3) << fungsi_turunan(x);
        cout << "|" << setw(12) << fixed << setprecision(3) << fungsi(x2);
        cout << "|" << setw(11) << fixed << setprecision(3) << errabs(x,x2) << "|";
        cout << endl;

        err = errabs(x,x2);
        x = xplus(x,f_x,f_xt);
        i++;

    }while (err >= error);

    cout << endl;
    cout << " Nilai akar aproksimasi : "<< x << endl;
    cout << " Jumlah iterasi : "<< i-1 << endl;

    return 0;
}
