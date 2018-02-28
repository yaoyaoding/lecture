import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static BigInteger[][] comb = new BigInteger[210][210];

	public static void init( int n ) {
		for( int i = 0; i <= n; i++ )
			for( int j = 0; j <= i; j++ )
				if( j == i || j == 0 )
					comb[i][j] = BigInteger.ONE;
				else
					comb[i][j] = comb[i-1][j-1].add( comb[i-1][j] );
	}
	public static void main( String [] args ) {
		Scanner cin = new Scanner( System.in );
		init(200);
		int n;
		while( cin.hasNext() ) {
			n = cin.nextInt();
			if( n == -1 ) return;
			System.out.printf( "%d\n", comb[n+n][n].subtract( comb[n+n][n-1] ) );
		}
	}
};

