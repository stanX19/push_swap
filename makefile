SRCDIR		= srcs
SRCS		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR		= objs
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

HEADER_DIR	=headers
HEADERS		:= $(shell find $(HEADER_DIR) -name '*.h')
IFLAGS		= -I. -I$(HEADER_DIR)
LINKERS		= 

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3
RM			= rm -rf
UP			= \033[1A
FLUSH		= \033[2K

NAME		= push_swap
ARGV		= 5 4 3 2 1

run: all
	./$(NAME) $(ARGV)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LINKERS) -o $(NAME)

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

clean:
	@$(RM) $(OBJS)
fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(OBJDIRS)
	@$(RM) ./a.out

re: fclean $(NAME)

push:
	@echo -n "Commit name: "; read name; make fclean;\
	git add .; git commit -m "$$name"; git push;

.PHONY: all clean fclean re bonus push