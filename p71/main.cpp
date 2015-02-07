 #include <stdio.h>
 main(){ long long m, n; long long bestm = 0, bestn = 1; for( n=1 ; n<=1000000 ; n++ ){ m = (n*3-1)/7; if( m*bestn > n*bestm ){ bestm = m; bestn = n; } } printf("%lld/%lld\n", bestm, bestn); }
