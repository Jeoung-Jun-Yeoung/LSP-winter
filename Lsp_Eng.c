#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {

	char eng[20];
	char kor[3][20];
	struct Node* next;

} Node;



   int main(void){
   
   	while(1){
		
      int play_num = 0;
	  int file_num = 0;
	  int play_mode = 0;
   
      printf(" >>영어 단어 암기 프로그램<< \n");
	  blank();
	  
	  printf("1. 영어 단어 맞추기	2. 플래쉬 카드\n");
	  blank();
	 
	  printf("3. 행맨(hangman)	4. 단어장 관리\n");
	  blank();
     
	  printf("5. 프로그램 종료\n");
	  printf("\n");


      printf("번호를 선택하세요 : \n");
	  scanf ("%d", &play_num);

	  printf("파일 번호를 선택하세요 : \n");
	  scanf("%d", &file_num);
	  
	  printf("출력방식(알파벳 순서대로 :1, 무작위 :2)\n");
	  scanf("%d", &file_num);

	switch(play_num){
		
		case 1 : 
			
		First_Function();
		
		break;

      	case 2 :

		Second_Function();
	   
		break;

		case 3 :
			
		Third_Function();
		
		break;

		case 4 :

		Fourth_Function();
		
		break;

		case 5 :

		return 0 ;
			
		default : 
			printf("유효한 숫자가 아닙니다. 1 ~ 5만 입력해 주세요");
			sleep(5);
		
		}
	}
  
  }

void blank(){

	printf("\n");

}


void First_Function(){

blank();
blank();
printf(">> 영어단어 암기 프로그램 : 영어단어 맞추기 <<");

char *buffer;
int size;
int count;

FILE *fp = fopen("1.dic","r");

fseek(fp,0,SEEK_END);

size = ftell(fp);


Node* node = (Node*)malloc(sizeof(Node));

for(int i = 0; i < size; i++){

fscanf(fp,"%s %s",&node.[i]



}

fclose(fp);

}


void Second_Function(){

printf("2번프로그램입니다.");

}


void Third_Function(){


printf("3번 프로그램 입니다.");

}



void Fourth_Function(){


printf("4번 프로그램 입니다.");

}


