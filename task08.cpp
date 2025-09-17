#include <iostream>
#include <cmath>

using namespace std;

int main ()
{   
    constexpr float INCOMETAX = 13.0/100.0;

    int workersCounty;
    cout << "County of workers: ";
    cin >> workersCounty;

    int minEarnedWorkerNum = 1;
    int maxEarnedWorkerNum = 1;

    float workersHours[workersCounty] = {};
    float workersPayment[workersCounty] = {};

    float salaries[workersCounty] = {};

    float taxes[workersCounty] = {};
    float totalTaxSum = 0;

    int more50000County = 0;
    int more50000[workersCounty] = {};

    for (int i = 0; i < workersCounty; i++)
    {
        float hours, payment;
        
        cout << "Enter hours worked for worker " << i+1 << ": ";
        cin >> hours;
        cout << "Enter hourly payment for worker " << i+1 << ": ";
        cin >> payment;

        workersHours[i] = hours;
        workersPayment[i] = payment;
    }

    for (int i = 0; i < workersCounty; i++)
    {
        float earned = workersHours[i] * workersPayment[i];
        float tax = earned * INCOMETAX;
        float salary = earned - tax;

        salaries[i] = salary;
        taxes[i] = tax;
    }

    float maxSalary = salaries[0];
    float minSalary = salaries[0];

    for (int i = 0; i < workersCounty; i++)
    {
        float salary = salaries[i];
        float tax = taxes[i];

        totalTaxSum += tax;

        if (salary > maxSalary)
        {
            maxSalary = salaries[i];
            maxEarnedWorkerNum = i+1;
        }

        if (salaries[i] < minSalary)
        {
            minSalary = salaries[i];
            minEarnedWorkerNum = i+1;
        }

        if (salary > 50000)
        {
            more50000[i] = 1;
            more50000County += 1;
        }
    }

    cout << endl << "The worker " << minEarnedWorkerNum << " earned the least" << endl;
    cout << "Max salary is " << maxSalary << endl;
    cout << "THe worker " << maxEarnedWorkerNum << " earned the most" << endl;
    
    cout << more50000County << " worker(s) earned more than 50000: ";
    if (more50000County > 0)
    {
        for (int i = 0; i < workersCounty; i++)
        {
            if (more50000[i] != 0)
            {
                cout << i+1 << " ";
            }
        }
    }    

    return 0;
}