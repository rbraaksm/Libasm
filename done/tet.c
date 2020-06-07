/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tet.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 17:18:06 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/05 11:10:16 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int cmp(void *data, void *data_ref)
{
	int *i = data;
	int *j = data_ref;

	if (*i == *j)
		return (0);
	return (1);
}
