# [level 3] 단어 변환 - 43163 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43163) 

### 필기 요약
- dfs를 사용한다.
- 방문한 노드에 대한 기록을 위해 boolean타입의 배열 visited를 선언한다.
- visited는 main안에서 words에 대한 첫 방문을 할 때 새로 동적 생성한다.
- begin과 words에 있는 단어 하나하나에 대해 비교하면서 글자가 하나만 차이나는지를 확인할 수 있는 canChange라는 함수를 선언
- dfs 함수를 선언 .
- dfs 함수내에서는 for문을 돌면서 방문한 노드인지를 확인하고, 한글자 차이인지를 확인한다. 그안에서 dfs를 재귀적으로 호출한다.
- 중요한 점은, dfs를 재귀 호출 할때, 하기 전 visited에 방문했음을 표시하고, dfs를 돌고 난 후에는, 다시 이전 단계로 돌아와서 다른 루트를 탐색하기 위해 visited를 풀어주는 단계가 꼭 필요하다. 아주 중요한 단계이다.
- class의 solution함수 전에 static 전역으로 answer와 visited, list를 생성해주었다. 이는 solution함수를 포함한, dfs랑 canChange함수에서 현황을 그대로 활용하기 위함이다.
- Integer.MAX_VALUE는 int타입의 최대 값을 불러오고, answer는 이렇게 시작해서, 총 횟수랑 비교하여 min값인 것을 선택하게 하기 위함이다.
    
### 성능 요약

메모리: 77.4 MB, 시간: 0.10 ms

### 구분

코딩테스트 연습 > 깊이／너비 우선 탐색（DFS／BFS）

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2023년 10월 1일 23:51:53

### 문제 설명

<p>두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.</p>
<div class="highlight"><pre class="codehilite"><code>1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
</code></pre></div>
<p>예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면 "hit" -&gt; "hot" -&gt; "dot" -&gt; "dog" -&gt; "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.</p>

<p>두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>각 단어는 알파벳 소문자로만 이루어져 있습니다.</li>
<li>각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.</li>
<li>words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.</li>
<li>begin과 target은 같지 않습니다.</li>
<li>변환할 수 없는 경우에는 0를 return 합니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>begin</th>
<th>target</th>
<th>words</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>"hit"</td>
<td>"cog"</td>
<td>["hot", "dot", "dog", "lot", "log", "cog"]</td>
<td>4</td>
</tr>
<tr>
<td>"hit"</td>
<td>"cog"</td>
<td>["hot", "dot", "dog", "lot", "log"]</td>
<td>0</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>예제 #1<br>
문제에 나온 예와 같습니다.</p>

<p>예제 #2<br>
target인 "cog"는 words 안에 없기 때문에 변환할 수 없습니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges
