/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:26:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/17 17:27:12 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*get_file(char *name)
{
	t_file		*res;
	struct stat	info;

	stat(name, &info);
	IFNOTRETURN((res = (t_file*)malloc(sizeof(t_file))), NULL);
	res->name = name;
	res->type = get_type(info.st_mode);
	return (res);
}
