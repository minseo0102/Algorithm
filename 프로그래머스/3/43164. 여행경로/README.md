# [level 3] 여행경로 - 43164 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43164) 

### 풀이 요약
- dfs와 bfs를 섞어 사용해야함
- 그런데 bfs의 경우는 출발이 같을 때 도착 중 사전 순으로 오도록 할 때 사용하는 것이라, tickets를 사전순으로 정렬하는 것으로써 해결할 수 있음.
- 이때 람다식으로 정렬 기준을 설정하였음.
- 가능한 경로에 대한 여러 루트를 저장해 둘 이중 리스트를 선언해두고, 각 루트를 도는 리스트의 크기가 tickets의 크기+1과 같으면 다 돈 것이므로 이중 리스트에 저장함
- dfs의 경우 방문한 노드에 visited를 true로 하고 재귀호출한 후 다시 visited를 false로 설정. 이때 list에도 넣었던 것을 빼주어야 함.
- 여러가지의 경로가 이중 리스트에 저장되면, 리스트를 또 사전 순으로 정렬하고, 그 중 첫번째 리스트가 최종 답안이 되므로, 첫번째 리스트를 anwser에 옮겨줌

### 성능 요약

메모리: 77.3 MB, 시간: 0.79 ms

### 구분

코딩테스트 연습 > 깊이／너비 우선 탐색（DFS／BFS）

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2023년 10월 2일 20:20:14

### 문제 설명

<p>주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.</p>

<p>항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>모든 공항은 알파벳 대문자 3글자로 이루어집니다.</li>
<li>주어진 공항 수는 3개 이상 10,000개 이하입니다.</li>
<li>tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.</li>
<li>주어진 항공권은 모두 사용해야 합니다.</li>
<li>만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.</li>
<li>모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>tickets</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>[["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]</td>
<td>["ICN", "JFK", "HND", "IAD"]</td>
</tr>
<tr>
<td>[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]</td>
<td>["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>예제 #1</p>

<p>["ICN", "JFK", "HND", "IAD"] 순으로 방문할 수 있습니다.</p>

<p>예제 #2</p>

<p>["ICN", "SFO", "ATL", "ICN", "ATL", "SFO"] 순으로 방문할 수도 있지만 ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"] 가 알파벳 순으로 앞섭니다.</p>

<h5>문제가 잘 안풀린다면😢</h5>

<p>힌트가 필요한가요? [코딩테스트 연습 힌트 모음집]으로 오세요! → <a href="https://school.programmers.co.kr/learn/courses/14743?itm_content=lesson43164" target="_blank" rel="noopener">클릭</a></p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges
