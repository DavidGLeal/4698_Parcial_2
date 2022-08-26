/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
INGENIERIA DE SOFTWARE             
	AUTORES:
		Johan Romo
		Cristhopher Villamarin
		Sebastian Torres
                Jeanhela Nazate
                Milena Maldonado
                Shared Tinoco
		Brandon Masacela
		Juan Reyes
        GRUPOS: 7 - 10 - 11 - 14
        FECHA DE CREACION:        Viernes, 1 de julio de 2022 7:34:00 p. m. 	
	FECHA DE MODIFICACION:    Martes, 19 de junio de 2022 4:58:00 p. m.
        PROPOSITO: Proyecto Segundo Parcial - Arboles B
*/

#ifndef _METRICS_H_
#  define _METRICS_H_

#  include "pdf.h"

   class Metrics
   {
      public:

         static int *get(PDF::Font theFont);

      private:

         Metrics();
   };

#endif
