import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P10807 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int arr[] = new int[N];

        st = new StringTokenizer(br.readLine());
        int target = Integer.parseInt(br.readLine());
        
        int answer = 0;
        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
            if(target == arr[i]){
                answer++;
            }
        }

        System.out.println(answer);

    }
}
