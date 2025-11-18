NAME		:= bureaucrat						# Name of final executable							# Source directory (current directory of the exercise)					# Where object files are built
CXX			:= c++								# C++ compiler
CXXFLAGS	:= -std=c++98 -Wall -Werror -Wextra	# Compilation flags
INCLUDE	:= -I.									# Looks in the current directory for #include files

SRCS		:=	main.cpp Bureaucrat.cpp
BUILD_DIR	:=	build							# Directory where all the compiled object files will go, keeps project organsised
OBJS		:=	$(SRCS:%.cpp=$(BUILD_DIR)/%.o)	# Transorms the list of cpp files into .o files in the build directory

#all is what is run when you run make
all: $(NAME)

#the executable depends on the object files/
# If any .o files are missing or outdated (timestamp), make will build it first
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

#rule that tells it how to create .o files
# first need to create the build directory
# to build .o, look for.cpp file
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
# <$ first prerequisite (the .cpp file)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

flean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all