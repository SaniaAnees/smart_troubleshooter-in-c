#include<stdio.h>
#include<string.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>   // library that helps convert text to pixels using pixel
int main( int argc , char*argv[]){
char is[100];
char* HD[]={"mouse","keyboard","screen","bluetooth","usb"};   //pointer to string
char* PF[]={"slow","lag","freeze","hanging"};
int network_flag=0 , hardware_flag=0,performance_flag=0;
int len=0;
is[0]='\0';
char c[100];
c[0]='\0';
char result[100]="Enter your issue...";
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
SDL_StartTextInput();
SDL_Window*window=SDL_CreateWindow("TROUBLESHOOTER",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,320,0);
SDL_Renderer*renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
//TTF_Font *font = TTF_OpenFont("consola.ttf", 24);
TTF_Font *font = TTF_OpenFont("Font/consola.ttf", 24);
if (!font) {
    printf("Font error: %s\n", TTF_GetError());
    return 1;
}
while(1){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type==SDL_QUIT){
            exit(0);
        }
        if(event.type==SDL_TEXTINPUT){
            is[len]=event.text.text[0];         //event.text-This is a structure  //event.text.text-This is the actual character data
            len++;
            is[len]='\0';
        }
        if(event.type==SDL_KEYDOWN){
            switch(event.key.keysym.sym){
                case SDLK_BACKSPACE:
                    if(len>0){
                    len--;
                    is[len]='\0';
            }
                break;
                case SDLK_RETURN:
                strcpy(c,is);
                printf("----SYSTEM TROUBLESHOOTER----\n\n");
                    for(int i=0;i<len;i++){
                    if(is[i]>=65 && is[i]<=90){
                    is[i]+=32;
                }
            }
                printf("Your entered issue is : %s\n",is);
                network_flag=0 , hardware_flag=0,performance_flag=0;
                for(int i=0;i<len;i++){                 //manual string based keyword search
                if(i+3<len && is[i]=='w' && is[i+1]=='i' && is[i+2]=='f' &&  is[i+3]=='i'){
                network_flag=1;
                break;
            }
                else if(i+7<len && is[i]=='i' && is[i+1]=='n' && is[i+2]=='t' &&  is[i+3]=='e' && is[i+4]=='r' && is[i+5]=='n' && is[i+6]=='e' &&  is[i+7]=='t'){
                        network_flag=1;
                        break;
            }
                else if(i+9<len && is[i]=='c' && is[i+1]=='o' && is[i+2]=='n' &&  is[i+3]=='n' && is[i+4]=='e' && is[i+5]=='c' && is[i+6]=='t' &&  is[i+7]=='i' && is[i+8]=='o' && is[i+9]=='n'){
                    network_flag=1;
                    break;
            }
            else if(i+6<len && is[i]=='n' && is[i+1]=='e' && is[i+2]=='t' && is[i+3]=='w' && is[i+4]=='o' && is[i+5]=='r' && is[i+6]=='k'){
                network_flag=1;
                break;
            }
                else if(i+6<len && is[i]=='o' && is[i+1]=='f' && is[i+2]=='f' && is[i+3]=='l' && is[i+4]=='i' && is[i+5]=='n' && is[i+6]=='e'){
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
            strcpy(result, "NETWORK ISSUE");
            }
            else if(hardware_flag==1){
                 strcpy(result, "HARDWARE ISSUE");
            }
            else if(performance_flag==1){
               strcpy(result,"PERFORMANCE ISSUE");
            }
            else{
                strcpy(result,"UNKNOWN ISSUE");
            }
            len=0;
            is[0]='\0';    
            break;
                        }
                    }
                }
        SDL_SetRenderDrawColor(renderer,20,20,65,255);
        SDL_RenderClear(renderer);
        SDL_Color color={255,255,255};   //white5
        SDL_Surface*surface=TTF_RenderText_Solid(font,is,color);
        if(surface!=NULL){
        //rendertext-Draw the text using the font,but no on screen but in memry (RAM)-bbuilds pixels
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);   //A GPU-ready version of that image //string → surface (RAM image) → texture (GPU image) → screen--displays pixels
        SDL_Rect rect = {50, 80, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
        }
          SDL_Color color2={255,255,255};
        SDL_Surface*surface2=TTF_RenderText_Solid(font,result,color2);
        if(surface2!=NULL){
            SDL_Texture*texture2=SDL_CreateTextureFromSurface(renderer,surface2);
            SDL_Rect rect2={50,30,surface2->w,surface2->h};
            SDL_RenderCopy(renderer,texture2,NULL,&rect2);
            SDL_FreeSurface(surface2);
            SDL_DestroyTexture(texture2);
        }
        SDL_RenderPresent(renderer);
}
}