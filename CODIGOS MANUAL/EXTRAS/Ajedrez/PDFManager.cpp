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
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>
#include "PDFManager.hpp"
#include "pdf.hpp"

//#include <vector>

using std::ostringstream;
using std::ifstream;
using std::cout;
using std::endl;
using std::ios;

static vector <int> Order;

static void demoThree(PDF &p)
{
   PDFManager pd;
   vector<std::string> texto;
   string nombreArch;
   vector<XY> points;
   ImageRow row1;
   ImageRow row2;

   row1.push_back(RGB(0, 0, 0));
   row1.push_back(RGB(255,255, 255));
   row1.push_back(RGB(  0, 0,  0));
   row1.push_back(RGB(255,255, 255));
   row1.push_back(RGB(  0, 0,  0));
   row1.push_back(RGB(255,255, 255));
   row1.push_back(RGB(  0, 0,  0));
   row1.push_back(RGB(  255, 255, 255));


   row2.push_back(RGB(  255, 255, 255));
   row2.push_back(RGB(0, 0,   0));
   row2.push_back(RGB(  255, 255, 255));
   row2.push_back(RGB(  0, 0,  0));
   row2.push_back(RGB(  255, 255, 255));
   row2.push_back(RGB(  0, 0,  0));
   row2.push_back(RGB(  255, 255, 255));
   row2.push_back(RGB(  0, 0,  0));


   Image anImage;

   anImage.push_back(row1);
   anImage.push_back(row2);
   anImage.push_back(row1);
   anImage.push_back(row2);
   anImage.push_back(row1);
   anImage.push_back(row2);
   anImage.push_back(row1);

   ImageInfo info = p.processImage(anImage);
   double scale   = 10.0;
   int xValue = 50 ; 
      int yValue =680 ;
   p.showImage(info, xValue, yValue, scale);
    p.drawRect(
         xValue,
         yValue,
         (int)(scale * info.mWidth  + 0.5),
         (int)(scale * info.mHeight + 0.5)
      );

   p.drawCircle(512,750,15);
   points.push_back(XY(527, 735));
   points.push_back(XY(495, 735));
   points.push_back(XY(495, 730));
   points.push_back(XY(527, 730));
   points.push_back(XY(527, 735));
   p.setLineColor(0, 0, 0);
   p.drawLine(points);
   points.clear();
   points.push_back(XY(500, 730));
   points.push_back(XY(495, 680));
   points.push_back(XY(532, 680));
   points.push_back(XY(523, 730));
   p.setLineColor(0, 0, 0);
   p.drawLine(points);
   //********************************Título***********************************
   p.setFont(PDF::TIMES_BOLD_ITALIC,35);
   p.showTextXY("  A J E D R E Z ",170, 710);
   //************************Pie de Página************************************
   p.setFont(PDF::TIMES_BOLD,10);
   p.showTextXY("Autores:      Iza Christopher    - * -    Rea Denise     - * -    De Veintemilla Luca     - * -    Vargas Kevin    ",30, 20);

   //*************************Contenido******************************************
   nombreArch =pd.IngresarNombre();
   texto= pd.Obtener_datos(nombreArch);
   for (int i = 0; i < texto.size(); i++)
   {
      p.setFont(PDF::TIMES_BOLD,15);
      p.showTextXY(texto[i],45,650-i*15);
   }
   
}

void PDFManager::generatePDF()
{
    typedef void (*DemoFunction)(PDF &p);

   DemoFunction functions[] =
   {
      demoThree
   };
      ostringstream out;
      out << "Ajedrez_DV-I-R-V.pdf";
      string fileName = out.str();
      PDF pdf;
      functions[0](pdf);
      string errMsg;
      if(!pdf.writeToFile(fileName, errMsg))
      {
         cout << errMsg << endl;
      }
      else
      {
         cout << "(Reporte PDF Generado  de forma Exitosa, presione 2 veces Enter)" << endl;
         getchar();
         getchar();
      }
}

std::vector <std::string> PDFManager:: Obtener_datos(std::string nombre)
{
    std::ifstream lectura;
    std::vector <std::string> el_texto;
    lectura.open(nombre, std::ios::in);
    std::string texto;
    while (!lectura.eof())
    {
        std::getline(lectura,texto);
        el_texto.push_back(texto);
    }
    return el_texto;
}

bool PDFManager:: verif_nombreArch(std::string nombre)
{
    bool Verif;
    std::ofstream lectura;
    lectura.open(nombre+".txt",std::ios::in);
    if (!lectura.is_open())
    {
    Verif=true;
    }
    else
    {
    Verif =false;
    }
    return Verif;
}

std::string PDFManager::IngresarNombre()
{
    std::string nombreArc="";
    while (verif_nombreArch(nombreArc))
    {
    std::cout<<"\n Digite el nombre del archivo a generar el informe (sin extension):"<<std::endl;
    std::cin>>nombreArc;
    }
    return nombreArc+".txt";
}
