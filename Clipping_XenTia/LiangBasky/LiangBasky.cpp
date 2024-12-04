#include<graphics.h>
#include<stdio.h>

//khai bao bien
int xwmin = 100;
int xwmax = 300;
int ywmin = 100;
int ywmax = 300;

void khoitao(){//ve cua so cat
	setcolor(15);
	setlinestyle(1, 0, 2);
	rectangle(xwmin, ywmax, xwmax, ywmin);
}

float MAX(float a, float b){
	return (a>b)?a:b;
}

float MIN(float a, float b){
	return (a<b)?a:b;
}

void LiangBasky(int xa, int ya, int xb, int yb){
	//ve duong thang di qua A(xa, ya) va B(xb, yb)
	setcolor(4);
	line(xa, ya, xb, yb);
	printf("Toa do cua XA = %d, YA = %d, Xb = %d, YB = %d", xa, ya, xb, yb);
	//tim pk va qk
	int dx=xb-xa;
	int dy=yb-ya;
	int p[4]={-dx, dx, -dy, dy};
	int q[4]={xa-xwmin, xwmax-xa, ya-ywmin, ywmax-ya};
	printf("\nPk[]: ");
	for(int i=0; i<4; i++){
		printf("%5d", p[i]);
	}
	printf("\nQk[]: ");
	for(int i=0; i<4; i++){
		printf("%5d", q[i]);
	}
	//tim giao diem: x0, x1, y0, y1
	int x0, x1, y0, y1;
	float t1=0;
	float t2=1;
	for(int i=0; i<4; i++){
		if(p[i]<0){
			t1=MAX(t1,(float)q[i]/p[i]);
		}else{
			t2=MIN(t2,(float)q[i]/p[i]);
		}
	}
	//in ra man hinh t1 va t2
	printf("\nt1: %f va t2: %f", t1, t2);
	//the t1 t2 vao pt1 va pt2
	x0 = xa + t1*dx; 
	y0 = ya + t1*dy;
	x1 = xa + t2*dx; 
	y1 = ya + t2*dy;
	printf("\nX0 = %d, Y0 = %d, X1 = %d, Y1 = %d", x0, y0, x1, y1);
	if(x0<xwmin || x0>xwmax || y0<ywmin || y0>ywmax || x1<xwmin || x1>xwmax || y1<ywmin || y1>ywmax){
		//loai cac diem x0, y0, x1, y1
	}else{
		//ve duong thang
		setcolor(2);
		line(x0, y0, x1, y1);
	}
}

int main(){
	initwindow(500, 500);
	khoitao();
	LiangBasky(150,280,260,150);
//	LiangBasky(150,150,250,250);
//	LiangBasky(150,150,250,30);
//	LiangBasky(150,150,250,380);
//	LiangBasky(150,150,50,250);
//	LiangBasky(150,150,365,250);
//	LiangBasky(200,200,365,20);
//	LiangBasky(200,200,10,90);
//	LiangBasky(200,200,50,320);
//	LiangBasky(200,200,10,420);
//	LiangBasky(200,200,365,320);
//	LiangBasky(200,200,365,390);
//	LiangBasky(50,200,365,280);
//	LiangBasky(250,50,280,380);
//	LiangBasky(50,200,280,280);
//	LiangBasky(50,200,250,50);
//	LiangBasky(380,250,200,50);
//	LiangBasky(280,380,365,280);
//	LiangBasky(80,380,365,380);
	getch();
	return 0;
}
