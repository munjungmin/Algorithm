import java.util.*;
import java.io.*;

public class P10026_2 {
    static char[][] map;
    static char[][] map2;
    static boolean[][] marked;
    static int N;
    static int[] resutl = {0, 0};
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static void bfs(int x, int y, char[][] maps){
        Queue<int []> q = new LinkedList<>();
        q.add(new int[]{x, y}); //map 좌표 
        marked[x][y] = true;

        while(!q.isEmpty()){
            int[] cur = q.poll();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];
                
                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if(marked[nx][ny]) continue;
                if(maps[x][y] != maps[nx][ny]) continue;

                q.add(new int[]{nx, ny});
                marked[nx][ny] = true;
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new char[N][N];
        map2 = new char[N][N];
        marked = new boolean[N][N];

        for(int i = 0; i < N; i++){
            map[i] = br.readLine().toCharArray();

            for(int j = 0; j < N; j++){
                if(map[i][j] == 'R') map2[i][j] = 'G';
                else map2[i][j] = map[i][j];
            }
        }

        
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!marked[i][j]){
                    bfs(i, j, map);
                    cnt++;
                }
            }
        }

        int cnt2 = 0;
        marked = new boolean[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!marked[i][j]){
                    bfs(i, j, map2);
                    cnt2++;
                }
            }
        }

        System.out.println(cnt + " " + cnt2);
    }
}
