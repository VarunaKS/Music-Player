#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include "new.c"


int main(int argc, char *argv[])
{
printf("Welcome\n");
int c=1,n,pn;char play[10],song[30],ch,x;
while(c)
{
printf("enter your choice:");
printf("1.Play 2.Create Playlist 3.Search 4.Play all 5.Shuffle");
scanf("%d",&n);
switch(n)
{
case 1:printf("play by 1.Artist name\n 2.Album name\n 3.Playlist name\n");
scanf("%d",&ch);
switch(ch){
case 1:printf("enter artist name:");scanf("%s",play);
playnext(player(play,ch));break;
case 2:printf("enter album name:");scanf("%s",play);
playnext(player(play,ch));break;
case 3:printf("enter your playlist name:");scanf("%s",play);
playnext(player(play,ch));break;
default:printf("try again");
}
break;
case 2:savetext();
break;
case 3:x=3;
printf("enter song name:");
scanf("%s",song);struct node*o=search(song);
if(o){
playnext(o);}
else{
	printf("  try again\n");
}break;
case 4:playnext(playall());break;
case 5:playnext(shuffle());break;
default: c=0;
}
}printf("See you again!!");
}