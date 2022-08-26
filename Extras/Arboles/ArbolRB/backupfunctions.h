/*
* @flie backupfunctions.h
* @author Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos - Estructura de Datos
* @date 19/7/2022
* @brief Archivo de cabecera para la clase backupfunctions.h
* @version 1.0
* 
*@copyright Copyright (c) 2022,Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos 
*@license MIT License
*/


#ifndef CLEANUPFUNCTIONS_H
#define CLEANUPFUNCTIONS_H

/**
* @brief method to clean up the memory
*
* @param char*
* @param char*
* @param char*
* @param char*
*/
void cleanup(char* folder_name, char* source_path, char* destination_path, char* info_folder_path);
/**
* @brief method to delete file
*
* @param name
* @param pass
* @return true
* @return false
*/
void delete_files_in_the_given_directory(char* given_folder_with_its_path);
#endif