/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:26:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/23 21:27:00 by mnunnari         ###   ########.fr       */
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

void			set_lengths(t_args *args, t_file *tfile)
{
	int			linkslen;
	int			userlen;
	int			grouplen;
	int			sizelen;

	linkslen = getlen(tfile->links);
	if (linkslen > args->maxlinks)
		args->maxlinks = linkslen;
	userlen = ft_strlen(tfile->user);
	if (userlen > args->maxuser)
		args->maxuser = userlen;
	grouplen = ft_strlen(tfile->group);
	if (grouplen > args->maxgroup)
		args->maxgroup = grouplen;
	sizelen = getlen(tfile->size);
	if (sizelen > args->maxsize && (args->considerdirsize || tfile->type != 'd'))
		args->maxsize = sizelen;
}

int			get_stat(char *name, t_args *args, struct stat *info)
{
	if (lstat(name, info) == -1)
	{
		error(name, args);
		return (0);
	}
	if (get_file_type(info->st_mode) == 'l'
			&& args->is_first && !ft_strcont(args->opts, 'l'))
	{
		if (stat(name, info) == -1)
		{
			error(name, args);
			return (0);
		}
	}
	return (1);
}

t_file			*get_file(char *name, t_args *args)
{
	t_file		*tfile;
	struct stat	info;

	if (!get_stat(name, args, &info))
		return (NULL);
	if (!(tfile = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	tfile->name = name;
	tfile->type = get_file_type(info.st_mode);
	tfile->permissions = get_permissions(info.st_mode);
	tfile->links = (long)info.st_nlink;
	tfile->user = get_username((long)info.st_uid);
	tfile->group = get_groupname((long)info.st_gid);
	tfile->size = (long long)info.st_size;
	tfile->mtime = info.st_mtimespec;
	tfile->devtype = info.st_rdev;
	args->blocks += (long long)info.st_blocks;
	set_lengths(args, tfile);
	return (tfile);
}
