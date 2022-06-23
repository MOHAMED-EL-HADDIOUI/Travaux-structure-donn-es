#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//--------------------------------------------------------------------------------------------------
typedef struct Noeud_t Noeud_t;
struct Noeud_t{
	int coff;
	int degre;
	Noeud_t *next;
};
typedef struct Liste_t Liste_t;
struct Liste_t{
	Noeud_t *tete,*queue;
	int longueur;
	int degre;
};
//--------------------------------------------------------------------------------------------------
Liste_t Creer(); //Creation d'une liste a l'etat vide
Liste_t Inserer(Liste_t,Noeud_t); //Insertion en tete de la liste
void Afficher(Liste_t);
Liste_t Add(Liste_t,Liste_t); //la somme de deux polynomes
Liste_t Produit(Liste_t,Liste_t); //la somme de deux polynomes
Liste_t Derive(Liste_t); //la derive d'une polynome
Liste_t Primitive(Liste_t); //la primitive d'une polynome
//--------------------------------------------------------------------------------------------------
//----------------------------------------Creation--------------------------------------------------
Liste_t Creer(){
	Liste_t t;
	t.longueur=0;
	t.tete=NULL;
	t.queue=NULL;
	t.degre=0;
	return t;
}
//--------------------------------------------------------------------------------------------------
//----------------------------------------Inserer --------------------------------------------------
Liste_t Inserer(Liste_t liste,float coeff,int degre)
{
	Noeud_t *p=(Noeud_t *)malloc(sizeof(Noeud_t));
	p->coff=coeff;
	p->degre=degre;
	if(liste==NULL){
		liste.tete=p;
		liste.queue=p;
		liste.longueur=1;
        liste.degre=degre;
	} 
    else{
    	Noeud_t *m=liste.tete;
    	if (m.degre>degre)
    	{
    		p->next=m;
    		liste->tete=p;
    		liste.longueur++;
            liste.degre=degre;
		}
		else{
	      	while(m->next.degre>=degre)
            	{
            		if(m->next.degre==degre)
            		{
            		   m->next.coff+=coff;
					}
					else{
						p->next=m->next;
						m->next=p;
						liste.longueur++;
					}
					if(m->next==NULL)
					{
						p->next=
					}
            		
	        	}
		}
    	
	}
	
}
//--------------------------------------------------------------------------------------------------




