# 42Seoul-push_swap
## 소개
- push_swap 프로젝트는 매우 간단하고 복잡하지 않은 알고리즘 프로젝트다. : 데이터를 정렬시켜야 한다.
- 정렬시킬 정수들의 모음, 두 개의 스택, 두 스택을 조작하기 위한 명령어들이 있다.
- 목표는 인자로 받은 정수를 정렬하고, 정렬하기 위해 사용된 가장 적은 수의 명령어를 표준 출력하는 push_swap 프로그램을 C언어로 만드는 것이다.
- 쉬울 것 같아?
- 한번 지켜보겠어..

## 목표
- 정렬 알고리즘을 작성하는 것은, 개발자의 여정에서 항상 정말 중요하게 여겨지는 단계이다.
- 이것은 종종 복잡성([complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms))이라는 개념과 처음 마주하게된다.
- 정렬 알고리즘과 복잡성은 면접(job interviews)에서 논의하기 위한 일반적인 질문에 속한다.
- 언젠가는 이 개념들을 알아야하기 때문에, 이 개념들을 공부하기 위한 좋은 과제가 될 것이다.
- 이 과제의 학습 목표는 엄격함, C언어 사용, 기본적인 알고리즘 사용이며, 특히나 복잡성에 대해 초점을 맞추고 있다.
- 값을 정렬하는 것은 간단하지만, 가능한 한 빨리 정렬하는 것은 덜 간단하다.
- 특히 정수 값 구성에 따라 가장 효율적인 정렬 방법이 다를 수 있다.

## Mandatory
### 규칙
- a, b라는 두 개의 ```스택```을 가진다.
- 프로그램 시작시:
  - 스택 a에는 중복되지 않는 정수들이 랜덤하게 포함되어 있다.
  - 스택 b는 비어있다.
- 목표는 스택 a에 정수들을 오름차순으로 정렬하는 것이다.
- 정렬을 위해서 아래와 같은 동작을 사용할 수 있다.
```
sa (swap a) : 스택 a의 맨 위(top) 요소 두 개의 자리를 바꾼다. (만약 요소가 하나뿐이거나 없을 경우 아무런 동작을 하지 않는다.)
sb (swap b) : 스택 b의 맨 위(top) 요소 두 개의 자리를 바꾼다. (만약 요소가 하나뿐이거나 없을 경우 아무런 동작을 하지 않는다.)
ss : sa와 sb를 동시에 수행한다.
---
pa (push a) : 스택 b의 맨 위(top) 요소를 스택 a의 맨 위(top)로 넣는다. (만약 스택 b가 비어있는 경우 아무런 동작을 하지 않는다.)
pb (push b) : 스택 a의 맨 위(top) 요소를 스택 b의 맨 위(top)로 넣는다. (만약 스택 a가 비어있는 경우 아무런 동작을 하지 않는다.)
---
ra (rotate a) : 스택 a의 모든 요소를 위로 한 칸씩 옮긴다. (맨 위(top)의 요소는 맨 아래(bottom)로 옮겨진다.)
rb (rotate b) : 스택 b의 모든 요소를 위로 한 칸씩 옮긴다. (맨 위(top)의 요소는 맨 아래(bottom)로 옮겨진다.)
rr : ra와 rb를 동시에 수행한다.
---
rra (reverse rotate a) : 스택 a의 모든 요소를 아래로 한 칸씩 옮긴다. (맨 밑(bottom)의 요소는 맨 위(top)로 옮겨진다.)
rrb (reverse rotate b) : 스택 b의 모든 요소를 아래로 한 칸씩 옮긴다. (맨 밑(bottom)의 요소는 맨 위(top)로 옮겨진다.)
rrr : rra와 rrb를 동시에 수행한다.
```

