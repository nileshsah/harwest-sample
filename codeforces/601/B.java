/**
 * @author nellex
 * Created at: 26-Aug-2016 1:52:23 PM
 */

import java.util.Scanner;
import java.util.Stack;

public class CF601B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int q = in.nextInt();
		
		int v[] = new int[n+1];
		
		for( int i = 0; i < n; i++ )
			v[i] = in.nextInt();
		
		int diff[] = new int[n+1];
		
		for( int i = 1; i < n; i++ )
			diff[i] = Math.abs(v[i]-v[i-1]);
				
		int R[] = new int[n+1];
		int L[] = new int[n+1];
		
		Stack<Integer> st = new Stack<Integer>();
		
		diff[0] = diff[n] = Integer.MAX_VALUE;
				
		for( int i = 1; i <= n; i++ ) {
			while( !st.empty() && diff[st.peek()] < diff[i] ) {
				R[st.peek()] = i-1;
				st.pop();
			}
			st.push(i);
		}
		
		st.clear();
		
		for( int i = n-1; i >= 0; i-- ) {
			while( !st.empty() && diff[st.peek()] <= diff[i] ) {
				L[st.peek()] = i+1;
				st.pop();
			}
			st.push(i);
		}
				
		while( q-- > 0 ) {
			int l = in.nextInt();
			int r = in.nextInt();
			
			long ans = 0;
			
			for( int i = l; i < r; i++ )
				ans += diff[i] * (long)( i - Math.max(l, L[i]) + 1 ) * (long)( Math.min(r-1, R[i]) - i + 1);
			
			System.out.println(ans);
		}
		
		
	}
	

}
