# 42Seoul-push_swap
### 목표
- 특정 명령어를 사용하는 스택 두 개를 사용하여, 인자로 받은 숫자들을 최소한의 명령어로 정렬하는 프로그램 만들기.
- 이 과제의 학습 목표는 엄격함, C언어 사용, 기본적인 알고리즘 사용이며, 특히나 복잡도([complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms))에 대해 초점을 맞추고 있다.

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
![image](https://user-images.githubusercontent.com/67255013/218249775-49297774-feec-4b82-844d-41949b9d3934.png)
- 명령어 12개를 사용하여 스택 a에 정수를 정렬했다.

## 관련 개념
- 자료구조(Data Structure).
- 알고리즘(Algorithm).
- 시간 복잡도(Time Complexity), 공간 복잡도(Space Complexity).
- 빅오 표기법(Big-O).

## 개발 및 테스트 환경
- Intel CPU 기반 Mac.
- MacOS Version = 12.6.2

## 사용 방법
- make = Mandatory용 실행 파일 생성. (정렬 프로그램 생성)
- make bonus = Bonus용 실행 파일 생성. (정렬되었는지 확인하는 checker 프로그램 생성)

## 정렬 시각화 영상
https://www.youtube.com/watch?v=3TVhgok0Z3s
