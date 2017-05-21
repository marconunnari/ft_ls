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

void			print_long(t_file *file, t_args *args)
{
	char	*mtime;
	char	*name;

	if (file->type == 'l')
	{
		name = ft_strnew(PATH_MAX + 1);
		readlink(file->name, name, PATH_MAX + 1);
		name = ft_strjoin(" -> ", name);
		name = ft_strjoin(removepath(file->name), name);
	}
	else
		name = removepath(file->name);
	mtime = ctime((const long *)&file->mtime);
	printf("%c%s %*ld %s  %s %*lld %2.2s %3.3s %5.5s %s\n",
			file->type, file->permissions,
			args->maxlinks + 1, file->links,
			file->user, file->group,
			args->maxsize + 1, file->size,
			&mtime[8], &mtime[4], &mtime[11],
			name);
}

void			print_file(t_file *file, t_args *args)
{
	if (ft_strcont(args->opts, 'l'))
		print_long(file, args);
	else
		print_normal(file, args);
}
