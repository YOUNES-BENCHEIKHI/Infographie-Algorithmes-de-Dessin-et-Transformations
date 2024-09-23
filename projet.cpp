#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include <time.h>

#define PI 3.14159265


void init_graph(){
int g = DETECT, m ; 


    initgraph(&g, &m, "C:\\TC\\BGI");
     setviewport(0, 0,1500, 1500, 1);
	}
void drawClockHand(int angle, int length,int h,int k,int color) {
    int x1, y1, x2, y2;
    int xc = h; // Coordonnée x du centre
    int yc =k; // Coordonnée y du centre

    x2 = xc + length * cos(angle * PI / 180);
    y2 = yc + length * sin(angle * PI / 180);
   setcolor(color);
    line(xc, yc, x2, y2);
}
void repere(){

cleardevice() ; 
setbkcolor(9) ;
setcolor(5) ; 
 
line(0,240, 640,240) ; 

line(320, 0, 320,480) ;
}
void pixel (int x, int y, int color){

x = x+320 ; 
y = 240-y ; 
putpixel(x, y, color);
}


void lignever(int xd, int yd, int xf, int yf,int color) {
    int x = xd;
    int y = yd;
    int deltaX = xf - xd;
    int dx=abs(deltaX);
    int deltaY = yf - yd;
    int dy=abs(deltaY);
    int s = 2 * dy - dx;
    int i = 1;

    while (i <= dy) {
       
        if (s > 0) {
        	if(deltaY >=0){
			
                y = y + 1;
				}
            else{
			
			    y--;    
				}
            s = s + 2 * (dy - dx);
             pixel(x, y, color);
        } else {
            s = s + 2 * dy;
             pixel(x, y, color);
        }
        if(deltaX >0){
            x = x + 1;
			}
        else if(deltaX<0){
		 x=x-1;
		 }
		 else{
		 	x=x;
		 }
        i = i + 1;
       
    }
   
}

void ligneparal(int xd, int yd, int xf, int yf,int color) {
    int x = xd;
    int y = yd;
    int deltaX = xf - xd;
    int dx=abs(deltaX);
    int deltaY = yf - yd;
    int dy=abs(deltaY);
    int s = 2 * dy - dx;
    int i = 1;
     
	  
       while (i <= dx) {
       
        if (s > 0) {
        	if(deltaY >=0){
                y = y + 1;
				}
            else{
			
			    y--;    }
            s = s + 2 * (dy - dx);
             pixel(x, y, color);
        } else {
            s = s + 2 * dy;
             pixel(x, y, color);
        }
        if(deltaX >0){
            x = x + 1;
			}
        else if(deltaX<0){
		 x=x-1;
		 }
		
        i = i + 1;
         
    }


}
void ligne(int xd, int yd, int xf, int yf, int color) {
    int x = xd;
    int y = yd;
    int deltaX = xf - xd;
    int deltaY = yf - yd;
    int dx = abs(deltaX);
    int dy = abs(deltaY);
    int s;
    int incX, incY;

    // Déterminer les directions d'incrémentation pour x et y
    if (deltaX > 0) {
        incX = 1;
    } else if (deltaX < 0) {
        incX = -1;
    } else {
        incX = 0;  // La ligne est verticale
    }

    if (deltaY > 0) {
        incY = 1;
    } else if (deltaY < 0) {
        incY = -1;
    } else {
        incY = 0;  // La ligne est horizontale
    }

    // Initialiser la valeur de s
    if (dx > dy) {
        s = 2 * dy - dx;
    } else {
        s = 2 * dx - dy;
    }

    // Boucle principale de tracé de ligne
    for (int i = 1; i <= ((dx > dy) ? dx : dy); i++) {
        pixel(x, y, color);

        while (s >= 0) {
            if (dx > dy) {
                y += incY;
                s -= 2 * dx;
            } else {
                x += incX;
                s -= 2 * dy;
            }
        }

        if (dx > dy) {
            x += incX;
            s += 2 * dy;
        } else {
            y += incY;
            s += 2 * dx;
        }
    }
}

