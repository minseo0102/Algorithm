# [D3] [S/W 문제해결 기본] 1일차 - Flatten - 1208 

[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV139KOaABgCFAYh) 

### 풀이 요약
- 상자의 높이를 저장한 벡터를 한번 turn을 돌때마다 정렬한다.
- 그럼 가장 앞에 있는 요소는 가장 작고, 마지막에 있는 요소는 가장 크다.
- 이 두 값을 비교했을 때 차이가 1이하이면, 더이상 옮길 필요가 없으므로 , 이 값을 return하도록 한다.
- 그렇지 않다면 가장 큰 값은 1줄이고, 가장 작은값은 1 늘린다.
- 다음 턴에서는 이 결과를 다시 오름차순 정렬하여 과정을 반복하면 된다.
  
### 성능 요약

메모리: 13,548 KB, 시간: 64 ms, 코드길이: 627 Bytes

### 제출 일자

2023-12-30 21:27



> 출처: SW Expert Academy, https://swexpertacademy.com/main/code/problem/problemList.do
