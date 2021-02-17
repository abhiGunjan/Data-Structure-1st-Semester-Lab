/*  according to Euclid's remainder algorithm.

               | a  if b = 0.
    gcd(a,b) = |
               | gcd(b,a%b) if b != 0


*/
#include<stdio.h>
int gcd(int x,int y);
int main()
{
    int a,b,gcd0;
    printf("Enter the two integer value to find their GCD: \n");
    scanf("%d %d",&a,&b);
    gcd0 = gcd(a,b);
    printf("GCD of %d & %d is %d.\n",a,b,gcd0);
    return 0;
}
int gcd(int a,int b){
    if(b == 0){
        return a;
    }
    else
    return gcd(b,a%b);

}
