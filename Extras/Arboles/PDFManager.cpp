#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>
#include "PDFManager.hpp"
#include "Tree.hpp"
#include "Node.hpp"
#include <vector>

using std::ostringstream;
using std::ifstream;
using std::cout;
using std::endl;
using std::ios;

static vector <int> Order;

static void demoThree(PDF &p, Tree tree_)
{
   if (tree_.getRoot()==nullptr)
   {
      cout<<"Su arbol esta vacio, Existiran datos vacios"<<endl;
   }
   
   PDFManager pd;
   string name="";
   string last_name="";
   string id="";
   string inOrder="";
   string preOrder ="";
   string postOrder="";

   p.setFont(PDF::HELVETICA_BOLD,33);
   p.showTextXY(" Arbol de Busqueda Binaria",90, 746);
   p.setFont(PDF::HELVETICA_BOLD,35);
   p.showTextXY("  A    V    L",220, 710);

   //esto es por si se puede graficar el árbol
   /*p.drawCircle(306,650,30);
   p.setFont(PDF::COURIER_OBLIQUE,16);
   p.showTextXY("35",291, 650);
   //pa la izquierda descendiendo 
   // 336 es desde donde inicia 650 altura 400 hasta donde va 600 altura entre 600 y 650
   p.drawLine(336,650,400,600);
   // aqui se aplica una logica similar
   p.drawLine(276,650,212,600);
   p.drawCircle(153+(60),575,30);
   p.drawCircle(306+(120),575,30);*/
   //*******************************
   vector<XY> points;
   points.push_back(XY(60, 760));
   points.push_back(XY(54, 750));
   points.push_back(XY(64, 750));
   points.push_back(XY(50, 740));
   points.push_back(XY(68, 740));
   points.push_back(XY(45, 730));
   points.push_back(XY(72, 730));
   points.push_back(XY(41, 720));
   points.push_back(XY(76, 720));
   points.push_back(XY(36, 710));
   points.push_back(XY(80, 710));
   p.setLineColor(0, 255, 0);
   p.drawLine(points);
   points.clear();
   points.push_back(XY(60, 758));
   points.push_back(XY(54, 748));
   points.push_back(XY(64, 748));
   points.push_back(XY(50, 738));
   points.push_back(XY(68, 738));
   points.push_back(XY(45, 728));
   points.push_back(XY(72, 728));
   points.push_back(XY(41, 718));
   points.push_back(XY(76, 718));
   points.push_back(XY(36, 708));
   points.push_back(XY(80, 708));
   p.setLineColor(12, 144, 80);
   p.drawLine(points);

   points.clear();
   points.push_back(XY(60, 756));
   points.push_back(XY(54, 746));
   points.push_back(XY(64, 746));
   points.push_back(XY(50, 736));
   points.push_back(XY(68, 736));
   points.push_back(XY(45, 726));
   points.push_back(XY(72, 726));
   points.push_back(XY(41, 716));
   points.push_back(XY(76, 716));
   points.push_back(XY(36, 706));
   points.push_back(XY(80, 706));
   p.setLineColor(132, 144, 12);
   p.drawLine(points);

   points.clear();
   points.push_back(XY(64, 760));
   points.push_back(XY(58, 750));
   points.push_back(XY(68, 750));
   points.push_back(XY(54, 740));
   points.push_back(XY(72, 740));
   points.push_back(XY(49, 730));
   points.push_back(XY(76, 730));
   points.push_back(XY(45, 720));
   points.push_back(XY(80, 720));
   points.push_back(XY(40, 710));
   points.push_back(XY(84, 710));
   p.setLineColor(28, 210, 152);
   p.drawLine(points);
   points.clear();

   //**************************************
   points.push_back(XY(540, 760));
   points.push_back(XY(534, 750));
   points.push_back(XY(544, 750));
   points.push_back(XY(530, 740));
   points.push_back(XY(548, 740));
   points.push_back(XY(525, 730));
   points.push_back(XY(552, 730));
   points.push_back(XY(521, 720));
   points.push_back(XY(556, 720));
   points.push_back(XY(516, 710));
   points.push_back(XY(560, 710));
   p.setLineColor(28, 136, 210);
   p.drawLine(points);
   points.clear();
   points.push_back(XY(540, 758));
   points.push_back(XY(534, 748));
   points.push_back(XY(544, 748));
   points.push_back(XY(530, 738));
   points.push_back(XY(548, 738));
   points.push_back(XY(525, 728));
   points.push_back(XY(552, 728));
   points.push_back(XY(521, 718));
   points.push_back(XY(556, 718));
   points.push_back(XY(516, 708));
   points.push_back(XY(560, 708));
   p.setLineColor(12, 144, 80);
   p.drawLine(points);

   points.clear();
   points.push_back(XY(540, 756));
   points.push_back(XY(534, 746));
   points.push_back(XY(544, 746));
   points.push_back(XY(530, 736));
   points.push_back(XY(548, 736));
   points.push_back(XY(525, 726));
   points.push_back(XY(552, 726));
   points.push_back(XY(521, 716));
   points.push_back(XY(556, 716));
   points.push_back(XY(516, 706));
   points.push_back(XY(560, 706));
   p.setLineColor(27, 151, 149);
   p.drawLine(points);

   points.clear();
   points.push_back(XY(544, 760));
   points.push_back(XY(538, 750));
   points.push_back(XY(548, 750));
   points.push_back(XY(534, 740));
   points.push_back(XY(552, 740));
   points.push_back(XY(529, 730));
   points.push_back(XY(556, 730));
   points.push_back(XY(525, 720));
   points.push_back(XY(560, 720));
   points.push_back(XY(520, 710));
   points.push_back(XY(564, 710));
   p.setLineColor(187, 187, 35);
   p.drawLine(points);
      /*p.drawRect(
         xValue,
         yValue,
         (int)(scale * info.mWidth  + 0.5),
         (int)(scale * info.mHeight + 0.5)
      );*/
    //******************************


    p.setFont(PDF::HELVETICA_BOLD,12);
    p.showTextXY("INFORME ",90,650);
    p.setFont(PDF::HELVETICA_BOLD_OBLIQUE,12);
    p.showTextXY("Datos personales ",90,620);
    p.showTextXY("Nombre: ",90,605);
    p.showTextXY("Apellido: ",90,590);
    p.showTextXY("Cedula: ",90,575);
    
    p.showTextXY("Arbol en InOrden: ",90,525);
    p.showTextXY("Arbol en PreOrden: ",90,495);
    p.showTextXY("Arbol en PostOrden: ",90,465);


    p.setFont(PDF::HELVETICA,12);
    pd.getInORder(tree_);
    inOrder= pd.convert_(Order);
    Order.clear();
    p.showTextXY(inOrder,90,510);
    //
    pd.getPreOrder(tree_);
    preOrder= pd.convert_(Order);
    Order.clear();
    p.showTextXY(preOrder,90,480);
    //
    pd.getPostOrder(tree_);
    postOrder= pd.convert_(Order);
    Order.clear();
    p.showTextXY(postOrder,90,450);
    //Ocupo el método para pasar los datos.
    p.showTextXY(name,220,605);
    p.showTextXY(last_name,220,590); 
    p.showTextXY(id,220,575);
    //****************************************
   //Pie de página 
   p.setFont(PDF::TIMES_BOLD,10);
   p.showTextXY("Autores:      Iza Christopher    - * -    Rea Denise     - * -    Guacan Alexander     - * -    Moncayo Alison    ",30, 20);
}

