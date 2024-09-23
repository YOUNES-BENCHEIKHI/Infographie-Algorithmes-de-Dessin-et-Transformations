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
    initwindow(1500, 750, "Ma fenêtre");
	}
//void repere(){
//
//cleardevice() ;
////setbkcolor(9) ;
//setcolor(15) ; 
// 
//line(0,375, 1500,375) ;
//
//line(500, 0, 500,750) ;
//}
void repere() {
    cleardevice();
    
    // Dessiner l'axe x (rouge)
    setcolor(RED);
    line(500,375, 1200,375) ;

    // Dessiner l'axe y (vert)
    setcolor(YELLOW);
    line(500, 20, 500,375);

    // Dessiner l'axe z (bleu)
    setcolor(WHITE);
    line(500, 375, 0, 660);

    // Étiquettes des axes
    setcolor(WHITE);
    outtextxy(1210, 375, "X");
    outtextxy(500, 10, "Y");
    outtextxy(0, 670, "Z");
}


void pixel (int x, int y, int color){

 x = x + 320;
 y = 240 - y;
 printf("Transformed coordinates: x=%d, y=%d\n", x, y);
 putpixel(x, y, color);
}
void linee(int x, int y, int x1, int y1) {
  x = x + 320;
  y = 240 - y; 
  x1 = x1 + 320;
  y1 = 240 - y1;
  line(x, y, x1, y1);
}
void produit_deux_matrice(double Result[8][4],double X[8][4],double M[4][4]){
    int i, j, k, l;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            int sum = 0;
            for (k = 0, l = 0; l < 4 && k < 4; k++, l++) {
                sum += X[i][k] * M[l][j];
            }
            Result[i][j] = sum;
        }
    }
}	
void produit_deux_matrice_caree(double Result[4][4],double X[4][4],double M[4][4]){
    int i, j, k, l;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            int sum = 0;
            for (k = 0, l = 0; l < 4 && k < 4; k++, l++) {
                sum += X[i][k] * M[l][j];
            }
            Result[i][j] = sum;
        }
    }
}

void projection_cube( double Resultat[8][4],double X[8][4]) {
	double a = sqrt(2) / 2;
	  double MP[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {a, a, 0, 0},
        {0, 0, 0, 1}
    };
    produit_deux_matrice(Resultat, X,MP);
}

void tracer_cub(double Result[8][4],int distanceX,int distanceY,int color){
	setcolor(color) ;
 	outtextxy(Result[0][0]+distanceX,distanceY-Result[0][1], "B");
    outtextxy(Result[1][0]+distanceX,distanceY-Result[1][1], "F");
    outtextxy(Result[2][0]+distanceX,distanceY-Result[2][1], "H");
    outtextxy(Result[3][0]+distanceX,distanceY-Result[3][1], "D");
    outtextxy(Result[4][0]+distanceX,distanceY-Result[4][1], "C");
    outtextxy(Result[5][0]+distanceX,distanceY-Result[5][1], "A");
    outtextxy(Result[6][0]+distanceX,distanceY-Result[6][1], "E");
    outtextxy(Result[7][0]+distanceX,distanceY-Result[7][1], "G");
   line(Result[0][0]+distanceX,distanceY-Result[0][1],Result[1][0]+distanceX,distanceY-Result[1][1]);
   line(Result[1][0]+distanceX,distanceY-Result[1][1],Result[2][0]+distanceX,distanceY-Result[2][1]);
   line(Result[2][0]+distanceX,distanceY-Result[2][1],Result[3][0]+distanceX,distanceY-Result[3][1]);
   line(Result[0][0]+distanceX,distanceY-Result[0][1],Result[3][0]+distanceX,distanceY-Result[3][1]);
   line(Result[3][0]+distanceX,distanceY-Result[3][1],Result[4][0]+distanceX,distanceY-Result[4][1]);
   line(Result[4][0]+distanceX,distanceY-Result[4][1],Result[7][0]+distanceX,distanceY-Result[7][1]);
   line(Result[1][0]+distanceX,distanceY-Result[1][1],Result[6][0]+distanceX,distanceY-Result[6][1]);
   line(Result[6][0]+distanceX,distanceY-Result[6][1],Result[7][0]+distanceX,distanceY-Result[7][1]);
   line(Result[5][0]+distanceX,distanceY-Result[5][1],Result[6][0]+distanceX,distanceY-Result[6][1]);
   line(Result[4][0]+distanceX,distanceY-Result[4][1],Result[5][0]+distanceX,distanceY-Result[5][1]);
   line(Result[2][0]+distanceX,distanceY-Result[2][1],Result[7][0]+distanceX,distanceY-Result[7][1]);
   line(Result[0][0]+distanceX,distanceY-Result[0][1],Result[5][0]+distanceX,distanceY-Result[5][1]);
   
}
void Translation(double Result1[8][4],double X[8][4],int translaX,int translY,int translZ){
	 double MT[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0,1, 0},
        {translaX,translY,translZ, 1}
    }; 
    
	double Result[8][4];
	produit_deux_matrice(Result,X,MT);
	
	projection_cube(Result1,Result);
	
}

