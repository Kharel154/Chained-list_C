#include <stdio.h>
#include <stdlib.h>


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
	return l;
	}

}


void display(List* l){
	List* temp=l;
	while(temp){
		printf("%d -> ",temp->num);
		temp=temp->next;
	}
	printf("NULL \n");
}

void freelist(List* l){
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
	
	display(list);
	freelist(list);
}
