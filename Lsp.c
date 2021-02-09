#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

typedef struct Word {
	char eng[16];
	char kor[3][31];
	struct Word* next;
} Word;

typedef struct file {
	char name[10];
} file;

int search_dir() {
	DIR* dp = NULL;
	struct	dirent* entry = NULL;
	int filecount = 0;

	if ((dp = opendir(".")) == NULL) {
		printf("디렉토리를 열수 없습니다.\n");
	}
	while ((entry = readdir(dp)) != NULL) {
		char* ptr = strstr(entry->d_name,".dic");	
		if (ptr != NULL){
			filecount++;
		}
	}
	closedir(dp);
	return filecount;
}

void filelist(file* list[]) {
	DIR* dp = NULL;
	struct dirent* entry = NULL;
	int index = 0;

	if ((dp = opendir(".")) == NULL) {
		printf("디렉토리를 열수 없습니다.");
	}

	while ((entry = readdir(dp)) != NULL) {
		char* ptr = strstr(entry->d_name,".dic");

		if (ptr != NULL) {
			strcpy(list[index]->name,entry->d_name);
			index++;
		}
	}
	closedir(dp);
}


int count_word(char* number) {
	FILE* fp;
	char ch;
	int count = -1;

	fp = fopen(number,"r");

	while (feof(fp) == 0) {
		fscanf(fp,"%c",&ch);
		if (ch == '\n') {
			count++;
		}
	}
	fclose(fp);
	return count;
}

void makeList(Word* head,int count,char* number) {
	FILE * fp;
	fp = fopen(number,"r");

	while (count != 0) {
		int index = 0;
		char buffer[100];

		fgets(buffer,sizeof(buffer),fp);
		buffer[strlen(buffer)-1]='\0';

		char *token = strtok(buffer," ");
		Word* word = (Word*)malloc(sizeof(Word));

		while (token != NULL) {
			if (index == 0) {
				strcpy(word->eng,token);
			}
			else {
				strcpy(word->kor[index - 1],token);
			}
			token = strtok(NULL," ");
			index++;
		}
		word->next = head->next;
		head->next = word;
		count--;
	}
}

