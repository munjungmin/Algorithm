import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P3052 {
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int arr[] = new int[42]; // 0~41

        for(int i = 0; i < 10; i++){
            int k = Integer.parseInt(br.readLine());
            int mod = k % 42;

            arr[mod]++;
        }

        int answer = 0;
        for(int i = 0; i < 42; i++){
            if(arr[i] != 0){
                answer++;
            }
        }

        System.out.println(answer);
    }
}
