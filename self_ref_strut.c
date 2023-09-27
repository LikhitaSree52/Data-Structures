#include<stdio.h>
struct self
	{
		int a;
		char c;
		struct self *p;
	};
int main()
{
	struct self x;
	x.a=10;
	x.c='A';
	x.p=NULL;
	struct self y;
	y.a=20;
	y.c='B';
	y.p=NULL;
	x.p=&y;
	struct self z;
	z.a=30;
	z.c='C';
	y.p=&z;
	printf("Block 1 : %d and  %c",x.a,x.c);
	printf("\nBlock 2 : %d and  %c",x.p->a,x.p->c);
	printf("\nBlock 3 : %d and  %c",y.p->a,y.p->c);
	printf("\n%d\n%d\n%d",x.p,y.p,z.p);
}
