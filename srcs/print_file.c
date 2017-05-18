/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:04:05 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/18 19:36:07 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_normal(t_file *file)
{
	char		*name;

	name = file->name;
	name = get_file_name_without_path(name);
	printf("%s\n", name);
}

void			print_long(t_file *file, t_args *args)
{
	char	*mtime;

	mtime = ctime((const long *)&file->mtime);
	printf("%c%s %*ld %s  %s %*lld %2.2s %3.3s %5.5s %s\n",
			file->type, file->permissions,
			args->maxlinks + 1, file->links,
			file->user, file->group,
			args->maxsize + 1, file->size,
			&mtime[8], &mtime[4], &mtime[11],
			get_file_name_without_path(file->name));
}

void			print_file(t_file *file, t_args *args)
{
	if (ft_strcont(args->opts, 'l'))
		print_long(file, args);
	else
		print_normal(file);
}
