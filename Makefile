main: main.o
	g++ -o main -I deps/imgui -I deps/cimgui -I deps/imgui/backends -I /usr/include/SDL2 -lm -lSDL2 main.o deps/cimgui/cimgui.cpp deps/cimgui/cimgui_impl_sdl2.cpp deps/cimgui/cimgui_impl_sdlrenderer2.cpp deps/imgui/imgui.cpp deps/imgui/imgui_draw.cpp deps/imgui/imgui_tables.cpp deps/imgui/imgui_widgets.cpp deps/imgui/imgui_demo.cpp deps/imgui/backends/imgui_impl_sdl2.cpp deps/imgui/backends/imgui_impl_sdlrenderer2.cpp

main.o: src/main.c
	gcc -c -I deps/cimgui -I deps/imgui src/main.c

# deps/cimgui/cimgui.cpp
# deps/imgui/imgui.cpp
# deps/imgui/imgui_draw.cpp
# deps/imgui/imgui_tables.cpp
# deps/imgui/imgui_widgets.cpp
# deps/imgui/imgui_demo.cpp
