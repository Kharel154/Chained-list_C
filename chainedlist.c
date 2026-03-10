#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List{
	int  num;
	struct List *next;

}List;


List* inserthead(List* l, int v){
	List* node= malloc(sizeof(List));
	if(node){
		node->num=v;
		node->next=l;
		
	}else{
		printf("Allocation Error\n");
		exit(0);
	}
	return node;
}

List* insertend(List* l, int v){
	
	if(l==NULL){
                inserthead(l,v);
        }else{
		List* node= malloc(sizeof(List));
		List* temp=l;
		node->num=v;
		node->next=NULL;
		while(temp->next){
			temp=temp->next;
		}
		temp->next=node;
	
	}
	return l;

}


void display(List* l){
	if(l==NULL){
		printf("The list is empty\n");
		return;
	}
	printf("\n");
	List* temp=l;
	while(temp){
		printf("%d -> ",temp->num);
		temp=temp->next;
	}
	printf("NULL \n");
}

void freelist(List* l){
	if(l==NULL){
		printf("The list is already free\n");
		return;
	}
	while(l!=NULL){
		List* temp=l;
		l=l->next;
		free(temp);
	
	}
	printf("\n Deleted........ \n");
	return;
}

int main(){

	List* list= NULL;
	list=inserthead(list,3);
	list=inserthead(list,4);
	list=inserthead(list,5);
	list=insertend(list,10);
	bool flag=true;
	

	display(list);
	
	while(flag){
		int choice;

		printf("            ---MENU---               \n");
		printf("1) Add a number at the head of the list\n");
		printf("2) Add a number at the end of the list\n");
		printf("3) Display list\n");
		printf("4) Free list\n");
		printf("5) Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			int a;
			case 1:
				
				printf("\nEnter the number : ");
				scanf("%d",&a);
				list=inserthead(list,a);
				printf("\n %d has been succesfuly inserted at the head \n",a);
				break;

			case 2:
				
                                printf("\nEnter the number : ");
                                scanf("%d",&a);
                                list=insertend(list,a);
                                printf("\n %d has been succesfuly inserted at the end \n",a);
				break;

			case 3:
				display(list);
				break;
			case 4:
                                freelist(list);
				list=NULL;
                                printf("The list has been freed succesfully\n");
                                break;
			case 5:
				freelist(list);
				flag=false;
				printf("Good bye !\n\n");
				break;
			default : 
				printf("Wrong entry try again ");
				break;



		}
	}


}
