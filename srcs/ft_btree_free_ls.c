/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_free_ls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 20:46:04 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/27 20:46:14 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_btree_free_ls(t_btree *b)
{
	t_file	*tfile;

	tfile = (t_file*)b->content;
	if (tfile)
	{
		free(tfile->name);
		free(tfile->permissions);
		free(tfile);
	}
	free(b);
}
