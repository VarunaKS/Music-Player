#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<string.h>
#include<time.h>
struct node{
	
	char playname[30];
	char name[30];
	char art[30];
	char alb[30];
	int count;
	struct node* next;
	struct node* prev;
	};
	

int savetext()
{char nam[10];
	printf("enter playlist name:");
	scanf("%s",nam);
	char g[10]=".ogg";char f[40];
FILE *data;
  data = fopen("music.csv", "a+");
	int c=1,con;struct node *new=NULL;
struct node **p=&new;
	struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
		temp->next=temp->prev=NULL;
		
	while(c)
	{   
        strcpy(temp->playname,nam);
		printf("enter name of the song");
		scanf("%s",f);strcat(f,g);
		strcpy(temp->name,f);
		
		printf("enter the artist's name"); 
		scanf("%s",temp->art);
		printf("enter the album's name"); 
		scanf("%s",temp->alb);
		fprintf(data,"%s,%s,%s,%s,%d\n",(temp->playname),(temp->name),(temp->art),(temp->alb),0);
		if(*p==NULL)
			*p=temp;
		else
		{
			temp->next=*p;
		(*p)->prev=temp;
		(*p)=temp;
	}
	printf("do you want to add:press 1 to continue");
	scanf("%d",&con);
	if(con!=1)
	{c=0;fclose(data);
	}}
}
struct node* getll(char *p,int v)
{   char h[10];strcpy(h,p);int c=1;
    struct node* first =NULL; int u=0;
	FILE *data;
    data = fopen("music.csv", "r");
	if(data==NULL){printf("error try again");exit(0);}
	
    char parsedLine[100];

while (fgets(parsedLine, 100, data)!= NULL) {
    struct node *temp = malloc(sizeof(struct node));
    char *getpn = strtok(parsedLine, ", ");
    strcpy(temp->playname, getpn);
    char *getna = strtok(NULL, ", "); 
    strcpy(temp->name, getna);
	char *getart = strtok(NULL, ", "); 
    strcpy(temp->art, getart);
	char *getalb = strtok(NULL, ", "); 
    strcpy(temp->alb, getalb);
	char*x=(strtok(NULL, "\n")); 
	//temp->count=atoi(x);
	temp->next=temp->prev=NULL;
    if(first==NULL)
		first=temp;
	else
	{temp->next=first;
	first->prev=temp;
	first=temp;
	}   u++;   		
}fclose(data);
struct node*fir=NULL;struct node**q=&fir;

switch(v)
{
	case 1:while(first!=NULL)
	{struct node* get=(struct node*)malloc(sizeof(struct node));
get->prev=get->next=NULL;
strcpy(get->alb,"nr");
strcpy(get->art,"nr");
strcpy(get->playname,"nr");
strcpy(get->name,"nr");
		if(strcmp(first->art,h)==0)
		{
			strcpy(get->name,first->name);
			if((*q)==NULL)
			{
			(*q)=get;
			}
			else{
				get->next=(*q);
				(*q)->prev=get;
				(*q)=get;
			}
		}
		first=first->next;
		
	}
	return fir;
	
	case 2:while(first!=NULL)
	{struct node* get=(struct node*)malloc(sizeof(struct node));
get->prev=get->next=NULL;
strcpy(get->alb,"nr");
strcpy(get->art,"nr");
strcpy(get->playname,"nr");
strcpy(get->name,"nr");
get->count=0;
		if(strcmp((first->alb),h)==0)
		{    strcpy(get->name,first->name);
			if((*q)==NULL)
			{
			(*q)=get;
			}
			else{
				get->next=(*q);
				(*q)->prev=get;
				(*q)=get;
			}
		}
		first=first->next;
	}
	return fir;
	case 3:while(first!=NULL)
	{struct node* get=(struct node*)malloc(sizeof(struct node));
get->prev=get->next=NULL;
strcpy(get->alb,"nr");
strcpy(get->art,"nr");
strcpy(get->playname,"nr");
strcpy(get->name,"nr");
		if(strcmp(first->playname,h)==0)
		{
			strcpy(get->name,first->name);
			if((*q)==NULL)
			{
			(*q)=get;
			}
			else{
				get->next=(*q);
				(*q)->prev=get;
				(*q)=get;
			}
		}
		first=(first->next);
}
return fir;

	default:printf("invalid choice");return NULL;
}
} 
struct node* search(char *s)
{
	struct node*r;
	
