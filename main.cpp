#include <iostream>
#include <math.h>
#include <cassert>
using namespace std;



class Polinom {
	int grad; // polinomul va avea "indexare" de la -1 (v = NULL). grad = 0 inseamna ca are un element v[0];
	double *v;


public:

	// constructor default, seteaza grad la -1 (polinom gol)
	Polinom() {
		grad = -1;
	}
	// constructor cu parametri, dam grad si adresa unui vector de double cu coeficientii
	Polinom(const int gr,const double *w) {
		grad = gr;
		v = new double[grad+1];
		for (int i = 0; i <= grad; i++) {
			v[i] = w[i];
		}
	}
	// constructor pentru numar real (polinom de grad 0)
	Polinom(const double x) {
		grad = 0;
		v = new double[1];
		v[0] = x;
	}
	// copy constructor, dam adresa unui polinom si facem altul
	Polinom(const Polinom& ot) {
		grad = ot.grad;
		v = new double[grad+1];
		for (int i = 0; i <= grad; i++)
			v[i] = ot.v[i];
	}
	// destructor : grad = -1 (polinom gol) si dealocarea vectorului
	~Polinom() {
		grad = -1;
		if (v != NULL)
			delete[] v;
	}

	// get-uri
	int getGrad() {
		return grad;
	}
	double getPolinom(const int pozitie) {
	    return v[pozitie];

	}
	double* getAddres() {
		return v;
	}
	// insert
	void insert(const double x) {
		grad++;
		double *aux = new double[grad+1];
		for (int i = 0; i <= grad; i++)
			aux[i] = v[i];
		delete[] v;
		aux[grad - 1] = x;
		v = aux;
	}
	// overload pe = cu polinoame
	void operator=(const Polinom &ot) {
		grad = ot.grad;
		v = new double[grad+1];
		for (int i = 0; i <= grad; i++) {
			v[i] = ot.v[i];

		}
	}
	// overload pe = cu double
	void operator=(const double ot) {
		grad = 0;
		if (v != NULL) {
			delete[] v;
			v = new double[1];
			v[0] = ot;
		}
		else {
			v = new double[1];
			v[0] = ot;
		}
	}
	// overload pe [] pentru get
	double operator[](const int index) {
		if (index > grad) {
			return 0; // daca indexul este in afara returneaza 0
		}
		else return v[index];
	}
	double operator()(const int punct){
       int valoare=1;
       int suma=0;
	   int grad1=grad;
	   for ( int i=0;i<=grad;i++)
       {
        while(grad1!=0)
           {valoare=valoare*punct;
           grad1-=1;}
        suma=suma+valoare*v[i];
        grad1=grad-i-1;
        valoare=1;

       }
       return suma;


	}
	friend Polinom operator+ (Polinom p1 ,Polinom p2){
	   int gradmax=max(p1.grad,p2.grad);
	   int j=p1.grad,k=p2.grad;
	   double w[gradmax+1];
	    for (int i=gradmax; i>=0; i--)
        {
            if (j>=0 && k>=0)
            {
               w[i]=p1.v[j]+p2.v[k];
               k-=1;
               j-=1;
            }
            else
            {
                if (j>=0)
                    w[i]=p1.v[i];
                if (k>=0)
                    w[i]=p2.v[i];
            }

        }
        return Polinom(gradmax, w);
	}
	friend Polinom operator^ (Polinom p ,int putere){

	    double w[2*(p.grad)];
	    for(int i=0;i<=p.grad; i++)
            for(int j=0;j<=p.grad;j++)
            w[(p.grad-i)+(p.grad-j)]+=p.v[i]*p.v[j];

        return Polinom(2*(p.grad),w);


	}


};
int main()
{
    int n;
   double v[100];
   cin>>n;
   for(int i=0;i<=n;i++)
    v[i]=i+1;
    Polinom z(n,v);
    cout<<z.getGrad()<<endl;
    cout<<z.getAddres()<<endl;
    cout<<z.getPolinom(4)<<endl;
    cout<<z.operator[](4)<<endl;
    cout<<z.operator()(2)<<endl;
    cout<<z[4]<<endl;
    cout<<z(2)<<endl;
    Polinom k;
    k=z;
    Polinom j=z+k;
    cout<<j[4]<<endl;
    Polinom x=z^2;
    cout<<x[3]<<endl;



}
