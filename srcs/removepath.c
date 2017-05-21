/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removepath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 23:20:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/21 23:20:52 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*removepath(char *name)
{
	char	*slash;

	if (name[ft_strlen(name) - 1] == '/')
		name[ft_strlen(name) - 1] = '\0';
	if ((slash = ft_strrchr(name, '/')))
		name = slash + 1;
	return (name);
}
