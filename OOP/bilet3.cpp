#include <iostream>
#include <cmath>
using namespace std;

class Triunghi
{
    private:
        int m_l1;
        int m_l2;
        int m_l3;
    
    public:
        Triunghi(int l1 = 0, int l2 = 0, int l3 = 0) : m_l1(l1), m_l2(l2), m_l3(l3){}


    bool checkTriangle()
    {
        if(m_l1 == 0 || m_l2 == 0 || m_l3 == 0)
        {
            cout << "nu se poate forma un triunghi" << '\n';
                return false;
        }
        return true;
    }

    int getL1()
    {
        return m_l1;
    }

    int getL2()
    {
        return m_l2;
    }

    int getL3()
    {
        return m_l3;
    }

    void setL1(int l1)
    {
        m_l1 = l1;
    }

    void setL2(int l2)
    {
        m_l2 = l2;
    }

    void setL3(int l3)
    {
        m_l3 = l3;
    }

    void printLaturi()
    {
        cout << "l1=" << m_l1 << " l2=" << m_l2 << " l3=" << m_l3 << '\n';
    }


    int perimetru()
    {
        if(checkTriangle() == true)
        {
            cout << "Perimetrul triunghiului=" << m_l1 + m_l2 + m_l3 <<'\n'; 
        }
        else
        {
            cout << "tot nu e triunghi" << '\n';
        }
    }

    bool checkRightAngle()
    {
        if(pow(m_l1, 2) + pow(m_l2, 2) == pow(m_l3, 2) || pow(m_l2, 2) + pow(m_l3, 2) == pow(m_l1, 2) || pow(m_l1, 2) + pow(m_l3, 2) == pow(m_l2, 2))
        {
            cout << "triunghiul este dreptunghic" << '\n';
        }
        else
        {
        cout << "nu e dreptunghic" << '\n';
        }
    }


};

int main()
{
    Triunghi echilateral{};
    echilateral.setL1(5);
    echilateral.setL2(3);
    echilateral.setL3(4);
    
    echilateral.printLaturi();
    echilateral.checkTriangle();
    echilateral.perimetru();
    echilateral.checkRightAngle();

}
