# [level 2] 타겟 넘버 - 43165 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43165?language=cpp) 

### 풀이 요약
-DFS를 이용하여 풀이함.
-재귀적으로 SOLUTION함수를 호출하도록 구현하였음.
-한 분기를 끝까지 탐색했을 때 조건에 해당하면 1을 리턴하여, 해당 분기가 타겟 넘버를 만드는 하나의 방식임을 알 수 있음.
-SOLUTION함수에서 NUMBERS의 끝에있는 수부터 접근해서 TARGET에 해당 값을 더했을 때와 뺐을 때를 재귀적으로 계산하도록 하고, 끝에 가서 모든 연산을 했을 때 TARGET이 0이 되면 해당 분기가 타겟 넘버를 만드는 하나의 방식임을 확인하고, 1을 반환하도록 하였음.
-재귀적으로 호출했기 때문에 각각의 분기에서 조건을 만족하여 반환된 1씩 더해지면, 최종으로 리턴되는 ANSWER가 타겟 넘버를 만드는 모든 가지의 수가 될 수 있음.
-dfs를 활용한 함수의 재귀적 호출이, 테스트 케이스 1,2에서는 실행시간이 다소 높게 나왔는데, 입력데이터가 커서 시간복잡도는 상승한 것 같음.

### 성능 요약

메모리: 4.14 MB, 시간: 0.29 ms

### 구분

코딩테스트 연습 > 깊이／너비 우선 탐색（DFS／BFS）

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2023년 10월 2일 16:19:34

### 문제 설명

<p>n개의 음이 아닌 정수들이 있습니다. 이 정수들을 순서를 바꾸지 않고 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.</p>
<div class="highlight"><pre class="codehilite"><code>-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
</code></pre></div>
<p>사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>주어지는 숫자의 개수는 2개 이상 20개 이하입니다.</li>
<li>각 숫자는 1 이상 50 이하인 자연수입니다.</li>
<li>타겟 넘버는 1 이상 1000 이하인 자연수입니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>numbers</th>
<th>target</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>[1, 1, 1, 1, 1]</td>
<td>3</td>
<td>5</td>
</tr>
<tr>
<td>[4, 1, 2, 1]</td>
<td>4</td>
<td>2</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong></p>

<p>문제 예시와 같습니다.</p>

<p><strong>입출력 예 #2</strong></p>
<div class="highlight"><pre class="codehilite"><code>+4+1-2+1 = 4
+4-1+2-1 = 4
</code></pre></div>
<ul>
<li>총 2가지 방법이 있으므로, 2를 return 합니다.</li>
</ul>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges
