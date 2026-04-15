#include<stdio.h>
#include<string.h>
#include<SDL2/SDL.h>
int main(){
char is[100];
char* HD[]={"mouse","keyboard","screen","bluetooth","usb"};   //pointer to string
char* PF[]={"slow","lag","freeze","hanging"};
int network_flag=0 , hardware_flag=0,performance_flag=0;

printf("----SYSTEM TROUBLESHOOTER----\n\n");
printf("Enter your issue:\n");
fgets(is,sizeof(is),stdin);
int a=strlen(is);
//int b=sizof(HD)/sizeof(HD[i]);
 for(int i=0;i<a;i++){
    if(is[i]>=65 && is[i]<=90){
            is[i]+=32;
    }
}   
printf("Your entered issue is : %s\n",is);
for(int i=0;i<a;i++){                 //manual string based keyword search
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
   else if(i+6<a && is[i]=='n' && is[i+1]=='e' && is[i+2]=='t' && is[i+3]=='w' && is[i+4]=='o' && is[i+5]=='r' && is[i+6]=='k'){
    network_flag=1;
    break;
   }
    else if(i+6<a && is[i]=='o' && is[i+1]=='f' && is[i+2]=='f' && is[i+3]=='l' && is[i+4]=='i' && is[i+5]=='n' && is[i+6]=='e'){
    network_flag=1;
    break;
   }
}
for(int i=0;i<sizeof(HD)/sizeof(HD[i]);i++){
if (!(strstr(is,HD[i])==NULL)){
  hardware_flag=1;
    break;
}
}
for(int i=0;i<sizeof(PF)/sizeof(PF[i]);i++){
    if(strstr(is,PF[i])!=NULL)
    {
        performance_flag=1;
        break;
    }
}

if(network_flag==1){
    printf("DETECTED : NETWORK ISSUE.\n");
}
else if(hardware_flag==1){
    printf("DETECTED : HARDWARE ISSUE.\n");
}
else if(performance_flag==1){
    printf("DETECTED : PERFORMANCE ISSUE.\n");
}
else{
    printf("DETECTED : UNKNOWN ISSUE.\n")
}
}