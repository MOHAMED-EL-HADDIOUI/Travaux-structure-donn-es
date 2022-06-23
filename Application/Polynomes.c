#include <stdio.h>
#include <stdlib.h>
#include "Polynomes.h"
//--------------------------------------------------------------------------------------------------
//----------------------------------- Construction d'une liste vide---------------------------------
void Crealiste(Liste_t *l)
{
	l->tete=l->queue=NULL;
	l->longueur=0;
}
//--------------------------------------------------------------------------------------------------
Liste_t Creavide()
{
	Liste_t l={NULL,NULL,0};
	return l;
}
//--------------------------------------------------------------------------------------------------
Noeud_t *Creation(int degre,double coeff)
{
	Noeud_t *m=(Noeud_t *)malloc(sizeof(Noeud_t));
	m->coff=coeff;
	m->degre=degre;
	m->next=NULL;
	return m;
}
//--------------------------------------------------------------------------------------------------
//---------------------------------------------Insertion Monome-------------------------------------
void InsererMonome(int degre ,double coeff,Liste_t *l)
{
	Noeud_t *m=Creation(degre,coeff);
	if(l->tete==NULL)
	{
		l->tete=m;
		l->queue=m;
		l->longueur=1;
	}
	else if(degre<=l->tete->degre)
		{
			m->next=l->tete;
			l->tete=m;
			l->longueur++;
		}
	else{
		Noeud_t *tmp=l->tete;
		while(tmp->next!=NULL&& tmp->next->degre<degre)
			tmp=tmp->next;
		m->next=tmp->next;
		if(tmp->next==NULL) l->queue=m;
		tmp->next=m;
		l->longueur++;
	}
}
//--------------------------------------------------------------------------------------------------
//---------------------------------------------Afficher Polynome------------------------------------
void Afficher(Liste_t l)
{
	Noeud_t *tmp=l.tete;
	printf("P(x)=");
	while(tmp!=NULL)
	{
		if(tmp->next!=NULL){
			printf("%lfX^(%d)",tmp->coff,tmp->degre);
			if(tmp->next->coff>=0)
			{
				printf("+");
			}
		}
		else{
			printf("%lfX^(%d).\n",tmp->coff,tmp->degre);
		}
		
		tmp=tmp->next;
	}
	
}
//--------------------------------------------------------------------------------------------------
//---------------------------------------------Reduire Polynome-------------------------------------
void Reduire(Liste_t *t)
{
	Noeud_t *p,*pp,*q;
	if(t->longueur>2)
	{
		pp=NULL;
		p=t->tete;
		while(p->next!=NULL)
		{
			q=p->next;
			pp=p->next;
			while(q->next!=NULL)
		    {
		      if(p->degre==q->degre)
		      {
		      	p->coff+=q->coff;
		      	if(p->next==q){
		      		p->next=q->next;
		      		free(q);
		      		t->longueur--;
		      		
				  }
				  else{
				  	pp->next=q->next;
				  	free(q);
				  	t->longueur--;
				  }
			  }
			  pp=q;
			  q=q->next;	
			}
			p=p->next;
		}
	}
}
//--------------------------------------------------------------------------------------------------
//---------------------------------------------Eliminer Polynome------------------------------------
void Eliminer(Liste_t *t){
	Noeud_t *tmp,*tmp1,*tmp2;
	tmp1=t->tete;
	if(tmp1->coff==0)
	{
	   t->tete=tmp1->next;
	   t->longueur--;
	   free(tmp1);
	}
	else{
		
		tmp=t->tete;
		tmp2=t->tete;
     	while(tmp!=NULL)
    	{
    		if(tmp->coff==0)
    		{
    			Noeud_t *tj=tmp;
    			tmp2->next=tmp->next;
    			free(tj);
    			t->longueur--;
			}
			tmp2=tmp;
	    	tmp=tmp->next;
    	}
	}
	
}
//--------------------------------------------------------------------------------------------------
//---------------------------------------------ADD Polynome-----------------------------------------
Liste_t ADD(Liste_t liste1,Liste_t liste2)
{
	Liste_t liste;
	Noeud_t *p1,*q1;
	p1=liste1.tete;
	q1=liste2.tete;
	Crealiste(&liste);
	while(p1!=NULL||q1!=NULL)
	{
		if(p1!=NULL)
		{
			InsererMonome(p1->degre,p1->coff,&liste);
		}
	   	if(q1!=NULL)
		{
			InsererMonome(q1->degre,q1->coff,&liste);
		}
		q1=q1->next;
		p1=p1->next;
	}
	return liste;
}
/*
{
	Liste_t liste;
	Noeud_t *p1,*q1;
	p1=liste1.tete;
	q1=liste2.tete;
	if(p1->degre>=q1->degre)
	{
		liste=liste2;
		liste.longueur+=liste1.longueur;
	}
	else{
		liste=liste1;
		liste.longueur+=liste2.longueur;
	}
	if(liste1.queue->degre>liste2.queue->degre)
	{
		liste.queue=liste1.queue;
	}
	else{
		liste.queue=liste2.queue;
	}
	while(p1!=NULL&&q1!=NULL)
	{
		if(p1->degre<=q1->degre)
		{
			Noeud_t *pp1=p1->next,*qq1=q1->next;
			p1->next=q1;
			q1->next=pp1;
			p1=p1->next;
			q1=qq1;
		}
		p1=p1->next;
	}
	return liste;
}*/
//--------------------------------------------------------------------------------------------------
//---------------------------------------------Product Polynome------------------------------------
Liste_t Product(Liste_t liste1,Liste_t liste2)
{
	Liste_t liste;
	Noeud_t *p1,*q1;
	p1=liste1.tete;
	Crealiste(&liste);
	while(p1!=NULL)
	{
	   q1=liste2.tete;
		while(q1!=NULL)
	   {
	   	InsererMonome(p1->degre+q1->degre,p1->coff*q1->coff,&liste);
		q1=q1->next;
       }
		p1=p1->next;
	}
	return liste;
}
//--------------------------------------------------------------------------------------------------
//---------------------------------------------Derive Polynome--------------------------------------
Liste_t Derive(Liste_t liste1)
{
	Liste_t liste;
	Noeud_t *p1;
	p1=liste1.tete;
	Crealiste(&liste);
	while(p1!=NULL)
	{
	   	InsererMonome(p1->degre-1,p1->coff*p1->degre,&liste);
		p1=p1->next;
	}
	return liste;
}
//--------------------------------------------------------------------------------------------------
//---------------------------------------------Primitive Polynome-----------------------------------
Liste_t Primitive(Liste_t liste1)
{
	Liste_t liste;
	Noeud_t *p1;
	p1=liste1.tete;
	Crealiste(&liste);
	while(p1!=NULL)
	{
		double w=(double)(p1->coff)/(p1->degre+1);
		printf("\n-------%lf ------------------\n",w);
	   	InsererMonome(p1->degre+1,w,&liste);
		p1=p1->next;
	}
	return liste;
}
//--------------------------------------------------------------------------------------------------
//-----------------------------------------------Saisir Polynome------------------------------------
void Saisir(Liste_t *polynome)
{
	int nb1;
    printf("|        Entrez svp le nombre des monomes          |\n");
    scanf("%d",&nb1);
    int i;
    for(i=0;i<nb1;i++)
    {
    printf("|                monome : %d                       |\n",i+1);
    int degre;
    double coff;
    printf("|          Entrez le coefficient de monome         |\n");
    scanf("%lf",&coff);
    printf("|             Entrez le degre de monome            |\n");
    scanf("%d",&degre);
    InsererMonome(degre,coff,polynome);
	}
}
//--------------------------------------------------------------------------------------------------

