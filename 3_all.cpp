#include <iostream>
#include<conio.h>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
        {
            if (arr[i] == key)
            {
                return i;
            }
        }
        return -1;
}

int binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
            {
                return mid;
            }
            else if (arr[mid] < key)
                {
                    low = mid + 1;
                }
                else
                    {
                        high = mid - 1;
                    }
        }

        return -1;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
                {
                    arr[k] = R[j];
                    j++;
                }
                k++;
        }

        while (i < n1)
            {
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < n2)
                {
                    arr[k] = R[j];
                    j++;
                    k++;
                }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
        {
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
        {
            int pivotIndex = partition(arr, low, high);

            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
        {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }

                arr[j + 1] = key;
        }
}

int main()
{
    int n;

    cout << "Enter The Number Of Elements In The Array: ";
    cin >> n;

    int arr[n];
    cout << "Enter The Elements Of The Array:" << endl;
    for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Choose A Searching Algorithm:" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        int searchChoice;
        cin >> searchChoice;

        int key;
        cout << "Enter The Key To Search For: ";
        cin >> key;
        int result = -1;

        switch (searchChoice)
        {
            case 1:
                result = linearSearch(arr, n, key);
                break;
            case 2:
                result = binarySearch(arr, n, key);
                break;
            default:
                cerr << "Invalid Choice For Searching Algorithm" << endl;
                return 1;
        }

        if (result != -1)
            {
                cout << "Key Found At Index: " << result << endl;
            }
             else
                {
                    cout << "Key Not Found In The Array." << endl;
                }

                cout << "Choose a sorting algorithm:" << endl;
                cout << "1. Quick Sort" << endl;
                cout << "2. Merge Sort" << endl;
                cout << "3. Insertion Sort" << endl;
                int sortChoice;
                cin >> sortChoice;

                switch (sortChoice)
                {
                    case 1:
                        quickSort(arr, 0, n - 1);
                        break;
                    case 2:
                        mergeSort(arr, 0, n - 1);
                        break;
                    case 3:
                        insertionSort(arr, n);
                        break;
                    default:
                        cerr << "Invalid Choice For SOrting Algorithm" << endl;
                        return 1;
                }

                cout << "Sorted Array: ";
                printArray(arr, n);

    getch();
}

