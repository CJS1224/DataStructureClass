#include<stdio.h>
#include<string.h>
#include<conio.h>



char *r(char *str)
{
char *front = malloc(sizeof(char) * 1000), *end = malloc(sizeof(char) * 1000);
char *target = malloc(sizeof(char) * 1000);
char *ans = malloc(sizeof(char) * 1000);
int l, j, k, i, c;
char *temp;
l = strlen(str) / 2;
while(l > 0)
{
for(i = 0; i + l * 2 - 1 < strlen(str); i ++)
{
strncpy(target, str + i, l);
target[l] = '\0';
//printf("%s\n", target);
temp = str + l + i;
c = 1;
while(strncmp(target, temp, l) == 0)
{
c ++;
temp += l;
}
if(c > 1)
{
strncpy(front, str, i);
strcpy(front, r(front));
front[i] = '\0';
char buf[100];
strcpy(buf, r(target));
char *a = buf;
int base = 0;
while((*a + 2) / 10 == 5)
{
base = base * 10 + *a - '0';
a ++;
}
if(*a == '[' && buf[strlen(buf) - 1] == ']')
{
c = c * base;
strcpy(target, a + 1);
target[strlen(target) - 1] = '\0';
}
strcpy(end, temp);
strcpy(end, r(end));
//printf("%d\n", c);
//printf("[%s]\n[%s]\n", front, end);
sprintf(ans, "%s%d[%s]%s", front, c, target, end);
//printf("%s,%s,%s,%s\n", front, end, target, ans);
//getch();
return ans;
}
}
l --;
}
strcpy(ans, str);
return ans;
}



void p(char *str)
{



}



int main()
{
char str[1000];
scanf("%s", str);
printf("%s", r(str));
}
