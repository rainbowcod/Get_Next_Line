/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:22:43 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/23 12:55:43 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// typedef struct s_list
// {
// 	char *str;
// 	str

// }	t_list;

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);


# endif