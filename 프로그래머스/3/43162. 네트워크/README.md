# [level 3] 네트워크 - 43162 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43162) 

### 풀이 요약 추가
- ArrayList로 0부터 n-1까지의 값을 넣어두고, 방문한 노드는 삭제하는식으로 함. 이 list가 빌 때까지 방문을 진행함
- 스택에는 첫 방문한 노드에 대해서 이어지는 노드를 넣고, 스택에서 top에 있는 노드에서 또 방문할 수 있는 노드를 확인함. top으로 뺄 때마다 list에서는 방문한 노드로써 해당 노드를 삭제하도록 함.
- 자바 문법 때문에, 애먹음. 특히 ArrayList의 메서드 중 remove가 두개 있는데, 하나는 인덱스로 삭제하는 방식, 하나는 Object로(int의 경우 Integer 객체 타입으로 바꾸어)삭제하는 방식이라, 잘 구분하여 사용해야함. 처음에는 이것 때문에 인덱스 범위 오류가 나서 1시간 가까이 오류를 해결하는데 시간을 씀.
### 성능 요약

메모리: 73.3 MB, 시간: 1.33 ms

### 구분

코딩테스트 연습 > 깊이／너비 우선 탐색（DFS／BFS）

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2023년 10월 0일 0:26:50

### 문제 설명

<p>네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다. 예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다. 따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.</p>

<p>컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 네트워크의 개수를 return 하도록 solution 함수를 작성하시오.</p>

<h5>제한사항</h5>

<ul>
<li>컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.</li>
<li>각 컴퓨터는 0부터 <code>n-1</code>인 정수로 표현합니다.</li>
<li>i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.</li>
<li>computer[i][i]는 항상 1입니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>n</th>
<th>computers</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>3</td>
<td>[[1, 1, 0], [1, 1, 0], [0, 0, 1]]</td>
<td>2</td>
</tr>
<tr>
<td>3</td>
<td>[[1, 1, 0], [1, 1, 1], [0, 1, 1]]</td>
<td>1</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>예제 #1<br>
아래와 같이 2개의 네트워크가 있습니다.<br>
  <img src="https://grepp-programmers.s3.amazonaws.com/files/ybm/5b61d6ca97/cc1e7816-b6d7-4649-98e0-e95ea2007fd7.png" title="" alt="image0.png"></p>

<p>예제 #2<br>
아래와 같이 1개의 네트워크가 있습니다.<br>
  <img src="https://grepp-programmers.s3.amazonaws.com/files/ybm/7554746da2/edb61632-59f4-4799-9154-de9ca98c9e55.png" title="" alt="image1.png"></p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges
