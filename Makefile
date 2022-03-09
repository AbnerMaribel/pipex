# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaribel <amaribel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 07:09:48 by amaribel          #+#    #+#              #
#    Updated: 2022/01/20 22:46:04 by amaribel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS	= 	pipex.c utils.c\
			
LIB 	= ./libft/libft.a

HEADER  = pipex.h ./libft/libft.h

RM		= rm -f
		 
OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) -C ./libft
			$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${NAME}

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME) ./libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re	