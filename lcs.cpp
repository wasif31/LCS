#include<bits/stdc++.h>
#include<string.h>
#define maxx 8010
using namespace std ;

int LCS(char x[], char y[], int xLength, int yLength)
{
    int matrix[xLength+1][yLength+1] ;
    int i = 0, j = 0;
    for(i=0;i<=xLength;i++)
    {
        for(j=0;j<=yLength;j++)
        {
            if(i ==0 || j == 0)
            {
                matrix[i][j] = 0 ;
            }
            else if(x[i-1] == y[j-1])
            {
                matrix[i][j] = matrix[i-1][j-1] + 1 ;
            }
            else
            {
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]) ;
            }
        }
    }
    int lcsLength = matrix[xLength][yLength] ;
    int index = lcsLength ;

    i = xLength ;
    j = yLength ;

    char lcsString[lcsLength] ;

    while(i>0 && j>0)
    {
        if(x[i-1] == y[j-1])
        {
            lcsString[index-1] = x[i-1] ;
            i-- ;
            j-- ;
            index-- ;
        }
        else if(matrix[i-1][j] > matrix[i][j-1])
        {
            i-- ;
        }
        else j-- ;
    }

    i = 0 ;

    for(i=0;i<lcsLength;i++)
    {

    }


    return lcsLength ;
}


int main()
{

 int n;

 char x[maxx];
 char y[maxx];

   cin>>n;
   cin>>x;


   strcpy(y, x) ;
    reverse(y, y+n) ;
    int ans= n-LCS(x, y, n, n) ;
    cout<<ans<<endl ;

    return 0 ;
}
