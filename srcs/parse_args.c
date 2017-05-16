/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:26:32 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/16 21:28:33 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		usage(int code)
{
	printf("%s\n", "usage: ft_ls [-Ralrt] [file ...]");
	exit(code);
}

void		check_opts(char *opts)
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

t_args			*init_args()
{
	t_args		*args;

	args = (t_args*)malloc(sizeof(t_args));
	args->opts = ft_strnew(0);
	args->files = NULL;
	return (args);
}

t_args			*parse_args(int argc, char **argv)
{
	int			i;
	t_args		*args;
	t_list		*file;

	i = 1;
	args = init_args();
	while (i < argc && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
	{
		REASSIGN(args->opts, ft_strjoin(args->opts, &argv[i][1]));
		i++;
	}
	check_opts(args->opts);
	while (i < argc)
	{
		IFRETURN(!(file = ft_lstnew(argv[i], ft_strlen(argv[i]) + 1)), NULL);
		if (args->files == NULL)
			args->files = file;
		else
			ft_lstadd(&args->files, file);
		i++;
	}
	if (args->files == NULL)
	{
		IFRETURN(!(file = ft_lstnew(".", 2)), NULL);
		args->files = file;
	}
	return (args);
}
