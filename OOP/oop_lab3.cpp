#include <string.h>
#include <iostream>
/* #pragma warning (disable:4996) */
using namespace std;

class Procesor 
{
	private:
		char *model;
		float frecventa;
		int numarNuclee;

	public:
		Procesor(char *_model, float _frecventa, int _numarNuclee);
		Procesor(const Procesor& ob);
		~Procesor();
		void afisare();
		void setModel(char *_model);
		void setFrecventa(float _frecventa);
		void setNumarNuclee(int _numarNuclee);
};

	Procesor::Procesor(char *_model, float _frecventa, int _numarNuclee)
	{
		model = new char[strlen(_model)+1];
		strcpy(model, _model);
		frecventa = _frecventa;
		numarNuclee = _numarNuclee;
		cout << "Apel constructor cu parametri" << '\n';
	}

	Procesor::Procesor(const Procesor& ob)
	{
		model = new char[strlen(ob.model)+1];
		strcpy(model, ob.model);
		frecventa = ob.frecventa;
		numarNuclee = ob.numarNuclee;
		cout << "Apel constructor de copiere" << '\n';
	}

	Procesor::~Procesor()
	{
		delete []model;
		cout << "apel destructor" << '\n';
	}

	void Procesor::afisare()
	{
		cout << "--------PRocesor-----" << '\n';
		cout << "model: " << model << '\n';
		cout << "frecventa: " << frecventa << '\n';
		cout << "-------------" << '\n';
	}

	void Procesor::setModel(char *_model)
	{
		if (strlen(model) != strlen(_model))
		{
			delete []model;
			model = new char[strlen(_model)+1];
		}
		strcpy(model, _model);
	}

	void Procesor::setFrecventa(float _frecventa)
	{
		frecventa = _frecventa;
	}

	void Procesor::setNumarNuclee(int _numarNuclee)
	{
		numarNuclee = _numarNuclee;	
	}


	int main()
	{
		Procesor p1("Core i5", 1.9, 4);
		p1.afisare();
		Procesor p2 = p1;
		p2.afisare();

		p2.setFrecventa(2.0);
		p2.setModel("core i7");

		p2.afisare();
		p1.afisare();


		

		return 0;
		
	}



