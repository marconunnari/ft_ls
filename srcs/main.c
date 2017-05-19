/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:22:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/19 19:35:24 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printfile(t_list *elem)
{
	printf("%s ", (char*)elem->content);
}

int		main(int argc, char **argv)
{
	t_args		*args;

	setbuf(stdout, NULL);
	args = parse_args(argc, argv);
	ls(args);
}
