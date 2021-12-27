// File Name: e_computing.cpp
// Author: Kai Li
// Email Address: kai.li@stonybrook.edu
// AMS 595 Project
// Description: Program accepts choices for different numerical
// approximations of Euler's number e and an input n or number of 
// terms wanted. Program prints out numerical approximation
// using the method and the given input. Actual error will be
// printed along with approximation to compare with accuracy.
// Last Updated: December 2nd, 2020


#include <iostream>
#include <cmath>
using namespace std;
  
int n_input();
// Postcondition: Description of n is written on the screen.
int order_input();
// Postcondition: Description of order is written on the screen.
int factorial(int n);
// Precondition: An integer that needs to calculate its factorial
// is ready.
// Postcondition: The factorial of the given integer is returned.
long double calculation_1(int n);
// Precondition: n is the number to approximate in the method.
// Postcondition: A numerical approximation of e using the
// first method is calculated.
long double calculation_2(int n, int p);
// Precondition: n is the number to approximate in the method.
// Order is the order to approximate in the method.
// Postcondition: A numerical approximation of e using the
// second method is calculated.
long double calculation_3(int n);
// Precondition: n is the number to approximate in the method.
// Postcondition: A numerical approximation of e using the
// third method is calculated.
long double calculation_4(int n);
// Precondition: n is the number to approximate in the method.
// Postcondition: A numerical approximation of e using the
// fourth method is calculated.
long double calculation_5(int n);
// Precondition: n is the number to approximate in the method.
// Postcondition: A numerical approximation of e using the
// fifth method is calculated.
long double calculation_6(int order);
// Precondition: order is the order to approximate in the method.
// Postcondition: A numerical approximation of e using the
// sixth method is calculated.
long double calculation_7(int order);
// Precondition: order is the order to approximate in the method.
// Postcondition: A numerical approximation of e using the
// seventh method is calculated.
long double calculation_8(int order);
// Precondition: order is the order to approximate in the method.
// Postcondition: A numerical approximation of e using the
// eighth method is calculated.
void show_results(long double e_estimate);
// Precondition: A numerical approximation of e is ready.
// Postcondition: The approximation and the absolute error
// is written on the screen.

int main(){
    int choice = 0; 
    double n = 0.0;
    double order = 0.0;
    long double e_estimate = 0.0;    
    
    cout << endl;
    cout << "This is a program that calculates Euler's number e using" << endl;
    cout << "different approximation methods. Please read the PDF" << endl;
    cout << "written document for full details about the methods." << endl;

    do{
        cout << endl;
        cout << "Main Menu\n";
        cout << "Choose 1 for Compound Interest Method.\n";
        cout << "Choose 2 for Improved Compound Interest Method.\n";
        cout << "Choose 3 for Complementary Addition Method.\n";
        cout << "Choose 4 for Power Ratio Method.\n";
        cout << "Choose 5 for Stirling's Formula Approximation Method.\n";
        cout << "Choose 6 for Power Series Method.\n";
        cout << "Choose 7 for Continued Fraction Method.\n";
        cout << "Choose 8 for Pippenger Product Method.\n";
        cout << "Choose 0 to exit the program.\n";
        cin >> choice;

        switch (choice){
            case 1:
                n = n_input();
                e_estimate = calculation_1(n);    
                show_results(e_estimate);
                break;
            case 2:
                n = n_input();
                order = order_input();
                if (order >= 13){
                    cout << "Due to the precision level of variable type int, " << endl;
                    cout << "we maximize the number of orders to be 12 so that" << endl;
                    cout << "the result of approximation is accurate." << endl;
                } else {
                    e_estimate = calculation_2(n, order);
                    show_results(e_estimate);
                }                 
                break;
            case 3:
                n = n_input();
                e_estimate = calculation_3(n);
                show_results(e_estimate);
                break;
            case 4:
                n = n_input();
                if (n >= 143){
                    cout << "Due to the precision level of variable type int, " << endl;
                    cout << "we maximize the number of orders to be 143 so that" << endl;
                    cout << "the result of approximation is accurate." << endl;
                } else {
                    e_estimate = calculation_4(n);
                    show_results(e_estimate);
                }  
                break;
            case 5:
                n = n_input();
                if (n >= 13){
                    cout << "Due to the precision level of int, we maximize" << endl;
                    cout << "the number of n to be 12 so that the result" << endl;
                    cout << "of approximation is accurate." << endl;
                } else {
                    e_estimate = calculation_5(n);
                    show_results(e_estimate);
                }    
                break;
            case 6:
                order = order_input();
                if (order >= 13){
                    cout << "Due to the precision level of variable type int, " << endl;
                    cout << "we maximize the number of orders to be 12 so that" << endl;
                    cout << "the result of approximation is accurate." << endl;
                } else {
                    e_estimate = calculation_6(order);
                    show_results(e_estimate);
                }
                break;                
            case 7:
                order = order_input();
                e_estimate = calculation_7(order);
                show_results(e_estimate);
                break;
            case 8:
                order = order_input();
                if (order == 1){
                    cout << "The order must be greater than 1.\n";
                } else if (order >= 8){
                    cout << "Due to the precision level of variable type int, " << endl;
                    cout << "we maximize the number of orders to be 7 so that" << endl;
                    cout << "the result of approximation is accurate." << endl;
                } else {
                    e_estimate = calculation_8(order);
                    show_results(e_estimate);
                }
                break;      
            case 0:
                cout << "End of Program.\n";
                break;
            default:
                cout << "Not a valid choice. Choose Again.\n";
        }
    }while (choice != 0);
}

