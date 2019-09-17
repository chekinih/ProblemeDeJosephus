#include<stdio.h>
#include<stdlib.h>
typedef struct liste 
{
	int info;

	struct liste *svt;
	
}liste ;

liste *creerliste(int n) /* creation de la liste dans l'ordre croissant */
{
	liste *tete, *p, *pr;
	int i;
	tete=NULL;
	tete=(liste*) malloc(sizeof(liste));
	if(tete==NULL)
	{
		return (tete);/* si l'allocation n'a pas était faite, on retourne tete qui pointé vers NULL*/
	}
	(*tete).info=1; /*creer d'abord le premier element */
	(*tete).svt=tete;
	pr=tete;
	for(i=1; i<n; i++) /* creer les autres elements */
	{
		p=(liste*) malloc(sizeof(liste));
		if(p==NULL)
		{
			return (NULL);
		}
		(*p).info=i+1;
		(*p).svt=tete;
		(*pr).svt=p;
		pr=p;
	}
	return (tete);
}
int main()
{
	liste *tete, *p, *pr;
	int n, m, i;
	printf("veuillez introduire le nombre de prisonniers\n");
	scanf("%d", &n);
	printf("veuillez introduire le nombre de sauts\n");
	scanf("%d", &m);
	tete=creerliste(n);
	printf(" voila les numeros des prisonniers\n ");
	p=tete;
	for (i=0;i<n;i++)
	{
		printf("%d\t", (*p).info);
		p=(*p).svt;
	}
	
	p=tete;
	if(m==1)  /*dans le cas ou le nombre de sauts que l'utilisateur a rentré est 1 */
	{
		while((*p).svt != tete)
		{
			printf("voila le prisonnier elimine %d\n", (*p).info);
			p=(*p).svt;
		}
		printf("voila le dernier survivant %d \n", (*p).info);	/*le dernier survivant est le dernier numéro*/
	}
else 
{
	p=tete;
	while((*p).svt!=p)
	{
		i=0;
		while(i<(m-1))
		{
			pr=p;
			p=(*p).svt;
			i=i+1;
		}
		printf("\n le prisonnier elimine est  %d\n", (*p).info);
		p=(*p).svt;
		(*pr).svt=p;
	}
	
	printf("voila le dernier survivant %d\n", (*p).info);
}
	system ("pause");
	return 0;
}
	
		
		
	
	
	

	

	

