# LSP-winter


2021-winter-vacation-LSP_project_with_soongsil_student




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


***
***
***
***




## 2021년 1월 24일


### 어제까지 진행한 내용

화면 기본설계 그러나, 문제점이 많아서 오늘 중점적으로 화면 기본을 다시 설계함.

### 오늘 해야할 내용

~~1. 사전에 정리된 영단어 file 우분투로 넘기기~~ 완료

2. file들 프로그램상에서 입출력 해보기 >진행중

3. 1번 기능부터 구현해보기 >진행중


### 오늘 작업한 내용


![img1](https://user-images.githubusercontent.com/59688981/105626500-58dc1380-5e73-11eb-8a84-87623559406e.JPG)


어제 작성한 code를 다시 실행했을때 모습이다. 명세와 디자인이 다른 부분도 있지만, 파일을 번호로 선택했을때 \n되어서 출력 되는등 문제점이 보임.

![img2](https://user-images.githubusercontent.com/59688981/105626501-5a0d4080-5e73-11eb-9fa1-f6c894101add.JPG)

아래와 같이 수정해 가면서 틀을 다시 잡아가는 과정을 거침.

![img3](https://user-images.githubusercontent.com/59688981/105626503-5aa5d700-5e73-11eb-9369-f245ce52851e.JPG)

최종적으로 위와 같이 디자인을 했습니다.

이제는 각 번호별로 고른 기능들로 넘어가서 기능이 작동하면 되는 상황.

가장 먼저 구현하려한 기능은 __영어단어 맞추기 기능__

중요한 점은 파일 입출력이 기본적으로 되야한다. 

### 파일 입출력의 관한 공부

https://dojang.io/mod/page/view.php?id=610

코딩도장을 통해 파일입출력과 관련된 기본 학습을 함.

파일을 입출력 하려면 알아야하는 것

1. 파일의 위치를 포인터로 만들어서 기억
2. 파일을 열고
3. 파일을 입력하거나, 출력
4. 파일 닫음	

+ 추가적으로 system(clear);는 window상에서만 작동하는 기능. 화면 클리어기능은 표준이 없기에 운영체제마다 다르기 때문이다. 그런데 주된 클리어 내용은 윈도우중심으로 정보가 많아서 리눅스상에서 console에 해당하는 화면을 어떻게 클리어할지 더 알아봐야 할것 같음.


### 현재 진행 내용

![img4](https://user-images.githubusercontent.com/59688981/105626504-5d083100-5e73-11eb-9f5f-38f73380e189.JPG)

위를 보면 __apple 사과__ 출력을 확인 할 수 있음. 단어를 화면에 띄우는것까지 성공함.


### 앞으로 진행할 내용

일단 1.dic파일에 모든 단어들을 콘솔에 띄워보아야함. 현재는 한개만 띄워둔 상황.

그 이후 파일에서 읽어온 단어들을 linked_list를 통해 다뤄서 영어단어맞추기 기능을 구현할 예정. 

어떻게 할것인가? 

>> 단어를 담는 buffer의 문제임을 확인했음. file크기를 구하는 방법 공부중 이를 통해 파일 전체크기를 구해서 한번에 띄운후, 자료구조 처리를 하는 과정을 거칠 예정


## 2021년 1월 25일



### 현재 진행 내용

1. ui를 명세와 똑같이 변경 완료.

2. 1.dic의 전체 내용을 화면에 출력완료.

3. 이제 파일을 읽어서 출력하는것까지 완성했으니, 연결리스트로 만들면 되는 상황.


### 고찰

1.dic자료들을 전체 출력하는것까지는 성공함.
