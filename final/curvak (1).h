/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   curvak.h
 * Author: ariel
 *
 * Created on November 10, 2017, 1:56 PM
 */

#ifndef CURVAK_H
#define CURVAK_H

#include <math.h>



#define LARGO 300

#define CASO_BASE 0
#define TOLERANCIA 2.0

#define START_X  500.0
#define START_Y  500.0 

#include <allegro5/allegro5.h>
#include <allegro5/allegro_color.h> 
#include <allegro5/allegro_primitives.h> 



void encontrar_coordenada( double pxi, double pyi, double angulo, double largo, double * pxf, double * pyf);
//funcion que me permite encontrar las coordenadas siguientes del punto proximo de la siguiente linea


void crear_copo(int orden, double largo, double angulo, double px, double py );
//funcion recursiva que hace la curva de koch del orden indicado y si en las iteraciones el largo se vuelve mas chico que
//la tolerancia declarada se dibujo hasta el orden en que el largo no sea mas chico que esa tolerancia

void copo_final(int n);
//crea la version final del copo de nieve uniendo 3 curvas de koch



#endif /* CURVAK_H */