int  lignePolynomial(int xd,int yd,int xf,int yf,int color){
	float a,b;int dx=xf-xd;int dy=yf-yd;
	int x,y,px,py;
	px=(xd>xf)?-1:1;
	py=(yd>yf)?-1:1;
	pixel(xd, yd, color);
	pixel(xf, yf, color);
	if(abs(dx)>=abs(dy)){
		a=(float)dy/dx;
		b=yd-xd*a;
		for(x=xd+px;x!=xf;x=x+px){
			y=a*x+b;
			pixel(x, y, color);
		}
	}
	else{
			a=(float)dx/dy;
		b=xd-yd*a;
		for(y=yd+py;y!=yf;y=y+py){
			x=a*y+b;
			pixel(x, y, color);
			}
	}
}

int cerclebresenham(int h,int k,int r,int color){
	int x=0;
	int y=r;
	int s=3-2*r;

	while(x<y){
		 
		pixel(x+h,y+k, color);pixel(-x+h,-y+k, color);pixel(y+h,x+k, color);pixel(-y+h,-x+k, color);
     	pixel(-y+h,x+k, color);pixel(y+h,-x+k, color);pixel(-x+h,y+k, color);pixel(x+h,-y+k, color);
		if(s>0){
			s+=4*(x-y)+10;
			x++;
			y--;
		}
		else{
			s+=4*x+6;
			x++;
		}
    }
   

}

int cerclebresenhamho(int h,int k,int r ){
//	init_graph() ;
	int x=0;
	int y=r;
	int s=3-2*r;
  
  outtextxy(h+320+r/2+10,240-k-r*(sqrt(3)/2)-10, "1");
  outtextxy(h+320+r*(sqrt(3)/2)+10,240-k-r/2-10, "2");
  outtextxy(h+320+r+10,240-k, "3");
  outtextxy(h+320+r*(sqrt(3)/2)+7,240-k+r/2+7, "4");
  outtextxy(h+320+r/2+7,240-k+r*(sqrt(3)/2)+7, "5");
  outtextxy(h+320,240-k+r+10, "6");
  outtextxy(h+320-r/2-10,240-k+r*(sqrt(3)/2)+7, "7");
  outtextxy(h+320-r*(sqrt(3)/2)-7,240-k+r/2+7, "8");
  outtextxy(h+320-r-20,240-k, "9");
  outtextxy(h+320-r*(sqrt(3)/2)-15,240-k-r/2-15, "10");
  outtextxy(h+320-r/2-15,240-k-r*(sqrt(3)/2)-15, "11");
  outtextxy(h+320,240-k-r-20, "12");
   
 
  while (true){
  	 //cleardevice(); // Effacer l'écran à chaque mise à jour de l'horloge
          
        // init_graph() ;
        // setbkcolor(BLACK);
 
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        int hours = timeinfo->tm_hour;
        int minutes = timeinfo->tm_min;
        int seconds = timeinfo->tm_sec;
        printf("%d : %d :%d\n",hours,minutes,seconds);
         
          
	while(x<y){
		 
		pixel(x+h,y+k, 8);pixel(-x+h,-y+k, 8);pixel(y+h,x+k, 8);pixel(-y+h,-x+k, 8);
     	pixel(-y+h,x+k, 8);pixel(y+h,-x+k, 8);pixel(-x+h,y+k, 8);pixel(x+h,-y+k, 8);
		if(s>0){
			s+=4*(x-y)+10;
			x++;
			y--;
		}
		else{
			s+=4*x+6;
			x++;
		}
    }
   
  drawClockHand((hours % 12 + minutes / 60.0) * 30 - 90,r-60 ,h+320,240-k,12); // Heures
        
  drawClockHand(minutes * 6 - 90, r-25,h+320,240-k,12); // Minutes
  drawClockHand(seconds * 6 - 90, r-10,h+320,240-k,12 ); // Secondes
  delay(1000);
  drawClockHand((hours % 12 + minutes / 60.0) * 30 - 90,r-50 ,h+320,240-k,0); // Heures
        
  drawClockHand(minutes * 6 - 90, r-25,h+320,240-k,0); // Minutes
  drawClockHand(seconds * 6 - 90, r-10,h+320,240-k,0); // Secondes  

      
}
}


