/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:34:57 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/21 23:39:18 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			error(char *filename, t_args *args)
{
	char	*err;

	if (!args->is_first)
		filename = removepath(filename);
	err = ft_strjoin("ls: ", filename);
	perror(err);
}


