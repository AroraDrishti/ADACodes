
#include <iostream>
#include <string.h>
using namespace std;

int inDict(string word)
{
    string dictionary[] = {"I", "man", "mango", "icecream", "and", "go", "i", "love", "ice", "cream"};

    for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++)
    {
        if (dictionary[i].compare(word) == 0)
        {
            return true;
        }
    }
    return false;
}

bool wordBreakDP(string str)
{
    int size = str.size();
    if (size == 0)
    {
        return true;
    }

    bool wb[size + 1];
    memset(wb, 0, sizeof(wb));

    for (int i = 1; i <= size; i++)
    {
        if (wb[i] == false && inDict(str.substr(0, i)))
        {
            wb[i] = true;
        }

        if (wb[i] == true)
        {
            if (i == size)
                return true;

            for (int j = i + 1; j <= size; j++)
            {
                if (wb[j] == false && inDict(str.substr(i, j - i)))
                    wb[j] = true;

                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }

    for (int i = 1; i <= size; i++)
    {
        cout << " " << wb[i];
    }

    return false;
}
int main()
{
    string str;
    cout << "Enter a string for the Word Break Problem: ";
    cin >> str;
    wordBreakDP(str) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}