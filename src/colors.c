/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:39:45 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/12 12:45:07 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	get_sea_color(int z)
{
	if (z < -100)
		return (0x14213d);
	if (z < -50)
		return (0x1d3557);
	if (z < -25)
		return (0x457b9d);
	if (z < -10)
		return (0x61a5c2);
	return (0xa9d6e5);
}

static int	get_land_color(int z)
{
	if (z == 0)
		return (0xd9ed92);
	if (z < 10)
		return (0xb5e48c);
	if (z < 20)
		return (0x99d98c);
	if (z < 30)
		return (0x76c893);
	if (z < 40)
		return (0x52b69a);
	if (z < 50)
		return (0x34a0a4);
	if (z < 60)
		return (0x168aad);
	if (z < 70)
		return (0x6c584c);
	if (z < 80)
		return (0xa98467);
	return (0xd4a373);
}

static int	get_mountain_color(int z)
{
	if (z < 100)
		return (0xc3b091);
	if (z < 150)
		return (0xa68a64);
	if (z < 200)
		return (0x8e8d8a);
	if (z < 250)
		return (0xbfc0c0);
	if (z < 300)
		return (0xe5e5e5);
	return (0xffffff);
}

int	get_color(int z)
{
	if (z < 0)
		return (get_sea_color(z));
	if (z < 100)
		return (get_land_color(z));
	return (get_mountain_color(z));
}
