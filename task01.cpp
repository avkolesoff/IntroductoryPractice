#include <iostream>

int main ()
{
    using namespace std;

    float hoursWorked, hourlyPayment, premiumPercentage;

    cout << "Hours you worked: ";
    cin >> hoursWorked;

    cout << "Your hourly payment: ";
    cin >> hourlyPayment;

    cout << "Your persent of premium: ";
    cin >> premiumPercentage;

    float basicEarnedSum = hoursWorked * hourlyPayment;
    float earnedSumWithPremium = basicEarnedSum + (basicEarnedSum * premiumPercentage)/100.0;
    
    cout << "You have earned: " << earnedSumWithPremium;

    return 0;
}