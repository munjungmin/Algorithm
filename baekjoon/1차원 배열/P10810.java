import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P10810 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        int arr[] = new int[N + 1];
        for(int a = 0; a < M; a++){
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            for(int b = i; b <= j; b++){
                arr[b] = k;
            }
        }

        for(int i = 1; i < N+1; i++){
            System.out.print(arr[i] + " ");
        }
    }
    
}