int CercleTrigonomtrique(int h,int k,int r){
	double x,y;
	double a=0.;
	while(a<=M_PI/4){
		x=r*cos(a);
		y=r*sin(a);
			pixel(x+h,y+k, 12);pixel(-x+h,-y+k, 12);pixel(y+h,x+k, 12);pixel(-y+h,-x+k,12);
        	pixel(-y+h,x+k, 12);pixel(y+h,-x+k, 12);pixel(-x+h,y+k,12);pixel(x+h,-y+k,12);
        	a+=M_PI/90;
	}
}

int cerclepolynomial(double h,double k,double r){
	double x=0.,y;
	while(x<r/sqrt(2)){
		y=sqrt(r*r -( (x-h)*(x-h)))+k;
		x++;
			pixel(x+h,y+k, 8);pixel(-x+h,-y+k, 8);pixel(y+h,x+k, 8);pixel(-y+h,-x+k, 8);
        	pixel(-y+h,x+k, 8);pixel(y+h,-x+k, 8);pixel(-x+h,y+k, 8);pixel(x+h,-y+k, 8);
	}
}

int Ellipsepolynomial(double h,double k,double a,double b){
	double x=0.,y;double ye;double t;
	while(x<=a){
		t=(1-((x*x)/(a*a)));
		if(t<0) ye=-t;
		else 
		   ye=t;
		
		y=b*sqrt(ye);
		pixel(x+h,y+k,12);pixel(x+h,-y+k,12);
        pixel(-x+h,-y+k,12);pixel(-x+h,y+k,12);
        x=x+0.1;
	}
}
int EllipseBresenham(int h,int k,int a,int b){
	int x=0;
	int y=b;
	int s1=(2*b*b)-(2*a*a*b)+(a*a);
	int i=1; 
	while(a*a*(y-1)>b*b*(x+1)){
	pixel(x+h,y+k,8) ;
    pixel(x+h,-y+k,8) ;
    pixel(-x+h,-y+k,8) ;
    pixel(-x+h,y+k,8) ;
//         	pixel(x+h,y+k, 8);pixel(-x+h,-y+k, 8);pixel(y+h,x+k, 8);pixel(-y+h,-x+k, 8);
//        	pixel(-y+h,x+k, 8);pixel(y+h,-x+k, 8);pixel(-x+h,y+k, 8);pixel(x+h,-y+k, 8);
       
        	if(s1>0){
        		s1+=((pow(b,2))*(2*x+3))+( pow(a,2)*(-2*y+2));
        		x++;
        		y--;
			}else{
				s1+=pow(b,2)*(2*x+3);
				x++;
			}
 
	}
		
			int s2=b*b*(x+1)*(x+1) + a*a*(y-1)*(y-1)-a*a*b*b;
		
			while(y>0){
//					pixel(x+h,y+k, 8);pixel(-x+h,-y+k, 8);pixel(y+h,x+k, 8);pixel(-y+h,-x+k, 8);
//        	        pixel(-y+h,x+k, 8);pixel(y+h,-x+k, 8);pixel(-x+h,y+k, 8);pixel(x+h,-y+k, 8);
	pixel(x+h,y+k,8) ;
    pixel(x+h,-y+k,8) ;
    pixel(-x+h,-y+k,8) ;
    pixel(-x+h,y+k,8) ;
        	        if(s2<0){
        	        	s2=s2+b*b*(2*x+2)+a*a*(-2*y+3);
        	        	y--;
        	        	x++;
					}else{
						s2=s2+a*a*(-2*y+3);
						y--;
					}
					
        	
			}
			
			
		}
		
	void EllipseTrigo(double a, double b, double h, double k) {
    double angle = 0;
    double x, y;
    double t = 1;

    //initwindow(800, 600); // Initialisation de la fenêtre graphique

    while(angle <= 360) {
        x = h + a * cos(angle * M_PI / 180);
        y = k + b * sin(angle * M_PI / 180);

//        pixel(x-320, 3*y-240, 15);
            pixel(x,y,15);
        angle += t;
    }

    getch();
   
}
int lignevertical(int xd,int yd,int xf,int yf,int n){
	   int i;
	lignever(xd,yd,xf,yf,15);
	for(i=xd;i<=n;i=i+10){
	ligne(i,yd,i,yf,15);
	}
}
int lignehorizontal(int xd,int yd,int xf,int yf,int n){
	     int j;
for(j=yd;j>=n;j=j-10){
	ligne(xd,j,xf,j,15);
	}

}
int pendul(float h,float k,int xf,int yf ){
	
	ligneparal(h-30,k,h-25,k+10,15);
	ligneparal(h-20,k,h-15,k+10,15);
	ligneparal(h-10,k,h-5,k+10,15);
	ligneparal(h,k,h+5,k+10,15);
	ligneparal(h+10,k,h+15,k+10,15);
	ligneparal(h+20,k,h+25,k+10,15);
	ligneparal(h+30,k,h+35,k+10,15);
	ligneparal(h-30,k,h+30,k,15);
	int xg;
	while(true){
		
		
		while(xf>=h){
			
		setcolor(15);
		line(320+h,240-k,xf+320,240-yf);
		cerclebresenham(xf+5,yf-10,10,15);
		
		//printf("%d et  %d",xf,yf);
		Sleep(10);
		setcolor(0);
		line(320+h,240-k,xf+320,240-yf);
		//lignePolynomial(h,k,xf,yf,0);
		cerclebresenham(xf+5,yf-10,10,0);
		xf=xf-2;
		//yf=yf-2;
	}
		while(xf>h-60){
			
		setcolor(15);
		line(320+h,240-k,xf+320,240-yf);
		//lignePolynomial(h,k,xf,yf,12);
		cerclebresenham(xf+5,yf-10,10,15);
		//printf("%d et  %d",xf,yf);
		Sleep(10);
		setcolor(0);
		line(320+h,240-k,xf+320,240-yf);
		//lignePolynomial(h,k,xf,yf,0);
		cerclebresenham(xf+5,yf-10,10,0);
		xf=xf-2;
//		yf=yf+2;
	}
	
	
	while(xf<=h){
		setcolor(15);
		line(h+320,240-k,xf+320,240-yf);
		//lignePolynomial(h,k,xg,yf,12);
		cerclebresenham(xf+5,yf-10,10,15);
		printf("%d %d",xf,yf);
	    Sleep(10);
	    setcolor(0);
	    line(h+320,240-k,xf+320,240-yf);
		//lignePolynomial(h,k,xg,yf,0);
		cerclebresenham(xf+5,yf-10,10,0);
		xf=xf+2;
//		yf=yf-2;
	}
	while(xf<h+60){
		
		setcolor(15);
		line(h+320,240-k,xf+320,240-yf);
		//lignePolynomial(h,k,xg,yf,12);
		cerclebresenham(xf+5,yf-10,10,15);
		//printf("%d %d",xf,yf);
	    Sleep(10);
	    setcolor(0);
	    line(h+320,240-k,xf+320,240-yf);
		//lignePolynomial(h,k,xg,yf,0);
		cerclebresenham(xf+5,yf-10,10,0);
		xf=xf+2;
//		yf=yf+2;
	}
}
	}
	

