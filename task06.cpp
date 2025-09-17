#include <iostream>
#include <cstring>

using namespace std;

string inputWorkersLastname()
{       
    string lastname;
    
    do {
        cout << "Worker`s lastname: ";
        cin >> lastname;
        if (lastname.length() > 20) {
            cout << "Lastname must be less than 21! Try again!\n";
        }
    } while (lastname.length() > 20);
    
    return lastname;
}

int main ()
{
    float hours1, hours2, payment1, payment2, sum1, sum2, tax1, tax2;
    
    string lastname1 = inputWorkersLastname();
    cout << lastname1 << "`s hours worked: ";
    cin >> hours1;
    cout << lastname1 << "`s hourly payment: ";
    cin >> payment1;

    string lastname2 = inputWorkersLastname();
    cout << lastname2 << "`s hours worked: ";
    cin >> hours2;
    cout << lastname2 << "`s hourly payment: ";
    cin >> payment2;

    sum1 = hours1*payment1;
    tax1 = (sum1*13)/100.0;
    sum2 = hours2*payment2;
    tax2 = (sum2*13)/100.0;

    if (sum1 > 1000 || sum2 > 1000)
    {
        if (sum1-tax1 < 1000) cout << lastname1 << " earned less than 1000\n";
        if (sum2-tax2 < 1000) cout << lastname2 << " earned less than 1000\n";
    }
    else cout << "Noone earned less than 1000\n";

    if (tax1 > 50 || tax2 > 50)
    {
        if (tax1 > 50) cout << lastname1[0] << '-' << lastname1[lastname1.length()-1] << " has tax more than 50\n";
        if (tax2 > 50) cout << lastname2[0] << '-' << lastname2[lastname2.length()-1] << " has tax more than 50\n";
    }
    else cout << "Noone has tax more than 50\n";

    return 0;
}