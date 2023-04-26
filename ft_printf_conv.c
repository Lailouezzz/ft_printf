/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:43:43 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/26 17:00:49 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "ft_printf_conv.h"

int	ft_print_chr(t_printf_arg *arg)
{
	if (arg->pad != 0 && !arg->leftflag)
		ft_print_pad(arg->pad - 1, ' ');
	ft_putchar_fd(arg->d.c, STDOUT_FILENO);
	if (arg->pad != 0 && arg->leftflag)
		ft_print_pad(arg->pad - 1, ' ');
	if (arg->pad != 0)
		return (arg->pad);
	return (1);
}

int	ft_print_str(t_printf_arg *arg)
{
	int			diff;
	const char	*s;

	if (arg->d.str == NULL)
		arg->d.str = "(null)";
	diff = (int) arg->pad - ft_strlen(arg->d.str);
	if (diff > 0 && !arg->leftflag && !arg->cutflag)
		ft_print_pad(diff, ' ');
	s = arg->d.str;
	while (*s != '\0')
	{
		if (arg->cutflag)
			if (arg->pad-- == 0)
				break ;
		ft_putchar_fd(*(s++), STDOUT_FILENO);
	}
	if (diff > 0 && arg->leftflag && !arg->cutflag)
		ft_print_pad(diff, ' ');
	if (diff > 0 && !arg->cutflag)
		return (diff + ft_strlen(arg->d.str));
	return (s - arg->d.str);
}

int	ft_print_ptr(t_printf_arg *arg)
{
	int		written;
	char	*str;

	if (arg->d.ptr == 0)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	arg->altflag = 1;
	arg->convf = ft_print_hxm;
	str = ft_printf_uitoabase(arg->d.ptr, "0123456789abcdef", arg);
	arg->d.str = str;
	written = ft_print_str(arg);
	free(str);
	return (written);
}

int	ft_print_dec(t_printf_arg *arg)
{
	int		written;
	char	*str;

	str = ft_printf_itoabase(arg->d.nb, "0123456789", arg);
	arg->cutflag = 0;
	arg->d.str = str;
	written = ft_print_str(arg);
	free(str);
	return (written);
}

int	ft_print_uns(t_printf_arg *arg)
{
	int		written;
	char	*str;

	str = ft_printf_uitoabase(arg->d.unb, "0123456789", arg);
	arg->d.str = str;
	written = ft_print_str(arg);
	free(str);
	return (written);
}

int	ft_print_hxm(t_printf_arg *arg)
{
	int		written;
	char	*str;

	str = ft_printf_uitoabase(arg->d.unb, "0123456789abcdef", arg);
	arg->d.str = str;
	written = ft_print_str(arg);
	free(str);
	return (written);
}

int	ft_print_hxc(t_printf_arg *arg)
{
	int		written;
	char	*str;

	str = ft_printf_uitoabase(arg->d.unb, "0123456789ABCDEF", arg);
	arg->d.str = str;
	written = ft_print_str(arg);
	free(str);
	return (written);
}

int	ft_print_prc(t_printf_arg *arg)
{
	arg->d.c = '%';
	ft_putchar_fd(arg->d.c, STDOUT_FILENO);
	return (1);
}
