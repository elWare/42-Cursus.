/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:15:42 by jumarque          #+#    #+#             */
/*   Updated: 2024/11/28 08:27:46 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Este código está diseñado para leer líneas de un archivo utilizando
   un buffer de tamaño configurable, manejando casos especiales como errores
   en la lectura o archivos vacíos. */

#include "get_next_line.h"

// Función que lee del archivo y construye el buffer.
// Function that reads from the file and builds the buffer.

char	*ft_create(int fd, char *buffer)
{
	char	*tmp_buff;
	ssize_t	fr;

	// Asigna memoria temporal para el buffer temporal de lectura.
	// Allocates temporary memory for the reading buffer.
	tmp_buff = malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!tmp_buff)
		return (NULL);
	fr = 1;
	// Lee el archivo hasta encontrar un salto de línea o hasta que no haya más datos. 
	// Reads the file until a newline or no more data is found.
	while (!(ft_strchr(buffer, '\n')) && fr > 0)
	{
		fr = read(fd, tmp_buff, BUFFER_SIZE); 
		if (fr == -1) // Manejo de error en la lectura. / Error handling during reading.
		{
			free(tmp_buff);
			free(buffer);
			return (NULL);
		}
		// Asegura que el buffer es una cadena terminada en '\0'.
		// Ensures the buffer is a null-terminated string.
		tmp_buff[fr] = '\0'; 
		// Combina el contenido leído con el buffer existente.
		// Combines the read content with the existing buffer.
		buffer = ft_strjoin(buffer, tmp_buff); 
	}
	free(tmp_buff); // Libera la memoria temporal. / Frees the temporary memory.
	tmp_buff = NULL;
	return (buffer); // Devuelve el buffer actualizado. / Returns the updated buffer.
}

// Función que extrae la línea del buffer.
// Function that extracts the line from the buffer.

char	*ft_getline(char *buffer)
{
	char	*line;
	int		index;

	index = 0;
	if (buffer[index] == 0) // Si el buffer está vacío, devuelve NULL. / If the buffer is empty, return NULL.
		return (NULL);
	// Encuentra la posición del salto de línea o el final del buffer.
	// Finds the newline or the end of the buffer.
	while (buffer[index] && buffer[index] != '\n')
		index++;
	
	// Incluye el salto de línea, si existe.
	// Includes the newline if it exists.
	index += (buffer[index] == '\n');
	line = malloc((index + 1) * sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	// Copia la línea desde el buffer.
	// Copies the line from the buffer.
	while (buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] == '\n') // Si hay un salto de línea, lo añade. / If there is a newline, add it.
	{
		line[index] = '\n';
		index++;
	}
	line[index] = '\0'; // Termina la cadena con '\0'. / Null-terminate the string.
	return (line);
}

// Función que limpia el buffer después de extraer una línea.
// Function to clean the buffer after extracting a line.

char	*ft_cleanline(char *buffer)
{
	char	*result_buffer;
	int		i;
	int		j;

	i = 0;
	// Encuentra el salto de línea o el final del buffer. / Finds the newline or the end of the buffer.
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i]) // Si no hay más datos, libera el buffer y devuelve NULL. / If no more data, free the buffer and return NULL.
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	// Asigna memoria para el buffer restante después del salto de línea. / Allocates memory for the remaining buffer after the newline.
	result_buffer = malloc((ft_strln(buffer) - i + 1) * sizeof(char));
	if (!result_buffer)
		return (NULL);
	i++;
	j = 0;
	// Copia el contenido restante al nuevo buffer. / Copies the remaining content to the new buffer.
	while (buffer[i])
		result_buffer[j++] = buffer[i++];
	result_buffer[j] = '\0'; // Termina el buffer con '\0'. / Null-terminate the buffer.
	free(buffer); // Libera el buffer original. / Frees the original buffer.
	buffer = NULL;
	return (result_buffer);
}

// Función que calcula la longitud de una cadena. / Function to calculate the length of a string.
size_t	ft_strln(const char *s)
{
	size_t	len;

	if (!s) // Si la cadena es NULL, retorna 0. / If the string is NULL, return 0.
		return (0);
	len = 0;
	while (s[len]) // Recorre la cadena hasta el final. / Traverse the string until the end.
	{
		len++;
	}
	return (len); // Retorna la longitud. / Returns the length.
}

// Función principal para obtener la siguiente línea del archivo. / Main function to get the next line from the file.
char	*get_next_line(int fd)
{
	static char	*buffer; // Buffer estático para mantener el estado entre llamadas. / Static buffer to maintain state between calls.
	char		*line;

	// Verifica las condiciones de entrada. / Checks input conditions.
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (!buffer)
			free(buffer);
		line = NULL;
		return (NULL);
	}
	buffer = ft_create(fd, buffer); // Lee del archivo y actualiza el buffer. / Reads from the file and updates the buffer.
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer); // Extrae la línea del buffer. / Extracts the line from the buffer.
	buffer = ft_cleanline(buffer); // Limpia el buffer restante. / Cleans the remaining buffer.
	return (line);
}