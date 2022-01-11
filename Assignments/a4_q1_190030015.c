// client code
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *ptr_list)
	{
		// Fill this function
		ptr_list->head=NULL;
	}

void insert(list_t *ptr_list, int coeff, int expo)
	{
		// Fill this function
		node_t* temp;
		temp=(node_t*)malloc(sizeof(node_t));
		temp->coeff=coeff;
		temp->expo=expo;
		if(ptr_list->head == NULL)
		{
			ptr_list->head = temp;
			temp->link = NULL;
		}
		else
		{
			node_t* prev = NULL ;
			node_t* pres = ptr_list->head;
			// beginning; head has to change
			if(prev == NULL)
			{
				ptr_list->head = temp;
				temp->link = pres;
			}
			else // middle or end
			{
				prev->link = temp;
				temp->link = pres;
			}	
		}

	}

	int eval(const list_t *ptr_list)
		{
			// Fill this function.
			node_t* temp=ptr_list->head;
			
			int x; 
			scanf("%d", &x); // This input x should be used to evaluate the polynomial
			int val=0;
			while(temp!=NULL)
			{
				int term=(temp->coeff);
				int y=(temp->expo);
				while(y>0)
				{
					term*=(x);
					y--;
				}
				val+=term;
				temp=temp->link;
			}
			return val;
			
		}

int main(){

	list_t l;
	int coeff;
	int expo;
	
	init_list(&l);
	int n; // number of terms
	scanf("%d", &n);
	for(int i = 0; i <= n; ++i)
	{
		scanf("%d %d", &coeff, &expo);
		insert(&l, coeff, expo);
	}
	printf("%d", eval(&l));
}
