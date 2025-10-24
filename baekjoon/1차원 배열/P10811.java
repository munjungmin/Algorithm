import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P10811 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int arr[] = new int[N + 1]; // 0~N (1부터 사용)
        for(int i = 0; i <= N; i++){
            arr[i] = i;
        }


        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            int tmp = 0;
            
            for(int j = p; j < q; j++, q--){
                tmp = arr[j];
                arr[j] = arr[q];
                arr[q] = tmp; 
            }
        }

        for(int i = 1; i <= N; i++){
            System.out.print(arr[i] + " ");
        }

    }
}
