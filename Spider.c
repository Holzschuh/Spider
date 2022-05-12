#include <stdio.h>
#include <stdlib.h>
#define N 30 /// Lines
#define M 15 /// Columns
#define KNOTS 25

/// REFERENCE FOR CHARS

///   186 205 ║ ═
///   201 203 187 ╔ ╦ ╗
///   204 206 185 ╠ ╬ ╣
///   200 202 188 ╚ ╩ ╝

/// 186 ║
/// 204 ╠
/// 185 ╣
/// 205 ═


unsigned char** initializeWeb(unsigned char**);
void destroyWeb(unsigned char**);
void randomizeWeb(unsigned char**);
void printWeb(unsigned char**);
void randomizeSpiderPosition(char*);
void printSpider(char);
char computeSpiderFinalPosition(unsigned char**, char);

int main(){
   unsigned char **web;
   char spiderPosition;
   char answer;
   char spiderFinalPosition;

   srand(time(NULL));

   web = initializeWeb(web);

   randomizeWeb(web);
   randomizeSpiderPosition(&spiderPosition);

   printSpider(spiderPosition);
   printWeb(web);

   spiderFinalPosition = computeSpiderFinalPosition(web, spiderPosition);
   printf("\n\nSpider Initial Position: %d", spiderPosition);
   printf("\n\nSpider Final Position: %d\n\n", spiderFinalPosition);
   destroyWeb(web);
}

unsigned char** initializeWeb(unsigned char **web){
   web = (unsigned char**) malloc(N*sizeof(unsigned char*));
   for(int i=0; i<N; i++){
      web[i] = (unsigned char*) malloc(M*sizeof(unsigned char));
      for (int j=0; j<M; j++){
         web[i][j] = 186;
      }
   }
   return web;
}

void destroyWeb(unsigned char **web){
   for(int i=0; i<N; i++){
      free(web[i]);
   }
   free(web);
}

void randomizeWeb(unsigned char **web){
   char asd[M];
   for (int i=0; i<M; i++){
      asd[i] = 0;
   }
   for(int i=0; i<N; i++){
      for (int j=0; j<M-1; j++){
         if(web[i][j] == 186){
            if(rand()%100 < (KNOTS - asd[j])){
               web[i][j] = 204;
               web[i][j+1] = 185;
               asd[j] += 10;
            }
         }
      }
      for(int k=0; k<M; k++){
         asd[k]--;
      }
   }
}

void printWeb(unsigned char **web){
   for(int i=0; i<N; i++){
      for (int j=0; j<M; j++){
         if(web[i][j] != 204) printf("%c  ", web[i][j]);
         else printf("%c%c%c", web[i][j], 205, 205);
      }
      printf("\n");
   }
   for(int i=0; i<M; i++){
      if(i>=10) printf("%d ", i);
      else printf("%d  ", i);
   }
}

void randomizeSpiderPosition(char *spiderPosition){
   *spiderPosition = rand()%M;
   printf("%d\n\n", *spiderPosition);
}

void printSpider(char spiderPosition){
   for(int i=0; i<spiderPosition; i++){
      printf("   ");
   }
   printf("O\n");
}

/// 204 ╠
/// 185 ╣
char computeSpiderFinalPosition(unsigned char **web, char spiderPosition){
   for(int i=0; i<N; i++){
      if(web[i][spiderPosition] == 204) spiderPosition++;
      else if(web[i][spiderPosition] == 185) spiderPosition--;
   }
   return spiderPosition;
}
