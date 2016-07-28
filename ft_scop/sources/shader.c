/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shader.h"

t_shader	*new_shader(char *vert_src, char *frag_src)
{
	t_shader *shader;

	shader = (t_shader *)malloc(sizeof(t_shader));
	shader->id_vert = 0;
	shader->id_frag = 0;
	shader->id_program = 0;
	shader->vert_src = vert_src;
	shader->frag_src = frag_src;
	return (shader);
}

void		delete_shader(t_shader *shader)
{
	if (glIsShader(shader->id_vert) == GL_TRUE)
		glDeleteShader(shader->id_vert);
	if (glIsShader(shader->id_frag) == GL_TRUE)
		glDeleteShader(shader->id_frag);
	if (glIsProgram(shader->id_program) == GL_TRUE)
		glDeleteProgram(shader->id_program);
}

int			load_shader(t_shader *shader)
{
	GLint link_status;

	delete_shader(shader);
	if (create_compile_shader(shader))
		return (-1);
	shader->id_program = glCreateProgram();
	glAttachShader(shader->id_program, shader->id_vert);
	glAttachShader(shader->id_program, shader->id_frag);
	glBindAttribLocation(shader->id_program, 0, "in_Vertex");
	glBindAttribLocation(shader->id_program, 1, "in_Color");
	glBindAttribLocation(shader->id_program, 2, "in_TexCoord");
	glLinkProgram(shader->id_program);
	link_status = 0;
	glGetProgramiv(shader->id_program, GL_LINK_STATUS, &link_status);
	if (link_status != GL_TRUE)
	{
		ft_putendl_fd("Error loading shader:", 2);
		glDeleteProgram(shader->id_program);
		return (-1);
	}
	shader->u_mdlview = glGetUniformLocation(shader->id_program, "modelview");
	shader->u_proj = glGetUniformLocation(shader->id_program, "projection");
	shader->u_coltotext = glGetUniformLocation(shader->id_program
		, "coltotext");
	return (0);
}
