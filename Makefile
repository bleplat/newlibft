# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:05:04 by bleplat           #+#    #+#              #
#    Updated: 2019/04/01 07:00:43 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FNT = ft_welcome \
		ft_dirfilepath \
		ft_filemode \
		ft_strmode \
		ft_dputstrvec \
		ft_putstrvec \
		ft_listdir \
		ft_vecdel \
		ft_vecdel0 \
		ft_dclamp \
		ft_dmix \
		ft_pause \
		ft_readtonl \
		ft_readline \
		ft_intsshuffle \
		ft_intsnshuffle \
		ft_intsrange \
		ft_putints \
		ft_strpopnls \
		ft_random \
		ft_urandom \
		ft_llrandom \
		ft_ullrandom \
		ft_swapint \
		ft_atoi \
		ft_atoi32check \
		ft_bzero \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isblank \
		ft_iscntrl \
		ft_isdigit \
		ft_isprint \
		ft_isspace \
		ft_isxdigit \
		ft_itoa \
		ft_lstadd \
		ft_lstcount \
		ft_lstdel \
		ft_lstdelone \
		ft_lstfold \
		ft_lstindex \
		ft_lstiter \
		ft_lstlast \
		ft_lstmap \
		ft_lstnew \
		ft_max \
		ft_memalloc \
		ft_memccpy \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memdel \
		ft_memdup \
		ft_memmove \
		ft_memrealloc \
		ft_memset \
		ft_min \
		ft_putchar \
		ft_putchar_fd \
		ft_putendl \
		ft_putendl_fd \
		ft_putnbr \
		ft_putnbr_fd \
		ft_putstr \
		ft_putstr_fd \
		ft_sqrt \
		ft_strcat \
		ft_strchr \
		ft_strclr \
		ft_strcmp \
		ft_strcpy \
		ft_strdel \
		ft_strdup \
		ft_strequ \
		ft_striter \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlen \
		ft_strlstsplit \
		ft_strmap \
		ft_strmapi \
		ft_strncat \
		ft_strncmp \
		ft_strncpy \
		ft_strndup \
		ft_strnequ \
		ft_strnew \
		ft_strnstr \
		ft_strrchr \
		ft_strsplit \
		ft_strstr \
		ft_strsub \
		ft_strtolower \
		ft_strtoupper \
		ft_strtrim \
		ft_strrev \
		ft_tolower \
		ft_toupper \
		ft_putwchar \
		ft_putwchar_fd \
		ft_putwstr \
		ft_putwstr_fd \
		ft_wstrlen \
		ft_isstrnum \
		ft_strbegins \
		ft_strends \
		ft_lstpop \
		ft_pushpop \
		ft_lltoa \
		ft_ulltoa_basestr \
		ft_strfuse \
		ft_autofree_pushpop \
		ft_autofree_begin \
		ft_autofree \
		ft_autofree_end \
		ft_autofree_end0 \
		ft_autofree_abort \
		ft_autofree_abort0 \
		ft_abs \
		ft_memdel0 \
		ft_memdel1 \
		ft_free0 \
		ft_ptrcount \
		ft_isupper \
		ft_array_new \
		ft_array_del \
		ft_array_reserve \
		ft_array_newitem \
		ft_array_shrink \
		ft_array_at \
		ft_array_clear \
		ft_array_reset \
		ft_pow \
		ft_llpow \
		ft_strcatchar \
		ft_ldsize \
		ft_ldtoa \
		ft_intsize \
		ft_strputchr \
		ft_strminfield \
		ft_stranychr \
		ft_strtoupper_inplace \
		ft_ldspecial \
		ft_ldsign \
		ft_va_as_char \
		ft_va_as_double \
		ft_va_as_int \
		ft_va_as_intmax \
		ft_va_as_long \
		ft_va_as_longdouble \
		ft_va_as_longlong \
		ft_va_as_ptr \
		ft_va_as_ptrdiff \
		ft_va_as_short \
		ft_va_as_size \
		ft_va_as_wchar \
		ft_va_as_uchar \
		ft_va_as_ushort \
		ft_va_as_uint \
		ft_va_as_ulong \
		ft_va_as_ulonglong \
		ft_wchrtostr \
		ft_wstrtostr \
		ft_argb \
		ft_colorwheel \
		ft_mixcolors \
		ft_ansicolor \
		ft_hcolortoansi \
		ft_strpop \
		ft_alnumcmp \
		ft_alnumpop \
		ft_printf \
		ft_vprintf \
		ft_printf_wrapped_entry \
		ft_printf_rstparts_get \
		ft_printf_nextrstpart \
		ft_printf_nextrstpart_percent \
		ft_printf_nextrstpart_bracket \
		ft_printf_parting_helpers \
		ft_printf_apvect \
		ft_printf_formatall \
		ft_printf_format \
		ft_printf_format_unknow \
		ft_printf_format_n \
		ft_printf_format_ints \
		ft_printf_format_floats \
		ft_printf_format_others \
		ft_printf_format_s \
		ft_printf_format_c \
		ft_printf_format_p \
		ft_printf_format_y \
		ft_printf_format_r \
		ft_printf_skipva \
		ft_printf_readva \
		ft_printf_addconvmod \
		ft_printf_addoptionflag \
		ft_printf_adjust_field \
		ft_printf_prefix_int \
		ft_printf_prefix_float \
		ft_printf_rstparts_fuse \
		ft_printf_rstparts_clean \
		ft_goodbye

INCLUDES = includes
SRC_DIR = srcs
OBJ_DIR = .obj
DEP_DIR = $(OBJ_DIR)

CFLAGS = -Wall -Werror -Wextra
#CFLAGS += -fsanitize=address

SRC = $(patsubst %, $(SRC_DIR)/%.c, $(FNT))
OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(FNT))
DEP = $(patsubst %, $(DEP_DIR)/%.d, $(FNT))


.PHONY: all
all: $(NAME)

.PHONY: optimized
optimized: CFLAGS += -o3
optimized: all

$(NAME): $(OBJ)
	rm -rf ./*/.git # Safety to prevent gits inside gits, requiered at 42.
	@printf "\e[92m" || true
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@printf "\e[0m" || true

$(OBJ_DIR):
	@printf "\e[94m" || true
	mkdir -p $@
	@printf "\e[0m" || true

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@printf "\e[96m" || true
	gcc $(CFLAGS) -o $@ -I $(INCLUDES) -c $<
	@printf "\e[0m" || true

.PHONY: clean
clean:
	@printf "\e[93m" || true
	rm -f $(OBJ)
	rm -f $(OBJ_DIR)/*.o
	rmdir $(OBJ_DIR) || true
	@printf "\e[0m" || true

.PHONY: fclean
fclean: clean
	@printf "\e[91m" || true
	rm -f $(NAME)
	@printf "\e[0m" || true

.PHONY: re
re: fclean all
	@printf "\e[0m" || true

.PHONY: run
run: $(NAME)
	@printf "\e[0m" || true
	@clear
	@./$< || printf "\e[31mFailed to run \"$<\"!\n" || true
	@printf "\e[31mYou cannot run a library!\n" || true
