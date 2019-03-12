/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:18:38 by marvin            #+#    #+#             */
/*   Updated: 2019/03/12 11:54:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int	read_music(t_doom **doom)
{
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	(*doom)->music = Mix_LoadMUS("assets/music.ogg");
	if (!((*doom)->music))
		return (0);
	return (1);
}
