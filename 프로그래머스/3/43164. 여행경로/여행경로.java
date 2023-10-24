import java.util.*;

class Solution {
    static List<List<String>> answerList;
    static boolean[] visited;
    
    public String[] solution(String[][] tickets) {
        answerList = new ArrayList<>();
        visited = new boolean[tickets.length];
        
        Arrays.sort(tickets, (a, b) -> {
            if (a[0].equals(b[0])) {
                return a[1].compareTo(b[1]);
            }
            return a[0].compareTo(b[0]);
        });
        
        for (int i = 0; i < tickets.length; i++) {
            if (tickets[i][0].equals("ICN")) {
                List<String> list = new ArrayList<>();
                list.add("ICN");
                visited[i] = true;
                list.add(tickets[i][1]);
                dfs(tickets, i, list);
                visited[i] = false;
            }
        }
        
        // 결과로 반환할 경로 선택 (알파벳 순서가 앞서는 경로)
        Collections.sort(answerList, (a, b) -> {
            for (int i = 0; i < a.size(); i++) {
                int compare = a.get(i).compareTo(b.get(i));
                if (compare != 0) {
                    return compare;
                }
            }
            return 0;
        });

        List<String> answer = answerList.get(0);

        return answer.toArray(new String[answer.size()]);
    }
    
    public void dfs(String[][] tickets, int begin, List<String> list) {
        if (list.size() == tickets.length + 1) {
            answerList.add(new ArrayList<>(list));
            return;
        }
        
        for (int i = 0; i < tickets.length; i++) {
            if (!visited[i] && tickets[i][0].equals(tickets[begin][1])) {
                visited[i] = true;
                list.add(tickets[i][1]);
                dfs(tickets, i, list);
                visited[i] = false;
                list.remove(list.size() - 1); // 백트래킹
            }
        }
    }
}
