/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:48:38 by pierre            #+#    #+#             */
/*   Updated: 2024/10/09 19:50:34 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstget(t_list *lst, int n)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (n == 0)
			return (lst);
		lst = lst->next;
		n--;
	}
	return (NULL);
}