int n_input(){
    double n = 0.0;

    do{
        cout << endl;
        cout << "Please enter a positive integer n used to approximate" << endl;
        cout << "the value of e: ";
        cin >> n;
        cout << endl;
        
        if (n <= 0 && n - (int) n != 0){
            cout << "Not a valid input.\n";
            cout << "Enter Again.\n";
        }
    }while (n <= 0 && n - (int) n != 0);

    return n;
}

int order_input(){
    double order = 0.0;

    do{
        cout << endl;
        cout << "Please enter a positive integer number of orders or" << endl;
        cout << "number of terms used to approximate the value of e: ";
        cin >> order;
        cout << endl;
        
        if (order <= 0 && order - (int) order != 0){
            cout << "Not a valid input.\n";
            cout << "Enter Again.\n";
        }
    }while (order <= 0 && order - (int) order != 0);

    return order;
}

int factorial(int n){
    int result = 1;

    for (int i = 1; i <= n; i++){
        result *= i;
    }

    return result;
}

long double calculation_1(int n){
    long double result = 0.0;

    result = pow(1 + 1.0/n, n);
    return result;
}

long double calculation_2(int n, int p){
    long double result = 1.0; 

    for (int i = 1; i <= p; i++){
        result += 1.0/(factorial(i)*pow(n, i));
    }
    result = pow(result, n);
    return result;
}

long double calculation_3(int n){
    long double result = 0.0;
    
    result = 1.0/2*(pow(1 + 1.0/n, n) + pow(1 - 1.0/n, -n));
    return result;
}

long double calculation_4(int n){
    long double result = 0.0;

    result = pow(n + 1, n + 1)/pow(n, n) - pow(n, n)/pow(n - 1, n - 1);
    return result;
}

long double calculation_5(int n){
    long double result = 0.0;
    int n_factorial = 0;

    n_factorial = factorial(n);
    result = n/pow(n_factorial, 1.0/n);
    return result;
}

long double calculation_6(int order){
    long double result = 0.0; 
    int i_factorial = 0;

    for (int i = 0; i <= order; i++){
        i_factorial = factorial(i);
        result += 1.0/i_factorial;
    }
    return result;
}

long double calculation_7(int order){
    long double result = 0.0; 

    if ((order + 1) % 3 == 0){
        result = 1.0/(2*(order + 1)/3);
    } else {
        result = 1.0;
    }

    for (int i = order - 1; i >= 1; i--){
        if ((i + 1) % 3 == 0){
            result = 1/(2*(i + 1)/3 + result);
        } else {
            result = 1/(1 + result);
        }
    }
    result += 2;
    return result;
}

long double calculation_8(int order){
    long double result = sqrt(2);
    long double i_term = 0;

    for (int i = 2; i <= order; i++){
        i_term = pow(2, (pow(2, i) - 1))*pow(tgamma(1.0/2 + pow(2, i - 2)), 4)
                /(M_PI*pow(tgamma(1.0/2 + pow(2, i - 1)), 2));
        result *= pow(i_term, 1.0/pow(2, i));
    }
    result *= 2;    
    return result;
}

void show_results(long double e_estimate){
    if (isnan(e_estimate) || isinf(e_estimate)){
        cout << "The estimated e cannot be represented in such a" << endl;
        cout << "high precision level. Please try again with a" << endl;
        cout << "lower n and/or the number of orders in the input." << endl;
    } else{
        cout.setf(ios::scientific);
        cout.setf(ios::showpoint);
        cout.precision(8);
        cout << "Estimated e is " << e_estimate << endl;
        cout << "Absolute Error: " << fabs(exp(1) - e_estimate) << endl;
    }
}