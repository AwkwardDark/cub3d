/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:22:01 by pierre            #+#    #+#             */
/*   Updated: 2024/10/31 16:13:21 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*temp;

	temp = lst;
	n = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	return (n);
}
