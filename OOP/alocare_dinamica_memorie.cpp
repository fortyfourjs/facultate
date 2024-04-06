#include <iostream>
 
using namespace std;

 class Punct 
{
    private:
        float x;
        float y;
    
    public:
        Punct()
        {
            x = 0;
            y = 0;
            cout << "Apel constructor implicit Punct(0,0)" << '\n';
        }
        
        Punct(float x, float y)
        {
            this -> x = x;
            this -> y = y;
            cout << "Apel constructor Punct(" << x << "," << y << ")" << '\n';
        }

        ~Punct()
        {
            cout << "Apel destructor Punct(" << x << "," << y << ")" << '\n';
        }
};

int main()
{
    Punct *p1 = new Punct;
    Punct *p2 = new Punct(3,4);
    Punct *t = new Punct[3];

    delete p1;
    delete p2;

    cout << "eliberez tabloul: " << '\n';
    delete []t;
    
    return 0;
}
