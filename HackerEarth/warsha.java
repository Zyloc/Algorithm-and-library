import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
 
class Test {
    static int vertex,edges,src,money;
    static LinkedList<Edge> adj[];
    static ArrayList<Integer> order;
    static long[] distance;
    public static void main(String[] args) {
        FastReader in = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = in.nextInt();
        while (t-- > 0) {
            vertex = in.nextInt();
            edges = in.nextInt();
            adj = new LinkedList[vertex+1];
            for(int i=1;i<=vertex;++i)
                adj[i] = new LinkedList<>();
            for(int i=1;i<=edges;++i){
                int a = in.nextInt();
                int b = in.nextInt();
                int c = in.nextInt();
                adj[a].add(new Edge(b,c));
            }
            src = in.nextInt();
            money = in.nextInt();
            order = new ArrayList<>();
            topologicalSort();
//            for(int i:order)
//                out.print(i+" ");
//            out.println();
            evaluate();
            //distance[0] = Long.MAX_VALUE;
//            for(int i=1;i<=vertex;++i)
//                out.print(distance[i]+" ");
//            out.println();
            Arrays.sort(distance);
            int count=0;
            for(int i=0;i<=vertex;i++) {
                if(money>=distance[i] && distance[i]!=1e17){
                    money-=distance[i];
                    ++count;
                }
                else
                    break;
            }
            out.println(count-1);
        }
        out.close();
    }
 
    static void evaluate(){
        distance = new long[vertex+1];
        Arrays.fill(distance,(long)1e17);
        distance[src] = 0;
        for(int current:order){
            Iterator<Edge> iterator = adj[current].iterator();
            while(iterator.hasNext()){
                Edge nextEdge = iterator.next();
                distance[nextEdge.dest] = Math.min(distance[nextEdge.dest],distance[current]+(long)nextEdge.weight);
            }
        }
    }
 
    static void topologicalSort(){
        LinkedList<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[vertex+1];
        int[] in_degree = new int[vertex+1];
        for(int i=1;i<=vertex;i++) {
            Iterator<Edge> itr = adj[i].iterator();
            while (itr.hasNext()) {
                Edge j = itr.next();
                in_degree[j.dest]+=1;
            }
        }
        for(int i=1;i<=vertex;i++) {
            if (in_degree[i] == 0) {
                queue.add(i);
                visited[i] = true;
            }
        }
        while (!queue.isEmpty()) {
            int vertex = queue.poll();
            order.add(vertex);
            Iterator<Edge> itr = adj[vertex].iterator();
            while (itr.hasNext()) {
                Edge next = itr.next();
                in_degree[next.dest]-=1;
                if(in_degree[next.dest]==0){
                    queue.add(next.dest);
                    //visited[next.dest]=true;
                }
            }
        }
    }
 
    static class Edge{
        int dest,weight;
        Edge(int dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }
    }
 
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}