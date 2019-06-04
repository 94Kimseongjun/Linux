#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
  int i;
  double j;
  char *bug = NULL;
  bug = (char *)calloc(3, sizeof(char));


  /* 다음은 i/2 + i 의 값을 출력 시키는 문이다.       */
  /* i 가 1 이면, j 는 1.5 가 되도록 짠 것이다.       */
  /* 그러나 실제로 그렇지 않다.                       */

  for (i = 0; i < 5; i++)
  {
    j = i / 2 + i;
    printf(" j is %lf \n", j);
  }

  /* 다음은 bug 변수에 hi를 copy하려는 것이다.          */
  /* 변수명 bug에서 느끼겠지만, 일부려 bug를 만들었다.  */
  /* 무엇일까 ?                                         */

  strcpy(bug, "hi");
  printf("bug is %s \n", bug);

  return 0;
}
