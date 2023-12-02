# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 18:59:07 by fcouserg          #+#    #+#              #
#    Updated: 2023/11/23 17:46:38 by fcouserg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS	=	push_swap.c \

OBJS	=	$(SRCS:.c=.o)

GCC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I.
NAME	=	libftpush_swap.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
