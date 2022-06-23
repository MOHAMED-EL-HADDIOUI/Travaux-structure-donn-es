#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tnoeud tnoeud;
struct tnoeud {
       int data;
	   tnoeud *gauche;
	   tnoeud *droite;
};
int taille(tnoeud *racine){
	if(racine == NULL) return 0;
	else return 1+taille(racine->gauche)+taille(racine->droite);
}
int feuille(tnoeud *noeud){
    return  !noeud->gauche && !noeud->droite;
}
int nbfeuille(tnoeud *racine){
	if(racine == NULL) return 0 ;
	if(feuille(racine) )return 1 ;
	return   nbfeuille(racine->gauche) 
	           + nbfeuille(racine->droite);
}
int nondegener(tnoeud *racine){
	if(racine == NULL) 
	    return 0;
	if((racine->gauche != NULL ) && (racine->droite != NULL))
		return 1;
	if(racine->gauche == NULL)  
		return nondegener(racine->droite);
	return nondegener(racine->gauche);
}
int rechAssoc(tnoeud *racine ,int val){
	if(racine == NULL) return 0 ;
	if (racine->data == val ) return 1;
	if (rechAssoc(racine->gauche ,val)) return 1;
	return rechAssoc(racine->droite,val);
}
void prefixe(tnoeud *racine)
{
	printf("%d\t",racine->data);
	prefixe(racine->gauche);
	prefixe(racine->droite);
}
void infixe(tnoeud *racine)
{
	infixe(racine->gauche);
	printf("%d\t",racine->data);
	infixe(racine->droite);
}
void postfixe(tnoeud *racine)
{
	postfixe(racine->gauche);
	postfixe(racine->droite);
	printf("%d\n",racine->data);
}


void insertion(tnoeud **racine , int val)
{
	if(*racine == NULL) creeFeuille( racine,val);
	else
		if( val >=(*racine)->data)
			insertion(&((*racine)->droite ),val);
		else 
			insertion(&((*racine)->gauche) , val) ;
}
void creeFeuille(tnoeud **feuille ,int val )
{
	*feuille=(tnoeud *)malloc(sizeof(tnoeud));
	(*feuille)->data =val;
	(*feuille)->gauche=NULL;
	(*feuille)->droite=NULL;
}
int rechDichoAssoc(tnoeud *racine  ,int val)
{
	if(racine == NULL)
		return 0;
	if (racine->data ==val )
		return 1;
	if (racine->data < val ) 
		return rechDichoAssoc(racine->droite ,val) ;
	return rechDichoAssoc(racine->gauche,val) ;
}






int main()
{
	tnoeud *racine=(tnoeud *)malloc(sizeof(tnoeud));
	racine->data=1;
	racine->droite=racine->gauche=NULL;
	printf("%d",rechAssoc(racine,1));
}
