#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char *argv[]){
int ch;
FILE *fp;
int count=0;

if(argc==2 && argv[1][0]!='-'){
fp= fopen(argv[1],"r");

int count1=0;
int count2=0;
int count3=0;
while((ch=fgetc(fp))!=EOF){
count1=count1+1;
}
rewind(fp);
while((ch=fgetc(fp))!=EOF){
if(ch=='\n'){
count2=count2+1;
}
}
rewind(fp);
int inword1=0;
while((ch=fgetc(fp))!=EOF){
if(!isspace(ch)){
if(inword1==0){
count3=count3+1;
inword1=1;
}
}
else{
inword1=0;
}
}
printf("%d %d %d %s\n", count2, count3,count1,argv[1]);
}
else if(argc==2 && argv[1][0]=='-'){
fp=stdin;
if(strcmp(argv[1],"-c")==0){
while((ch= fgetc(fp))!=EOF){
count = count+1;
 
}
}
else if(strcmp(argv[1],"-l")==0){   
while((ch=fgetc(fp))!=EOF){
if(ch=='\n'){
count = count + 1;

}
}
}

else if(strcmp(argv[1],"-w")==0){
int inword=0;
while((ch=fgetc(fp))!=EOF){
if(!isspace(ch)){
if(inword==0){
count=count+1;
inword=1;
}
}
else{
inword=0;
}
}
}
else if(strcmp(argv[1],"-m")==0){
while((ch= fgetc(fp))!=EOF){
count = count+1; 

}
}
printf("%d\n",count);
}
else{

fp= fopen(argv[2],"r");
if(strcmp(argv[1],"-c")==0){
while((ch= fgetc(fp))!=EOF){
count = count+1;

}
}
else if(strcmp(argv[1],"-l")==0){
while((ch=fgetc(fp))!=EOF){
if(ch=='\n'){
count = count + 1;

}
}
}

else if(strcmp(argv[1],"-w")==0){
int inword=0;
while((ch=fgetc(fp))!=EOF){
if(!isspace(ch)){
if(inword==0){
count=count+1;
inword=1;
}
}


else{
inword=0;
}
}
}
else if(strcmp(argv[1],"-m")==0){
while((ch= fgetc(fp))!=EOF){
count = count+1;

}
}
printf("%d %s\n",count,argv[2]);
return 0;
}
}
