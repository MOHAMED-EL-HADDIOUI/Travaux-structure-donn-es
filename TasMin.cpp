#include<iostream>
#include<string>
using namespace std;
class TasMin{ 
	private :
		int Size;
        int capacite;
		int  *Tas; 
		int getParent(int i);
		int getLC(int i);
		int getRC(int i);
		
	public :
		int size()
		{
			return Size;
		}
		TasMin(int capacite)
		{
			this->Size=0;
			this->capacite=capacite;
			this->Tas=new int[capacite];
		}
		bool isEmpty();
		void afficher();
		int extraireMin();
		void entasserMin(int );
		void diminuerCle(int , int );
		int getMin();
		void inserer(int);
        void supprimer(int );

};

int TasMin :: getParent(int i){
	if(i==0) return -1;
	
	return (i-1)/2 ;
}

int TasMin :: getLC(int i){
	if(2*i+1 > size()-1 )  return -1;
	return 2*i+1;
}

int TasMin :: getRC(int i){
	if(2*i+2 > size()-1 )  return -1;
	return 2*i+2;
}

bool TasMin ::  isEmpty(){
	return size() == 0;
		
}


int TasMin::extraireMin()
{
	if (size() <= 0)
	{
		return INT_MAX;
	}
	if (size() == 1)
	{
		Size--;
		return Tas[0];
	}
	int racine = Tas[0];
	Tas[0] = Tas[Size - 1];
	Size--;
	entasserMin(0);
	return racine;
}
void TasMin::entasserMin(int i)
{													
	int d = getRC(i);	
	int g = getLC(i); 
	int pp = i;
	if (d < Size && Tas[d] < Tas[i])
	{
		pp = d;
	}
	if (g < Size && Tas[g] < Tas[pp])
	{
		pp = g;
	}
	if (pp != i)
	{
		int ch=Tas[i];
		Tas[i]=Tas[pp];
		Tas[pp]=ch;
		entasserMin(pp);
	}
}
void TasMin::diminuerCle(int i, int new_i)
{ 
	Tas[i] = new_i;
	while (i != 0 && Tas[getParent(i)] > Tas[i])
	{
		int ch=Tas[i];
		Tas[i]=Tas[getParent(i)];
		Tas[getParent(i)]=ch;
		i = getParent(i);
	}
}
int TasMin::getMin()
{
	return Tas[0];
}
void TasMin::inserer(int cle)
{
	if (Size == capacite)
	{
		cout << " Vous povez pas inserer " << endl;
		return;
	}
	Size++;
	int i = Size - 1;
	Tas[i] = cle;
	while (i != 0 && Tas[getParent(i)] > Tas[i])
	{
		swap(Tas[i], Tas[getParent(i)]);
		i = getParent(i);
	}
}
void TasMin::supprimer(int i)
{
	diminuerCle(i, INT_MIN);
	extraireMin();
}
void TasMin::afficher()
{
	for (int i = 0; i < Size - 1; i++)
	{
		cout << Tas[i] << " ";
	}
}
main(){
	TasMin tas(4);
	tas.inserer(3);
	tas.inserer(12);
	tas.inserer(7);
	tas.inserer(2);
	tas.inserer(1);
	tas.afficher();
}
