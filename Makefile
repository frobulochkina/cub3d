NAME  =  cub3D

SRCS =	all_init.c \
		check_beginning_and_end_str.c \
		check_line_r_f_c_and_dir.c \
		check_line_texture.c \
		cub3d.c \
		drawing.c \
		ft_atoi_for_cub3d.c \
		ft_mlx_and_draw_c_f.c \
		lod_alg_wall.c \
		parser_one.c \
		parser_texture.c \
		parser_two.c \
		parser.c \
		parser_three.c \
		parser_four.c \
		screenshot.c \
		sprite_one.c \
		sprite_three.c \
		sprite_two.c \
		texture_check_trash_open_direction.c \
		texture_init.c \
		turns_left_right_and_keycode.c \
		walking_w_a_s_d.c \
		get_next_line/get_next_line.c

OBJS  =  $(SRCS:.c=.o)

LIBFT		= ./libft/libft.a

CFLAGS  =   -Wall -Werror -Wextra -g

LIBX		= libmlx.a -framework OpenGL -framework AppKit

INCS  =  ./

.c.o:
	@gcc $(CFLAGS) -I$(INCS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@gcc     $(CFLAGS) $(LIBX) $(LIBFT) $(OBJS) -o $(NAME)

$(LIBFT):
			$(MAKE) -C libft

all:  $(NAME)
   
clean:
	$(MAKE) clean -C libft
	@rm -f $(OBJS)
	

fclean:  clean
	$(MAKE) fclean -C libft
	@rm -f $(NAME)

re:   fclean all

.PHONY:  all clean fclean re