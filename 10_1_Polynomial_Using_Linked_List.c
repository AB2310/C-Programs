#include<stdio.h>
#include<malloc.h>
struct node{
	int coe;
	int exp;
	struct node *next;
};
typedef struct node poly;


void insert(poly **poly1, int exp, int coe)
{
    poly *t,*temp;
    int a;
    temp = (poly *)malloc(sizeof(poly));
    if(*poly1 == NULL)
    {

        temp->exp = exp;
        temp->coe = coe;
        temp->next = NULL;
        *poly1 = temp;
    }
    else
    {
        t = *poly1;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = (poly *)malloc(sizeof(poly));
        t->next->exp = exp;
        t->next->coe = coe;
        t->next->next = NULL;
    }
}

void readPoly(poly **poly)
{
	int n,i=0,coe;
	printf("Enter the degree of the polymonial : ");
	scanf("%d",&n);
	while(n>=0)
	{
		printf("Enter the coefficient of %d : ",n);
		scanf("%d",&coe);
		if(coe != 0)
		{
			insert(poly,n,coe);
			i++;
		}
		n--;
	}
}

simplify(poly *p)
{
	poly*i,*j,*t;
	int temp,coesum;
	for(i=p; i->next != NULL ; i=i->next)
	{
		for(j=i->next; j!= NULL; j=j->next)
		{
			if(i->exp < j->exp)
			{
				temp = i->coe;
				i->coe = j->coe;
				j->coe = temp;
				temp = i->exp;
				i->exp = j->exp;
				j->exp = temp;
			}
		}
	}
	for(i=p;i!=NULL;i=j)
	{
		coesum = 0;
		
		for(j=i;(j!=NULL && j->exp == i->exp); j=j->next)
		{
			printf("%d ",i->exp);
			coesum = coesum + j->coe;
		}
		t = p;
		p->coe = coesum;
		p->exp = i->exp;
		p=p->next;
	}
	t->next = NULL;
//	p->next = NULL;
}


addpoly(poly *p1, poly *p2, poly **psum)
{
	poly *t,*i,*j;
	
	
	for(i=p1,j=p2; i!=NULL && j!=NULL; )
	{
		if(*psum == NULL)
		{
			t = (poly *)malloc(sizeof(poly));
			*psum = t;
		}
		else
		{
			t -> next = (poly *)malloc(sizeof(poly));
			t = t->next;
		}
		if(i->exp == j->exp)
		{
			t->exp = i->exp;
			t->coe = i->coe + j->coe;
			i=i->next;
			j=j->next;
		}
		else if (i->exp < j->exp)
		{
			t->exp = j->exp;
			t->coe = j->coe;
			j=j->next;
		}
		else
		{
			t->exp = i->exp;
			t->coe = i->coe;
			i=i->next;
		}
	}
	
	
	if(i!=NULL)
	{
		while(i!=NULL)
		{
			t->next = (poly *)malloc(sizeof(poly));
			t=t->next;
			t->coe = i->coe;
			t->exp = i->exp;
			i=i->next;
		}
	}
	if(j!=NULL)
	{
		while(j!=NULL)
		{
			t->next = (poly *)malloc(sizeof(poly));
			t=t->next;
			t->coe = j->coe;
			t->exp = j->exp;
			j=j->next;
		}
	}
	t->next = NULL;
}

prodpoly(poly *p1, poly *p2, poly **pprod)
{
	poly *i,*j,*t,*temp;
	for(i=p1;i!=NULL;i=i->next)
    {
    	for(j=p2;j!=NULL;j=j->next)
    	{
    		    		
    		temp = (poly *)malloc(sizeof(poly));
    		if(*pprod == NULL)
    		{
    			*pprod = t = temp;
			}
			else
			{
				t->next = temp;
				t=t->next;
			}
    		t->coe = i->coe * j->coe;
    		t->exp = i->exp + j->exp;
		}
		
	}
	t->next = NULL;
	simplify(*pprod);
}



displayPoly(poly *poly1)
{
	poly *t=poly1->next;
	(poly1->exp == 0) ? printf(" %d",poly1->coe) : printf(" %dx^%d",poly1->coe,poly1->exp);
	while(t!=NULL)
	{
		(t->exp == 0) ? printf(" + %d",t->coe) : printf(" + %dx^%d",t->coe,t->exp);
		t=t->next;
	} 
}

void main()
{
	poly *p1=NULL;
	poly *p2=NULL;
	poly *psum = NULL;
	poly *pprod = NULL;
	printf("Polymonial 1\n");
	readPoly(&p1);
	printf("Polymonial 2\n");
	readPoly(&p2);
	printf("\nPolymonial 1 is : \n");
	displayPoly(p1);
	printf("\nPolymonial 2 is : \n");
	displayPoly(p2);
	addpoly(p1,p2,&psum);
	printf("\nSum Polynomial is : \n");
	displayPoly(psum);
	prodpoly(p1,p2,&pprod);
	printf("\nProduct Polynomial is : \n");
	displayPoly(pprod);
}
