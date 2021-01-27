#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{

	char eng[20];
	char kor[2][20];
	struct Node* next;

} Node;


int file_num = 0;


   int main(void){
   
  int print_num = 0;
  int play_mode = 0;

	   
	   while(1){
		
   
      printf(" >>영어 단어 암기 프로그램<< \n");
	  blank();
	  
	  printf("1. 영어 단어 맞추기	2. 플래쉬 카드\n");
	  blank();
	 
	  printf("3. 행맨(hangman)	4. 단어장 관리\n");
	  blank();
     
	  printf("5. 프로그램 종료\n");
	  printf("\n");


      printf("번호를 선택하세요 : \n");
	  scanf ("%d", &play_mode);

	  printf("파일 번호를 선택하세요 : \n");
	  scanf("%d", &file_num);
	  
	  printf("출력방식(알파벳 순서대로 :1, 무작위 :2)\n");
	  scanf("%d", &print_num);



	switch(play_mode){
		
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

int count = 0;


blank();
blank();

printf(">> 영어단어 암기 프로그램 : 영어단어 맞추기 <<");


blank();
blank();

// open file num -> file_num,  global value

void word_count(){
  
      int count = 0;
      FILE *fp;
	  char cha;
  

	 printf("파일번호확인 %d \n", file_num);
     
  if (file_num == 1){

	Node* word = (Node*)malloc(sizeof(Node)); 

    fp = fopen("1.dic","rt");
  
	if(fp == NULL){


	printf("파일읽기에 실패했습니다.");
	
	return 0;
	
	}


    while(feof(fp) == 0) {

	fscanf(fp,"%c",word->eng);

	
	if (cha == ' '){
	
	
	int kor_count = 0;

	fscanf(fp,"%c",word->kor[kor_count]);
	
	kor_count++;
	
	}


	printf("%s\n",word->eng);
	
	printf("%c",cha);

	

	if (cha == '\n'){ //다음 단어가 있으면 노드를 만들어서 연결.
	
		count++;
		
		Node* next_node = (Node*)malloc(sizeof(Node));

		next_node->next = NULL;

		word->next = next_node;

	}

	}

	printf("단어갯수 %d \n", count);
	fclose(fp);
  }


  else if(file_num == 2){

	fp = fopen("2.dic","rt");
 
     if(fp == NULL){
 
     
     printf("파일읽기에 실패했습니다.");
     
     return 0;
     
     }
     
     while(feof(fp) == 0) {
 
     fscanf(fp,"%c",&cha);
     printf("%c",cha);
 
     if(cha == '\n'){
     
         count++;
     
     }
     
     }
 
     printf("단어갯수 %d \n", count);
 
	 fclose(fp);
   }

	else if(file_num == 3){

	fp = fopen("3.dic","rt");
 
     if(fp == NULL){
      
     printf("파일읽기에 실패했습니다.");
     
     return 0;
     
     }
     
     while(feof(fp) == 0) {
 
     fscanf(fp,"%c",&cha);
   
	 printf("%c",cha);
 
     if(cha == '\n'){
     
         count++;
     
     }
     
     }
 
     printf("단어갯수 %d \n", count);
 	 
	 fclose(fp);
 
	}

}

printf("word count 함수 실행전 \n");

word_count();

printf("word count 실행 됨 \n");


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


