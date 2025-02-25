EXE = bin.exe
OBJ_DIR = obj
UB_CLASS_DIR = class

SOURCES = main.cpp glad.c
SOURCES += $(UB_CLASS_DIR)/shader.cpp $(UB_CLASS_DIR)/camera.cpp $(UB_CLASS_DIR)/texture.cpp  $(UB_CLASS_DIR)/inputHandler.cpp $(UB_CLASS_DIR)/buttons.cpp
SOURCES += $(UB_CLASS_DIR)/simpleBox.cpp
SOURCES += stb_image/stb_image.cpp

OBJS_FILES = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(SOURCES)))))

UNAME_S := $(shell uname -s)
LINUX_GL_LIBS = -Llib/ -lglfw3 -lGL -ldl -lX11 -lpthread -lXrandr -lXi
CXXFLAGS = -w -g
RUN = ./$(EXE)

ifeq ($(UNAME_S), Linux)
	ECHO_MESSAGE = "Linux"
endif


$(OBJ_DIR)/%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o:$(UB_CLASS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o:%.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o:stb_image/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	$(shell $(RUN)) @echo Build complete for $(ECHO_MESSAGE)

$(EXE): $(OBJS_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LINUX_GL_LIBS)

clean:
	rm -f $(EXE) $(OBJS_FILES)
