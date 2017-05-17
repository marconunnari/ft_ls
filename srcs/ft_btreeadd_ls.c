/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeadd_ls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:27:42 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/17 19:33:17 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeadd_ls(t_btree **root, t_btree *new, char *opts,
					int (*cmpf)(t_btree*, t_btree*, char*))
{
	if (*root == NULL)
		*root = new;
	else if (cmpf(new, *root, opts) < 0)
		ft_btreeadd_ls(&((*root)->left), new, opts, cmpf);
	else
		ft_btreeadd_ls(&((*root)->right), new, opts, cmpf);
}
