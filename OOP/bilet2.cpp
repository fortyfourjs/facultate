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
            cout << (m_luna < 10 ? '0' : ' ') << m_luna << "/" << (m_zi < 10 ? '0' : ' ') << m_zi + 1 << "/" << m_an << '\n';  // hehe +1 
        }
};
int main()
{

DataCalendaristica data_unu{};
data_unu.setAn(2021);
data_unu.setZi(5);
data_unu.setLuna(7);

data_unu.printDataCalendaristica();

}
