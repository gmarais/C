/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_TOOLS_H
# define TIME_TOOLS_H

# ifdef __APPLE__
#  define CURRENT_TIME (double)clock() / 5000.0
# else
#  define CURRENT_TIME (double)clock() / (double)CLOCKS_PER_SEC;
# endif

double	update_delta_time();
float	custom_rand();

#endif
