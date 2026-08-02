#include <iostream>
using namespace std;

// Function to find the largest number
int getMax(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

// Counting Sort according to the digit represented by exp
void countingSort(int arr[], int n, int exp)
{
    int output[100];
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Convert count[] into cumulative count[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build output array (traverse from end for stability)
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output back to original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Radix Sort
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    // Sort by each digit (1,10,100,...)
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

int main()
{
    int n;

    cout << "Enter number of tracking codes: ";
    cin >> n;

    int arr[100];

    cout << "Enter tracking codes:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    radixSort(arr, n);

    cout << "\nSorted Tracking Codes:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}