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

/* 

시간복잡도 분석  
    LinkedList 삽입/삭제 O(1)

    NxN 크기의 map 
    bfs()는 방문 안한 칸 하나를 시작으로 연결된 영역 모두 탐색
    marked[][]로 중복 방지하여 각 칸을 최대 1회 방문

    그래프를 두번 순회하므로 O(2N^2) -> O(N^2)


static 변수 선언 
    Scope -> 모든 메서드가 접근 가능해 bfs, dfs에서 쉽게 공유 가능 
  */