#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define maxdinh 20
#define toado "chopnhon_v2.inp"
#define matranke "chopnhon_v2.mtk"
//khai bao bien 
int n;//so dinh cua hinh chop
int dinh[maxdinh][maxdinh];//toa do cac dinh
int mtk[maxdinh][maxdinh];//danh sach ma tran ke
FILE *fp;//con tro tap tin

void inmatran(int a[][maxdinh], int hang, int cot){
	for(int i=0; i<hang; i++){
			for(int j=0; j<cot; j++){
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//doc toa do cac dinh cua hang chop
void readfile(){
	//doc file toa do
	fp=fopen(toado, "r");
	if(fp==NULL) printf("File not found");
	else{
		//doc so dinh: dong 1 cua tap tin
		fscanf(fp, "%d", &n);//1 lan fscanf thi doc duoc 1 gia tri
		for(int i=0; i<n ; i++)//so hang
			for(int j=0; j<3; j++){
				fscanf(fp, "%d", &dinh[i][j]);//5*3=15 ham fscanf
			}
		inmatran(dinh, n, 3);
		fclose(fp);//dong tap tin toa do dinh
	}
	//doc file ma tran ke 
	fp=fopen(matranke, "r");
	if(fp==NULL) printf("File not found");
	else{
		//doc so dinh: dong 1 cua tap tin
		fscanf(fp, "%d", &n);//1 lan fscanf thi doc duoc 1 gia tri
		for(int i=0; i<n ; i++)//so hang
			for(int j=0; j<n; j++){
				fscanf(fp, "%d", &mtk[i][j]);//5*5=25 ham fscanf
			}
		inmatran(mtk, n, n);
		fclose(fp);//dong tap tin toa do dinh
	}
}

//chieu len mat phang xy
void oxy(){
	for(int i=0; i<n; i++){//duyet qua cac dinh 0->n-1
		for(int j=i+1; j<n; j++){//duyet qua cac dinh tu i->n
			if(mtk[i][j]==1){//2 dinh noi nhau
				line(dinh[i][0], dinh[i][1], dinh[j][0], dinh[j][1]);//x0, y0 <-> x1, y1, ...
			}
		}
	}
}

//chieu len mat phang xz
void oxz(){
	for(int i=0; i<n; i++){//duyet qua cac dinh 0->n-1
		for(int j=i+1; j<n; j++){//duyet qua cac dinh tu i->n
			if(mtk[i][j]==1){//2 dinh noi nhau
				line(dinh[i][0], dinh[i][2], dinh[j][0], dinh[j][2]);//x0, y0 <-> x1, z1, ...
			}
		}
	}
}

//chieu len mat phang yz
void oyz(){
	for(int i=0; i<n; i++){//duyet qua cac dinh 0->n-1
		for(int j=i+1; j<n; j++){//duyet qua cac dinh tu i->n
			if(mtk[i][j]==1){
				line(dinh[i][1], dinh[i][2], dinh[j][1], dinh[j][2]);//x0, y0 <-> y1, z1, ...
			}
		}
	}
}

void chieuxien(double L, int theta){
	printf("\n");
	double T[3][3]={{1, 0, 0},{0, 1, 0},{L*cos(theta*3.1416/180), L*sin(theta*3.1416/180), 0}};
	//khoi tao ma tran ket qua
	int Pnew[maxdinh][maxdinh];
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			Pnew[i][j]=0;
		}
	}
	//nhan 2 ma tran [n][3] * T[3][3]
	for(int i=0; i<n; i++)
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				Pnew[i][j]+=round(dinh[i][k]*T[k][j]);//toa do cac dinh cua hinh chop la so nguyen
			}
		}
	//int ra toa do sau khi chieu
	inmatran(Pnew, n, 3);
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(mtk[i][j]==1){
				line(Pnew[i][0], Pnew[i][1], Pnew[j][0], Pnew[j][1]);
			}
		}
	}
}

int main(){
	readfile();
	initwindow(600, 600);
	for(int i=0; i<180; i++){
		chieuxien(0.5, i);
		delay(100);
		cleardevice();
	}
	getch();
}