void sorting(Word* head,Word* array[],int count,int sorting_option) {
	Word* curr = (Word*)malloc(sizeof(Word));
	curr = head;
	Word* temp;

	for (int i = 0; i < count; i++) {
		curr = curr->next;
		array[i] = curr;
	}

	if (sorting_option == 1) { // 정렬실행
		for (int i = 0; i < count-1; i++) {
			for (int j = 0; j < count-i-1; j++) {
				if (strcmp(array[j]->eng,array[j+1]->eng) > 0) {
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}
	}
	else {// 랜덤일 경우
		srand(time(NULL));
		for (int i = 0; i < count; i++) {
			int numseed1 = rand() % count; // 30까지의 난수를 만들어줌
			int numseed2 = rand() % count; // 30까지의 난수를 만들어줌
			temp = array[numseed1]; //랜덤인덱스로 섞어줌
			array[numseed1] = array[numseed2];
			array[numseed2] = temp;
		}
	}
}

void first(Word* array[],int count) {
	printf(">> 영어 단어 암기 프로그램 : 영어 단어 맞추기 <<\n");
	printf("\n");

	char input[16];
	char stop [6] =".quit"; //입력받은거랑 비교해서 종료해줌
	char enter;
	double score = 0; // 몇개 맞췄는지
	double play = 0; // 몇개 단어가 나왔는지	

	for (int i = 0; i < count; i++) {
		printf("%s -> ",array[i]->kor[0]);
		fgets(input,sizeof(input),stdin);
		input[strlen(input)-1] = '\0';

		if (strcmp(input,stop) == 0) { //종료조건입력시 종료
			break;
		}
		else if (strcmp(input,array[i]->eng) == 0) { // 맞춤
			score++;
			printf("\n");
			printf("correct!\n");
			printf("\n");
		}
		else { // 못맞춤
			printf("\n");
			printf("incorrect!");	
			printf("\n");
		}
		play++;
	}

	if (score != 0) { // score에 따른 점수 계산 
		score = (score / play) * 100;
	}

	printf("당신의 점수는 %0.2f 점 입니다.\n",score);  
	system("clear");
	enter = getchar();
}

void second(Word* array[],int sec,int count) {
	for (int i = 0; i<count; i++) {
		printf(">> 영어 단어 암기 프로그램 : 플래쉬 카드 <<\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("			%s\n",array[i]->eng); // 영어출력
		sleep(sec);//입력받은만큼쉬기
		system("clear");
		printf("\n");
		printf("\n");
		printf("			%s %s %s\n",array[i]->kor[0],array[i]->kor[1],array[i]->kor[2]); // 반복문사용을 해도됨
		//한글출력
		sleep(sec);
		system("clear");
	}
}

void third(Word* array[]) {
	int error = 0; //틀린횟수로 행맨보여주기
	int index = strlen(array[0]->eng);
	int try = 1; // 도전횟수
	char input;
	char rst[index+1]; // 보여줄결과창
	char copy[index+1]; // 영어만 copy해서 사용.

	for (int i = 0; i < index; i++) {
		rst[i] = '_'; //초기 세팅
		copy[i] = array[0]->eng[i]; // 영어 복사
	}

	while(1) {
		if (error == 0) { // 처음
			printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
			printf("(힌트) %s %s %s\n",array[0]->kor[0],array[0]->kor[1],array[0]->kor[2]);
			printf("\n");
			printf("\n");
			printf("-------------------+\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
		}
		else if (error == 1) { 
			printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
			printf("(힌트) %s %s %s\n",array[0]->kor[0],array[0]->kor[1],array[0]->kor[2]);
			printf("\n");
			printf("\n");
			printf("-------------------+\n");
			printf("                    O\n ");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
		}
		else if (error == 2) {
			printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
			printf("(힌트) %s %s %s\n",array[0]->kor[0],array[0]->kor[1],array[0]->kor[2]);
			printf("\n");
			printf("\n");
			printf("-------------------+\n");
			printf("                    O\n ");
			printf("                  / ");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
		}
		else if (error == 3) {
			printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
			printf("(힌트) %s %s %s\n",array[0]->kor[0],array[0]->kor[1],array[0]->kor[2]);
			printf("\n");
			printf("\n");
			printf("-------------------+\n");
			printf("                    O\n ");
			printf("                  / ");
			printf("|");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
		}
		else if (error == 4) {
			printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
			printf("(힌트) %s %s %s\n",array[0]->kor[0],array[0]->kor[1],array[0]->kor[2]);
			printf("\n");
			printf("\n");
			printf("-------------------+\n");
			printf("                    O\n ");
			printf("                  / ");
			printf("|");
			printf("W\n");
			printf("\n");
			printf("\n");
			printf("\n");
		}
		else {
			printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");
			printf("(힌트) %s %s %s\n",array[0]->kor[0],array[0]->kor[1],array[0]->kor[2]);
			printf("\n");
			printf("\n");
			printf("-------------------+\n");
			printf("                    O\n ");
			printf("                  / ");
			printf("|");
			printf("W\n");
			printf("                    /\n");
			printf("\n");
			printf("\n");
		}

		for (int j = 0; j < index; j++) {
			printf("%c", rst[j]); // 결과보여주기
		}

		printf("\n");	
		printf("\n");	
		printf("%d번째 시도 : ",try); // 몇번째 입력했는지

		input = getchar(); // 한문자 입력받기
		getchar();

		for (int j = 0; j < index; j++) {	
			if (copy[j] == input) { // 영어에 있으면
				rst[j] = input; // 출력에 넣어주고
				copy[j] = '*'; // 이미 비교한거는 방문표시
				break; 
			}

			if (j == index-1) { // 입력문자가 문자열에 없으면
				error++; // 틀렸음.
			}
		}

		if (strcmp(array[0]->eng,rst) == 0) {// 원본이랑 비교.
			printf("     #########################\n");
			printf("     ### Congratulations!! ###\n");
			printf("     #########################\n");
			printf("\n");
			printf("\n");
			break; 
		}
		system("clear");
		try++; // 한번에 입력에 대한 작동완료. 카운트해줌.
	}
}

void fourth(){

	while(1) {
		printf(">> 영어 단어 암기 프로그램 : 단어장 관리 <<");
		printf("\n");
		printf("1. 새파일 추가하기		2. 새 단어 추가하기\n");	
		printf("3. 단어장 보기			4. 단어 파일 목록보기\n");	
		printf("5. 단어장 관리 종료 \n");
		printf("\n");	
		printf("\n");	
		printf("번호를 입력하세요 : ");

		int control = 0;
		char newdic[5] = ".dic";		
		int filecount = 0;

		filecount = search_dir();
		file* list [filecount];
		file* temp;	

		for (int i = 0; i < filecount; i++) {
			file* node = (file*)malloc(sizeof(file));
			list[i] = node;
		}

		filelist(list);

		for (int i = 0; i < filecount-1; i++) {
			for (int j = 0; j < filecount-i-1; j++) {
				if (strcmp(list[j]->name,list[j+1]->name) > 0 ) {
					temp = list[j];
					list[j] = list[j+1];
					list[j+1] = temp;
				}
			}
		}

		scanf("%d",&control);
		getchar();

		switch (control){
			case 1 :
				system("clear");
				printf(">> 영어 단어 암기 프로그램 : 단어장 관리 : 새파일 추가하기 <<\n");
				printf("\n");

				FILE* newfile;
				char number[7];
				char stop[5] = ".add";

				sprintf(number,"%d",filecount+1);
				strcat(number,".dic");
				newfile = fopen(number,"w");

				if (newfile == NULL) {
					printf("파일을 추가하는데 실패했습니다.");
					printf("\n");
				}

				while (1) {
					char input [110];

					fgets(input,sizeof(input),stdin);
					input[strlen(input)-1] = '\0';

					if (strcmp(input,stop) == 0) { //종료조건입력시 종료
						fclose(newfile);
						break;
					}	
					else{
						fputs(input,newfile);
						fputs("\n",newfile);
					}
				}
				system("clear");

				break;

			case 2 :
				system("clear");
				printf(">> 영어 단어 암기 프로그램 : 단어장 관리 : 새단어 추가하기 <<");
				printf("\n");
				printf("단어를 추가할 파일을 입력해주세요 ex) 1.dic");
				printf("\n");

				char filename [7];
				char end[5] = ".add";
				FILE* fp;

				fgets(filename,sizeof(filename),stdin);
				filename[strlen(filename)-1] = '\0';
				fp = fopen(filename,"a");
				
				system("clear");
				printf(">> 영어 단어 암기 프로그램 : 단어장 관리 : 새단어 추가하기 <<");
				printf("\n");
				printf("단어를 추가할 파일을 입력해주세요 ex) 1.dic");
				printf("\n");

				while (1) {
					char input [110];

					fgets(input,sizeof(input),stdin);
					input[strlen(input)-1] = '\0';

					if (strcmp(input,end) == 0) {
						fclose(fp);
						system("clear");
						break;
					}
					else{
						fputs(input,fp);
						fputs("\n",fp);
					}
				}
				break;

			case 3 :
				system("clear");
				printf(">> 영어 단어 암기 프로그램 : 단어장 관리 : 단어장 보기 <<");
				printf("\n");
				printf("파일명(일차) : ");

				char newdic[4]=".dic";
				char ch;
				FILE* fps;	
				char* readnumber = malloc(sizeof(char)*20);
				
				scanf("%s",readnumber);	
				getchar();
				strcat(readnumber,newdic);
				
				fps = fopen(readnumber,"r");

				if (fps == NULL) {
					printf("파일을 여는데 실패했습니다\n");
					break;
				}

				printf("---- 단어장 -------------\n");

				while (!feof(fps)) {
					fscanf(fps,"%c",&ch);
					printf("%c",ch);
				}

				fclose(fps);
				break;
			case 4:
				printf("\n");
				printf("\n");
				printf("\n");
				printf("-------------단어 파일 목록-----------\n");
				
				int flag = 0;

				for (int i = 0; i < filecount; i++) {
					if (flag == 5) {
						printf("\n");
						flag = 0;
					}
					printf("      %s ",list[i]->name);
					flag++;
					if (i == filecount - 1) {
						printf("\n");
						printf("\n");
						printf("\n");
					}
				}
				break;
			case 5:

				return;
		}
	}
}

int main() {

	char dic[10] = ".dic"; //file양식
	char* number = malloc(sizeof(char)*20); // uesr로부터 입력받은 파일 번호 문자열로
	int mode = 0; // 기능변수
	int sec  = 1; // 플래쉬카드 속도변수
	int sorting_option = 0; // 출력방식변수
	int count = 0; // Count_word(단어갯수를 세는 함수)의 결과를  담을 변수

	Word* head = (Word*)malloc(sizeof(Word)); //main에서 단어연결리스트의 head를 선언. 
	head->next = NULL; // head의 초기화

	while(1) {
		printf(">> 영어 단어 암기 프로그램<<\n");
		printf("\n");
		printf("1. 영어 단어 맞추기	2. 플래쉬 카드\n");
		printf("\n");
		printf("3. 행맨(hangman)       4. 단어장 관리\n");
		printf("\n");
		printf("5. 프로그램 종료\n");
		printf("\n");
		printf("번호를 선택 하세요 : ");
		
		
		scanf("%d",&mode);
		getchar();
		printf("\n");

		if (mode == 2) {
			printf("속도 (초) : ");
			scanf("%d",&sec);
			getchar();
			printf("\n");
		}
		if (mode == 4) {
			system("clear");
			fourth();
		}

		printf("파일명(일차) : ");
		scanf("%s",number);
		getchar();
		
		printf("\n");
		printf("출력방식(알파벳순서대로 : 1 , 무작위 : 2) : ");

		scanf("%d",&sorting_option);
		getchar();	

		strcat(number,dic); //입력받은 숫자를 open하는데 필요한 양식으로 만듬.

		count = count_word(number);//파일이 존재한다면, 파일을 열어 단어갯수를 센다. 그리고 결과 저장.

		makeList(head,count,number); // 단어리스트를 만듬

		Word* array[count];

		sorting(head,array,count,sorting_option); // Word구조체 배열에 정렬 혹은 랜덤으로 단어가 정리되서 튀어나옴. 이제 이걸 각 기능별로 보내서 구현	

		switch (mode){
			case 1 :
				system("clear");
				first(array,count);
				break;
			case 2 :
				system("clear");
				second(array,sec,count);
				break;
			case 3 :
				system("clear");
				third(array);
				break;
			case 5 :
				return 0;
			default :
				system("clear");
				printf("유효한 숫자가 아닙니다. 1 ~ 5만 입력해 주세요.");

		}
	}
}
