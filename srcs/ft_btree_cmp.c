/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 22:27:04 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/18 18:26:43 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long		ft_btree_cmp(t_btree *b1, t_btree *b2, char *opts)
{
	t_file		*file1;
	t_file		*file2;
	long		res;

	file1 = (t_file*)b1->content;
	file2 = (t_file*)b2->content;
	if (ft_strcont(opts, 't'))
	{
		res = file2->mtime.tv_sec - file1->mtime.tv_sec;
		if (res == 0)
			res = file2->mtime.tv_nsec - file1->mtime.tv_nsec;
		if (res == 0)
			res = ft_strcmp(file1->name, file2->name);
	}
	else
		res = ft_strcmp(file1->name, file2->name);
	if (ft_strcont(opts, 'r'))
		res = res * (-1);
	return (res);
}
