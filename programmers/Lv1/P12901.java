// Lv1 12901 2016년
import java.time.*;

class Solution {
    public String solution(int a, int b) {
        return LocalDate.of(2016, a, b).getDayOfWeek().toString().substring(0, 3);        
    }
}
