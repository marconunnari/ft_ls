/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:04:05 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/23 19:47:23 by mnunnari         ###   ########.fr       */
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

void			print_file(t_file *file, t_args *args)
{
	if (ft_strcont(args->opts, 'l'))
		print_long(file, args);
	else
		print_normal(file, args);
}
