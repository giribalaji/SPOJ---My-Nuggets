    //#include <cstdio>
    #include<stdio.h>
     #define  N  2048
    int n, m[N][N], v[N];
    int max(int a, int b){ return a > b ? a : b; }
    int main(void){
     // int n, m[N][N], v[N];
     int i,a,s,L,e;
	    while(scanf("%d", &n) == 1){
            for(i = 0; i < n; ++i) 
			{
			
			scanf("%d", v + i);
			 m[i][i] = v[i] * n;
			 printf("%d\n",m[i][i]);
        }
			for(a = n - 1, L = 1; L < n; --a, ++L)
                for( s = 0, e = s + L; e < n; ++s, ++e)
                    m[s][e] = max(v[s]*a + m[s+1][e], v[e]*a + m[s][e-1]);
            printf("%d\n", m[0][n-1]);
        }
        return 0;
    }
