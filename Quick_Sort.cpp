#include<iostream>
#include<conio.h>
using namespace std;

int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

    swap(arr[i + 1], arr[h]);
    return i + 1;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
        {
            int pivotIndex = partition(arr, l, h);
            quickSort(arr, l, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, h);
        }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
}

int main()
{
    int n;

    cout << "Enter The Number Of Elements In The Array: "<<endl;
    cin >> n;
    cout<<endl;

    int arr[n];

    cout << "Enter The Elements Of The Array:\n";
    for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout<<endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: "<<endl;
    printArray(arr, n);

    getch();
}