void rotation_axeX(double X[8][4],double degre){
	 double MR[4][4] = {
        {1, 0, 0, 0},
        {0, cos(degre), sin(degre), 0},
        {0, -sin(degre),cos(degre), 0},
        {0, 0, 0, 1}
    };
    double Result[8][4]; double Result1[8][4];
    produit_deux_matrice(Result,X,MR);
	projection_cube(Result1,Result);
    tracer_cub(Result1,500,375,15);
   
}
void rotation_axeY(double X[8][4],double degre){
	 double MR[4][4] = {
        {cos(degre), 0,-sin(degre), 0},
        {0, 1,0, 0},
        {sin(degre), 0,cos(degre), 0},
        {0, 0, 0, 1}
    };
    double Result[8][4]; double Result1[8][4];
    produit_deux_matrice(Result,X,MR);
	projection_cube(Result1,Result);
    tracer_cub(Result1,500,375,15);
   
}
void rotation_axeZ(double X[8][4],double degre){
	 double MR[4][4] = {
        {cos(degre),sin(degre),0, 0},
        {-sin(degre), cos(degre),0, 0},
        {0, 0,1, 0},
        {0, 0, 0, 1}
    };
    double Result[8][4]; double Result1[8][4];
    produit_deux_matrice(Result,X,MR);
	projection_cube(Result1,Result);
     tracer_cub(Result1,500,375,15);
   
}
void SymetrieXY(double Result1[8][4],double X[8][4]){
	 double MT[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0,-1, 0},
        {0, 0, 0, 1}
    };
	double Result[8][4];int i,j;
	produit_deux_matrice(Result,X,MT);
	projection_cube(Result1,Result);
}
void SymetrieXZ(double Result1[8][4],double X[8][4]){
	 double MT[4][4] = {
        {1, 0, 0, 0},
        {0,-1, 0, 0},
        {0, 0,1, 0},
        {0, 0, 0, 1}
    };
	double Result[8][4];int i,j;
	produit_deux_matrice(Result,X,MT);
	projection_cube(Result1,Result);
}
void SymetrieYZ(double Result1[8][4],double X[8][4]){
	 double MT[4][4] = {
        {-1, 0, 0, 0},
        {0,1, 0, 0},
        {0, 0,1, 0},
        {0, 0, 0, 1}
    };
	double Result[8][4];int i,j;
	produit_deux_matrice(Result,X,MT);
	projection_cube(Result1,Result);
}
//void rotation_axe_quelconque( double X[8][4], double alpha, double beta, double gama, double angle) {
//	
//    double cos_theta = cos(angle);
//    double sin_theta = sin(angle);
//
//    double a = cos(alpha);
//    double b = cos(beta);
//    double c = cos(gama);
//    double R[4][4] = {
//        {pow(a,2)+ (1 - pow(a,2))* cos_theta, a*b* (1 - cos_theta) + c * sin_theta, a * c * (1 - cos_theta) -b * sin_theta, 0},
//        {b * a * (1 - cos_theta) - c * sin_theta, pow(b,2)+(1-pow(b,2))*cos_theta, b * c * (1 - cos_theta) +a * sin_theta, 0},
//        {b * a * (1 - cos_theta) - b * sin_theta, b * c * (1 - cos_theta) - a * sin_theta, pow(c,2)+(1-pow(c,2))*cos_theta, 0},
//        {0, 0, 0, 1}
//    };
//int i;double Result1[8][4];double Result2[8][4],
//    produit_deux_matrice(Result1,X,R);
//    projection_cube(Result2, Result1);
//     tracer_cub(Result2,500,375,15);
//}
void rotation_axe_quelconque(double X[8][4], double alpha, double beta, double gama, double angle) {

    double cos_theta = cos(angle);
    double sin_theta = sin(angle);

    double a = cos(alpha);
    double b = cos(beta);
    double c = cos(gama);

    double R[4][4] = {
        {pow(a,2)+ (1 - pow(a,2))*cos_theta, a*b*(1 - cos_theta) + c*sin_theta, a*c*(1 - cos_theta) - b*sin_theta, 0},
        {b*a*(1 - cos_theta) - c*sin_theta, pow(b,2)+(1-pow(b,2))*cos_theta, b*c*(1 - cos_theta) + a*sin_theta, 0},
        {b*a*(1 - cos_theta) - b*sin_theta, b*c*(1 - cos_theta) - a*sin_theta, pow(c,2)+(1-pow(c,2))*cos_theta, 0},
        {0, 0, 0, 1}
    };

    double Result1[8][4];
    double Result2[8][4];

    produit_deux_matrice(Result1, X, R);
    projection_cube(Result2, Result1);
    tracer_cub(Result2, 500, 375, 15);
}

