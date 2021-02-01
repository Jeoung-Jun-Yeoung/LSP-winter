#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{

	char* eng;
	char* kor[3];
	struct Node* next;

} Node;

int file_num = 0;


void blank(){

	printf("\n");

}



Node* make_node(int file_num){

	FILE *fp;

	int count = 0;

	char buffer[80];
	char ch;

	Node* head = (Node*)malloc(sizeof(Node));
	
	if (file_num == 1){

	fp = fopen("1.dic","rt");

	} else if (file_num == 2){

		fp = fopen("2.dic","rt");

	} else if(file_num == 3){

		fp = fopen("3.dic","rt");
	}


	if(fp == NULL){

		printf("파일을 읽지 못했습니다.");

	}


	while(feof(fp) == 0){


		int index = 0;

		Node* node = (Node*)malloc(sizeof(Node));


		fgets(buffer,sizeof(buffer),fp);

		buffer[sizeof(buffer) -1] = '\0';

		char *token = strtok(buffer," ");

		while(token != NULL){
			

			if(index == 0){

				node->eng = token;

			}

			else {

				node->kor[index - 1] = token;

			}

		
			token = strtok(NULL," ");
			index++;

		}

		node->next = head->next;

		printf("%s\n",node->eng);
		printf("%s\n",node->kor[0]);

		head->next = node;

	}

	fclose(fp);
/*
	int c = 30;
	Node *curr = head;

	while(c != 0){

	printf("%s ",curr->eng);

	printf("%s ",curr->kor[0]);
	c--;
	curr = curr->next;
	}*/
	return head;

//	return count;

}

/*

   void Make_linkedlist(){


   int count = 0;

//	char buffer[80];

FILE *fp;

count = Count_word();


Node* head_node = (Node*)malloc(sizeof(Node) * count);

// fgets 로 한줄씩 받고, strok거르자.


fopen("1.dic","rt");


while(count != 0){

count--;

char buffer[80];
fgets(buffer,sizeof(buffer),fp);

//	buffer[strlen(buffer) - 1] = '\0';


printf("%s",buffer);


}

printf("끝");

fclose(fp);



}
 */

/*
   void Getc(){



   FILE *fp = fopen("1.dic","rt");

   int c = 0;

   if (fp == NULL){

   printf("파일을 읽을 수 없습니다.");
   }

   while((c = fgetc(fp)) != EOF){

   Node* node = (Node*)malloc(sizeof(Node));	

   if((c = fgetc(fp)) == ' '){

   while ((c = fgetc(fp)) != ' ' ){


   node->kor = c;

   }
   }

   else {

   node->eng = c;

   }

   }




   }
 */


void Sorting(Node* node){







}

void First_Function(int file_num){

	blank();
	blank();
	blank();

	printf(">> 영어단어 암기 프로그램 : 영어단어 맞추기 <<");


	blank();
	blank();

	Node* node = (Node*)malloc(sizeof(Node));

	node = make_node(file_num);


//	printf("%s", node->next->next->kor[0]);



}

void Second_Function(){


	//	make_node();

	char g = 'A';

	printf("%40c",g);

}


void Third_Function(){


	printf("3번 프로그램 입니다.");

}



void Fourth_Function(){


	printf("4번 프로그램 입니다.");

}

int main(void){

	int print_num = 0;
	int play_mode = 0;
	int file_num = 0;
	int sec = 7;


	while(1){


		printf(" >>영어 단어 암기 프로그램<< \n");
		blank();

		printf("1. 영어 단어 맞추기 2. 플래쉬 카드\n");
		blank();

		printf("3. 행맨(hangman)    4. 단어장 관리\n");
		blank();

		printf("5. 프로그램 종료\n");
		blank();


		printf("번호를 선택하세요 : ");
		scanf ("%d", &play_mode);

		blank();

		printf("파일명(일차) : ");
		scanf("%d", &file_num);

		blank();

		printf("출력방식(알파벳 순서대로 :1 , 무작위 : 2) : ");
		scanf("%d", &print_num);

		if(play_mode == 2){

			blank();

			printf("속도(초) : ");
			scanf("%d", &sec);

		}

		blank();


		switch(play_mode){

			case 1 :

				First_Function(file_num);

				system("clear");

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

		}
	}

}   