### 예시
- 각 명령어들이 어떻게 동작하는지 예시를 보여주기 위해서 정수 몇 개를 정렬해보자.
![image](https://user-images.githubusercontent.com/67255013/218249775-49297774-feec-4b82-844d-41949b9d3934.png)
- 명령어 12개를 사용하여 스택 a에 정수를 정렬했다.
- 넌 더 좋게 만들 수 있겠지?

### 사용 가능한 함수
- read, write, malloc, free, exit
- libft, ft_printf

### 참고 사항
- Makefile로 소스 파일 컴파일하고 리링크 안되도록 만들어야 된다.
- 전역 변수는 사용이 금지 된다.
- push_swap이라는 이름의 프로그램을 작성해야 하며, 프로그램은 처음에 스택 a에 저장될 정수들을 인자로 받아야 한다.
- 첫번 째 인자가 스택의 맨 위(top)로 와야 한다.
- 프로그램은 스택 a에 정수를 정렬하기 위한 가장 적은 수의 명령어 순서를 출력해야 한다.
- 정렬이 완료되었다면, 스택 a의 맨 위(top)에 가장 낮은 숫자가 있어야 한다.
- 출력된 명령어들은 개행 문자('\n')로 나뉘어져야 한다.
- 목표는 가장 적은 수의 명령어를 사용하여 정렬하는 것이다.
- 평가 중에, 프로그램이 찾은 명령어의 개수가 허용된 개수보다 적은지 비교할 것이다.
- 프로그램이 찾은 명령어 개수가 허용된 개수보다 높거나, 정렬이 제대로 되지 않았을 경우 0점이다.
- 어떠한 인자도 받지 않은 경우, 프로그램은 아무 것도 출력하면 안되며 프롬프트를 반환한다.
- 오류 발생시 "Error"를 **표준 에러**로 출력해야 하며, 개행 문자('\n')를 포함해야 한다.
- 오류 발생 예시 : 인자로 받은 값이 정수가 아닌 경우, 인자로 받은 값이 int 자료형의 최대값보다 크거나, 최소값보다 작은 경우(정수 오버플로우), 인자로 받은 값이 중복된 경우.
![image](https://user-images.githubusercontent.com/67255013/218250705-966104ec-aa66-4b02-92d8-93b1331723e2.png)
- 평가를 진행하면, 프로그램을 올바르게 확인하기 위한 바이너리(실행 파일)이 제공되며, 아래와 같이 동작한다.
![image](https://user-images.githubusercontent.com/67255013/218250775-5db007e7-f4e6-42be-97aa-bf4df094f6f0.png)
- 만약 checker_OS 프로그램이 "KO"를 출력할 경우, push_swap이 정수를 정렬하지 않는 명령어들을 생성했음을 의미한다.

## Bonus
- 자신만의 checker 프로그램을 만들어보자.
### 사용 가능한 함수
- read, write, malloc, free, exit
- libft, ft_printf

### 참고 사항
- 스택 a에 들어갈 정수의 목록을 인자로 가지는 checker 라는 이름의 프로그램을 만들어라.
- 첫번 째 숫자가 스택의 맨 위(top)에 있어야 한다.
- 인자가 없으면 아무 것도 출력하지 않고 프로그램을 종료한다.
- checker는 표준 입력으로 개행 문자(\n)가 포함되어 있는 명령어들을 읽는다.
- 모든 명령어들을 읽은 후, 인자를 저장한 스택 a에서 읽은 명령어들을 수행한다.
- 명령어를 모두 수행 후, 스택 a가 정확하게 정렬되어 있고 스택 b가 비어 있으면, "OK"를 개행 문자(\n)와 같이 표준 출력한다.
- 다른 모든 경우에는 "KO"를 개행 문자(\n)와 같이 표준 출력한다.
- 오류 발생시 "Error"를 **표준 에러**로 출력해야 하며, 개행 문자('\n')를 포함해야 한다.
- 오류 발생 예시 : 인자로 받은 값이 정수가 아닌 경우, 인자로 받은 값이 int 자료형의 최대값보다 크거나, 최소값보다 작은 경우(정수 오버플로우), 인자로 받은 값이 중복된 경우, 명령어가 존재하지 않거나 잘못된 형식인 경우.
![image](https://user-images.githubusercontent.com/67255013/218251512-62ba2479-ee6e-468e-9335-17248b7db639.png)
- 제공된 바이너리와 완전히 동일하게 동작하지 않아도 된다.
- 오류를 관리하는 것은 필수이나, 인자를 구문 분석하는 방법은 사용자에게 달려있다.
