#include <iostream>
#include<conio.h>
using namespace std;

int main()
{
    const int numberOfItems = 5;
    const int numberOfDays = 7;
    const int maxInputValue = 1000;

    double salesUnitPrice[numberOfItems];
    int salesQuantity[numberOfItems][numberOfDays];

    cout<<"Enter Sales Unit Price For Each Item:\n";
    for (int i=0; i<numberOfItems; ++i)
        {
            do
            {
                cout<<"Item "<<(i + 1)<<": $";
                cin>> salesUnitPrice[i];


                if (salesUnitPrice[i]<0 || salesUnitPrice[i]>maxInputValue)
                {
                    cout<<"Invalid Input."<<endl<<"Please Enter A Value Between 0 And "<<maxInputValue<<".\n";
                }
            }
            while (salesUnitPrice[i] < 0 || salesUnitPrice[i] > maxInputValue);
    }

    cout<<"\nEnter Sales Quantity For Each Item For Each Day:\n";
    cout<<endl;
    for (int i = 0; i < numberOfItems; ++i)
        {
            cout << "Item " << (i + 1) << ":\n";
            cout<<endl;

            for (int j=0; j<numberOfDays; ++j)
            {
                do
                {
                    cout<<"Day "<<(j + 1)<<": ";
                    cin>>salesQuantity[i][j];

                    if (salesQuantity[i][j] < 0 || salesQuantity[i][j] > maxInputValue)
                        {
                            cout<<"Invalid Input."<<endl<<"Please Enter A Value Between 0 And "<<maxInputValue<<".\n";
                        }
                }
                while (salesQuantity[i][j] < 0 || salesQuantity[i][j] > maxInputValue);
            }
        }

        double totalSales[numberOfItems] = {0};
        double averageSalesQuantity = 0;

        for (int i=0; i<numberOfItems; ++i)
            {
                for (int j=0; j<numberOfDays; ++j)
                {
                    totalSales[i] += salesUnitPrice[i] * salesQuantity[i][j];
                }
                averageSalesQuantity += totalSales[i];
            }

            averageSalesQuantity /= numberOfItems;

            cout<<"\nTotal Sales For Each Item:\n";

            for (int i = 0; i < numberOfItems; ++i)
                {
                    cout<<"Item "<<(i + 1)<<": $"<<totalSales[i]<<endl;
                }

                cout<<"\nAverage Sales Quantity For All Items: "<<averageSalesQuantity<<endl;

    getch();
}

