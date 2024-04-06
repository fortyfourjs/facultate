#include <string.h>
#include <iostream>

using namespace std;

class Imprimanta
{
    private:
        char* marca;
        char* tip;
        bool color;
        char* viteza;
        char* rezolutie;
    
    public:
        Imprimanta(char* _marca, char* _tip, bool _color, char* _viteza, char* _rezolutie);
        Imprimanta(const Imprimanta& ob);
        ~Imprimanta();

        void afisare();
        void setMarca(char* _marca);
        void setTip(char* _tip);
        void setColor(bool _color);
        void setViteza(char* _viteza);
        void setRezolutie(char* _rezolutie);
};

Imprimanta::Imprimanta(char* _marca, char* _tip, bool _color, char* _viteza, char* _rezolutie)
{
    marca = new char[strlen(_marca)+1];
    strcpy(marca, _marca);
    tip = new char[strlen(_tip)+1];
    strcpy(tip, _tip);
    color = _color;
    viteza = new char[strlen(_viteza)+1];
    strcpy(viteza, _viteza);
    rezolutie = new char[strlen(_rezolutie)+1];
    strcpy(rezolutie, _rezolutie);
    
}

Imprimanta::Imprimanta(const Imprimanta& ob)
{
    marca = new char[strlen(ob.marca)+1];
    strcpy(marca, ob.marca);
    tip = new char[strlen(ob.tip)+1];
    strcpy(tip, ob.tip);
    color = ob.color;
    viteza = new char[strlen(ob.viteza)+1];
    strcpy(viteza, ob.viteza);
    rezolutie = new char[strlen(ob.rezolutie)+1];
    strcpy(rezolutie, ob.rezolutie);

    
}

Imprimanta::~Imprimanta()
{
    delete []marca;
    
}

void Imprimanta::afisare()
{
    cout << "Marca: " << marca << '\n';
    cout << "Tip: " << tip << '\n';
    cout << "Color: " << boolalpha << color << '\n';
    cout << "Viteza: " << viteza << '\n';
    cout << "Rezolutie: " << rezolutie << '\n';
    cout << "---------" << '\n';
}

void Imprimanta::setMarca(char* _marca)
{
    if(strlen(marca) != strlen(_marca))
    {
        delete []marca;
        marca = new char[strlen(_marca)+1];
    }
    strcpy(marca, _marca);
}

void Imprimanta::setTip(char* _tip)
{
    if(strlen(tip) != strlen(_tip))
    {
        delete []tip;
        tip = new char[strlen(_tip)+1];
    }
    strcpy(tip, _tip);
}

void Imprimanta::setColor(bool _color)
{
    color = _color;
}

void Imprimanta::setViteza(char* _viteza)
{
    if(strlen(viteza) != strlen(_viteza))
    {
        delete []viteza;
        viteza = new char[strlen(_viteza)+1];
    }
}

void Imprimanta::setRezolutie(char* _rezolutie)
{
    if(strlen(rezolutie) != strlen(_rezolutie))
    {
        delete []rezolutie;
        rezolutie = new char[strlen(_rezolutie)+1];
    }
}


int main()
{
    Imprimanta i1("hp", "jet", "true", "100ppm", "1080p");
    i1.afisare();
    Imprimanta i2 = i1;
    i2.afisare();

    i1.setViteza("150ppm");
    
    i2.setRezolutie("1440p");
    i2.setMarca("logitech");
    i2.setTip("laser");

    i2.afisare();
    i1.afisare();

}
