#include <iostream>
#include <cstring>

using namespace std;


class Palindrom
{
    private:
        char* string;
    
    public:
        Palindrom(const char* string);
        bool ePalindrom() const;

};

Palindrom::Palindrom(const char* string)
{
    this->string = new char[strlen(string) + 1];
    strcpy(this->string, string);
}

bool Palindrom::ePalindrom() const
{
    int length = strlen(string);
    char* start = string;
    char* end = string + length - 1;

    while(start < end)
    {
        if(*start != *end)
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    Palindrom p1("capac");
    if(p1.ePalindrom())
    {
        cout << "sirul este palindrom" << '\n';
    }
    else
    {
        cout << "sirul nu este palindrom" << '\n';
    }

    return 0;
}
