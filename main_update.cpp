#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double a, x0, tolerance, epsilon;
void getInput ( ) {
    cout << "Enter the number we want to find the square root of: ";
    cin >> a;
    cout << "Enter the initial guess: ";                                    //kezdeti érték
    cin >> x0;
    cout << "Enter the tolerance: ";                         //a Julia-kódban is tolerancia, a különbségben kell
    cin >> tolerance;
    cout << "Enter the epsilon: ";                            //ez az f(x)/fdev(x) értékének a vizsgálására kell
    cin >> epsilon;
}
auto f=[](double x)->double{return pow(x,2)-a;};            //alap függvény
auto fdev=[](double x)->double{return 2*x;};                  //derivált függvény   

double sqrt_newton(double num, double x0){                      //megadott függvény a feladat szerint, ami számol a Newton-módszer szerint
    double x=x0;
    double x1=x-(f(x)/fdev(x));                                 
    if (fabs( x1 - x )<=num){                                   //ha egy érték alatt van a különbség akkor "elfogadja" mint eredmény
    cout<<"The root of the equation is "<<x1<<endl;             //az érték kiiratása
    }
    return x1;
}   
int main(int argc, char** argv){
    getInput();                                          
    if(x0 < 0){
        cout<<"x0 is a negative number "<<endl;                 //ha negatív szám a kezdeti érték, akkor leáll a program
        return 0;
    }
    do{
        double x00=sqrt_newton(tolerance, x0);                  //a számoló függvény meghívása, amely kiiratja minden ciklusban az x0, az eredmény és a két különbségét
          cout<<x0<<"           "<<x00<<"           "<<abs(x0-x00)<<endl;
        if(fabs(x00) < epsilon) {  
        break;
        }
        x0=x00;
    } while (fabs(sqrt_newton(tolerance, x0)-x0)>=tolerance);   //eddig fut a program
return 0;
}