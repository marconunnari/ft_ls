/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_name_without_path.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:05:06 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/18 18:05:44 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_file_name_without_path(char *name)
{
	char	*slash;

	if ((slash = ft_strrchr(name, '/')))
		name = slash + 1;
	return (name);
}
