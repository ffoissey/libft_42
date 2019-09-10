# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 18:25:23 by ffoissey          #+#    #+#              #
#    Updated: 2019/09/10 15:31:54 by ffoissey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
################################               #################################
################################    SUMMARY    #################################
################################               #################################
################################################################################

# Main Variables >>>>>>>>>>>>>> line  47
# Print Var 	 >>>>>>>>>>>>>>	line  75
# Includes	 	 >>>>>>>>>>>>>>	line  97
# Headers 		 >>>>>>>>>>>>>>	line 107
# Path Sources   >>>>>>>>>>>>>>	line 135
# Sources     	 >>>>>>>>>>>>>>	line 154
#       |---> string		--> line 156 
#       |---> char			--> line 233
#       |---> memory		--> line 253 
#       |---> output		--> line 280 
#       |---> conversion	--> line 304
#       |---> maths			--> line 315
#       |---> list			--> line 321
#       |---> sort			--> line 348
#       |---> other			--> line 357
#       |---> get_next_line --> line 362
#       |---> ft_printf     --> line 368
#       |---> vector	    --> line 398
#       |---> #attribution  --> line 431
# Objs    	 	 >>>>>>>>>>>>>>	line 451
# Rules     	 >>>>>>>>>>>>>>	line 463
# End  		   	 >>>>>>>>>>>>>>	line 516

################################################################################
################################                ################################
################################ MAIN VARIABLES ################################
################################                ################################
################################################################################

# Name
NAME = libft.a
DEBUG_NAME = db_libft.a

# Compiler
CC = clang

# Compiler Flags
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

# Compiler Debug Flags
DBFLAGS += $(CFLAGS)
DBFLAGS += -fsanitize=address,undefined
DBFLAGS += -g3
DBFLAGS += -pedantic

# Debug Dir
DSYM += $(NAME).dSYM
DSYM += $(DBNAME).dSYM

################################################################################
################################                ################################
################################   PRINT VAR    ################################
################################                ################################
################################################################################

