
/**
 * @author nellex
 * Created at: 27-Aug-2016 1:42:14 AM
 */

import java.util.*;

public class CF603B {

	/**
	 * @param args
	 */
	
	static long p, k;
	static int next[] = new int[1000005];
	static boolean explore[] = new boolean[1000005];
	
	static void dfs( int x ) {
		if( explore[x] )
			return;
		explore[x] = true;
		
		dfs( next[x] );
	}
	
	static long MOD = (long)(1e9)+7;
		
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner in = new Scanner(System.in);
		p = in.nextInt();
		k = in.nextInt();
		
		if( k == 0 ) {
			long val = 1;
			for( int i = 0; i < p-1; i++ )
				val = ( val * p )%MOD;
			System.out.println(val);
	
			return;
		}
		
		if( k == 1 ) {
			long val = 1;
			for( int i = 0; i < p; i++ )
				val = ( val * p )%MOD;
			System.out.println(val);
			
			return;
		}
		
		for( int i = 0; i < p; i++ )
			next[ (int) ((k*i)%p) ] = i;
		
		Arrays.fill( explore, false );
		
		long ans = 1;
		
		for( int i = 0; i < p; i++ ) {
			if( explore[i] || next[i] == i ) continue;
			dfs(i);
			ans = ( ans * p )%MOD;
		}
		
		System.out.println(ans);
	}

}
