/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:51 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/06 18:46:59 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "rt.h"

/*
**	calculate_normals.c
*/
t_vector		cone_normal(t_obj *figure, t_vector point);
t_vector		cylinder_normal(t_obj *figure, t_vector point);
t_vector		sphere_normal(t_obj *figure, t_vector point);
t_vector		plane_normal(t_obj *figure, t_vector point);
t_vector		get_normal(t_obj *figure, t_vector point);

/*
**	color_parse.c
*/
int				set_color_rgb(int red, int green, int blue);
int				color_parse(int color, t_vector point, t_vector normal,
							t_lights *light, t_obj obj, t_vector dir);

/*
**	draw.c
*/
void			put_pixel(int x, int y, int color, SDL_Surface *sur);
int				ray_trace(t_vector dir, t_rt *rt);
void			draw(t_rt *rt);

/*
**	find.c
*/
int				closest_object(t_obj *cur_obj, t_vector dir,
								double *closest_t, t_rt *rt);
/*
**	help.c
*/
int				set_color_rgb(int red, int green, int blue);
t_vector		calculate_direction(int x, int y, int width, int height);

/*
**	hit.c
*/
t_root			hit_cone(t_vector vec, t_vector camera, t_obj *cone);
t_root			hit_cylinder(t_vector vec, t_vector camera, t_obj *cylinder);
t_root			hit_sphere(t_vector vec, t_vector camera, t_obj *sphere);
t_root			hit_plane(t_vector vec, t_vector camera, t_obj *plane);
t_root			hit_obj(t_vector vec, t_vector camera, t_obj *obj);

/*
**	init.c
*/
void			init_figure(t_obj *figure);
void			init_sdl(t_sdl *sdl);
t_rt			*init_rt(void);

/*
**	light.c
*/
double			compute_light(t_vector point, t_vector normal,
							t_lights *lights, int specular, t_vector view);

/*
**  main.c
*/
void			show_example_input(void);
int				main(int ac, char **av);

/*
**	ray_trace.c
*/

/*
**	sdl_loop.c
*/
void			sdl_loop(SDL_Window *win);

/*
**  validation.c
*/
void			validation(char *arg, t_rt *rt);

/*
**  validation_get_value.c
*/
t_vector		get_array_value(char *str);
float			get_float_value(char *str);
float			get_int_value(char *str);

/*
**  validation_figures.c
*/
t_lights		*new_light(void);
t_lights		*find_light(t_lights **light);
int				lights_processing(int i, char **file_split, t_lights **light);

/*
**  validation_light.c
*/
t_obj			*new_obj(void);
t_obj			*find_obj(t_obj **obj);
int				objects_processing(int i, char **file_split,
					t_obj **figure);

#endif
