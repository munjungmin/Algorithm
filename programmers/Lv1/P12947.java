class Solution {
    public boolean solution(int x) {

        int sum = 0;
        int x2 = x;
        while(x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return (x2 % sum) == 0;

    }
}
