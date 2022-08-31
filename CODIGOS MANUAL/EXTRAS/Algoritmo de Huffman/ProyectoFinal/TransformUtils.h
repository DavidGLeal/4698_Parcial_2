/**
 * @file TransformUtils.h
 * @author Arias, Escobar,Portilla,Valdiviezo,Yanez
 * @brief  Archivo de cabecera para la clase TransformUtils
 * @version 0.1
 * @date 2022-08-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <vector>
#include <bitset>

using std::string;
using std::vector;
using std::bitset;

class TransformUtils
{
public:
	/**
	 * @brief Metodo transform string to byte array
	 *
	 * @param string
	 * @return vector<bitset<8>>
	 */
	static vector<unsigned char> transformar_string_to_bytes(const string&);
	/**
	 * @brief Metodo transform_bytes_to_string()
	 *
	 * @param vector<bitset<8>>
	 * @return string
	 */
	static string transformar_byte_a_string(const unsigned char&);

private:
	TransformUtils();
};

