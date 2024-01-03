# [D3] [S/W 문제해결 기본] 2일차 - Sum - 1209 

[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV13_BWKACUCFAYh) 

### 풀이 요약
- 100*100의 2차원 배열에 굳이 값을 저장하지 않고도 구할 수 있다.
- 입력을 받으면서, 동시에 row합, col합, 오른쪽 대각선 합, 왼쪽 대각선 합을 구하였다.
- row는 각 row를 입력 받고 난 뒤에 현재의 max값과 비교해서 합이 더 큰 쪽을 max로 갖는다.
- col은 크기가 100인 배열을 하나 선언해서, 입력 시 현재의 열번호에 해당 입력 값을 누적하도록 하였다. 그래서 2중 for문이 끝나고 나서는 100번 순회하여 max값을 찾는다.
- 양쪽 대각선 값은, 행과 열이 같으면 rcross에, 행과 열을 더한 값이 99이면 lcross에 저장하도록 하였다.
- 그리고 마찬가지로 두 값 중 max를 구하고, 이를 현재의 max와 비교해 갱신하도록 한다.
- 최종 max를 출력한다.
  
### 성능 요약

메모리: 13,540 KB, 시간: 15 ms, 코드길이: 727 Bytes

### 제출 일자

2024-01-03 23:18



> 출처: SW Expert Academy, https://swexpertacademy.com/main/code/problem/problemList.do
