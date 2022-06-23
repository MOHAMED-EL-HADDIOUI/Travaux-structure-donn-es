#include <iostream>
#include <string.h>
using namespace std;
class Personne 
{
	private:
       int Mr;
	   string nom;
	   int age;	
	   int priorite;
	public :
		Personne *next;
		Personne(int MR,string nom,int age,int priorite);
		void afficher();
		int getPriorite()
		{
			return this->priorite;
		}
		Personne(Personne *P)
		{
			this->age=P->age;
	        this->Mr=P->Mr;
	        this->nom=P->nom;
	        this->priorite=P->priorite;
	        this->next=P->next;		
		}
		~Personne()
		{
			delete this->next;
		}
};
class file_priority {
	private:
	    int nombre;
	public :
		Personne *premier;
	    Personne *dernier;
		file_priority(Personne);
		void Afficher();
		void push(Personne);
		void pop();
		Personne top();
		bool isEmpty()
		{
			return this->premier==NULL;
		}
		int size()
		{
			return this->nombre;
		}
		~file_priority()
		{
			while(this->premier!=NULL)
			{
				Personne *tmp=this->premier->next;
				delete this->premier;
				this->premier=tmp;
			}
		}
};
Personne::Personne(int MR,string nom,int age,int priorite)
{
	this->age=age;
	this->Mr=MR;
	this->nom=nom;
	this->priorite=priorite;
	this->next=NULL;
}
void Personne::afficher()
{
	cout <<"-------------Afficher les informations---------------------\n";
	cout <<"Priorite : "<<priorite<<"\n";
	cout <<"Nom : "<<nom<<"\n";
	cout <<"Mr : "<<Mr<<"\n";
	cout <<"Age : "<<age<<"\n";
	cout <<"-----------------------------------------------------------\n";
}
file_priority::file_priority(Personne P)
{
	this->premier=this->dernier=new Personne(P);
	this->nombre=1;
}
void file_priority::push(Personne P)
{
	if(this->premier==NULL)
	{
		this->premier=this->dernier=&P;
		return;
	}
	else
	{
		P.next=this->premier;
		this->premier=&P;
		this->nombre++;	
	}
}
void file_priority::Afficher()
{
   Personne *tmp=this->premier;
   while(tmp!=NULL)
   {
   	tmp->afficher();
   	tmp=tmp->next;
   }
}
void file_priority::pop()
{
	Personne *tmp=this->premier,*tm=this->premier;
	int priority=this->premier->getPriorite();
	while(tmp->next!=NULL)
	{
		if(priority<=tmp->next->getPriorite())
		{
			priority=tmp->next->getPriorite();
			tm=tmp;
		}
		tmp=tmp->next;
	}	
	Personne *suiv1=tm->next;
	tm->next=suiv1->next;
	delete suiv1;
	this->nombre--;
}
Personne file_priority::top()
{
	Personne *tmp=this->premier,*tm=this->premier; 
	int priority=tmp->getPriorite();
	while(tmp->next!=NULL)
	{
		if(priority<=tmp->next->getPriorite())
		{
			tm=tmp;
		}
		tmp=tmp->next;
	}	
	return	*(tm->next);
}
main()
{
	Personne P1(1,"MOHAMED EL HADDIOUI",22,12);
	Personne P2(2,"AHMED EL QNZQR",43,1);
	Personne P3(3,"SAID EL YOUSFI",43,9);
	Personne P4(4,"MOSTAPHA EL OUDIR",43,4);
	Personne P5(5,"NAJIB EL SAWSAM",43,10);
	Personne P6(6,"farah EL ahnadi",43,7);
	Personne P7(7,"wqssim EL hs",43,3);
	file_priority L(P1);
	L.push(P2);L.push(P3);L.push(P4);L.push(P5);L.push(P6);L.push(P7);
	L.Afficher();
	cout<<"le size de file est "<<L.size();
	cout<<"\n apres suppression  \n";
	L.pop();
	L.Afficher();
    cout<<"\nle size de file est "<<L.size();
    cout<<"\n sommet de file d'attente prioritaire  \n";
	L.top().afficher(); 
	L.pop();
	L.pop();
	L.pop();
	L.pop();
	L.pop();
	L.pop();
	cout<<"la file est :"<<L.isEmpty();
	   
}





