#include "main.h"

static void update_model_view(double delta_time)
{
	if (g_env.rots[0] != 0)
		rotate_x(&(g_env.mv), 0.002 * delta_time * (float)(g_env.rots[0]));
	if (g_env.rots[1] != 0)
		rotate_y(&(g_env.mv), 0.002 * delta_time * (float)(g_env.rots[1]));
	if (g_env.rots[2] != 0)
		rotate_z(&(g_env.mv), 0.002 * delta_time * (float)(g_env.rots[2]));

	translate_matrix(&(g_env.mv)
		, 0.001 * delta_time * (float)(g_env.trans[0])
		, 0.001 * delta_time * (float)(g_env.trans[1])
		, 0.001 * delta_time * (float)(g_env.trans[2]));
}

static void update_texture_color_ratio(double delta_time)
{
	if (!g_env.text_is_on && g_env.col_to_text > 0)
		g_env.col_to_text -= 0.001 * delta_time;
	else if (g_env.text_is_on && g_env.col_to_text < 1)
		g_env.col_to_text += 0.001 * delta_time;
	if (g_env.col_to_text > 1)
		g_env.col_to_text = 1;
	else if (g_env.col_to_text < 0)
		g_env.col_to_text = 0;
}

static void send_matrices_to_shader()
{
	GLuint u_mlocation;
	GLuint u_plocation;
	GLuint u_coltotext;

	u_mlocation = glGetUniformLocation(g_env.shader->id_program, "modelview");
	u_plocation = glGetUniformLocation(g_env.shader->id_program, "projection");
	u_coltotext = glGetUniformLocation(g_env.shader->id_program
		, "colorToTextureFloat");
	glUniformMatrix4fv(u_mlocation, 1, GL_FALSE, g_env.mv.val);
	glUniformMatrix4fv(u_plocation, 1, GL_FALSE, g_env.proj.val);
	glUniform1f(u_coltotext, g_env.col_to_text);
}

void draw()
{
	double delta_time;

	delta_time = update_delta_time();
	update_model_view(delta_time);
	update_texture_color_ratio(delta_time);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, g_env.mdl->positions);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, g_env.mdl->colors);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, g_env.mdl->uvs);
	glEnableVertexAttribArray(2);
	send_matrices_to_shader();
	glBindTexture(GL_TEXTURE_2D, g_env.texture->id_texture);
	glDrawArrays(GL_TRIANGLES, 0, g_env.mdl->v_size);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}
