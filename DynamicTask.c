#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};

void main()
{
	struct node *head = NULL;
	struct noed *temp;
	int **ArrayAddresses;
	int *p = (int *)malloc(sizeof(int));
	
	ArrayAddresses = (int **)malloc(sizeof(int *)*10);
	ArrayAddresses = &p;
	printf("Enter the numbers\n");
	int size=0,i,j,ch;
	do
	{
		printf("Enter a number : ");
		p = (int *) realloc(p, (size+1) *sizeof(int));
		scanf("%d",(p+size));
		size++;
		printf("\nDo you want to continue? (1.yes)  : ");
		scanf("%d",&ch);
	}
	while(ch==1);
	
	printf("\n");

	printf("Size %d",size);
	
  	for(i=2;i<size;i++)
	{
//		ArrayAddresses = (int **) realloc(ArrayAddresses, sizeof(int *) * (i+1));
		int *pn = (int *) malloc(sizeof(int));
		ArrayAddresses[i] = pn;
	}
	printf("Here");
		
	for(j=0; j<size ; j++)
	{
		printf("%d\t",*(*(ArrayAddresses) + j));
	}
	printf("\n\n");
		
		
		
//	int k=1;
//	int tsize= size;
//	start:
//	for(i=0,j=i+1; i<tsize-1; i++,j++)
//	{
//		*(*(ArrayAddresses + k) + i) = *(p + i)  + *(p+j);
//	}
//	tsize--;
//	k++;
//	if(tsize==1)
//	goto start;
	
	
	
		
//	for(i=0;i<size;i++)
//	{
//		int tsize = size-1;
//		for(j=0; j<tsize ; j++)
//		{
//			printf("%d\t",*(*(ArrayAddresses + i) + j));
//		}
//		printf("\n");
//	}

}
