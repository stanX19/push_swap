SRCDIR		= srcs
SRCS		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR		= objs
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

INCLUDE_DIR	= includes
HEADER_DIR	= headers
HEADERS		:= $(shell find $(HEADER_DIR) -name '*.h') $(shell find $(INCLUDE_DIR) -name '*.h')
HEADERS_INC	= $(addprefix -I,$(sort $(dir $(HEADERS))))

IFLAGS		:= -I. $(HEADERS_INC)

PRINTFLIB_DIR	= $(INCLUDE_DIR)/libftprintf
PRINTFLIB	= $(PRINTFLIB_DIR)/libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3
RM			= rm -rf
UP			= \033[1A
FLUSH		= \033[2K

NAME		= push_swap
ARGV		= 1 5 2 3 4

run: all
	./$(NAME) $(ARGV)

all: $(NAME)

$(NAME): $(PRINTFLIB) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(PRINTFLIB) -o $(NAME)

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

clean:
	@$(RM) $(OBJS)

fclean:	clean
	make -C $(PRINTFLIB_DIR) fclean
	@$(RM) $(NAME)
	@$(RM) $(TESTDIR)
	@$(RM) $(OBJDIRS)
	@$(RM) ./a.out

re: fclean $(NAME)

push:
	@echo -n "Commit name: "; read name; make fclean;\
	git add .; git commit -m "$$name"; git push;

$(PRINTFLIB): $(PRINTFLIB_DIR)
	make -C $(PRINTFLIB_DIR) all

$(PRINTFLIB_DIR):
	touch .gitmodules
	git submodule add --force git@github.com:stanX19/ft_printf.git $(PRINTFLIB_DIR)
	git config -f .gitmodules submodule.$(PRINTFLIB_DIR).branch main
	git submodule update --init --recursive --remote

.PHONY: all clean fclean re bonus push