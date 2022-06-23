#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Personne Personne;
struct Personne {
       int Mr;
	   char nom[100];
	   int age;	
	   Personne *next;
};
typedef struct liste liste;
struct liste{
	Personne *premier;
	Personne *dernier;
	int nombre;
};
Personne *CreationPersonne(int MR,char nom[],int age)
{
	Personne *nv;
	nv=(Personne *)malloc(sizeof(Personne));
	nv->age=age;
	nv->Mr=MR;
	strcpy(nv->nom,nom);
	nv->next=NULL;
	return nv;
}
void afficher(Personne *P)
{
	printf("-------------Afficher les informations---------------------\n");
	printf("Nom : %s\n",P->nom);
	printf("Mr : %d\n",P->Mr);
	printf("Age : %d\n",P->age);
	printf("-----------------------------------------------------------\n");
}
liste *CreationListe(int MR,char nom[],int age)
{
	liste *nv=(liste *)malloc(sizeof(liste));
	nv->premier=nv->dernier=CreationPersonne(MR,nom,age);
	nv->nombre=1;
	return nv;	
}
void Inserer_debut(liste *L,int MR,char nom[],int age)
{
	Personne *nv=CreationPersonne(MR,nom,age);
	nv->next=L->premier;
	L->premier=nv;
	L->nombre++;
}
void Inserer_fin(liste *L,int MR,char nom[],int age)
{
	Personne *nv=CreationPersonne(MR,nom,age);
	L->dernier->next=nv;
	L->dernier=nv;
	L->nombre++;
}
void Inserer_milieu(liste *L,int MR,char nom[],int age)
{
	Personne *tmp,*tm;
	tmp=tm=L->premier;
	if(MR<=tmp->Mr)
	{
		Inserer_debut(L,MR,nom,age);
	}
	else
	{
	  Personne *nv=CreationPersonne(MR,nom,age);
	 while(tmp!=NULL)
	   {
	   	if(MR>tmp->Mr)
	   	{
	   		tm=tmp;
	   		tmp=tmp->next;
		}
		else
		{
			break;
		}
       }
	if(tm->next!=NULL)
	{
		nv->next=tm->next;
	    tm->next=nv;
	    L->nombre++;
			
	}
	else
	{
	    Inserer_fin(L,MR,nom,age);
	}
		
	}
}
void Afficher_Liste(liste *L)
{
   Personne *tmp=L->premier;
   while(tmp!=NULL)
   {
   	afficher(tmp);
   	tmp=tmp->next;
   }
}
int Rechercher(Personne *p,int mr)
{
	if(p!=NULL)
	{
		if(p->Mr==mr)
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
void Modifier(liste *L,int MR,char nom[],int age)
{
	if(Rechercher(L->premier,MR)==1)
	{
		Personne *t=L->premier;
		while(t!=NULL)
		{
			if(t->Mr==MR)
			{
				t->age=age;
	            strcpy(t->nom,nom);break;
			}
			t=t->next;
		}
	}
	else
	{
		Inserer_milieu(L,MR,nom,age);
	}
}
void Supprimer_debut(liste *L)
{
	if(L->premier!=NULL)
	{
		Personne *p=L->premier;
		L->premier=p->next;
		free(p);
		L->nombre--;
	}	
}
void Supprimer_Fin(liste *L)
{
	if(L->premier->next==NULL)
	{
	   L->premier=L->dernier=NULL;
	}
	else
	{
		Personne *p=L->premier;
		while(p->next!=L->dernier)
		{
			p=p->next;
		}
		L->dernier=p;
		L->dernier->next=NULL;
		free(p);
	}
	L->nombre--;	
}

void Supprimer(liste *L,int MR)
{
	if(Rechercher(L->premier,MR)==1)
	{
		if(MR!=L->premier->Mr)
		{
		    Personne *P=L->premier;
		while(P->next->Mr!=MR)
			P=P->next;
		Personne *tmp=P->next;
		P->next=tmp->next;
		free(tmp);
	    }
	    else{
	    	Supprimer_debut(L);
		}
		L->nombre--;
	}
	else
	{
		printf("Erreur _____________________\n");
	}
}
int main()
{
	liste *L=CreationListe(2,"MOHAMED EL HADDIOUI",22);
	Inserer_debut(L,1,"AYMAN EL MASSODI",33);
	Inserer_fin(L,3,"SAID EL NASIR",23);
	printf("-----------------------------------------\n");
	Inserer_milieu(L,4,"ANWAR EL HAS",15);
	Afficher_Liste(L);
	printf("le nombre total est %d\n",L->nombre);
	Supprimer_debut(L);
	Supprimer_Fin(L);
	Supprimer(L,3);
	printf("-----------------------\n");
	Afficher_Liste(L);
}