    struct node* first =NULL; 
	FILE *data;
    data = fopen("music.csv", "r");
	if(data==NULL){printf("error try again");exit(0);}
	
    char parsedLine[100];
	char g[10]=".ogg";
	strcat(s,g);
while (fgets(parsedLine, 100, data)!= NULL) {
    struct node *temp = malloc(sizeof(struct node));
    char *getpn = strtok(parsedLine, ", ");
    strcpy(temp->playname, getpn);
    char *getna = strtok(NULL, ", "); 
    strcpy(temp->name, getna);
	char *getart = strtok(NULL, ", "); 
    strcpy(temp->art, getart);
	char *getalb = strtok(NULL, ", "); 
    strcpy(temp->alb, getalb);
	temp->next=temp->prev=NULL;
    if(first==NULL)
		first=temp;
	else
	{temp->next=first;
	first->prev=temp;
	first=temp;
	}      		
}fclose(data);
	struct node* t=first;int cnt=0;
	while(first!=NULL && strcmp(first->name,s))
	{first=first->next;}
	if(first==NULL) {printf("NOT FOUND!!\n");while(t!=NULL){if((t->name)[0]==s[0]){printf("\n%s\n",(t->name));cnt++;}t=t->next;}
if(cnt>0)printf("Did you mean this?\n");
	return NULL;}
	else 
		return first;
	}
	

struct node* shuffle(){                                              //SHUFFLE FUNCTION
	int c=1;
    struct node* first =NULL; int u=0;
	FILE *data;
    data = fopen("music.csv", "r");
	if(data==NULL){printf("error try again");exit(0);}
	
    char parsedLine[100];

while (fgets(parsedLine, 100, data)!= NULL) {u++;
    struct node *temp = malloc(sizeof(struct node));
    char *getpn = strtok(parsedLine, ", ");
    strcpy(temp->playname, getpn);
    char *getna = strtok(NULL, ", "); 
    strcpy(temp->name, getna);
	char *getart = strtok(NULL, ", "); 
    strcpy(temp->art, getart);
	char *getalb = strtok(NULL, ", "); 
    strcpy(temp->alb, getalb);
	char*x=(strtok(NULL, "\n")); 
	
	temp->next=temp->prev=NULL;
    if(first==NULL)
		first=temp;
	else
	{temp->next=first;
	first->prev=temp;
	first=temp;
	}      		
}fclose(data);
struct node*fir=NULL;struct node**q=&fir;
struct node* s=first;time_t t;
	srand(time(&t));
	int k=u; 
	while(k!=0)
	{
		int r=rand()%(u);//printf("%d",r);
		//if(r==0)r==1;
	for(int i=0;i<r;i++)
	{s=s->next;
	}
	struct node* get=(struct node*)malloc(sizeof(struct node));
get->prev=get->next=NULL;
strcpy(get->alb,"nr");
strcpy(get->art,"nr");
strcpy(get->playname,"nr");
strcpy(get->name,"nr");
	strcpy(get->name,s->name);
if((*q)==NULL)
			{
			(*q)=get;
			}
			else{
				get->next=(*q);
				(*q)->prev=get;
				(*q)=get;
			}
			k--;
			s=first;
}
return (*q);
}

struct node* playall(){                                                     //PLAY ALL FUNCTION
	int c=1;
    struct node* first =NULL; 
	FILE *data;
    data = fopen("music.csv", "r");
	if(data==NULL){printf("error try again");exit(0);}
	char s[20];
    char parsedLine[100];

while (fgets(parsedLine, 100, data)!= NULL) {
    struct node *temp = malloc(sizeof(struct node));
    char *getpn = strtok(parsedLine, ", ");
    strcpy(temp->playname, getpn);
    char *getna = strtok(NULL, ", "); 
    strcpy(temp->name, getna);
	char *getart = strtok(NULL, ", "); 
    strcpy(temp->art, getart);
	char *getalb = strtok(NULL, ", "); 
    strcpy(temp->alb, getalb);
	char*x=(strtok(NULL, "\n")); 
	strcpy(s,x);
	temp->count=atoi(s);
	temp->next=temp->prev=NULL;
    if(first==NULL)
		first=temp;
	else
	{temp->next=first;
	first->prev=temp;
	first=temp;
	}      		
}fclose(data);

return first;}
























	