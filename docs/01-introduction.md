# 소개

## 셸이란?

셸 (shell)은 운영 체제가 제공하는 서비스를 쉽게 이용할 수 있게 하는 응용 프로그램을 뜻한다. 셸은 `bash` (Bourne Again Shell)나 파워셸 (Windows Powershell)과 같은 CLI (Command-Line Interface) 형태일 수도 있고, 데스크톱 환경 (desktop environment)과 같은 GUI (Graphical User Interface) 형태일 수도 있다.

명령줄 인터페이스 형태의 셸이 주로 제공하는 기능은 다음과 같다.
- **사용자가 입력한 명령어를 읽고, 명령어에 해당하는 프로그램을 실행한다.**
- 프로그램 실행에 사용되는 환경 변수 (environment variable)를 관리한다.
- 명령어의 출력 내용을 다른 명령어의 표준 입력 스트림에 전달하는 파이프 (piping) 기능을 수행한다.
- 변수나 제어문 등으로 조건에 따라 명령어를 실행할 수 있게 하는 셸 스크립팅 언어를 제공한다.

<br>

## POSIX 셸의 실행 주기

1. 셸은 사용자가 명령어를 입력할 때까지 대기한다.
2. 사용자가 "Ctrl + D" (`EOF`)를 입력했을 때는 셸을 종료한다.
3. 명령어가 입력되면, 공백 문자를 기준으로 명령어를 한 단어씩 잘라 배열로 변환한다.
4. 셸은 현재 프로세스를 `fork()`로 복제하여, 새로운 프로세스를 생성한다.
5. `execve()`를 이용해 사용자가 실행하고자 하는 프로그램의 내용을 새로운 프로세스의 메모리 영역에 덮어쓴다.

<br>

## 참고 자료

- [Arpaci-Dusseau, R. H., & Arpaci-Dusseau, A. C. "Operating Systems: Three Easy Pieces (Version 1.10)". Arpaci-Dusseau Books. November, 2023.](https://pages.cs.wisc.edu/~remzi/OSTEP)
- [Randal E. Bryant & David R. O'Hallaron. "Computer Systems: A Programmer's Perspective, 3/E". Pearson. 2016.](https://csapp.cs.cmu.edu)