void remplacer(double Result[8][4],double X[8][4]){
	int i,j;
	for (i = 0; i < 8; i++) {
        for (j = 0; j < 2; j++) {
        	 Result[i][j]=X[i][j]/X[i][3];
            }
            
        }
}  
void PerspectiveZ(double Result2[8][4], double X[8][4], double r){
	
//	double MR[4][4] = {
//        {cos(degre), 0,0, -sin(degre)/perspective},
//        {0, 1,0, 0},
//        {sin(degre), 0,0, cos(degre)/perspective},
//        {0, translatey,0, (translatez/perspective)+1}
//    };
    double MT[4][4] = {
        {1, 0, 0, 0},
        {0,-1, 0, 0},
        {0, 0,0, 1/r},
        {0, 0, 0, 1}
    };
    double Result[8][4]; double Result1[8][4];
    produit_deux_matrice(Result,X,MT);
    projection_cube(Result1,Result);
    remplacer(Result2,Result1);int i,j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 2; j++) {
        	 printf("%lf \t",Result2[i][j]);
            }
            printf("\n");
        }
}
//void calcul_deta1(double X[8][4],double a,double b,double c)
void TransformationT( double X[8][4],double a,double b,double c,double degre){
//	
	double MR[4][4] = {
        {cos(degre), 0,-sin(degre), 0},
        {0, 1,0, 0},
        {sin(degre), 0,cos(degre), 0},
        {0, 0, 0, 1}
    };
//    double Result[8][4]; double Result1[8][4];
//    produit_deux_matrice(Result,X,MR);
//	projection_cube(Result1,Result);
//    tracer_cub(Result1,500,375,15);
//	
	
	double B=sqrt(b*b + c*c);
double A = sqrt(a*a + b*b + c*c);
	double MT_inverse[4][4] = {
        {B/A,(-a*b)/(A*B),(-c*a)/(A*B), 0},
        {0,c/B, -b/B, 0},
        {a/A, b/A,c/B, 0},
        {0, 0, 0, 1}
    };
    double Result[8][4]; double Result1[8][4];double Result2[8][4];
    produit_deux_matrice(Result,X,MT_inverse);
    produit_deux_matrice(Result1,Result,MR);
    projection_cube(Result2,Result1);
    tracer_cub(Result2,500,375,15);
    
}

