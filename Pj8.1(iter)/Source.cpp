#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

// Функція для перевірки, чи є в рядку група з трьох зірочок "***"
bool ContainsTripleAsterisk(const char* str)
{
    size_t len = strlen(str);
    for (size_t i = 0; i < len - 2; i++)
    {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
            return true;
    }
    return false;
}

// Функція для заміни кожної групи з трьох зірочок "***" на "!!"
char* ReplaceTripleAsterisk(char* str)
{
    size_t len = strlen(str);
    if (len < 3)
        return str;

    char* tmp = new char[len * 2]; // Виділяємо достатньо пам'яті для замін
    char* t = tmp;

    size_t i = 0;

    while (i < len)
    {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
        {
            strcat(t, "!!");
            t += 2;
            i += 3; // Пропускаємо трійку зірочок
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    strcpy(str, tmp); // Копіюємо результат у початковий рядок
    delete[] tmp;

    return str;
}

int main()

{
    char str[101];
    cout << "Enter string: ";
    cin.getline(str, 100);

    // Перевіряємо, чи є група з трьох зірочок
    if (ContainsTripleAsterisk(str))
        cout << "The string contains a group of three asterisks \"***\"." << endl;
    else
        cout << "The string does not contain a group of three asterisks \"***\"." << endl;

    // Замінюємо всі групи "***" на "!!"
    ReplaceTripleAsterisk(str);
    cout << "Modified string: " << str << endl;

    return 0;
}
