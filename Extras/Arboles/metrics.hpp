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
