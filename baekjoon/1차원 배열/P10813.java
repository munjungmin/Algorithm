import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P10813 {
    
    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int arr[] = new int[N+1];
        for(int i = 0; i <= N; i++){
            arr[i] = i;
        }

        int tmp = 0;
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());

            tmp = arr[k];
            arr[k] = arr[j];
            arr[j] = tmp;
        }

        for(int i = 1; i <= N; i++){
            System.out.print(arr[i] + " ");
        }
    }
}
