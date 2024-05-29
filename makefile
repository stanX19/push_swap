SRCDIR		= srcs
SRCS		:= $(wildcard $(SRCDIR)/**/*.c)

OBJDIR		= objs
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

CWD			:= $(shell pwd)
INCLUDE_DIR	= includes
HEADER_DIR	= headers
HEADERS		:= $(shell find $(HEADER_DIR) -name '*.h') $(shell find $(INCLUDE_DIR) -name '*.h')
HEADERS_INC	= $(addprefix -I,$(sort $(dir $(HEADERS))))

LIBFT_DIR	= $(INCLUDE_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a

LIBS		= $(LIBFT)

IFLAGS		:= -I. $(HEADERS_INC)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3
AR			= ar -rcs
RM			= rm -rf
UP			= \033[1A
FLUSH		= \033[2K

NAME		= push_swap
#ARGV		= 81 3 87 17 32 41 65 99 54 89 14 40 55 16 12 92 75 69 30 86 36 4 73 8 42 77 88 21 39 71 26 27 98 37 67 35 24 93 66 58 68 76 59 6 70 19 29 23 9 97 72 64 49 85 22 96 18 90 56 53 34 74 52 28 63 48 0 78 80 1 11 79 10 46 15 62 47 50 13 83 45 2 84 95 60 61 25 38 7 20 43 51 5 31 57 44 94 91 82 33
ARGV		= -65 -233 -206 -34 -239 159 -66 -73 85 -32 -28 225 -95 104 122 179 -245 205 39 44 166 229 184 56 -86 123 -44 -246 -82 93 -138 -156 174 19 -130 -7 146 92 -128 214 173 218 -185 134 161 -218 243 -71 -109 117 -169 16 -222 -249 -111 -57 -78 -37 -63 -147 -214 20 192 120 -133 231 -51 189 -29 -36 198 -121 -118 40 -91 197 209 -99 199 42 242 95 -228 183 -35 -188 -10 -243 51 188 2 -235 239 128 127 -240 83 -23 246 29 -162 -221 59 21 -61 -136 77 -238 118 66 112 7 -19 96 17 57 -215 -184 -241 74 -100 165 -126 160 -5 -9 12 -247 144 -20 154 -199 -219 129 -139 -176 23 191 -208 -225 241 132 1 -149 145 -104 236 109 -96 87 -223 237 131 108 -205 -150 204 114 50 187 -220 -110 180 -11 175 219 125 -186 170 -114 -92 71 -64 -234 73 -40 -237 84 -170 -72 167 162 -137 -87 -161 164 -117 -50 -144 -70 -39 0 -171 -131 -178 -3 135 -90 82 -197 -202 -143 -69 -201 -229 -14 200 220 247 -179 -180 -196 206 141 -113 70 -24 -68 -94 -167 32 196 -216 140 -232 -17 -116 -46 53 136 27 81 -53 11 249 88 13 -250 -89 62 176 216 -210 -227 5 -27 194 -77 -181 208 -209 10 -30 -102 -67 139 -231 -101 54 18 234 -42 41 -58 90 -207 -81 -190 -43 -22 169 38 -145 -49 48 142 215 172 -165 -217 30 -108 137 -8 14 -200 8 182 -21 55 193 124 69 91 235 -41 -112 -187 223 212 -160 -153 34 -129 9 47 -236 -224 101 195 79 -174 233 -192 -164 -76 -6 -59 -12 64 -48 25 185 -158 31 245 133 238 60 -212 207 177 -80 126 -173 15 -54 230 -55 72 99 -198 -154 150 158 52 171 -123 -195 -140 -62 149 3 -248 105 -98 -15 78 63 -141 24 -125 -242 -105 58 -31 178 224 228 4 -107 -60 76 -75 102 -134 -194 -13 -97 -38 75 36 157 -124 -172 221 130 211 113 -4 -56 121 138 -84 -26 -163 226 -103 -148 -33 163 147 -151 111 244 151 6 43 119 -142 -157 240 -18 -166 -203 97 -47 -146 94 186 -1 -182 115 -189 -85 190 -159 -244 -152 -193 -115 222 37 107 227 67 -79 -213 98 -119 45 -25 201 152 143 116 -155 -226 -132 217 -83 -230 202 -45 210 -175 248 80 -135 156 -2 22 -93 213 28 -122 35 -191 89 153 106 49 46 -74 -52 168 103 100 61 -183 203 155 33 -88 -16 68 -127 110 -120 181 -168 65 -204 232 -106 86 -177 148 -211 26


run: all
	@touch _DISPLAY
	./$(NAME) $(ARGV)
	@$(RM) _DISPLAY

$(NAME): $(LIBS) $(OBJDIRS) $(OBJS) srcs/push_swap_main.c checker
	$(CC) $(CFLAGS) srcs/push_swap_main.c $(OBJS) $(IFLAGS) $(LIBS) -o $(NAME)

all: $(NAME)

bonus: checker

checker: $(LIBS) $(OBJDIRS) $(OBJS) srcs/checker_main.c
	$(CC) $(CFLAGS) srcs/checker_main.c $(OBJS) $(IFLAGS) $(LIBS) -o checker

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) $(LIBS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

clean:
	@$(RM) $(OBJS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@$(RM) $(TESTDIR)
	@$(RM) $(OBJDIRS)
	@$(RM) ./a.out

re: fclean $(NAME)

push:
	@echo -n "Commit name: "; read name; make fclean;\
	cd $(LIBFT_DIR); git add .; git commit -m "$$name"; git push;\
	cd $(CWD); git add .; git commit -m "$$name"; git push;\

BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
ifeq ($(BRANCH),HEAD)
BRANCH := main
endif
pull:
	git fetch --all
	git checkout -f $(BRANCH);
	git reset --hard origin/$(BRANCH);
	git submodule update --init --remote --recursive
	make -C $(LIBFT_DIR) pull

$(LIBFT): $(LIBFT_DIR) $(shell find $(LIBFT_DIR) -name "*.c")
	make -C $(LIBFT_DIR) all

$(LIBFT_DIR):
	touch .gitmodules
	git submodule add --force git@github.com:stanX19/libft.git $(LIBFT_DIR)
	git config -f .gitmodules submodule.$(LIBFT_DIR).branch main
	git submodule update --init --recursive --remote

init_libft: $(LIBFT_DIR)

TESTDIR		= ps_tester
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	TEST_SH	= push_swap_test_linux.sh
else
    TEST_SH	= push_swap_test.sh
endif
$(TESTDIR):
	git clone https://github.com/gemartin99/Push-Swap-Tester.git $(TESTDIR)

test: $(TESTDIR) all
	cp -r push_swap $(TESTDIR)/push_swap
	cd $(TESTDIR); bash $(TEST_SH) 1 200;

.PHONY: all clean fclean re bonus push .c.o