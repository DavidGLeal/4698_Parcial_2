#pragma once 
/*
* @flie Nodo.h
* @author Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos - Estructura de Datos
* @date 19/7/2022
* @brief Archivo de cabecera para la clase Nodo.h
* @version 1.0
* 
*@copyright Copyright (c) 2022,Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos 
*@license MIT License
*/
#include <iostream>


using namespace std;

class Nodo{

    public:
    int data;
    int color;
    Nodo* left;
    Nodo* right;
    Nodo* parent;

    public:
    /**
     * @brief constructor of the class
     * 
     * @param int 
     */
    Nodo(int data);
    /**
     * @brief destructor of the class
     * 
     */
    ~Nodo();
    /**
     * @brief method to get the data
     * 
     * @return int 
     */
    int getData();
    /**
     * @brief method to get color 
     * 
     * @param int 
     */
    int getColor();
    /**
     * @brief method to get the left node
     *
     */
    Nodo* getLeft();
    /**
     * @brief method to get the right node
     * 
     */
    Nodo* getRight();
    /**
     * @brief method to get the parent node
     * 
     */
    Nodo* getParent();
    /**
     * @brief method to set the data
     * 
     * @param int 
     */
    void setData(int data);
    /**
     * @brief method to set the color
     * 
     * @param int 
     */
    void setColor(int color);
    /**
     * @brief method to set the left node
     * 
     * @param Nodo* 
     */
    void setLeft(Nodo* left);
    /**
     * @brief method to set the right node
     * 
     * @param Nodo* 
     */
    void setRight(Nodo* right);
    /**
     * @brief method to set the parent node
     * 
     * @param Nodo* 
     */
    void setParent(Nodo* parent);
    /**
     * @brief method to print the node
     * 
     */
    void print();
};