int rectangl(int x,int y,int xh,int yh){
	line(320+x,240-y,320+xh,240-y);
	line(320+x,240-y,320+x,240-yh);
    line(320+x,240-yh,320+xh,240-yh);
    line(320+xh,240-y,320+xh,240-yh);
	
}

int translation_cercle(int h,int k,int r){
	cerclebresenham(h,k,r,12);
	Sleep(500);
	cerclebresenham(h,k,r,0);
	cerclebresenham(h+50,k,r,12);
	Sleep(500);
	cerclebresenham(h+50,k,r,0);
	cerclebresenham(h-150,k+20,r,12);
	Sleep(500);
	cerclebresenham(h-150,k+20,r,0);
    cerclebresenham( h+100,k-30, r,12);
    Sleep(500);
    cerclebresenham( h+100,k-30, r,12);
   
}
void drawObliqueEllipse(double xc, double yc, int a, int b, float angle) {
    float theta;
    double x, y;

    for (theta = 0; theta <= 360; theta += 0.1) {
        float radian = theta * 3.14159 / 180;

        // Equation paramétrique de l'ellipse standard
        x = xc + a * cos(radian);
        y = yc + b * sin(radian);

        // Appliquer la rotation (transformation affine)
        double x_rotated = xc + (x - xc) * cos(angle) - (y - yc) * sin(angle);
        double y_rotated = yc + (x - xc) * sin(angle) + (y - yc) * cos(angle);

       pixel(x_rotated,y_rotated,15);
    }

}
void rotate(double xp, double yp, double h, double k, double angle, double *x, double *y) {
    angle *= PI / 180;
    double xM = xp - h;
    double yM = yp - k;

    *x = xM * cos(angle) + yM * sin(angle) + h;
    *y = -xM * sin(angle) + yM * cos(angle) + k;

    *x = round(*x);
    *y = round(*y);
}

