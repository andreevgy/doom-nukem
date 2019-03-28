/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:44:43 by ghalvors          #+#    #+#             */
/*   Updated: 2019/03/28 23:50:52 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
**	setup_settings
**	Settings for game input or environment
*/

void	setup_settings(t_doom **doom)
{
	(*doom)->settings.x_mouse_speed = 0.005;
	(*doom)->settings.y_mouse_speed = 3;
}
