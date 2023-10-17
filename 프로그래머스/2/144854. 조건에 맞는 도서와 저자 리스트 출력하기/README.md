# [level 2] 조건에 맞는 도서와 저자 리스트 출력하기 - 144854 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/144854) 

### 풀이 요약
- 기본적인 inner join 문제였으나, 처음에 join의 조건인 ON~ 구문을 빠뜨려서 틀렸습니다가 나옴. 
  => join on 구문을 꼭 기억할 것!
- DATE 형태의 출력에 대한 주의사항을 고려하지 않아서 틀렸습니다가 나옴.
  => 주의사항 꼭 확인하고, sql문의 경우 출력문의 형태를 꼭 확인하여, 바꾸어줄 컬럼의 이름은 꼭 바꾸어야 한다!
- DATE 포맷의 경우 기본 형태는 '2020-01-02 00:00:00'과 같음.
  => 문제에서 주어진 date 포맷을 '2020-01-02'처럼 변경하기 위해서는 DATE_FORMAT(A.PUBLISHED_DATE, '%Y-%m-%d')을 사용할 수 있음
  => 이 문제에서 내가 꼭 짚고 넘어가야 할 부분이라 할 수 있다!

### 성능 요약

메모리: 0.0 MB, 시간: 0.00 ms

### 구분

코딩테스트 연습 > JOIN

### 채점결과

Empty

### 제출 일자

2023년 10월 2일 14:10:33

### 문제 설명

<p>다음은 어느 한 서점에서 판매중인 도서들의 도서 정보(<code>BOOK</code>), 저자 정보(<code>AUTHOR</code>) 테이블입니다.</p>

<p><code>BOOK</code> 테이블은 각 도서의 정보를 담은 테이블로 아래와 같은 구조로 되어있습니다.</p>
<table class="table">
        <thead><tr>
<th>Column name</th>
<th>Type</th>
<th>Nullable</th>
<th>Description</th>
</tr>
</thead>
        <tbody><tr>
<td>BOOK_ID</td>
<td>INTEGER</td>
<td>FALSE</td>
<td>도서 ID</td>
</tr>
<tr>
<td>CATEGORY</td>
<td>VARCHAR(N)</td>
<td>FALSE</td>
<td>카테고리 (경제, 인문, 소설, 생활, 기술)</td>
</tr>
<tr>
<td>AUTHOR_ID</td>
<td>INTEGER</td>
<td>FALSE</td>
<td>저자 ID</td>
</tr>
<tr>
<td>PRICE</td>
<td>INTEGER</td>
<td>FALSE</td>
<td>판매가 (원)</td>
</tr>
<tr>
<td>PUBLISHED_DATE</td>
<td>DATE</td>
<td>FALSE</td>
<td>출판일</td>
</tr>
</tbody>
      </table>
<p><code>AUTHOR</code> 테이블은 도서의 저자의 정보를 담은 테이블로 아래와 같은 구조로 되어있습니다.</p>
<table class="table">
        <thead><tr>
<th>Column name</th>
<th>Type</th>
<th>Nullable</th>
<th>Description</th>
</tr>
</thead>
        <tbody><tr>
<td>AUTHOR_ID</td>
<td>INTEGER</td>
<td>FALSE</td>
<td>저자 ID</td>
</tr>
<tr>
<td>AUTHOR_NAME</td>
<td>VARCHAR(N)</td>
<td>FALSE</td>
<td>저자명</td>
</tr>
</tbody>
      </table>
<hr>

<h5>문제</h5>

<p><code>'경제'</code> 카테고리에 속하는 도서들의 도서 ID(<code>BOOK_ID</code>), 저자명(<code>AUTHOR_NAME</code>), 출판일(<code>PUBLISHED_DATE</code>) 리스트를 출력하는 SQL문을 작성해주세요. <br>
결과는 출판일을 기준으로 오름차순 정렬해주세요.</p>

<hr>

<h5>예시</h5>

<p>예를 들어 <code>BOOK</code> 테이블과 <code>AUTHOR</code> 테이블이 다음과 같다면</p>
<table class="table">
        <thead><tr>
<th>BOOK_ID</th>
<th>CATEGORY</th>
<th>AUTHOR_ID</th>
<th>PRICE</th>
<th>PUBLISHED_DATE</th>
</tr>
</thead>
        <tbody><tr>
<td>1</td>
<td>인문</td>
<td>1</td>
<td>10000</td>
<td>2020-01-01</td>
</tr>
<tr>
<td>2</td>
<td>경제</td>
<td>1</td>
<td>9000</td>
<td>2021-04-11</td>
</tr>
<tr>
<td>3</td>
<td>경제</td>
<td>2</td>
<td>11000</td>
<td>2021-02-05</td>
</tr>
</tbody>
      </table><table class="table">
        <thead><tr>
<th>AUTHOR_ID</th>
<th>AUTHOR_NAME</th>
</tr>
</thead>
        <tbody><tr>
<td>1</td>
<td>홍길동</td>
</tr>
<tr>
<td>2</td>
<td>김영호</td>
</tr>
</tbody>
      </table>
<p><code>'경제'</code> 카테고리에 속하는 도서는 도서 ID가 2, 3인 도서이고, 출판일을 기준으로 오름차순으로 정렬하면 다음과 같은 결과가 나와야 합니다.</p>
<table class="table">
        <thead><tr>
<th>BOOK_ID</th>
<th>AUTHOR_NAME</th>
<th>PUBLISHED_DATE</th>
</tr>
</thead>
        <tbody><tr>
<td>3</td>
<td>김영호</td>
<td>2021-02-05</td>
</tr>
<tr>
<td>2</td>
<td>홍길동</td>
<td>2021-04-11</td>
</tr>
</tbody>
      </table>
<hr>

<h5>주의사항</h5>

<p><code>PUBLISHED_DATE</code>의 데이트 포맷이 예시와 동일해야 정답처리 됩니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges
