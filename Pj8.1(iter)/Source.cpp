#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

// ������� ��� ��������, �� � � ����� ����� � ����� ������ "***"
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

// ������� ��� ����� ����� ����� � ����� ������ "***" �� "!!"
char* ReplaceTripleAsterisk(char* str)
{
    size_t len = strlen(str);
    if (len < 3)
        return str;

    char* tmp = new char[len * 2]; // �������� ��������� ���'�� ��� ����
    char* t = tmp;

    size_t i = 0;

    while (i < len)
    {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
        {
            strcat(t, "!!");
            t += 2;
            i += 3; // ���������� ����� ������
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    strcpy(str, tmp); // ������� ��������� � ���������� �����
    delete[] tmp;

    return str;
}

int main()

{
    char str[101];
    cout << "Enter string: ";
    cin.getline(str, 100);

    // ����������, �� � ����� � ����� ������
    if (ContainsTripleAsterisk(str))
        cout << "The string contains a group of three asterisks \"***\"." << endl;
    else
        cout << "The string does not contain a group of three asterisks \"***\"." << endl;

    // �������� �� ����� "***" �� "!!"
    ReplaceTripleAsterisk(str);
    cout << "Modified string: " << str << endl;

    return 0;
}
