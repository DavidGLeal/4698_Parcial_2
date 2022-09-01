/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    Luca de Veintemilla
				Kevin Vargas 
                Cristopher Iza
                Denisse Rea
					
	FECHA DE CREACION:        20-05-2022 	
	FECHA DE MODIFICACION:    24-05-2022
	Grupo #6
*/ 
#ifndef _METRICS_HPP_
#  define _METRICS_HPP_

#  include "pdf.hpp"

   class Metrics
   {
      public:

         static int *get(PDF::Font theFont);

      private:

         Metrics();
   };

#endif
