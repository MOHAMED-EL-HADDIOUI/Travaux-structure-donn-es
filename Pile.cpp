#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;
class Personne {
	   public :
       int Mr;
	   string nom;
	   int age;	
	   Personne *next;
	   Personne(int MR,string nom,int age)
	   {
	    this->age=age;
	    this->Mr=MR;
	    this->nom=nom;
	    this->next=NULL;
	   }
	   void afficher();

};
void Personne::afficher()
       {
    	cout<<"-------------Afficher les informations---------------------\n";
    	cout<<"Nom : "<<nom<<"\n";
	    cout<<"Mr : "<<Mr<<"\n";
	    cout<<"Age : "<<age<<"\n";
	    cout<<"-----------------------------------------------------------\n";
        }
class pile{
	public :
	Personne *premier;
	Personne *dernier;
	int nombre;
	pile(Personne *P)
	{
		premier=P;
		dernier=P;
	    nombre=1;
	}
	void push(Personne *);
    void Afficher_pile();
    void pop();
    int size();
    bool isEmpty();
    Personne top();

};
Personne pile::top()
{
	if(premier==NULL)
	{
	    cout<<"Erreur.....\n";
	}
	else
	   return *premier;
}
bool pile::isEmpty()
{
	if(premier==NULL)
	    return true;
	return false;
}
int pile::size()
{
	return nombre;
}
void pile::push(Personne *P)
{
	   P->next=premier;
	   premier=P;
	   nombre++;
}
void pile::Afficher_pile()
{ 
    Personne *tmp=premier;
    while(tmp!=NULL)
    {
   	  tmp->afficher();
   	  tmp=tmp->next;
    }
}
int Rechercher(Personne *p,int mr)
{
	if(p!=NULL)
	{		if(p->Mr==mr)
	{
		return 1;
	}
	else
	{
	   return Rechercher(p->next,mr);
	}
		
	}
	return 0;
}
void pile::pop()
{
	if(premier!=NULL)
	{
		Personne *p=premier;
		premier=p->next;
		delete p;
		nombre--;
	}	
}


int main()
{
	string Nom="MOHAMED EL HADDIOUI";
	Personne p1=Personne(1,Nom,22);
	Nom="AYMAN EL MASSODI";
	Personne p2=Personne(2,Nom,33);
	Nom="SAID EL NASIR";
	Personne p3=Personne(3,Nom,23);
	Nom="ANWAR EL HAS";
	Personne p4=Personne(4,Nom,15);
	pile L=pile(&p1);
    L.push(&p2);
	L.push(&p3);
	L.push(&p4);
	L.Afficher_pile();
	cout<<"le nombre total est "<<L.size();
	L.pop();
	L.pop();
	L.pop();
	printf("-----------------------\n");
	L.Afficher_pile();	
	cout<<"le nombre total est "<<L.size();
}




