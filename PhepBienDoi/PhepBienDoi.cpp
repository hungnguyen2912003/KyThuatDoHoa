#include<graphics.h>	//thu vien do hoa
#include<stdio.h>		//printf scanf
#include<math.h>		//sin cos

#define INPUT "dagiac.txt"
#define maxdinh 20

int dinh[maxdinh][2];	//toa do cac dinh
int n; 					//so dinh
FILE *fp;
void readfile(){
	fp = fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
	}
	else{
		//doc noi dung file: fscanf (1 lan dung ham fscanf la doc 1 tu cach nhau ktu trang)
		//doc so dinh cua da giac 
		fscanf(fp, "%d", &n);
		printf("So dinh cua da giac: %d", n);
		//doc toa do cac dinh da giac
		for(int i = 0; i < n ; i++){//n hang
			for(int j = 0; j < 2; j++){//2 cot
				fscanf(fp, "%d", &dinh[i][j]);
			}
		}
		//in ra man hinh toa do cac dinh cua da giac
		printf("\nToa do cac dinh cua da giac: \n");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2; j++){
				printf("%5d", dinh[i][j]);
			}
			printf("\n");	//xuong hang khi het 2 cot
		}
		fclose(fp);
	}
}

void vedagiac(){
	//them dinh cuoi = dinh dau
	dinh[n][0] = dinh[0][0];
	dinh[n][1] = dinh[0][1];
	for(int i = 0; i < n; i++){
		line(dinh[i][0], dinh[i][1], dinh[i+1][0], dinh[i+1][1]);
	}
}

void tinhtien(int dx, int dy){
	for(int i = 0; i < n; i++){
		dinh[i][0] += dx;
		dinh[i][1] += dy;
	}
	vedagiac();
}

void quayquay(int xr, int yr, int phi){
	//x` = xr+(x-xr)*cos(phi) - (y-yr)*sin(phi)
	//y` = ur+(x-xr)*sin(phi) - (y-yr)*cos(phi)
	for(int i = 0; i < n; i++){
		int dx = dinh[i][0] - xr;
		int dy = dinh[i][1] - yr;
		dinh[i][0] = round(xr + dx*cos(phi*3416/180) - dy*sin(phi*3416/180));
		dinh[i][1] = round(yr + dx*sin(phi*3416/180) + dy*cos(phi*3416/180));
	}
	vedagiac();
}

void tyle(int xr, int yr, float sx, float sy){
	//x` = xr + (x-xr)*sx
	//y` = yr + (y-xr)*sy
	for(int i = 0; i < n; i++){
		int dx = dinh[i][0] - xr;
		int dy = dinh[i][1] - yr;
		dinh[i][0] = round(xr + (float)dx*sx);
		dinh[i][1] = round(yr + (float)dy*sy);
	}
	vedagiac();
}

void latmat(){
	//ve 2 truc x, y
	line(0, getmaxy()/2, getmaxx(), getmaxy()/2);
	line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
	//lat qua truc y
	for(int i = 0; i < n; i++){
		dinh[i][0] += getmaxx()/2;
	}
	vedagiac();
	delay(200);
	//lat qua truc x
	for(int i = 0; i < n; i++){
		dinh[i][1] += getmaxy()/2;
	}
	vedagiac();
	delay(200);
	//lat qua truc y
	for(int i = 0; i < n; i++){
		dinh[i][0] -= getmaxx()/2;
	}
	vedagiac();
	delay(200);
}

int main(){
	readfile();
	initwindow(800,800);
	vedagiac();
//	for(int i = 0; i < 30; i++){
//		tinhtien(10,0);
//		delay(100);
//	}
	//quay quay
//	for(int i = 0; i < 360/5; i++){
//		quayquay(300,200,5);
//		delay(100);
//	}
	//ty le
//	for(int i = 0; i < 20; i++){
//		tyle(400,400,0.9,0.9);
//	}
	//lat mat
	latmat();
	getch();			//press any key
}
