/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix_ls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:33:26 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/17 16:57:28 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_btree_apply_infix_ls(t_btree *root, t_args *args,
		void (*applyf)(t_btree*, t_args *))
{
	if (root)
	{
		ft_btree_apply_infix_ls(root->left, args, applyf);
		applyf(root, args);
		ft_btree_apply_infix_ls(root->right, args, applyf);
	}
}
