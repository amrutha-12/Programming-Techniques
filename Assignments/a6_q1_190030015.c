#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char word[100]; //store the word
    int frequency; //store the frequency
	struct node *link;
};

typedef struct node node_t;

struct list
{
	node_t *head;
};
typedef struct list list_t;

void init_list(list_t *ptr_list )
{
	ptr_list->head = NULL;
}

//inserting words into the list and setting frequency as one
void insert(list_t *ptr_list, char word[100])
    {
        node_t* temp;
		temp=(node_t*)malloc(sizeof(node_t));
		strcpy(temp->word,word);
        temp->frequency=1;
		if(ptr_list->head == NULL)
		{
			ptr_list->head = temp;
			temp->link = NULL;
		}
		else
		{
			node_t* pres = ptr_list->head;
			ptr_list->head = temp;
			temp->link = pres;
		}
    }

//increasing frequency of repeated elements and eliminating repeated elemets
void get_frequency(const list_t *ptr_list)
{
    node_t *temp=ptr_list->head;
    while(temp!=NULL)
    {
        node_t *temp2=temp->link;
        while(temp2!=NULL)
        {
            if(strcmp(temp->word,temp2->word)==0)
            {
                if((temp->frequency)>0)
                {
                    (temp->frequency)++;
                }
                (temp2->frequency)--;
            }
            temp2=temp2->link;
        }
        temp=temp->link;
    }
}

void disp_list(const list_t *ptr_list)
{
	node_t *temp = ptr_list->head;
	while(temp != NULL)
	{
        if((temp->frequency)>0)
        {
		    printf("%s %d\n", temp->word,temp->frequency);
        }
        temp = temp->link; 
	}
		
}

int main()
{
    list_t list;
    init_list(&list); 
    char word[100];
    char end[]="-";
    do
    {
        scanf("%s", word);
        if(strcmp(word,end)==0)
        {
            break;
        }
        insert(&list, word);
    }
    while(strcmp(word,end)!=0);
    get_frequency(&list);
    disp_list(&list);
}