int main()	{int choix;
	double X[8][4] = {
        {0, 0, 0, 100},
        {100, 0, 0, 100},
        {100, 100, 0, 100},
        {0, 100, 0, 100},
        {0, 100, 100, 100},
        {0, 0, 100, 100},
        {100, 0, 100, 100},
        {100, 100, 100, 100}
    };
     double angle =-M_PI/2.0 ;/////////////pour la rotation axe X,Y,Z
   
   
     double anglee = M_PI/2 ;//////////////////pour un axe quelconque
	///////////////////////////////////////////:translation

////////////////////////////////////////////////////:rotation par x
//	double Rotx[8][4];
//	rotation_axeX(Rotx,X,angle);
//	tracer_cub(Rotx,200,375,12);
///////////////////////////////////////////////////:rotation par y
//	double Roty[8][4];
//	rotation_axeY(Roty,X,angle);
//	tracer_cub(Roty,800,375,4);
//////////////////////////////////////////////////:rotation par z
//	double Rotz[8][4];
//	rotation_axeZ(Rotz,X,angle);
//	tracer_cub(Rotz,800,375,4);
///////////////////////////////////////////////////:rotation par an axe quelconque 
   
//    rotation_axe_quelconque(Result, X,M_PI/2, M_PI/2,0,anglee);
//    tracer_cub(Result,300,400,12);
///////////////////////////////////////////////////: symetrique par xy

//    double symetrie_xy[8][4]; 
//    SymetrieXY(symetrie_xy,X);
//	tracer_cub(symetrie_xy,500,300,12);
///////////////////////////////////////////////////:symetrie par xz
//    double symetrie_xz[8][4]; 
//    SymetrieXZ(symetrie_xz,X);
//	tracer_cub(symetrie_xz,400,600,12);
////////////////////////////////////////////////:::::symetrie pa yz
//    double symetrie_yz[8][4]; 
//    SymetrieYZ(symetrie_yz,X);
//	tracer_cub(symetrie_yz,400,600,12);
do{

printf("si vouler translation Taper 1 : \n");
printf("rotation par rapport a X Taper 2:\n");
printf("rotation par rapport a Y Taper 3: \n");
printf("rotation par rapport a Z Taper 4 : \n");
printf("rotation par rapport un axe quelconque Taper 5: \n");
printf("Symetrie par rapport XY Taper 6:\n");
printf("Symetrie par rapport XZ Taper 7:\n");
printf("Symetrie par rapport YZ Taper 8:\n");
printf("Perspective Taper 9:\n");
printf("le choix est : ");
scanf("%d", &choix);
switch(choix){ 
    case 1:
    	int translationx,translationy,trnslationz;
    	  printf("donner la valeur de translation :\n");
    	  printf("pour X : ");scanf("%d",&translationx);
    	  printf("pour Y : ");scanf("%d",&translationy);
    	  printf("pour Z : ");scanf("%d",&trnslationz);
    	 double Result[8][4];
	     double translate[8][4]; 
	     projection_cube(Result,X);
      	Translation(translate,X,translationx,translationy,trnslationz);
     	init_graph()  ;
        repere();
        tracer_cub(Result,500,375,15);
     	tracer_cub(translate,500,375,12);break;
    case 2: 
        
	   	double Rotx[8][4];
     	
     	init_graph();
     	repere();
     	rotation_axeX(X,angle);
     	delay(100);
        cleardevice();
        while(true){
          repere();
          rotation_axeX(X,angle);
          angle+=2*PI/100;
          delay(100);
          cleardevice();
        }
//	     projection_cube(Result,X);
//	     tracer_cub(Result,500,375,15);
//        tracer_cub(Rotx,200,375,12); 
                	break;
    case 3:
	    double Roty[8][4];
     	
     	init_graph();
     	repere();
     	rotation_axeY(X,angle);
     	delay(100);
        cleardevice();
        while(true){
          repere();
          rotation_axeY(X,angle);
          angle+=2*PI/100;
          delay(100);
          cleardevice();
        }
//	     projection_cube(Result,X);
//	     tracer_cub(Result,500,375,15);
//        tracer_cub(Roty,200,375,12);     
            break;
    case 4:
	    double Rotz[8][4];
     	
     	init_graph();
     	repere();
     	rotation_axeZ(X,angle);
     	delay(100);
        cleardevice();
        while(true){ 
          repere();
          rotation_axeZ(X,angle);
          angle+=2*PI/100;
          delay(100);
          cleardevice();
        }
	         break;
    case 5:
    	init_graph();
     	repere();
     	rotation_axe_quelconque(X,M_PI/2 , M_PI/2.0 , M_PI/2.0,anglee);
     	delay(100);
        cleardevice();
        while(true){
          repere();
        rotation_axe_quelconque(X,M_PI/2,M_PI/2 ,0,anglee);
          anglee+=2*PI/100;
          delay(100);
          cleardevice();
        }  
	      break;
    case 6 :
    	init_graph();
     	repere();
	     projection_cube(Result,X);
	     tracer_cub(Result,500,375,15);
	    double symetrie_xy[8][4]; 
        SymetrieXY(symetrie_xy,X);
	    tracer_cub(symetrie_xy,500,300,12);   break; 
    case 7 :
    	init_graph();
     	repere();
	     projection_cube(Result,X);
	     tracer_cub(Result,500,375,15);
	    double symetrie_xz[8][4]; 
        SymetrieXZ(symetrie_xz,X);
	    tracer_cub(symetrie_xz,500,300,12);	break;
	case 8 :
    	init_graph();
     	repere();
	     projection_cube(Result,X);
	     tracer_cub(Result,500,375,15);
	  
		 
		  double symetrie_yz[8][4]; 
        SymetrieYZ(symetrie_yz,X);
	    tracer_cub(symetrie_yz,500,300,12);	break;
			 
	case 9 :		
		init_graph();
     	repere();
     	TransformationT( X,30,50,100,anglee);
     	delay(100);
        cleardevice();
        while(true){
        repere();
       	TransformationT( X,30,50,100,anglee);
        anglee+=2*PI/100;
        delay(100);
        cleardevice();
        }  
	      break;
    
	default :
                printf("Choix non valide.\n"); 			  			       
	
}
printf("Voulez-vous faire un autre choix? (1 pour oui, 0 pour non): ");
 scanf("%d", &choix);

}while(choix!=0);

    getch();
}
	
	
