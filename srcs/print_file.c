/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:04:05 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/21 23:28:01 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_normal(t_file *file, t_args *args)
{
	char		*name;

	name = file->name;
	if (!args->is_first)
		name = removepath(name);
	printf("%s\n", name);
}

void			l_name(t_file *file, t_args *args)
{
	char	*name;

	if (file->type == 'l')
	{
		name = ft_strnew(PATH_MAX + 1);
		readlink(file->name, name, PATH_MAX + 1);
		name = ft_strjoin(" -> ", name);
		name = ft_strjoin(removepath(file->name), name);
	}
	else
	{
		if (!args->is_first)
			name = removepath(file->name);
		else
			name = file->name;
	}
	printf(" %s", name);
}

void			l_mtime(t_file *file)
{
	char	*mtime;
	time_t	currtime;

	currtime = time(0);
	mtime = ctime((const long *)&file->mtime);
	if (currtime - file->mtime.tv_sec > 15770000
			|| currtime - file->mtime.tv_sec < -15770000)
		printf(" %2.2s %3.3s  %4.4s", &mtime[8], &mtime[4], &mtime[20]);
	else
		printf(" %2.2s %3.3s %5.5s", &mtime[8], &mtime[4], &mtime[11]);
}

void			l_size(t_file *file, t_args *args)
{
	if (file->type == 'c' || file->type == 'b')
	{
		printf(" %ld, %ld",
			(long)major(file->devtype),
			(long)minor(file->devtype));
	}
	else
		printf(" %*lld", args->maxsize + 1, file->size);
}

void			print_long(t_file *file, t_args *args)
{
	printf("%c%s %*ld %-*s  %-*s",
		file->type, file->permissions,
		args->maxlinks + 1, file->links,
		args->maxuser, file->user,
		args->maxgroup, file->group);
	l_size(file, args);
	l_mtime(file);
	l_name(file, args);
	printf("\n");
}

void			print_file(t_file *file, t_args *args)
{
	if (ft_strcont(args->opts, 'l'))
		print_long(file, args);
	else
		print_normal(file, args);
}
