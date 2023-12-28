# [D3] [S/W 문제해결 기본] 1일차 - View - 1206 

[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh) 

### 풀이 요약
-일단 각 테스트 케이스 마다 건물의 높이를 입력받아 arr 벡터에 넣어준다.
- 3번째 건물부터 기준으로 앞 뒤로 2개씩 건물의 높이를 비교해서, 가장 큰 건물인지 확인한다.
- 기준이 되는 건물이 가장 크다면, 나머지 4개 중 가장 큰 건물과 비교해서 그 차이를 구하고, 그 차이는 그 건물에서 view를 확보할 수 있는 세대의 개수이다.
- 따라서 그 값을 누적한 값이 한 테스트케이스에서의 답이 된다.
  
### 성능 요약

메모리: 13,380 KB, 시간: 8 ms, 코드길이: 2,305 Bytes

### 제출 일자

2023-12-28 18:27



> 출처: SW Expert Academy, https://swexpertacademy.com/main/code/problem/problemList.do