# Reset
NC = \033[0m

# Regular Colors
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

# One Line Output
ONELINE =\e[1A\r

################################################################################
#################################               ################################
#################################    INCLUDES   ################################
#################################               ################################
################################################################################

INCLUDES_LIBFT = includes/

I_INCLUDES += -I $(INCLUDES_LIBFT)

################################################################################
#################################               ################################
#################################    HEADERS    ################################
#################################               ################################
################################################################################

# libft
HEADER += libft.h
HEADER += define_libft.h
HEADER += ft_string.h
HEADER += ft_char.h
HEADER += ft_output.h
HEADER += ft_memory.h
HEADER += ft_conversion.h
HEADER += ft_maths.h
HEADER += ft_sort.h
HEADER += ft_other.h
HEADER += ft_vector.h

# get_next_line
HEADER += get_next_line.h

# ft_printf
HEADER += ft_printf.h
HEADER += ft_double.h

vpath %.h $(INCLUDES_LIBFT)

################################################################################
#################################               ################################
#################################  PATH SOURCES ################################
#################################               ################################
################################################################################

PATH_SRCS_STRING = srcs/string
PATH_SRCS_CHAR = srcs/char
PATH_SRCS_MEMORY = srcs/memory
PATH_SRCS_OUTPUT = srcs/output
PATH_SRCS_CONVERSION = srcs/conversion
PATH_SRCS_MATHS = srcs/maths
PATH_SRCS_LIST = srcs/list
PATH_SRCS_SORT = srcs/sort
PATH_SRCS_OTHER = srcs/other
PATH_SRCS_GNL = srcs/get_next_line
PATH_SRCS_PRINTF = srcs/ft_printf
PATH_SRCS_VECTOR = srcs/vector

################################################################################
#################################               ################################
#################################    SOURCES    ################################
#################################               ################################
################################################################################

#----------------------------------- STRING -----------------------------------#

# Concat
SRCS += ft_strcat.c
SRCS += ft_strlcat.c
SRCS += ft_strncat.c

# Comp
SRCS += ft_strcmp.c
SRCS += ft_strncmp.c
SRCS += ft_strequ.c
SRCS += ft_strnequ.c
SRCS += ft_strcasecmp.c
SRCS += ft_strncasecmp.c

# Search
SRCS += ft_strchr.c
SRCS += ft_strrchr.c
SRCS += ft_strstr.c
SRCS += ft_strnstr.c
SRCS += ft_strcasestr.c

# Copy
SRCS += ft_strcpy.c
SRCS += ft_strncpy.c
SRCS += ft_strlcpy.c

# Dup
SRCS += ft_strdup.c
SRCS += ft_strndup.c
SRCS += ft_strcdup.c

# Join
SRCS += ft_strjoin.c
SRCS += ft_strjoinfree.c

# Sub
SRCS += ft_strsub.c

# Len
SRCS += ft_strlen.c
SRCS += ft_strnlen.c
SRCS += ft_strclen.c

# Cleanup
SRCS += ft_strclr.c
SRCS += ft_strdel.c
SRCS += ft_free_tab_str.c

# Test
SRCS += ft_str_is_lowercase.c
SRCS += ft_str_is_uppercase.c
SRCS += ft_str_is_numeric.c

# New
SRCS += ft_strnew.c

# Trim
SRCS += ft_strtrim.c
SRCS += ft_strctrim.c

# Transform
SRCS += ft_strupcase.c
SRCS += ft_strlowcase.c
SRCS += ft_strcapitalize.c
SRCS += ft_strrev.c
SRCS += ft_striter.c
SRCS += ft_striteri.c

# Split
SRCS += ft_strsplit.c
SRCS += ft_strsplit_whitespaces.c

# Map
SRCS += ft_strmap.c
SRCS += ft_strmapi.c

#------------------------------------ CHAR ------------------------------------#

# Transform
SRCS += ft_tolower.c
SRCS += ft_toupper.c

# Test
SRCS += ft_islower.c
SRCS += ft_isupper.c
SRCS += ft_isxdigit.c
SRCS += ft_isblank.c
SRCS += ft_iscntrl.c
SRCS += ft_isgraph.c
SRCS += ft_isspace.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c

#----------------------------------- MEMORY -----------------------------------#

# Search
SRCS += ft_memchr.c

# Comp
SRCS += ft_memcmp.c

# Copy
SRCS += ft_memcpy.c
SRCS += ft_memccpy.c
SRCS += ft_memmove.c

# Free
SRCS += ft_memdel.c

# Alloc
SRCS += ft_memalloc.c

# Set
SRCS += ft_memset.c
SRCS += ft_bzero.c

# Bits
SRCS += ft_inverse_bits.c
SRCS += ft_swap_bits.c

#----------------------------------- OUTPUT -----------------------------------#

# Char
SRCS += ft_putchar.c
SRCS += ft_putchar_fd.c

# String
SRCS += ft_putstr.c
SRCS += ft_putstr_fd.c
SRCS += ft_putendl.c
SRCS += ft_putendl_fd.c

# Number
SRCS += ft_putnbr.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putnbr_base.c

# Tab
SRCS += ft_print_inttab.c
SRCS += ft_print_strtab.c

# Int Bit
SRCS += ft_print_int_bits.c

#--------------------------------- CONVERSION ---------------------------------#

# Str to Int
SRCS += ft_atoi.c
SRCS += ft_atoi_base.c
SRCS += ft_atol.c

# Int to Str
SRCS += ft_itoa.c
SRCS += ft_itoa_base.c

#------------------------------------ MATHS -----------------------------------#

SRCS += ft_factorial.c
SRCS += ft_pow.c
SRCS += ft_sqrt.c

#------------------------------------ LIST ------------------------------------#

# New
SRCS += ft_lstnew.c
SRCS += ft_lstnew_nomalloc.c

# Add
SRCS += ft_lstadd.c
SRCS += ft_lstadd_back.c

# Del
SRCS += ft_lstpop.c
SRCS += ft_lstdel.c
SRCS += ft_lstdelone.c
SRCS += ft_lstdelnode.c

# Map
SRCS += ft_lstiter.c
SRCS += ft_lstmap.c

# Get
SRCS += ft_lstlast.c
SRCS += ft_lstsize.c

# Get
SRCS += ft_lst_mergesort.c

#------------------------------------ SORT ------------------------------------#

# Bubble
SRCS += ft_bubblesort_integer.c
SRCS += ft_bubblesort_strtab.c

# Insertion
SRCS += ft_insertsort_integer.c

#----------------------------------- OTHER ------------------------------------#

SRCS += ft_swap.c
SRCS += ft_read_all.c

#-------------------------------- GET NEXT LINE -------------------------------#

SRCS += get_next_line.c
SRCS += get_next_line_multifd.c
SRCS += get_next_line_origin.c

#---------------------------------- FT_PRINTF ---------------------------------#

# Main
SRCS += ft_printf.c
SRCS += ft_dprintf.c
SRCS += ft_asprintf.c

# Extend
SRCS += ft_printf_extend.c
SRCS += ft_set_flags.c
SRCS += ft_set_flags_extend.c
SRCS += ft_flag_extend.c
SRCS += ft_functions_nb.c
SRCS += ft_util.c
SRCS += ft_util2.c

# Conversion
SRCS += ft_conversion.c
SRCS += ft_conversion_oth.c
SRCS += ft_conversion_u.c
SRCS += ft_conversion_large.c
SRCS += ft_conversion_extend.c

# Double
SRCS += ft_double_hub.c
SRCS += ft_double_set.c
SRCS += ft_double_extend.c
SRCS += ft_double_operate.c
SRCS += ft_double_precision.c
SRCS += ft_double_mantissa.c

#----------------------------------- VECTOR -----------------------------------#

SRCS += ft_vct_add.c
SRCS += ft_vct_addstr.c
SRCS += ft_vct_apply.c
SRCS += ft_vct_cat.c
SRCS += ft_vct_cdup.c
SRCS += ft_vct_charat.c
SRCS += ft_vct_clear.c
SRCS += ft_vct_cpy.c
SRCS += ft_vct_cut.c
SRCS += ft_vct_cutfrom.c
SRCS += ft_vct_del.c
SRCS += ft_vct_dup.c
SRCS += ft_vct_dupstr.c
SRCS += ft_vct_extend.c
SRCS += ft_vct_fill.c
SRCS += ft_vct_getstr.c
SRCS += ft_vct_join.c
SRCS += ft_vct_joinfree.c
SRCS += ft_vct_len.c
SRCS += ft_vct_ndup.c
SRCS += ft_vct_new.c
SRCS += ft_vct_newstr.c
SRCS += ft_vct_pop.c
SRCS += ft_vct_popfrom.c
SRCS += ft_vct_push.c
SRCS += ft_vct_pushstr.c
SRCS += ft_vct_replacechar.c
SRCS += ft_vct_replacestr.c
SRCS += ft_vct_reset.c
SRCS += ft_vct_sub.c

################# ATTRIBUTION

vpath %.c $(PATH_SRCS_STRING)
vpath %.c $(PATH_SRCS_CHAR)
vpath %.c $(PATH_SRCS_MEMORY)
vpath %.c $(PATH_SRCS_OUTPUT)
vpath %.c $(PATH_SRCS_CONVERSION)
vpath %.c $(PATH_SRCS_MATHS)
vpath %.c $(PATH_SRCS_LIST)
vpath %.c $(PATH_SRCS_SORT)
vpath %.c $(PATH_SRCS_OTHER)
vpath %.c $(PATH_SRCS_GNL)
vpath %.c $(PATH_SRCS_PRINTF)
vpath %.c $(PATH_SRCS_VECTOR)

################################################################################
#################################               ################################
#################################     OBJS      ################################
#################################               ################################
################################################################################

PATH_OBJS = objs/
OBJS = $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

DEBUG_PATH_OBJS = objs_debug/
DEBUG_OBJS = $(patsubst %.c, $(DEBUG_PATH_OBJS)%.o, $(SRCS))

################################################################################
#################################               ################################
#################################     RULES     ################################
#################################               ################################
################################################################################

#---------------------------------- STANDARD ----------------------------------#

all: $(PATH_OBJS) $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^
	printf "$(GREEN)$@ is ready.\n\n$(NC)"

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(I_INCLUDES) -c $< -o $@
	printf "$(ONELINE)$(CYAN)Compiling $<"
	printf "                                                            \n$(NC)"

$(PATH_OBJS):
	mkdir $@

#------------------------------------ DEBUG -----------------------------------#

debug: $(DEBUG_PATH_OBJS) $(DEBUG_NAME)

$(DEBUG_NAME): $(DEBUG_OBJS)
	ar rcs $@ $^
	printf "$(GREEN)$@ is ready.\n\n$(NC)"

$(DEBUG_OBJS): $(DEBUG_PATH_OBJS)%.o: %.c $(HEADER) Makefile
	$(CC) $(DBFLAGS) $(I_INCLUDES) -c $< -o $@
	printf "$(ONELINE)$(PURPLE)Compiling for DEBUG $<"
	printf "                                                            \n$(NC)"

$(DEBUG_PATH_OBJS):
	mkdir $@

#--------------------------------- Basic Rules --------------------------------#

clean:
	$(RM) $(OBJS)
	$(RM) $(DEBUG_OBJS)
	$(RM) -R $(PATH_OBJS)
	$(RM) -R $(DEBUG_PATH_OBJS)
	$(RM) -R $(DSYM)
	printf "$(RED)Objs from libft removed\n$(NC)"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DEBUG_NAME)
	printf "$(RED)$(NAME) removed\n$(NC)"

re: fclean all

#----------------------------------- Special ----------------------------------#

.PHONY: clean fclean re all
.SILENT:
