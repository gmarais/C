/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_H
# define SHADER_H

# include <GL/glew.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_shader
{
	GLuint		id_vert;
	char		*vert_src;
	GLchar		*vert_src_content;
	GLuint		id_frag;
	char		*frag_src;
	GLchar		*frag_src_content;
	GLuint		id_program;
	GLuint		u_mdlview;
	GLuint		u_proj;
	GLuint		u_coltotext;
}				t_shader;

t_shader		*new_shader(char *vertex_source, char *fragment_source);
void			delete_shader(t_shader *shader);
int				load_shader(t_shader *shader);
int				create_compile_shader(t_shader *shader);

#endif
