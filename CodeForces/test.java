
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Three {
	public static void main(String[] args) {
		InputReader in = new InputReader();
		PrintWriter out = new PrintWriter(System.out);
		Task solver = new Task();
		solver.solve(in, out);
		out.close();
	}

	static class Task {
		public void solve(InputReader in, PrintWriter out) {
			int n=in.nextInt();
			int m=in.nextInt();
			int[] cities=new int[n];
			TreeSet<Integer> set=new TreeSet<Integer>();
			
			int temp, r=0, a, b, diffa, diffb;
			
			for(int i=0; i<n; i++){
				cities[i]=in.nextInt();
			}
			
			for(int i=0; i<m; i++){
				temp=in.nextInt();
				set.add(temp);
			}
			
			for(int i=0; i<n; i++){
				temp=cities[i];
				try{
					a=set.floor(temp);
				}
				catch(java.lang.NullPointerException e){
					b=set.ceiling(temp);
					diffb=Math.abs(b-temp);
					if(diffb>r) r=diffb;
					continue;
				}
				
				diffa=Math.abs(a-temp);
				try{
					b=set.ceiling(temp);
				}
				catch(java.lang.NullPointerException e){
					if(diffa>r) r=diffa;
					continue;
				}
				diffb=Math.abs(b-temp);
				
				if(diffb>diffa){
					if(diffa>r) r=diffa;
				}
				else{
					if(diffb>r) r=diffb;
				}

			}
			
			out.println(r);
		}
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader() {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}