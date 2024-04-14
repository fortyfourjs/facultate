#include <iostream>
#include <cstring>

using namespace std;


class String
{
    private:
        char* sir;
       
    public:
        String(const char* sir); // constructor initialize
        String(const String& other); //copy constructor

    int MarimeSir() const
    {
        return strlen(sir);
    }

    int vocaleSir() const
    {
        int numarVocale = 0;
        char* temp = sir;

        while(*temp != '\0')
        {
            if(*temp == 'a' || *temp == 'e' || *temp == 'i' || *temp == 'o' || *temp == 'u' || *temp == 'A' || *temp == 'E' || *temp == 'I' || *temp == 'I' || *temp == 'U')
            {
            numarVocale++;
            }
        temp++;
        }
    return numarVocale;
    }

    ~String()  //destructor
    {
        if(sir != nullptr)
        {
            delete[] sir;
            sir = nullptr;
        }
    }

        
};

String::String(const char* sir) //constructor 
{
    this->sir = new char[strlen(sir) + 1];
    strcpy(this->sir, sir);
}

String::String(const String& other) //copy constructor
{
    this->sir = new char[strlen(other.sir) + 1];
    strcpy(this->sir, other.sir);
}



int main()
{
    String str1("rush b rush b");


    cout << "lenght of the string: " << str1.MarimeSir() << '\n';
    cout << "numarul vocalelor: " << str1.vocaleSir() << '\n';
    return 0;
}
