#include <iostream>
#include <conio.h>
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void displayLeapYearsBetween(int startYear, int endYear)
{
    bool foundLeapYear = false;

    cout << "Leap Years Between "<<startYear<<" and "<<endYear<<" are:\n";

    for (int year = startYear; year <= endYear; ++year)
        {
            if (isLeapYear(year))
            {
                cout << year << " ";
                foundLeapYear = true;
            }
        }

        if (!foundLeapYear)
            {
                cout << "No Leap Years Found.";
            }

            cout << endl;
}

int main()
{
    int startYear, endYear;

    cout<<"Start Year: "<<endl;
    cin>>startYear;
    cout<<endl;

    cout<<"End Year: "<<endl;
    cin>>endYear;
    cout<<endl;

    displayLeapYearsBetween(startYear, endYear);

    getch();
}

