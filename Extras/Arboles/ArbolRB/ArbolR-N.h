#pragma once
/*
* @flie ArbolR-N.h
* @author Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos - Estructura de Datos
* @date 19/7/2022
* @brief Archivo de cabecera para la clase ArbolR-N.h
* @version 1.0
* 
*@copyright Copyright (c) 2022,Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos 
*@license MIT License
*/
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"

using namespace std;

class ArbolRN{
private:
    Nodo* root;
    /**
     * @brief Get the Color object
     * 
     * @return int 
     */
    int getColor(Nodo* );
    /**
     * @brief Set the Color object
     * 
     */
    void setColor(Nodo*& , int );
    /**
     * @brief method to rotate left
     * 
     * @return Nodo* 
     */
    void rotateLeft(Nodo*& );
    /**
     * @brief method to rotate right
     * 
     * @return Nodo* 
     * 
     */
    
    void rotateRight(Nodo*& );
    /**
     * @brief method to balance tree
     * 
     * @return Nodo* 
     * @param Nodo* 
     */
     
    
    void RebalanceInsert(Nodo*& );
    /**
     * @brief method insert node
     * 
     * @return Nodo* 
     * @param Nodo*
     */
    
    Nodo* insertValue(Nodo* , Nodo* );
    /**
     * @brief method Nodo* getMinValue(Nodo*& );
     * 
     * @return Nodo* 
     * @param Nodo* 
     */
    
    Nodo* getMinValue(Nodo*& );
    /**
     * @brief Metod Nodo* getMaxValue(Nodo*& );
     * 
     * @return Nodo* 
     * @param Nodo* 
     */
    
    Nodo* getMaxValue(Nodo*& );
    /**
     * @brief method to delete node
     * 
     * @return Nodo* 
     * @param Nodo* 
     */

    void RebalanceDelete(Nodo*& );
    /**
     * @brief method to delete node
     * 
     */
    Nodo* deleteValue(Nodo*& , int );
    /**
     * @brief method to search node
     * 
     * @return Nodo* 
     * @param Nodo* 
     * @param int 
     */
    Nodo* searchValue(Nodo* , int );
    /**
     * @brief method to print information tree
     * 
     * @return Nodo* 
     * @param Nodo* 
     */
    void informationTree(Nodo*& );
    /**
     * @brief method to print tree
     * 
     * @return Nodo*
     * @param string 
     * @param Nodo*
     * @param int 
     */
    void printTree(const string& , Nodo* , bool , string , string , string , string );
    /**
     * @brief method preOrder
     * 
     * @return Nodo* 
     * @param Nodo* 
     */
    void preOrder(Nodo* );
    /**
     * @brief method inOrder
     * 
     * @return Nodo* 
     * @param Nodo* 
     */
    void inOrder(Nodo* );
    /**
     * @brief method postOrder
     * 
     * @return Nodo* 
     * @param Nodo* 
     */
    void postOrder(Nodo* );
    /**
     * @brief method save tree in txt file
     * 
     * @return Nodo* 
     * @param Nodo* 
     */
    void saveTreeTxt(Nodo* );
    /**
     * @brief method save tree in dat file
     * 
     * @return Nodo* 
     * @param Nodo* 
     */
    void saveTreeBin(Nodo* );
    /**
     * @brief method load tree from html file
     * 
     * @return Nodo* 
     * @param Nodo* 
     */
    void saveTxtData(Nodo* );

public:
    /**
     * @brief Construct a new ArbolRN object
     * 
     */
    ArbolRN();
    /**
     * @brief method to insert node
     *
     * @param int  
     */
    void insert(int );
    /**
     * @brief method to delete node
     * 
     * @param int 
     */
    void remove(int );
    /**
     * @brief method to search node
     * 
     * @param int 
      */
    void search(int );
    /**
     * @brief method to print information tree
     * 
     */
    void informationTree();
    /**
     * @brief method to print preOrder
     * 
     */
    void preOrder();
    /**
     * @brief method to print inOrder
     * 
     */
    void inOrder();
    /**
     * @brief method to print postOrder
     * 
     */
    void postOrder();
    /**
     * @brief method print tree
     * 
     */
    void print();
    /**
     * @brief method save tree in txt file
     * 
     */
    void saveTreeTxt();
    /**
     * @brief method save tree in dat file
     * 
     */
    void saveTreeBin();
    /**
     * @brief method load tree from html file
     * 
     */
    void saveTxtData();
    /**
     * @brief destructor
     * 
     */
    ~ArbolRN();
};