#include<stdio.h>
#include<string.h>
int main(){
char is[100];
int network_flag=0;
printf("----SYSTEM TROUBLESHOOTER----\n\n");
printf("Enter your issue:\n");
fgets(is,sizeof(is),stdin);
int a=strlen(is);
 for(int i=0;i<a;i++){
    if(is[i]>=65 && is[i]<=90){
            is[i]+=32;
    }
}   
printf("Your entered issue is : %s\n",is);
for(int i=0;i<a;i++){
    if(i+3<a && is[i]=='w' && is[i+1]=='i' && is[i+2]=='f' &&  is[i+3]=='i'){
        network_flag=1;
        break;
   }
   else if(i+7<a && is[i]=='i' && is[i+1]=='n' && is[i+2]=='t' &&  is[i+3]=='e' && is[i+4]=='r' && is[i+5]=='n' && is[i+6]=='e' &&  is[i+7]=='t'){
         network_flag=1;
         break;
   }
    else if(i+9<a && is[i]=='c' && is[i+1]=='o' && is[i+2]=='n' &&  is[i+3]=='n' && is[i+4]=='e' && is[i+5]=='c' && is[i+6]=='t' &&  is[i+7]=='i' && is[i+8]=='o' && is[i+9]=='n'){
         network_flag=1;
         break;
   }
}
if(network_flag==1){
    printf("Network connectivity issue.\n");
}
}