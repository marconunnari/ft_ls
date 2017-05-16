/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:22:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/15 17:47:45 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_args		*parse_args(int argc, char **argv)
{
	int		i;
	t_args		*args;
	t_list		*file;

	i = 1;
	args = (t_args*)malloc(sizeof(t_args));
	args->opts = ft_strnew(0);
	args->files = ft_lstnew(".", 2);
	while (i < argc && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
	{
		REASSIGN(args->opts, ft_strjoin(args->opts, &argv[i][1]));
		i++;
	}
	while (i < argc)
	{
		if (!(file = ft_lstnew(argv[i], ft_strlen(argv[i]) + 1)))
			return (NULL);
		if (((char*)args->files->content)[0] == '.')
			args->files = file;
		else
			ft_lstadd(&args->files, file);
		i++;
	}
	return (args);
}

void		usage(int code)
{
	printf("%s\n", "usage: ft_ls [-Ralrt] [file ...]");
	exit(code);
}

void		checkopts(char *opts)
{
	int	i;

	i = 0;
	while (opts[i])
	{
		if(!ft_strcont("altrR", opts[i]))
		{
			printf("ls: illegal option -- %c\n", opts[i]);
			usage(2);
		}
		i++;
	}
}

void		printfile(t_list *elem)
{
	printf("%s ", (char*)elem->content);
}

int		main(int argc, char **argv)
{
	t_args		*args;

	args = parse_args(argc, argv);
	checkopts(args->opts);
	printf("Options: %s\n", args->opts);
	printf("Files: ");
	ft_lstiter(args->files, &printfile);
	printf("\n");
}
