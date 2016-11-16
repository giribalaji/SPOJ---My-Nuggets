#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct st
{
	int no;
	struct st *r;
	struct st *l;
};

//struct st *h=NULL;


/*void insert()
{

	int a;
	struct st *n,*t;
	n=(struct st*)malloc(sizeof(struct st));

	printf("Enter the no to add...\n");
	scanf("%d",&(n->no));
			n->l=NULL;
		     n->r=NULL;


	if(h==NULL)
	{
		h=n;
	}
	else
	{
		t=h;
		while(t->l != NULL || t->r != NULL)
		{
			if(t->l !=NULL)
			{
				if(t->no > n->no)
					t=t->l;
			}
			if(t->r !=NULL)
			{
				if(t->no <= n->no)
					t=t->r;
			}

			if((t->l==NULL) && (n->no < t->no) && (n->no < t->r->no))
				break;

			if((t->r==NULL) && (n->no >= t->no) && (n->no > t->l->no))
				break;

		 }
 if((n->no < t->no) && (t->l==NULL))
  t->l=n;
 if((n->no > t->no) && (t->r==NULL))
  t->r=n;
}
	
}*/
	
	
/*	void insert()
{

	int a;
	struct st *n,*t;
	n=(struct st*)malloc(sizeof(struct st));

	printf("Enter the no to add...\n");

	scanf("%d",&a);
	n->no=a;
			n->l=NULL;
		     n->r=NULL;


	if(h==NULL)
	{
		h=n;
	}
	else
	{
		t=h;
		while(t!= NULL )
		{
			
				if(t->no > n->no && t->l != NULL)
					t=t->l;
			
		
				if(t->no <= n->no && t->r != NULL)
					t=t->r;
		}

	printf("Giri\n");
	t=n;
}
	
}*/


/*void insert_it()
{
	struct st *cur,*t,*p;
	
	t=malloc(sizeof(struct st));
	t->l=NULL;
	t->r=NULL;
	
	printf("Enter the no....\n");
	scanf("%d",&(t->no));
	
	cur=t;
	
	
	if(h==NULL)
	{
		h=cur;
	}
	else
	{
		p=NULL;
				
		while(cur!=NULL)
		{
			p=cur;
			
			if(t->no > cur->no)
			cur=cur->r;
			else
			cur=cur->l;
			
		}
		
		if(p->no < t->no)
		p->r=t;
		else
		p->l=t;
				
	}
	
	
}
*/






void insert_fun(struct st** t,int n)
{
//	struct st *cur,*t,*p;
	
	if(*t==NULL)
	{
	struct st *nw;
	nw=(struct st*)malloc(sizeof(struct st));
	nw->no=n;
	nw->l=NULL;
	nw->r=NULL;
	*t=nw;
}


			else if((*t)->no > n)
			insert_fun((&(*t)->l),n);
			else
			insert_fun((&(*t)->r),n);
			
	
}

void insert_iter(struct st** t,int n)
{
//	struct st *cur,*t,*p;
	
	struct st *nw;
	nw=(struct st*)malloc(sizeof(struct st));
	nw->no=n;
	nw->l=NULL;
	nw->r=NULL;


	while(*t!=NULL)
	{
	
			if((*t)->no > n)
			{
			//*t=(*t)->l;
			t=(&(*t)->l);
			}
			else
			{
			//*t=(*t)->r;
			t=(&(*t)->r);
	
	}}
	
	
	
    
	*t=nw;	

}


/*void insert(int n)
{
//	struct st *cur,*t,*p;
	
	if(h==NULL)
	{
	struct st *nw;
	nw=(struct st*)malloc(sizeof(struct st));
	nw->no=n;
	nw->l=NULL;
	nw->r=NULL;
	h=nw;
}


			else if(h->no > n)
			{
			h=h->l;	
			insert(n);
		}
			else
			{
			h=h->r;	
			insert(n);
		}
	
}
*/


	
/*	void del()
	{
		
		struct st *p,*x,*t1,*t;
		int num,f=0,f1=0;
		
		t=h;
		
		printf("Entr the no to delt...\n")	;
		scanf("%d",&num);
		
		while(t!=NULL)
		{
			
			if(t->no==num)
			{
			f=1;
			x=t;
			break;
		    }	
			if(t->no > num)
			{
				p=t;
				t=t->l;
			}
			else if(t->no <= num) 
			{
				p=t;
				t=t->r;				
			}
							
		}
	if(f==0)
	{
		printf("the entered no is not present..\n");
		return;
	}


// delete the node, no child

if((x->l==NULL) && (x->r==NULL))
{
	if(p->r==x)
	p->r=NULL;
	else
	p->l=NULL;

free(x);
return;
}


// delete the node has two child

if(x->r!=NULL && x->l!=NULL)
{
p=x;
t1=x->r;

if(t1->l!=NULL)	
{
f1=1;
p=t1;
t1=t1->l;
}

if(t1->l==NULL && t1->r==NULL)
{
	x->no=t1->no;
	
	if(f1==1)
	{
		p->l=t1->l;
	}
	if(f1==0)
	{
		x->r=t1->l;
	}
	
	free(t1);
	return;

}

if(t1->r!=NULL)
{
	x->no=t1->no;
	
	if(f1==1)
	p->l=t1->r;
	if(f1==0)
	p->r=t1->r;
	
	
	free(t1);
	return;	
}

}


//delete the node has only right child


if((x->r!=NULL) && (x->l==NULL) && (x->no!=h->no))
{
	if(p->r==x)
	p->r=x->r;
	else
	p->l=x->r;
	
	free(x);
	return;
}


//delete the node has only left child


if((x->l!=NULL) && (x->r==NULL) && (x->no!=h->no))
{
	if(p->r==x)
	p->r=x->l;
	else
	p->l=x->l;
}



if((x->r!=NULL) && (x->l==NULL) && (x->no==h->no))
{
	h=x->r;
	
	free(p);
	return;
}




if((x->l!=NULL) && (x->r==NULL) && (x->no==h->no))
{
	h=x->l;
	
	free(p);
	return;
}
		
		
	}
	
	
	
	
*/	
	
	

void print(struct st *t)
{
	
	if(t!=NULL)
	{
	//	printf("Giri\n");
		print(t->l);
		printf("%d\t",t->no);
		print(t->r);
		
	}
}



int main()
{
	int n,i;
	char ch;
	struct st *h=NULL;	
	
	do{

	printf("Enter the fn to execute..\n 1.Add\n 2.Delete\n 3.Print\n  4.Exit\n");;
	scanf("%d",&n);
	
	switch(n)
	{
	case 1:
	printf("Enter the no....");
	scanf("%d",&i);
	//	insert_fun(&h,i);
		insert_iter(&h,i);
		//insert(i);
		break;
	case 2:
	//	del();
		break;
	case 3:
		print(h);
		break;
	case 4:
		exit(0);
		break;
	}
	
	//printf("Do u want to do it again...y or n..\n");
	//scanf(" %c",&ch);

	}while(1);

}
