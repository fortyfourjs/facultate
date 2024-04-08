#include <iostream>
using namespace std;


class DataCalendaristica
{
    private:
        int m_zi;
        int m_luna;
        int m_an;
    
    public:
        DataCalendaristica(int zi = 1, int luna = 1, int an = 2000) : m_zi(zi), m_luna(luna), m_an(an){}
        void printDataCalendaristica()
        {
            cout << m_an << "/" << (m_luna < 10 ? '0' : ' ') << m_luna << "/" << (m_zi < 10 ? '0' : ' ') << m_zi << '\n';
        }

        static bool validareData(int zi, int luna, int an)
        {
            if(luna < 1 || luna > 12)
                return false;
            if(zi < 1)
                return false;
            switch(luna)
            {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    return zi <= 31;
                case 4: case 6: case 9: case 11:
                    return zi <= 30;
                case 2:
                if((an % 4 == 0 && an % 100 != 0) || (an % 400 == 0))
                    return zi <= 29;
                    else return zi <= 28;
                default:
                    return false;
            }
        }


    int getAn() const 
    {
        return m_an;
    }

    int getLuna() const
    {
        return m_luna;
    }

    int getZi() const
    {
        return m_zi;
    }

    void setAn(int an)
    {
        m_an = an;
    }

    void setLuna(int luna)
    {
        m_luna = luna;
    }

    void setZi(int zi)
    {
        m_zi = zi;
    }


};

int main()
{
    DataCalendaristica data_unu{};
    data_unu.setAn(2020);
    data_unu.setZi(9);
    data_unu.setLuna(7);

    data_unu.printDataCalendaristica();

    
}
