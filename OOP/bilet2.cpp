#include <iostream>
using namespace std;


class DataCalendaristica
{
    private:
        int m_an;
        int m_luna;
        int m_zi;

    public:
        DataCalendaristica() : m_an(2000), m_luna(1), m_zi(1){}
        int getAn()
        {
            return m_an;
        }

        void setAn(int an)
        {
            m_an = an;
        }

        int getLuna()
        {
            return m_luna;
        }

        void setLuna(int luna)
        {
            m_luna = luna;
        }

        int getZi()
        {
            return m_zi;
        }   

        void setZi(int zi)
        {
            m_zi = zi;
        }

        void printDataCalendaristica()
        {
            cout << (m_luna < 10 ? '0' : ' ') << m_luna << "/" << (m_zi < 10 ? '0' : ' ') << m_zi << "/" << m_an << '\n';  // hehe +1 
        }

        bool esteAnBisect() const
        {
            return(m_an % 4 == 0 && m_an % 100 != 0) || (m_an % 400 == 0);
        }

        int zileInLuna() const
        {
            switch(m_luna)
            {
                case 4: case 6: case 9: case 11: return 30;
                case 2: return esteAnBisect() ? 29 : 28;
                default: return 30;
            }
        }

        void urmatoareaZi()
        {
            m_zi++;
            if(m_zi > zileInLuna())
            {
                m_zi = 1;
                m_luna++;
                if(m_luna > 12)
                {
                    m_luna = 1;
                    m_an++;
                }
            }
        }
};
int main()
{

DataCalendaristica data_unu{};
data_unu.setAn(2021);
data_unu.setZi(30);
data_unu.setLuna(4);

data_unu.printDataCalendaristica();
data_unu.urmatoareaZi();
data_unu.printDataCalendaristica();

}
