#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void disp(const list_t* ptr_list)
    {
	node_t * temp = ptr_list->head;
	while(temp){
		printf("%d %d\n", temp->coeff, temp->expo);
		temp = temp->link;
	    }
    }

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

void diff(const list_t *expr, list_t *diff_expr)
    {
        // Fill this function
        node_t* temp=expr->head;
        //node_t* temp2=diff_expr->head;
        while(temp!=NULL)
        {
            if(temp->coeff!=0 && temp->expo>0)
            {
                int new_coeff=((temp->coeff)*(temp->expo));
                int new_expo=((temp->expo)-1);
                insert(diff_expr, new_coeff, new_expo);
            }
            temp=temp->link;
        }
    }


int main(){

	list_t expr;
	list_t diff_expr;
	int coeff;
	int expo;
	
	init_list(&expr);
	init_list(&diff_expr);
	
	int n; // number of terms
	scanf("%d", &n);
	for(int i = 0; i <= n; ++i)
	{
		scanf("%d %d", &coeff, &expo);
		insert(&expr, coeff, expo);
	}
	diff(&expr, &diff_expr);
	disp(&diff_expr);
}
