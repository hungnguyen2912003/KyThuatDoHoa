#include <graphics.h>		//Thu vien do hoa
#include <stdio.h>			//Thu vien chua lenh "printf"
#include <math.h>			//Thu vien tinh toan "round" - lam tron

//TH1: A(20;30) B(120,80)

void DDA1(int xa, int ya, int xb, int yb, int color)
{
	float m = float(yb-ya)/(xb-xa);		//TH1: m<1 && xa<xb
	int xsau = xa;
	float ysau = ya;
	for(xsau = xa;xsau<=xb;xsau++){
		printf("xsau = %d, ysau = %.0f\n", xsau, round(ysau));
		ysau = ysau + m;
		putpixel(xsau,round(ysau),color);
	}
}

//TH2: A(120;80) B(20,30)

void DDA2(int xa, int ya, int xb, int yb, int color)
{
	float m = float(yb-ya)/(xb-xa);		//TH2: m<1 && xa>xb
	int xsau = xa;
	float ysau = ya;
	for(xsau = xa;xsau>xb;xsau--){
		printf("xsau = %d, ysau = %.0f\n", xsau, round(ysau));
		ysau = ysau - m;
		putpixel(xsau,round(ysau),color);
	}
}

//TH3: A(120;30) B(20,80)

void DDA3(int xa, int ya, int xb, int yb, int color)
{
	float m = float(yb-ya)/(xb-xa);		//TH3: m<1 && xa>xb
	int xsau = xa;
	float ysau = ya;
	for(xsau = xa;xsau>xb;xsau--){
		printf("xsau = %d, ysau = %.0f\n", xsau, round(ysau));
		ysau = ysau - m;
		putpixel(xsau,round(ysau),color);
	}
}

//TH4: A(20;80) B(120,30)

void DDA4(int xa, int ya, int xb, int yb, int color)
{
	float m = float(yb-ya)/(xb-xa);		//TH4: m<1 && xa<xb
	int xsau = xa;
	float ysau = ya;
	for(xsau = xa;xsau<=xb;xsau++){
		printf("xsau = %d, ysau = %.0f\n", xsau, round(ysau));
		ysau = ysau + m;
		putpixel(xsau,round(ysau),color);
	}
}

//TH5: A(30;20) B(80,120)

void DDA5(int xa, int ya, int xb, int yb, int color)
{
	float m = float(yb-ya)/(xb-xa);		//TH5: m>1 && xa<xb
	float xsau = xa;
	int ysau = ya;
	for(xsau = xa;xsau<=xb;xsau+=1/m){
		printf("xsau = %.0f, ysau = %d\n", round(xsau), ysau);
		ysau = ysau + 1;
		putpixel(round(xsau),ysau,color);
	}
}

//TH6: A(80;120) B(30,20)

void DDA6(int xa, int ya, int xb, int yb, int color)
{
	float m = float(yb-ya)/(xb-xa);		//TH6: m>1 && xa>xb
	float xsau = xa;
	int ysau = ya;
	for(xsau = xa;xsau>xb;xsau-=1/m){
		printf("xsau = %.0f, ysau = %d\n", round(xsau), ysau);
		ysau = ysau - 1;
		putpixel(round(xsau),ysau,color);
	}
}

//TH7: A(30;120) B(80,20)

void DDA7(int xa, int ya, int xb, int yb, int color)
{
	float m = float(yb-ya)/(xb-xa);		//TH7: m<1 && xa<xb
	int xsau = xa;
	float ysau = ya;
	for(xsau = xa;xsau<=xb;xsau++){
		printf("xsau = %d, ysau = %.0f\n", xsau, round(ysau));
		ysau = ysau + m;
		putpixel(xsau,round(ysau),color);
	}
}

//TH8: A(80;20) B(30,120)

void DDA8(int xa, int ya, int xb, int yb, int color)
{
	float m = float(yb-ya)/(xb-xa);		//TH8: m<1 && xa>xb
	int xsau = xa;
	float ysau = ya;
	for(xsau = xa;xsau>xb;xsau--){
		printf("xsau = %d, ysau = %.0f\n", xsau, round(ysau));
		ysau = ysau - m;
		putpixel(xsau,round(ysau),color);
	}
}

int main(){
	initwindow(300,300);	//Khoi tao viewport
	DDA1(20,30,120,80,2);
	DDA2(130,80,20,10,2);
	DDA3(120,30,20,80,2);
	DDA4(10,80,120,10,2);
	DDA5(60,20,90,110,4);
	DDA6(80,120,50,20,4);
	DDA7(40,130,80,30,4);
	DDA8(80,10,30,110,4);
	getch();
}
