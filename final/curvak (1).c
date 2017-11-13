/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "curvak.h"


#define GRADOS_A_RADIANES(x)   (x*M_PI/180)    //para pasar el angulo de grados a radianes


void crear_copo(int orden, double largo, double angulo, double px, double py)
{
    double pxi=px;
    double pyi=py;
    
    double pxf=(px+(largo/3.0));
    double pyf=py;
    
    encontrar_coordenada(pxi,pyi,angulo,largo/3.0,&pxf,&pyf);
    
    
    if(largo <= TOLERANCIA)
    {
        orden=0;
    }
    
        if(orden==CASO_BASE)
        {
            al_draw_line((float)pxi,(float) pyi, (float) pxf , (float) pyf, al_color_name("hotpink") , 1.0 );
            al_flip_display();
        } 
        else
        {
            crear_copo(orden -1, largo/3.0 ,0.0+angulo , pxi, pyi );    //para dibbujar la primera parte de la primera linea
        }
     
        pxi=pxf;
        pyi=pyf;
        encontrar_coordenada(pxi,pyi,angulo+60.0,largo/3,&pxf,&pyf);

        
        
        
        if(orden==CASO_BASE)    //roto 60 grados la primera linea
        {
            al_draw_line((float)pxi,(float) pyi, (float) pxf , (float) pyf, al_color_name("hotpink") , 1.0 );
            al_flip_display();
        } 
        else
        {
            crear_copo(orden -1, largo/3.0,60+angulo , pxi, pyi ); 
        }
     
        pxi=pxf;
        pyi=pyf;
        encontrar_coordenada(pxi,pyi,angulo+300.0,largo/3.0,&pxf,&pyf);
        
        
      
        
            if(orden==CASO_BASE)    //roto 240 en sentido antihorario la segunda
        {
            al_draw_line((float)pxi,(float) pyi, (float) pxf , (float) pyf, al_color_name("hotpink") , 1.0 );
            al_flip_display();
        } 
        else
        {
            crear_copo(orden -1, largo/3.0 ,300.0+angulo , pxi, pyi );    
        }
     
        pxi=pxf;
        pyi=pyf;
        encontrar_coordenada(pxi,pyi,angulo+0.0,largo/3.0,&pxf,&pyf);
        
        
   
            if(orden==CASO_BASE)    //por ultimo hago una ultima rotacion
        {
            al_draw_line((float)pxi,(float) pyi, (float) pxf , (float) pyf, al_color_name("hotpink") , 1.0 );
            al_flip_display();
            pxi=pxf;
            pyi=pyf;

        } 
        else
        {
            crear_copo(orden -1, largo/3.0 ,0.0+angulo , pxi, pyi );   
        }
 
    
    
}







void copo_final(int n)
{
    double px1_triangulo,py1_triangulo;
    double px2_triangulo,py2_triangulo;
    
    if (n==CASO_BASE)
    {
     encontrar_coordenada(START_X,START_Y,60.0,LARGO,&px1_triangulo,&py1_triangulo);
     encontrar_coordenada(START_X,START_Y,0.0,LARGO,&px2_triangulo,&py2_triangulo);
     
     al_draw_triangle(START_X,START_Y,px1_triangulo,py1_triangulo,px2_triangulo,py2_triangulo,al_color_name("lemonchiffon"),1);
     al_flip_display();
             
    }
    else
    {
        double px,py;
        double pxf,pyf;

        crear_copo(n,LARGO,60.0,START_X,START_Y);
        encontrar_coordenada(START_X,START_Y,60.0,LARGO,&px,&py);
        crear_copo(n,LARGO,300.0,px,py);
        encontrar_coordenada(px,py,300.0,LARGO,&px,&py);
        crear_copo(n,LARGO,180.0,px,py);

    }
}





void encontrar_coordenada( double pxi, double pyi, double angulo, double largo, double * pxf, double * pyf)
{
    double angulo_en_rad=GRADOS_A_RADIANES(angulo);
    
    *pxf=(pxi+(largo*cos(angulo_en_rad)));  //calculo la siguiente coordenada en x
    *pyf=(pyi-(largo*sin(angulo_en_rad)));  //calculo la siguiente coordenada en y
}
