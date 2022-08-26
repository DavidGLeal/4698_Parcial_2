/*
* @flie commonfunctions.h
* @author Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos - Estructura de Datos
* @date 19/7/2022
* @brief Archivo de cabecera para la clase commonfunctions.h
* @version 1.0
* 
*@copyright Copyright (c) 2022,Diego Portilla - Darwin Valdiviezo - Danny Quingaluisa - Alejandro Gallegos 
*@license MIT License
*/
#include "constants.h"
#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H

/**
* @brief method malloc_2d_array
*
* @param char***
*/
void malloc_2d_string_array(char*** variable_name);
/**
 * @brief method malloc_1d_array
 * 
 * @param variable_name 
 * @param size 
 */
void malloc_1d_array(char** variable_name, int size);
/**
 * @brief method file_exists
 * 
 * @param const char*
 */
int FileExists(const char *filename);
/**
 * @brief method is_file_a_directory
 * 
 * @param char*
 */
int is_file_a_directory(char* file_name_with_path);
/**
 * @brief method get_list_of_files_in_the_given_folder
 * 
 * @param char*
 * @param char*
 */
int get_list_of_files_in_the_given_folder(char** list_of_files, char* folder_name_with_path);


#endif