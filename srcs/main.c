/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:22:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/16 21:32:17 by mnunnari         ###   ########.fr       */
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

	args = parse_args(argc, argv);
	printf("Options: %s\n", args->opts);
	printf("Files: ");
	ft_lstiter(args->files, &printfile);
	printf("\n");
	ls(args, 1);
}
