/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:34:57 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/19 20:36:02 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			error(char *filename)
{
	char	*err;

	filename = get_file_name_without_path(filename);
	err = ft_strjoin("ls: ", filename);
	perror(err);
}


