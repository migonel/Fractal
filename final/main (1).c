/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Ariel Martorell, Lucas Migone, Francisco Carricart, Juan Schinocca
 *
 * Created on November 10, 2017, 1:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "curvak.h"



#define TERMINAR ALLEGRO_KEY_ESCAPE 




int main(void) 
{
   ALLEGRO_EVENT_QUEUE * event_queue = NULL;
   ALLEGRO_DISPLAY *display = NULL; 
   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
 
   if(!al_init_primitives_addon()){
	  fprintf(stderr, "failed to initialize primitives!\n");
	  return -1;
   }
   
   display = al_create_display(2100, 2100);
 
   if(!display) {
	  al_shutdown_primitives_addon();
	  fprintf(stderr, "failed to create display!\n");
      return -1;
   }
   
   if(!al_install_keyboard()) 
        {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}
   
   event_queue = al_create_event_queue();
	if(!event_queue) 
        {
		fprintf(stderr, "failed to create event_queue!\n");
		return -1;
        }
   
 
	
        
        al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source()); 
        
        bool salir = false;
        
        int orden = 2;
      
  copo_final(orden);
  
  
 
        
        while(!salir)
	{
                ALLEGRO_EVENT ev;
                if( al_get_next_event(event_queue, &ev) )
                {
                    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
                    {
                        if(ev.keyboard.keycode== TERMINAR)
                                        salir= true;
                    }
                }
        }
   
   al_rest(1.0);
   
   
   
   al_destroy_display(display);
   al_shutdown_primitives_addon();
   return 0;
}




