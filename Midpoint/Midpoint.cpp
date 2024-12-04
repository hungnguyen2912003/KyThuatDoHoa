#include<stdio.h>
#include<graphics.h>
//Ve duong thang A(20,30), B(120,80) MidPoint
//Ax+By+C
void midpoint1(int xa, int ya, int xb, int yb, int color){
	int x = xa;
	int y = ya;
	int A = yb - ya;	//A=dy
	int B = -(xb-xa);	//B=-dx
	float M = (float)A + B/2;
	for(x=xa;x<=xb;x++){	//m<1, xa<xb => xsau = xtruoc + 1
		printf("x = %d, y=%d, M=%.1f", x,y,M);
		putpixel(x,y,color);
		if(M<0){
			M=M+A;
			y=y;		//ysau = ytruoc
		}		
		else{
			M=M+A+B;
			y++;		//ysau = ytruoc + 1
		}
	}
}


// A(20,30) B(120,80)
void mid1(int xa, int ya, int xb, int yb, int color)
{
 int A = yb - ya;
 int B = -(xb - xa);
 float m = (float)A + B/2;
 int x = xa;
 int y = ya;
 for(;x<=xb;x++)
 {
  putpixel(x,y,color);
  if(m<=0)
  {
   m=m+A;
   y=y;//ysau=ytruoc
  }
  else
  {
   m=m+A+B;
   y++;//ysau=ytruoc+1
  }
 }
}
// A(120,80) B(20,30)
void mid2(int xa, int ya, int xb, int yb, int color)
{
 int A = yb - ya;
 int B = -(xb - xa);
 float m = (float)-A - B/2;
 int x = xa;
 int y = ya;
 for(;x>=xb;x--)
 {
  putpixel(x,y,color);
  if(m<=0)
  {
   m=m-A;
  }
  else
  {
   m=m-A-B;
   y--;
  }
 }
}
// A(20,80) B(120,30) 
void mid3(int xa, int ya, int xb, int yb, int color)
{
 int A = yb - ya;
 int B = -(xb - xa);
 float m = (float)A - B/2;
 int x = xa;
 int y = ya;
 for(;x<=xb;x++)
 {
  putpixel(x,y,color);
  if(m<=0)
  {
   m=m+A-B;
   y--;
  }
  else
  {
   m=m+A;
  }
 }
}
// A(120,30) B(20,80)
void mid4(int xa, int ya, int xb, int yb, int color)
{
 int A = yb - ya;
 int B = -(xb - xa);
 float m = (float)-A + B/2;
 int x = xa;
 int y = ya;
 for(;x>=xb;x--)
 {
  putpixel(x,y,color);
  if(m<=0)
  {
   m=m-A+B;
   y++;
   
  }
  else
  {
   m=m-A;
  }
 }
}
// A(30,20) B(80,120)
void mid5(int xa, int ya, int xb, int yb, int color)
{
 int A = yb - ya;
 int B = -(xb - xa);
 float m = (float)A/2 + B;
 int x = xa;
 int y = ya;
 for(;y<=yb;y++)
 {
  putpixel(x,y,color);
  if(m<0)
  {
   m=m+A+B;
   x++;
   
  }
  else
  {
   m=m+B;
  }
 }
}
// A(30,120) B(80,20)
void mid6(int xa, int ya, int xb, int yb, int color)
{
 int A = yb - ya;
 int B = -(xb - xa);
 float m = (float)A/2 - B;
 int x = xa;
 int y = ya;
 for(;y>=yb;y--)
 {
  putpixel(x,y,color);
  if(m<0)
  {
   m=m-B;
  }
  else
  {
   m=m+A-B;
   x++;
  }
 }
}
// A(80,120) B(30,20)
void mid7(int xa, int ya, int xb, int yb, int color)
{
 int A = yb - ya;
 int B = -(xb - xa);
 float m = (float)-A/2 - B;
 int x = xa;
 int y = ya;
 for(;y>=yb;y--)
 {
  putpixel(x,y,color);
  if(m<=0)
  {
   m=m-A-B;
   x--;
  }
  else
  {
   m=m-B;
  }
 }
}
// A(80,20) B(30,120) 
void mid8(int xa, int ya, int xb, int yb, int color)
{
 int A = yb - ya;
 int B = -(xb - xa);
 float m = (float)A/2 - B;
 int x = xa;
 int y = ya;
 for(;y<=yb;y++)
 {
  putpixel(x,y,color);
  if(m<0)
  {
   m=m+B;
  }
  else
  {
   m=m-A+B;
   x--;
  }
 }
}
int main()
{
 initwindow(400,400);
 mid1(20,30,120,80,4);
 mid2(120,80,20,30,3);
 mid3(20,80,120,30,4);
 mid4(120,30,20,80,5);
 mid5(30,20,80,120,11);
 mid6(30,120,80,20,12);
 mid7(80,120,30,20,14);
 mid8(80,20,30,120,15);
 getch();
}
