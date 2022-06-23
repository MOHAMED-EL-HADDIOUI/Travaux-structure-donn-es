#include<iostream>
#include<string>
using namespace std;
class Tas_Max{ 
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
		Tas_Max(int capacite)
		{
			this->Size=0;
			this->capacite=capacite;
			this->Tas=new int[capacite];
		}
		bool isEmpty();
		void insererElem(int Elem);
		void shiftUp(int i); // Pour l'ajout
		void supprimerElem();
		void shiftDown(int i); // Pour la suppression
		void afficher();
		void pop_back()
		{
			int *Ts=new int[capacite];
			for(int i=0;i<size()-1;i++)
			{
				Ts[i]=Tas[i];
			}
		    delete Tas;
		    Tas=Ts;
		    Size--;
		}
		
};

int Tas_Max :: getParent(int i){
	if(i==0) return -1;
	
	return (i-1)/2 ;
}

int Tas_Max :: getLC(int i){
	if(2*i+1 > size()-1 )  return -1;
	return 2*i+1;
}

int Tas_Max :: getRC(int i){
	if(2*i+2 > size()-1 )  return -1;
	return 2*i+2;
}

bool Tas_Max ::  isEmpty(){
	return size() == 0;
}
void Tas_Max :: shiftUp(int i){
	if(i==0) return;
	
	if( Tas[i] > Tas[ getParent(i)]){
		    int ch=Tas[i];
		    Tas[i]=Tas[getParent(i)];
		    Tas[getParent(i)]=ch;
			shiftUp( getParent(i) );		
	}		
}


void Tas_Max :: insererElem(int Elem){
	Tas[size()]=Elem;
	Size++;
	shiftUp(size()-1);
}

void Tas_Max :: shiftDown(int i){
    if( i >= size()-1 ) return;
    
    if( getLC(i) == -1) return;
	if(Tas[i] < Tas[getLC(i)]){
    
		if( Tas[getLC(i)] > Tas[getRC(i)]){
    		int ch=Tas[i];
		    Tas[i]=Tas[getLC(i)];
		    Tas[getLC(i)]=ch;
    		shiftDown( getLC(i) );
		}
		else {
			int ch=Tas[i];
		    Tas[i]=Tas[getRC(i)];
		    Tas[getRC(i)]=ch;
			shiftDown( getRC(i) );
		} 	

	}
	else return;
}
void Tas_Max :: supprimerElem(){
	if(isEmpty()) return;
	int ch=Tas[0];
	Tas[0]=Tas[size()-1];
	Tas[size()-1]=ch;
	pop_back();
	shiftDown(0);
}

void Tas_Max ::  afficher(){
	for(int i=0; i< size(); i++)
		cout <<" "<< Tas[i] <<" ";
}
int main(){
	Tas_Max T(30);
	
	T.insererElem(100);
	T.insererElem(75);
	T.insererElem(95);
	T.insererElem(60);
	T.insererElem(65);
	T.insererElem(90);
	T.insererElem(9);
	T.insererElem(8);
	T.insererElem(6);
	T.insererElem(555);
	T.insererElem(55);
	
	T.afficher();
	cout << "\n";
	
	T.insererElem(98);
	T.afficher();
	
		cout << "\n";
	T.insererElem(200);
	T.afficher();
	
	cout << "\n";
	T.insererElem(2);
	T.afficher();
	
	cout << "\n";
	T.insererElem(150);
	T.afficher();
	
	cout << "\n";
	T.supprimerElem();
	T.afficher();
	
	return 0;
}
