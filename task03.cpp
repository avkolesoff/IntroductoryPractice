#include <iostream>
using namespace std;

float getTotalSum(float hours, float payment, float premium)
{
    float basicEarnedSum = hours * payment;
    float earnedSumWithPremium = basicEarnedSum + (basicEarnedSum * premium) / 100.0;

    return earnedSumWithPremium;
}

float getIncomeTax(float salary)
{
    float incomeTax = (salary * 13) / 100.0;
    return incomeTax;
}

float getRealSalary(float salary) 
{
    float incomeTax = getIncomeTax(salary);
    float realSalary = salary - incomeTax;

    return realSalary;
}

void enterWorkersData (float &hoursWorked, float &hourlyPayment, float &premiumPercentage)
{
    cout << "Hours you worked: ";
    cin >> hoursWorked;

    cout << "Your hourly payment: ";
    cin >> hourlyPayment;

    cout << "Your percent of premium: "; 
    cin >> premiumPercentage;
}

int main()
{
    float hoursWorked, hourlyPayment, premiumPercentage;
    enterWorkersData(hoursWorked, hourlyPayment, premiumPercentage);

    float totalSum = getTotalSum(hoursWorked, hourlyPayment, premiumPercentage);
    float incomeTax = getIncomeTax(totalSum);
    float realSalary = getRealSalary(totalSum);
    
    cout << "You have earned: " << totalSum << endl;
    cout << "Your income tax: " << incomeTax << endl; 
    cout << "Your real salary: " << realSalary << endl;  

    return 0;
}