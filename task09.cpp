#include <iostream>


int getMinElementIndex (float array[], const int size) 
{
    float minElement = array[0];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < minElement) 
        {
            minElement = array[i];
            index = i;
        }
    }
    return index;
}

void getMaxElement(float array[], const int size, float &element, int &index)
{
    element = array[0];
    index = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > element)
        {
            element = array[i];
            index = i;
        }
    }
}

int getNumOfElementsAbove (float array[], const int size, float number)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > number)
        {
            count += 1;
        }
    }
    return count;
}

float getSumOfElements (float array[], const int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}


int main ()
{   
    using namespace std;

    constexpr float INCOMETAX = 13.0/100.0;

    int workersCounty;
    int more50000County;

    cout << "County of workers: ";
    cin >> workersCounty;

    int maxEarnedWorkerNum, minEarnedWorkerNum;

    float workersHours[workersCounty] = {};
    float workersPayment[workersCounty] = {};

    float salaries[workersCounty] = {};
    float maxSalary, minSalary;

    float taxes[workersCounty] = {};
    float totalTaxSum;

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

    minEarnedWorkerNum = getMinElementIndex(salaries, workersCounty);
    getMaxElement(salaries, workersCounty, maxSalary, maxEarnedWorkerNum);
    more50000County = getNumOfElementsAbove(salaries, workersCounty, 50000);
    totalTaxSum = getSumOfElements(taxes, workersCounty);

    cout << endl << "The worker " << minEarnedWorkerNum << " earned the least" << endl;
    cout << "Max salary is " << maxSalary << endl;
    cout << "THe worker " << maxEarnedWorkerNum << " earned the most" << endl;

    cout << "Worker(s)";
    for (int i = 0; i < workersCounty; i++)
    {
        if (salaries[i] > 50000)
        {
            cout << " " << i+1;
        }
    }
    cout << " earned more than 50000";
    cout << endl << "Totaly " << more50000County << " worker(s) earned more than 50000" << endl;
    cout << "Total tax sum payed: " << totalTaxSum;

    return 0;
}