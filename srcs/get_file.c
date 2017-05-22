/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:26:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/21 23:30:41 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	getlen(intmax_t n)
{
	int		size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

t_file			*get_file(char *name, t_args *args)
{
	t_file		*res;
	int			linkslen;
	int			userlen;
	int			grouplen;
	int			sizelen;
	struct stat	info;

	if (lstat(name, &info) == -1)
	{
		error(name, args);
		return (NULL);
	}
	if (!(res = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	res->name = name;
	res->type = get_file_type(info.st_mode);
	res->permissions = get_permissions(info.st_mode);
	res->links = (long)info.st_nlink;
	res->user = get_username((long)info.st_uid);
	res->group = get_groupname((long)info.st_gid);
	res->size = (long long)info.st_size;
	res->mtime = info.st_mtimespec;
	res->devtype = info.st_rdev;
	args->blocks += (long long)info.st_blocks;
	linkslen = getlen(res->links);
	if (linkslen > args->maxlinks)
		args->maxlinks = linkslen;
	userlen = ft_strlen(res->user);
	if (userlen > args->maxuser)
		args->maxuser = userlen;
	grouplen = ft_strlen(res->group);
	if (grouplen > args->maxgroup)
		args->maxgroup = grouplen;
	sizelen = getlen(res->size);
	if (sizelen > args->maxsize && (args->considerdirsize || res->type != 'd'))
		args->maxsize = sizelen;
	return (res);
}
