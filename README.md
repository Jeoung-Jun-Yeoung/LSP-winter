# LSP-winter


2021-winter-vacation-LSP_project_with_soonsil_student




## 2021년 1월 22일

먼저, 2021년 1월 22일 00시10분 우분투 설치가 완료되었습니다.

아래는 공부 내용입니다.

### 리눅스시스템프로그래밍이란?

리눅스 커널이 동작하는 시스템상에서 어플리케이션이 시스템콜이나, 라이브러리콜을 통해 리눅스 커널이 제공하는 기능들을 사용할 수 있는 소프트웨어를 작성하는 것을 말합니다. 




### 환경설정 및 리눅스 익숙해지기



1. gcc는 컴파일을 할때 사용합니다. 먼저 gcc 컴파일 여부를 확인했고, 미설치로 설치를 진행했습니다. 

설치 명령어는 아래와 같습니다.

```
sudo apt install gcc

```

2. 이후 vim설치를 확인했습니다. vim은 코드에디터입니다. 미설치로 설치를 진행했습니다. 

설치 명령어는 아래와 같습니다.

```
sudo apt install vim

```

3. 이후 한/영 키변환과 입력에 대한 ibus를 해결했습니다.

+ 리눅스상에서는 터미널 환경에서 작업을 한다. 


### 현재 진행중인 내용

vimrc를 통한 에디터 세팅중.

### 오늘 진행할 내용

vim으로 C 파일을 만들어 helloword 출력해보기.

### 내일 진행할 내용

본격적으로 영어단어장에 대한 프로그래밍 시작 및 설계


***
***
***
***




## 2021년 1월 23일


### 어제까지 진행한 내용
~~vim으로 C 파일을 만들어 helloword 출력해보기.~~ 완료

### 현재까지 진행한 내용

영어단어장 프로그램 초기화면 설계 아래는 

```

   # include<stdio.h>

   int main(void){
   
   	while(1){
		
    int play_num = 0;
	  int file_num = 0;
	  int play_mode = 0;
   
    printf(" >>영어 단어 암기 프로그램<< \n");
    printf("\n");
	  printf("1.영어 단어 맞추기\n");
     
	  printf("\n");
	  printf("2. 플래쉬 카드 \n");

	  printf("\n");
	  printf("3. 행맨(hangman)\n");
	  
	  printf("\n");
	  printf("4. 단어장 관리\n");
     
	  printf("\n");
	  printf("5. 프로그램 종료\n");
  
          printf("번호를 선택하세요 : ");
	  scanf ("%d", &play_num);
	  printf("%d\n",play_num);


	  printf("파일 번호를 선택하세요 :");
	  scanf("%d", &file_num);
	  printf("%d\n",file_num);

	  printf("출력방식(알파벳 순서대로 :1, 무작위 :2)\n");
	  scanf("%d", &file_num);
          printf("%d\n",play_mode);


	switch(play_num){
		
		case 1 : 
			
		First_Function();

                case 2 :

		Second_Function();

		case 3 :
			
		Third_Function();

		case 4 :

		Fourth_Function();

		case 5 :

			return 0 ;
			
		default : 
			printf("유효한 숫자가 아닙니다. 1 ~ 5만 입력해 주세요");

		}
	}

  
  }


```

### 현재 문제점

1. 일과 병행하니 하루에 학습할 시간이 많지 않아 작업시간이 부족

1. 리눅스상에서 프로그래밍을 처음해보아서, 명령어가 익숙하지 않음

2. vim 적응이 잘 안되는중. vimrc 초기 설정에서 실수해서 vim의 세팅이 몇개만 되어있음.

3. 그래서 간단하게 입출력만 확인하려, 컴파일 하고 실행해보는데도 문법오류로 인해서 수정하는데 시간을 많이 뺏김.

4. 현재는 case문에서 각 함수들을 정의해주지 않아서 그런지 오류가뜸. 


### 진행방향

각각의 기능들을 함수로 만들예정. 그리고 main에서 실행 조건들(프로그램넘버, 모드등)을 int변수로 입력받아서 인자로 각 기능을 담당하는 함수에 넘겨준다.
이후에, 각 함수에서 넘겨진 인자를 바탕으로 기능을 세팅하고 실행. 다시 되돌아오는 방식으로 전체 진행. 


### 예상 문제점

종료전까지 이게 반복이 되야하는데 이에 대한 설계는 while문으로 제어해 놓은 상태. 그러나 아직 정확하게 실행해서 검사해보지 않음.

화면 clear가 필요함 >> 이는 **system("clear");** 로 가능함

filegets, fileopen의 학습이 필요함.


### 앞으로 진행할 내용 24일까지.

1. 사전에 정리된 영단어 file 우분투로 넘기기 


2. file들 프로그램상에서 입출력 해보기 


3. 1번 기능부터 구현해보기 