void EllipseBresenhamrotcnetre(int h, int k, int a, int b,double angle) {
    int x = 0;
    double xr, yr;
    int y = b;
    int s1 = (2 * b * b) - (2 * a * a * b) + (a * a);
    int i = 1;

    while (a * a * (y - 1) > b * b * (x + 1)) {
        rotate(x, y, h, k, angle, &xr, &yr);
        pixel(xr, yr, 8);
        rotate(x, y, h, k, -angle, &xr, &yr);
        pixel(-xr, yr, 8);
        rotate(x, y, h, k, -angle, &xr, &yr);
        pixel(xr, -yr, 8);
        rotate(x, y, h, k,angle , &xr, &yr);
        pixel(-xr, -yr, 8);

        if (s1 > 0) {
            s1 += ((pow(b, 2)) * (2 * x + 3)) + (pow(a, 2) * (-2 * y + 2));
            x++;
            y--;
        } else {
            s1 += pow(b, 2) * (2 * x + 3);
            x++;
        }
    }

    int s2 = b * b * (x + 1) * (x + 1) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y > 0) {
        rotate(x, y, h, k, angle, &xr, &yr);
        pixel(xr, yr, 12);
        rotate(x, y, h, k, -angle, &xr, &yr);
        pixel(-xr, yr, 12);
        rotate(x, y, h, k, -angle, &xr, &yr);
        pixel(xr, -yr, 12);
        rotate(x, y, h, k, angle, &xr, &yr);
        pixel(-xr, -yr, 12);

        if (s2 < 0) {
            s2 = s2 + b * b * (2 * x + 2) + a * a * (-2 * y + 3);
            y--;
            x++;
        } else {
            s2 = s2 + a * a * (-2 * y + 3);
            y--;
        }
    }
}
int plant(double h,double k,double r){
    cerclebresenham(h,k,r,15);
    int a = (r*40)/60;  // Longueur de l'axe majeur
    int b = a/2;  // Longueur de l'axe mineur
   
    // Définir l'angle d'inclinaison en radians 
    float angle = 90 * 3.14159 / 180;
    float anglea= 0 * 3.14159 / 180;
    // Tracer l'ellipse oblique
    drawObliqueEllipse( h, k+r+a, a , b , angle);
//    EllipseBresenhamrotcnetre(h-r,k-r,a,b,45);
    drawObliqueEllipse( h, k-r-a, a , b , angle);
    drawObliqueEllipse( h+r+a, k, a , b , anglea);
    drawObliqueEllipse( h-r-a, k, a , b , anglea);
    //drawObliqueEllipse(h+r/2   , k+r*(sqrt(3)/2)+a, a , b , 45*3.14159/180);
    drawObliqueEllipse(h+r*(sqrt(2)/2)+(b/2)   , k+r*(sqrt(2)/2)+a, a , b , 45*3.14159/180);
    drawObliqueEllipse(h+(r*sqrt(3)/2)+a   , k+(r/4)+a-(b/2), a  , b , 20*3.14159/180);
    drawObliqueEllipse(h-(r*(sqrt(2)/2))-(b/2)   , k+r*(sqrt(2)/2)+a, a , b , 145*3.14159/180);
    drawObliqueEllipse(h-(r*sqrt(3)/2)-a   , k+(r/4)+a-(b/2), a  , b , 160*3.14159/180);
    drawObliqueEllipse(h-r*(sqrt(2)/2)-(b/2)   , k-(r*sqrt(2)/2)-a, a , b , 45*3.14159/180);
    drawObliqueEllipse(h-(r*sqrt(3)/2)-a  , k-(r/4)-a+(b/2), a  , b , 20*3.14159/180);
    drawObliqueEllipse(h+r*(sqrt(2)/2)+(b/2) , k-r*(sqrt(2)/2)-a, a , b , 145*3.14159/180);
    drawObliqueEllipse(h+(r*sqrt(3)/2)+a , k-(r/4)-a+(b/2), a  , b , 160*3.14159/180);	
// 	EllipseBresenham(h,k+(b/2)+r,a,b);
}
 int main(){

int xd, yd, xf, yf ;int n;int pas;int choix;int h,k,r;int a,b;int xdv,ydv,xfv,yfv;int ai,bi;double angle;

do{

printf ("entrer le choix : \n  ");
printf("ligne breasnham entre 0 \n");
printf("ligne polynomial entre 1 \n");
printf("translation horizontal  entre 2 \n");
printf("translation vertical entre 3 \n ");
printf("ligne vertical avec lige horizontal entre 4 \t");printf("(entre les cordonne de ligne horizontal) \n");
printf("cercle breasnham entre 5 \n");
printf("cercle polynomial entre 6 \n");
printf("cercle trigonometrique entre 7 \n");
printf("pendule entre 8\n");
printf("translation Cercle  taper 9\n");
printf("Horloge taper 10 \n");
printf("Ellipse bresnham taper 11 \n");
printf("Ellipse polynomial 12 \n ");
printf(" Ellipse Trigonométrique  13 \n");
printf(" POUR Flour 14 \n");
printf("Ellipse breasnham et polynomial taper 15 : \n");
printf("rotation ellipse taper 16 : \n");
printf("le choix est : ");
scanf("%d", &choix);


 	
 

switch(choix){

	case 0 :printf("donner x et y\n") ;
            scanf("%d %d",&xd,&yd) ;
            printf("donner xf et yf\n") ;//par exemple xf=300,yf=120
            scanf("%d %d",&xf,&yf);init_graph() ;repere();ligne(xd,yd,xf,yf,15); break;
	case 1 :printf("donner x et y\n") ;
            scanf("%d %d",&xd,&yd) ;
            printf("donner xf et yf\n") ;//par exemple xf=300,yf=120
            scanf("%d %d",&xf,&yf);init_graph() ;repere();lignePolynomial(xd,yd,xf,yf,12);break;
    case 2 :printf("donner x et y\n") ;
            scanf("%d %d",&xd,&yd) ;
            printf("donner xf et yf\n") ;//par exemple xf=300,yf=120
            printf("donner la fin de translation ");
			scanf("%d",&n);
            scanf("%d %d",&xf,&yf);init_graph() ;repere();lignehorizontal(xd,yd,xf,yf,n);break;
    case 3 :printf("donner x et y\n") ;
            scanf("%d %d",&xd,&yd) ;
            printf("donner xf et yf\n") ;//par exemple xf=300,yf=120
            scanf("%d %d",&xf,&yf);init_graph() ;repere();lignevertical(xd,yd,xf,yf,100);break;
    case 4 :printf("donner x et y\n") ;
            scanf("%d %d",&xd,&yd) ;
            printf("donner xf et yf\n") ;//par exemple xf=300,yf=120
            scanf("%d %d",&xf,&yf);
			printf("donner la fin de translation (par exemple 0))");
			scanf("%d",&n);
			init_graph() ;repere();lignehorizontal(xd,yd,xf,yf,n);lignevertical(xd,yd,xd,n,xf);break;
    case 5 :printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
            scanf("%d %d",&h,&k);
            printf("donner rayon : ") ; 
            scanf("%d",&r);init_graph() ;cerclebresenham(h,k,r,12);break;
    case 6 : printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
            scanf("%d %d",&h,&k);
            printf("donner rayon : ") ; 
             scanf("%d",&r);init_graph() ;cerclepolynomial( h, k, r);break;
    case 7 :printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
            scanf("%d %d",&h,&k);
            printf("donner rayon : ") ; 
            scanf("%d",&r);init_graph() ;CercleTrigonomtrique( h, k, r);break;
    case 8 :printf("donner x et y\n") ;
            scanf("%d %d",&xd,&yd) ;
            printf("donner xf et yf\n") ;//par exemple xf=300,yf=120
            scanf("%d %d",&xf,&yf);init_graph() ;pendul(xd,yd,xf,yf);break;
    case 9 :printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
            scanf("%d %d",&h,&k);
            printf("donner rayon : ") ; 
            scanf("%d",&r);init_graph() ;translation_cercle( h, k, r);break;
    case 10 :printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
             scanf("%d %d",&h,&k);
             printf("donner rayon : ") ; 
               scanf("%d",&r);init_graph() ;cerclebresenhamho( h, k, r );break;
    case 11:  printf("entre a demi-longeur de grand axe et b demi-longeur de petit axe");
              scanf("%d %d",&a,&b);
              printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
              scanf("%d %d",&h,&k);
			  init_graph();EllipseBresenham(h,k,a,b);    
    case 12 : printf("entre a demi-longeur de grand axe et b demi-longeur de petit axe");
              scanf("%d %d",&a,&b);
              printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
              scanf("%d %d",&h,&k);
			  init_graph();Ellipsepolynomial(h,k,a,b);break;
    case 13 :  printf("entre a demi-longeur de grand axe et b demi-longeur de petit axe");
              scanf("%d %d",&a,&b);
              printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
              scanf("%d %d",&h,&k);
			  init_graph();EllipseTrigo(a,b,h,k);
	case 14 :  
              printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
              scanf("%d %d",&h,&k);
              printf("entre le rayon r : ");
              scanf("%d",&r);
			  init_graph();//repere();
			  plant(h, k, r);	//r=60;h=0;k=0
	case 15 :  printf("entre a demi-longeur de grand axe et b demi-longeur de petit axe");
              scanf("%d %d",&a,&b);
              printf("entre a demi-longeur de grand axe et b demi-longeur de petit axe");
              scanf("%d %d",&ai,&bi);
              printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
              scanf("%d %d",&h,&k);
			  init_graph();Ellipsepolynomial(h,k,a,b);
			  EllipseBresenham(h,k,ai,bi); 	break;
	case 16 : printf("entre a demi-longeur de grand axe et b demi-longeur de petit axe");
              scanf("%d %d",&a,&b);
              printf("donner les cordonnée de centre h et k : \n") ;//par exemple xf=300,yf=120
              scanf("%d %d",&h,&k);
			  init_graph();
			  EllipseBresenham(h,k,a,b);
			  EllipseBresenhamrotcnetre(h,k,a,b,145.0 ); break;			   			  
	default :
                printf("Choix non valide.\n"); 			  			       
	 
}
printf("Voulez-vous faire un autre choix? (1 pour oui, 0 pour non): ");
 scanf("%d", &choix);

}while (choix!=0);




getch();

}

