import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        int now = 0;  // 현재 완료 시간
        int wait = 0; // 총 대기 시간

        // jobs 배열을 요청 시간(int[i][0])을 기준으로 오름차순 정렬하되, 동일한 요청 시간인 경우 소요 시간(int[i][1])을 기준으로 오름차순 정렬
        Arrays.sort(jobs, new Comparator<int[]>() {
            @Override
            public int compare(int[] job1, int[] job2) {
                int diff = job1[0] - job2[0];
                if (diff != 0) {
                    return diff;
                } else {
                    return job1[1] - job2[1];
                }
            }
        });

        for (int i = 0; i < jobs.length; i++) {
            while (!minHeap.isEmpty() && now < jobs[i][0]) {
                int[] top = minHeap.poll();
                now += top[1];
                wait += now - top[0];
            }
            now = Math.max(now, jobs[i][0]);
            minHeap.add(jobs[i]);
        }

        while (!minHeap.isEmpty()) {
            int[] top = minHeap.poll();
            now += top[1];
            wait += now - top[0];
        }

        answer = wait / jobs.length;

        return answer;
    }
}
