/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:20:22 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/27 19:35:26 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_dir(char *name, t_args *args)
{
	t_btree		*files;
	t_args		*new_args;

	if (!(new_args = (t_args*)malloc(sizeof(t_args))))
		return ;
	new_args->opts = ft_strdup(args->opts);
	new_args->maxlinks = 0;
	new_args->maxuser = 0;
	new_args->maxgroup = 0;
	new_args->maxsize = 0;
	new_args->blocks = 0;
	new_args->considerdirsize = 1;
	new_args->is_first = 0;
	files = get_dirfiles(name, new_args);
	new_args->files = files;
	if (files && ft_strcont(new_args->opts, 'l'))
		ft_printf("total %lld\n", new_args->blocks);
	ls(new_args);
}
