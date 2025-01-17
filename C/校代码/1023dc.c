#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;
#define OK 1
typedef struct Lnode{
	ElemType data;
	struct Lnode *next;
}Lnode,*linklist;

void Initlist(linklist &L,int n){
	linklist p,s;
	L=(linklist)malloc(sizeof(Lnode));
	L->next=NULL;
	s=L;
	while(n--)
	{
	 p=(linklist)malloc(sizeof(Lnode));
	 cin>>p->data;
	 s->next=p;
	 s=p;
	 
	
	}
	p->next=NULL;
	
}

int ListInsert(linklist &L,int i,ElemType e)
{
	int j=0;
	linklist p=L,s;
	while(p&&j<i-1){
		p=p->next;
		j++;
	}
	if(!p||j>i-1)return 0;
	s=(linklist)malloc(sizeof(Lnode));
	if(!s)return -1;
	s->next=p->next;
	s->data=e;
	p->next=s;
	return OK;
	
}

int LocateElem(linklist L,int e){
	int i=1;
	linklist p=L->next;
	while(p)
	{

		if(p->data==e)break;
		i++;
				p=p->next;
	}
	if(!p)return 0;
	else return i;
}

int ListDelete(linklist &L,int i,int &e)
{
	int j=0;
	linklist p,s;
	p=L;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)return 0;
	s=p->next;
	e=s->data;
	p->next=s->next;
	free(s);
	return OK;
	
}

int GetElem(linklist L,int i)
{
	int j=1;
	linklist p=L->next;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)return -1;
	return p->data;
}

void ClearList(linklist &L)
{
	linklist p=L->next,s;
	while(L->next)
	{
		s=p->next;
		free(p);
		L->next=s;
		p=L->next;
	}
}
int main()
{
	int n,m,a,b;
	char step;
	cin>>n>>m;
	linklist L;
	Initlist(L,n);
	while(m--)
	{
		cin>>step>>a;
		switch(step)
		{
			case 'I':cin>>b;ListInsert(L,a,b);cout<<endl;break;
			case 'D':ListDelete(L,a,b);cout<<b<<endl;break;
			case 'G':cout<<GetElem(L,a)<<endl;break;
			case 'L':cout<<LocateElem(L,a)<<endl;break;
			case 'C':ClearList(L);	break;	
		}
	}
	return 0;
}
