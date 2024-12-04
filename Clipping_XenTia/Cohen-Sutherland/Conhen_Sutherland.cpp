#include <graphics.h>
#include <stdio.h>
#include <limits.h>

//Khai bao bien
int xwmin = 100;
int ywmin = 100;
int xwmax = 300;
int ywmax = 300;
//Toa do cua doan thang sau khi xen tia
int x0, y0, x1, y1;
//giao diem cua doan thang voi cacnh cua so cat
int xgd, ygd;
//he so goc
float m;
//Khoi tao ve cua so cat
void khoitao(){
	setlinestyle(0,1,2);
	setcolor(15);		//while
	rectangle(xwmin, ywmax, xwmax, ywmin);
}
//ham ma hoa
int mahoa(int x, int y){
	//ben trong
	if(x >= xwmin && x <= xwmax && y >= ywmin && y <= ywmax){
		return 0;	//0000(2) = 0(10)
	}
	//ben duoi
	if(x >= xwmin && x <= xwmax && y <= ywmin){
		return 4;	//0100(2) = 4(10)
	}
	//ben tren
	if(x >= xwmin && x <= xwmax && y > ywmax){
		return 8;	//1000(2) = 8(10)
	}
	//ben trai
	if(x < xwmin && y >= ywmin && y <= ywmax){
		return 1;	//0001(2) = 1(10)
	}
	//ben phai
	if(x > xwmax && y >= ywmin && y <= ywmax){
		return 2;	//0010(2) = 2(10)
	}
	//goc duoi ben trai
	if(x < xwmin && y < ywmin){
		return 5;	//0101(2) = 5(10)
	}
	//goc duoi ben phai
	if(x > xwmax && y < ywmin){
		return 6;	//0110(2) = 6(10)
	}
	//goc tren ben trai
	if(x < xwmin && y > ywmax){
		return 9;	//1001(2) = 9(10)
	}
	//goc tren ben phai
	if(x > xwmax && y > ywmax){
		return 10;	//1010(2) = 10(10)
	}
}
//tim giao diem: xet tung diem (x,y)
void timgiaodiem(int x, int y){
	switch(mahoa(x,y)){
		//diem (x,y) ben trong cua so
		case 0:{
			xgd = x;
			ygd = y;
			break;
		}
		//diem (x,y) ben duoi cua so
		case 4:{
			ygd = ywmin;
			xgd = x + (ygd - y)/m;	//m la he so goc
			break;
		}
		//diem (x,y) ben tren cua so
		case 8:{
			ygd = ywmax;
			xgd = x + (ygd - y)/m;	//m la he so goc
			break;
		}
		//diem (x,y) ben trai cua song
		case 1:{
			xgd = xwmin;
			ygd = y + (xgd - x) * m; 	//m la he so goc
			break;
		}
		//diem (x,y) ben phai cua so
		case 2:{
			xgd = xwmax;
			ygd = y + (xgd - x) * m; 	//m la he so goc
			break;
		}
		//diem (x,y) goc duoi ben phai co B va R = 1
		case 6:{
			//xet bit B = 1 truoc
			ygd = ywmin;
			xgd = x + (ygd - y)/m;	//m la he so goc
			if(xgd > xwmax){
				//xet bit R = 1 thay cho B = 1
				xgd = xwmax;
				ygd = y + (xgd - x) * m; 	//m la he so goc
			}
			break;
		}
		//diem (x,y) goc duoi ben trai co B va L = 1
		case 5:{
			//xet bit B = 1 truoc
			ygd = ywmin;
			xgd = x + (ygd - y)/m;	//m la he so goc
			if(xgd < xwmin){
				//xet bit L = 1 thay cho B = 1
				xgd = xwmin;
				ygd = y + (xgd - x) * m; 	//m la he so goc
			}
			break;
		}
		//diem (x,y) goc tren ben trai co A va L = 1
		case 9:{
			//xet bit A = 1 truoc
			ygd = ywmax;
			xgd = x + (ygd - y)/m;	//m la he so goc
			if(xgd < xwmin){
			//xet bit L = 1 thay cho A = 1
			xgd = xwmin;
			ygd = y + (xgd - x) * m; 	//m la he so goc
			}
			break;
		}
		//diem (x,y) goc tren ben phai co A va R = 1
		case 10:{
			//xet bit A = 1 truoc
			ygd = ywmax;
			xgd = x + (ygd - y)/m;	//m la he so goc
			if(xgd > xwmax){
			//xet bit R = 1 thay cho A = 1
			xgd = xwmax;
			ygd = y + (xgd - x) * m; 	//m la he so goc
			}
			break;
		}		
	}
}
//xen tia dia doan thang A(xa,ya), B(xb,yb)
void CohenSutherland(int xa, int ya, int xb, int yb){
	//tim he so goc
	if(xa == xb){
		m = INT_MAX;
	}
	if(ya == yb){
		m = 0;
	}
	if(xa != xb && ya != yb){
		m = (float)(yb - ya)/(xb - xa);
	}
	//ve duong thang di qua 2 diem AB
	setcolor(2);
	line(xa,ya,xb,yb);
	//tim giao diem
	printf("\nMa hoa A = %d va B = %d", mahoa(xa,ya), mahoa(xb,yb));
	timgiaodiem(xa,ya);
	x0 = xgd; y0 = ygd;	//toa do diem thu 1
	timgiaodiem(xb,yb);
	x1 = xgd; y1 = ygd;	//toa do diem thu 2
	//in ra man hinh toa do cac giao diem
	printf("\nX0 = %d, Y0 = %d, X1 = %d, Y1 = %d", x0, y0, x1, y1);
	if(x0 < xwmin || x0 > xwmax || y0 < ywmin || y0 > ywmax || x1 < xwmin || x1 > xwmax || y1 < ywmin || y1 > ywmax){
		//Loai cac diem x0, y0, x1, y1
	}
	else{
		//ve duong thang noi 2 diem 1,2
		setcolor(4);
		line(x0,y0,x1,y1);	
	}
}
//chuong trinh chinh
int main(){
	initwindow(400,400);
	khoitao();
	//CohenSutherland(150,150,250,250);
	//CohenSutherland(150,150,250,30);
	//CohenSutherland(150,150,250,380);
	//CohenSutherland(150,150,50,250);
	//CohenSutherland(150,150,365,250);
/*	CohenSutherland(200,200,365,20);
	CohenSutherland(200,200,365,90);
*/
	CohenSutherland(200,200,50,20);
	CohenSutherland(200,200,10,90);

/*	CohenSutherland(200,200,50,320);
	CohenSutherland(200,200,10,420);
*/
/*	CohenSutherland(200,200,365,320);
	CohenSutherland(200,200,365,390);
*/
//	CohenSutherland(50,200,365,280);
//	CohenSutherland(250,50,280,380);
//	CohenSutherland(50,200,280,380);
//	CohenSutherland(50,200,250,50);
//	CohenSutherland(380,250,200,50);


//	CohenSutherland(280,380,365,280);
//	CohenSutherland(80,380,365,380);
	getch();//press any key
}
