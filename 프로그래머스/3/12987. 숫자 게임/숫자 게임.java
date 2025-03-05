import java.util.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        List<Integer> aList = new ArrayList<>();
        List<Integer> bList = new ArrayList<>();
        for (int i : A) {
            aList.add(i);
        }
        for (int i : B) {
            bList.add(i);
        }
        
        for (int i = 0, aCnt = 0; i < bList.size(); i++) {
            if (aList.get(aCnt) < bList.get(i)) {
                answer++;
                aCnt++;
            }
        }
        
        return answer;
    }
}