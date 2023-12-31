# [Silver III] 숫자 정사각형 - 1051 

[문제 링크](https://www.acmicpc.net/problem/1051) 

### 풀이 요약
- 3중 for문을 이용하였다.
- 일단 모든 값에 대해 순회한다음, 정사각형이 될수있는 모든 크기를 고려해보면서, 배열의 유효범위를 살피고, 유효하다면 꼭지점의 값이 동일한지 확인했다
- 동일하다면 현재 최대 변의 수를 가지는 answer와 비교하여 더 큰 값으로 answer를 갱신한다
- 최종 answer값을 제곱한 값으로 출력하여 정사각형의 크기를 구한다.

### 성능 요약

메모리: 2156 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 구현

### 제출 일자

2023년 11월 19일 17:09:59

### 문제 설명

<p>N×M크기의 직사각형이 있다. 각 칸에는 한 자리 숫자가 적혀 있다. 이 직사각형에서 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오. 이때, 정사각형은 행 또는 열에 평행해야 한다.</p>

### 입력 

 <p>첫째 줄에 N과 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 수가 주어진다.</p>

### 출력 

 <p>첫째 줄에 정답 정사각형의 크기를 출력한다.</p>

