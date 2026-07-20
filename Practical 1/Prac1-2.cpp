#include <iostream>
using namespace std;

int main()
{
    int book[] = {1, 2, 2, 1, 2, 56, 77, 456, 44, 77};
    int n = sizeof(book) / sizeof(book[0]);

    int rec[10];
    int h = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = book[i];

        for (int j = i + 1; j < n; j++)
        {
            if (temp == book[j])
            {
                bool found = false;

                // Check if already stored
                for (int k = 0; k < h; k++)
                {
                    if (rec[k] == temp)
                    {
                        found = true;
                        break;
                    }
                }

                // If not already printed
                if (!found)
                {
                    cout << temp << " ";
                    rec[h] = temp;
                    h++;
                }

                break; // No need to check further duplicates of this number
            }
        }
    }

    return 0;
}