#include <iostream>

using namespace std;

class DataCalendaristica
{
    private:
        int m_zi;
        int m_luna;
        int m_an;
        const char* luni[12] = {"Ianuarie", "Februarie", "Martie", "Aprilie", "Mai", "Iunie", "Iulie", "August", "Septembrie", "Octombrie", "Noiembrie", "Decembrie"};
        
    public:
        void printFormatStandard()
        {
            cout << m_an << '/' << (m_luna < 10 ? '0' : ' ') << m_luna << '/' << (m_zi < 10 ? '0' : ' ') << m_zi << '\n';
        }

        void printFormatFancy()
        {
            if(m_luna >= 1 && m_luna <= 12)
            {
                cout << (m_zi < 10 ? '0' : ' ') << m_zi << ' ' << luni[m_luna - 1] << ' ' << m_an << '\n';
            }
            else
            {
                cout << "data eronata\n";
            }
        }
        bool anBisect(int an)
        {
            return(an % 4 == 0 && (an % 100 != 0) || (an % 400 == 0));
        }

        int getAn() const { return m_an; }
        void setAn(int an) { m_an = an; }

        int getLuna() const { return m_luna; }
        void setLuna(int luna) { m_luna = luna; }

        int getZi() const { return m_zi; }
        void setZi(int zi) { m_zi = zi; }

        int zileInLuna(int luna, int an)
        {
            switch(luna)
            {
                case 2:
                    return anBisect(an) ? 29 : 28;
                case 4: case 6: case 9: case 11:
                    return 30;
                default:
                    return 31;
            }
        }
        int saptamaniAn(int saptamani, int an)
        {
            int numarZileAn = anBisect(an) ? 366 : 365;
            int numarSaptamani = numarZileAn / 7;

            return numarSaptamani;
        }

        int zileTo(int zi, int luna, int an)
        {
            int zileTotal = an * 365 + an / 4 - an / 100 + an / 400;
            for(int m = 1; m < luna; m++)
            {
                zileTotal += zileInLuna(m, an);
            }
            zileTotal += zi;
            return zileTotal;
        }
};

int main()
{
    DataCalendaristica data_unu{};
    data_unu.setAn(2020);
    data_unu.setZi(2);
    data_unu.setLuna(9);

    data_unu.printFormatFancy();
    
    DataCalendaristica data_doi{};
    data_doi.setAn(2021);
    data_doi.setZi(26);
    data_doi.setLuna(6);
    
    data_doi.printFormatFancy();

    int zile1 = data_unu.zileTo(data_unu.getZi(), data_unu.getLuna(), data_unu.getAn());
    int zile2 = data_doi.zileTo(data_doi.getZi(), data_doi.getLuna(), data_doi.getAn());
    int diferentaZile = zile2 - zile1;

    int numarSaptamani = data_doi.saptamaniAn(0, data_doi.getAn());
    cout << numarSaptamani;
    cout << "diferenta: " << diferentaZile << '\n';


    return 0;
}
