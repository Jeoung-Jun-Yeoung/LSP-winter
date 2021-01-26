#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int play_num = 0;
int file_num = 0;
int play_mode = 0;


typedef struct Node{

	char eng[20];
	char kor[3][20];
	struct Node* next;

} Node;



//노드를 몇개 만들어야 하나 size에서 고민을 한참했음. 그런데 단어가
//개횡문자 갯수만큼 있으니까 파일에서 개횡을 세서 그만큼 노드를 만들어주면된다는생각을 함.
// 파일 이름을 main에서 넘겨받으니까.. 이를 통해 내가 구해야하는 파일에 단어수를 구해주자
// 근데 파일마다 조건문으로 어떤 파일인지 확인해야 하니 번거로운데, 이를 따로 만들어 관리해야 하나 고민중
// 일단 파일이 3개라서 3개로 만들어봄.

int voca(int dic_num){

	int count = 0;
	int line = 0;
	FILE *fp;

	fp = fopen("1.dic","r");

	if (dic_num == 1){

	fp = fopen("1.dic","r");

	 while((line == fgetc(fp)) != EOF){
          
          if(line == '\n'){
          
             line++;
  
          }
	}
	
	}

	else if (dic_num == 2){

	fp = fopen("2.dic","r");

		while((line == fgetc(fp)) != EOF){
          
          if(line == '\n'){
          
              line++;
  
          }
 
	}
	
	}
	

	else if (dic_num == 3){

	fp = fopen("1.dic","r");

	while((line == fgetc(fp)) != EOF){
          
    if(line == '\n'){
          
              line++;
  
          }
  
	}

}

	return line;

}

   int main(void){
   
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

int count = 0;

blank();
blank();

printf(">> 영어단어 암기 프로그램 : 영어단어 맞추기 <<");


FILE *fp = fopen("1.dic","r");

int voca_cont = (file_num);
int index = 0;


node = (Node*)malloc(sizeof(Node) * voca_count);



while(voca_count != 0){



fgets(node[index].eng,strlen(str),*fp);

str[strlen(str) - 1] = '\0';

}

// 여기서부터 다시 작업


voca_count--;

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


