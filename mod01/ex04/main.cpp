/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:52:11 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/30 16:41:15 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	printErrorAndExit(const std::string& errorMessage)
{
	std::cerr << "Error: " << errorMessage << std:: endl;
	return 1;
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return printErrorAndExit("Número de argumento incorrecto, <cmd> <arg01> <arg02> <arg03>");
	std::string inputFileName = argv[1];
	std::string searchString = argv[2];
	std::string replaceString = argv[3];
	std::string outFileName = inputFileName + "_replaced";
	std::string line;
	size_t	pos;

	if (searchString.empty())
		return printErrorAndExit("La cadena a buscar no puede estar vacia");

	std::ifstream inputFile(inputFileName.c_str());
	if (!inputFile.is_open())
		return printErrorAndExit("No se puede abrir el archivo de entrada");

	std::ofstream outputFile(outFileName.c_str());
	if (!outputFile.is_open())
		return printErrorAndExit("Nose puede crear el archivo");

	while (std::getline(inputFile, line))
	{
		pos = line.find(searchString, 0);
		while (pos != std::string::npos)
		{
			line.erase(pos, searchString.length());
			line.insert(pos, replaceString);
			pos = line.find(searchString, pos + replaceString.length());
		}
		outputFile << line << std::endl;
	}

	std::cout << "Procesamiento completado. Archivo de salida: "
			<< outFileName << std::endl;
	return 0;
}
