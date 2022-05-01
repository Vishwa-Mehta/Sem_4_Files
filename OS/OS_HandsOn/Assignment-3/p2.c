#include<stdio.h>
#include<stdlib.h>
struct list {
	int page;
	int frame;
	struct list *next;
}*p;

void add(struct list *q,int page,int frame) {
	if(p==NULL) {
		p=malloc(sizeof(struct list));
		p->page=page;
		p->frame=frame;
		p->next=NULL;
	}
	else {
		while(q->next!=NULL) {
			q=q->next;
		}
		q->next=malloc(sizeof(struct list));
		q->next->page=page;
		q->next->frame=frame;
		q->next->next=NULL;
	}
}
int search(struct list *q,int page) {
	while(q->page!=page) {
		q=q->next;
	}
	return q->frame;
}
int main() {
	p=NULL;
	int pagesize,logicaladdr;
	int i,page,frame;
	int quotient,offset,physicaladdr;
	printf("Enter page table as structure\n");
	printf("Enter 100 as page number for termination\n");
	printf("Enter page size");
	scanf("%d",&pagesize);
	do {
		printf("Enter the page number");
		scanf("%d",&page);
		if(page!=100) {
			printf("Enter the frame number:");
			scanf("%d",&frame);
			add(p,page,frame);
		}
	}
	while(page!=100);
	printf("Enter logical address");
	scanf("%d",&logicaladdr);
	quotient=logicaladdr/pagesize;
	offset=logicaladdr%pagesize;
	physicaladdr=(search(p,quotient)*pagesize)+offset;
	printf("CORRESPONDING PHYSICAL ADDRESS IS %d\n",physicaladdr);
}


