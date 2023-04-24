/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:43:43 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/24 17:50:28 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_utils.h"

int	ft_print_chr(t_printf_arg *arg)
{
	ft_putchar_fd(STDOUT_FILENO, arg->d.c);
	return (1);
}
int	ft_print_ptr(t_printf_arg *arg);
int	ft_print_dec(t_printf_arg *arg);
int	ft_print_uns(t_printf_arg *arg);
int	ft_print_hxm(t_printf_arg *arg);
int	ft_print_hxc(t_printf_arg *arg);
int	ft_print_prc(t_printf_arg *arg);
