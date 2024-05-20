#include <iostream>
using namespace std;

class Triangle
{
    private:
        int m_l1;
        int m_l2;
        int m_l3;
    public:
        Triangle(int l1 = 0, int l2 = 0, int l3 = 0) : m_l1(l1), m_l2(l2), m_l3(l3){}

    int getL1() const
    {
        return m_l1;
    }
    void setL1(int l1)
    {
        m_l1 = l1;
    }
    int getL2() const
    {
        return m_l2;
    }
    void setL2(int l2)
    {
        m_l2 = l2;
    }
    int getL3() const
    {
        return m_l3;
    }
    void setL3(int l3)
    {
        m_l3 = l3;
    }

    bool verificaTriunghi()
    {
        if(m_l1 == 0 || m_l2 == 0 || m_l3 == 0)
        {
            cout << "nu este triunghi" << '\n';
                return false;
        }
            return true;
    }


};
