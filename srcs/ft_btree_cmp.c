/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 22:27:04 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/17 17:36:12 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_btree_cmp(t_btree *b1, t_btree *b2)
{
	t_file		*file1;
	t_file		*file2;

	file1 = (t_file*)b1->content;
	file2 = (t_file*)b2->content;
	return (ft_strcmp(file1->name, file2->name));
}
