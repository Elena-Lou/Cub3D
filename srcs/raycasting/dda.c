/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:40:38 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/02 16:24:43 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
A_ Cast a ray
    1_ Find Horizontal intersections
    
- find coordinates of the first intersection

- d_y, the height of a grid cell == 1.

- delta_x : the distance between each horizontal intersection
-> delta_x = d_y / tan(FOV / 2)

- if there is a wall on the cell, stop to calculate the distance

- else, move on to the next horizontal intersection :
    Xnew = Xold + delta_x
    Ynew = Yold + d_y

    2_ Find Horizontal intersections
    
- find coordinates of the first intersection

- d_x, the width of a grid cell == 1

- delta_y : the distance between each vertical intersection
-> delta_y = d_x * tan(FOV / 2)

- if there is a wall, stop to calculate the distance

- else, move on to the next vertical intersection :
    Xnew = Xold + d_x
    Ynew = Yold + delta_y
*/
