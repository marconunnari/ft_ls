/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:26:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/18 16:54:35 by mnunnari         ###   ########.fr       */
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
	res->abs_secs = info.st_mtimespec.tv_sec;
	res->abs_nsecs = info.st_mtimespec.tv_nsec;
	return (res);
}