void PDFManager::generatePDF(Tree tree_)
{
    typedef void (*DemoFunction)(PDF &,Tree);

   DemoFunction functions[] =
   {
      demoThree
   };
      ostringstream out;
      out << "Arbol_AVL-I-G-M-R.pdf";
      string fileName = out.str();
      PDF pdf;
      functions[0](pdf,tree_);
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


std::string PDFManager:: convert_(std::vector<int> order_)
{
   std::string chain;
   for (int i = 0; i < order_.size(); i++)
   {
      chain+= std::to_string(order_[i])+" ";
   }
   return chain;
}

void PDFManager::Recursive_getInOrder(Node *&root){
   if (root != nullptr) {
        Recursive_getInOrder(root->getLeftNode());
        Order.push_back(root->getValue());
        Recursive_getInOrder(root->getRightNode());
    }
}

void PDFManager::Recursive_getPreOrder(Node *&root){
   if (root != nullptr) {
        Order.push_back(root->getValue());
        Recursive_getInOrder(root->getLeftNode());
        Recursive_getInOrder(root->getRightNode());
    }
}

void PDFManager::Recursive_getPostOrder(Node *&root){
   if (root != nullptr) {
        Recursive_getInOrder(root->getLeftNode());
        Recursive_getInOrder(root->getRightNode());
        Order.push_back(root->getValue());
    }
}

void PDFManager::getInORder(Tree &tree_){
      Recursive_getInOrder(tree_.getRoot());
}

void PDFManager::getPreOrder(Tree &tree_){
      Recursive_getPreOrder(tree_.getRoot());
}

void PDFManager::getPostOrder(Tree &tree_){
      Recursive_getPostOrder(tree_.getRoot());
}