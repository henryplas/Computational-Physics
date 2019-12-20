#include <stdio.h>
#include <math.h>





int main()
{

  int ni;
  int guess;
  int num = 5;

    
  while(1)
    {
      printf("Enter in guess > ");
      ni = scanf("%d",&guess);

      if(guess < num)
	printf("too low, guess again dummy\n");
      else if(guess > num)
	printf("too high, guess again dummy\n");
      else
	{
	  printf("Ding ding champ\n");
	  break;
	}
      
    }

  return(0);

}
