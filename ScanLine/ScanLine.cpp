#include <winbgim.h>			//Hàm line ve duong thang
#include <stdio.h>				//printf scanf
#include <math.h>				//round lam tron so

#define maxdinh 20				//so dinh toi da cua da giac
#define INPUT "dagiac.txt"		//file toa do da giac

int dinh[maxdinh][2];			//toa do cac dinh cua da giac
int n;							//so dinh cua da giac
FILE *fp;						//con tro tap tin
float m[maxdinh];				//he so goc cac canh cua da giac
//buoc 1. doc noi dung tap tin
void ReadFile(){
	fp = fopen(INPUT, "r");		//mo tap tin INPUT chi doc
	if(fp==NULL){
		printf("File not found");
	}
	else{
		//doc so dinh tu file -> luu vao bien n
		fscanf(fp,"%d", &n);
		printf("So dinh la: %d", n);
		//doc tung so trong file -> luu vao dinh [][]
		for(int i = 0; i < n; i++){	//duyet tung dinh
			for(int j = 0; j < 2; j++){	//0:hoanh do, 1: tung do
				fscanf(fp,"%d", &dinh[i][j]);
			}
		}
		//in ra cac dinh cua da giac
		printf("\nCac dinh cua da giac:\n");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2; j++){
				printf("%5d", dinh[i][j]);
			}
			printf("\n");	//ngat hang
		}
		fclose(fp);	//dong tap tin da mo
	}
}

//buoc2. ve da giac
void vedagiac(){
	//them 1 dinh cuoi co toa do la dinh dau
	dinh[n][0] = dinh[0][0];
	dinh[n][1] = dinh[0][1];
	for(int i = 0; i < n; i++){		//duyet cac dinh cua da giac
		line(dinh[i][0],dinh[i][1],dinh[i+1][0],dinh[i+1][1]);			//ve duong thang
		//dinh[i][0]: xi, dinh[i][1]: yi
		//dinh[i+1][0]: xi+1, dinh[i][1]: yi+1
	}
}

//buoc3. tinh he so goc

/**/
void hesogoc(){
	for(int i = 0; i < n; i++){		//duyet qua cac dinh cua da giac
		int dx = dinh[i+1][0] - dinh[i][0];
		int dy = dinh[i+1][1] - dinh[i][1];
		//cong thuc tinh xgd = (xtruoc + (y - ytruoc)/m)
		if(dy==0){
			m[i] = 99999;
		}
		if(dx==0){
			m[i] = 1.0;		//mien la m[i] <> 0
		}
		else{
			m[i] = (float)(dy/dx);
		}
	}
	printf("\nHe so goc: \n");
	for(int i = 0; i < n; i++){
		printf("%.1f  ", m[i]);
	}
}

//buoc4. to mau
void scanline(){
	int xgd[maxdinh];
	//tim ymin va ymax
	int ymin = dinh[0][1];
	int ymax = dinh[0][1];
	for(int i = 1; i < n; i++){
		if(ymin > dinh[i][1]){
			ymin = dinh[i][1];
		}
		if(ymax < dinh[i][1]){
			ymax = dinh[i][1];
		}
	}
	printf("\nymin = %d, ymax = %d", ymin, ymax);
	//tim giao diem cua y dong quet voi cac canh cua da giac
	int y = ymin;
	while(y<=ymax){
		int count = 0;	//reset dem sau moi dong quet
		//duyet qua cac canh cua da giac
		for(int i = 0; i < n; i++){
			//xet xem khi nao thi co giao diem
			if(y >= dinh[i][1] && y < dinh[i+1][1] || y < dinh[i][1] && y >= dinh[i+1][1]){
				//co giao diem
				xgd[count++]=round(dinh[i][0] + (y - dinh[i][1])/m[i]);
			}
		}
		//voi moi dong quet co so giao diem la:
		for(int i = 0; i < count; i++){
			printf("\ny=%d: (%d,%d)", y, xgd[i], y);
		}
		//sap xep tang dan hoanh do giao diem
		for(int i = 0; i < count-1; i++){
			for(int j = i + 1; j < count; j++){
				if(xgd[i] > xgd[j]){
					int temp = xgd[i];
					xgd[i] = xgd[j];
					xgd[j] = temp;
				}
			}
		}
		//ve duong thang noi cac giao diem
		for(int i = 0; i < count-1; i=i+2){
			line(xgd[i],y,xgd[i+1],y);
		}
		y++;	//tang dong quet len 1
		
	}
}

int main(){
	ReadFile();
	initwindow(500,500);
	vedagiac();
	hesogoc();
	scanline();
	getch();					//press any key
}
