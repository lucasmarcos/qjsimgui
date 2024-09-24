#include <cimgui.h>
#include <cimgui_impl_sdl2.h>
#include <cimgui_impl_sdlrenderer2.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	window = SDL_CreateWindow("qjsimgui", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 360, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);

	ImGui_CreateContext(NULL);

	cImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	cImGui_ImplSDLRenderer2_Init(renderer);

	_Bool demo_window = 1;

	SDL_bool running = SDL_TRUE;
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			cImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT) {
				running = SDL_FALSE;
			}
		}

		cImGui_ImplSDLRenderer2_NewFrame();
		cImGui_ImplSDL2_NewFrame();
		ImGui_NewFrame();

		if (demo_window) {
			ImGui_ShowDemoWindow(&demo_window);
		}

		ImGui_Render();
		SDL_RenderClear(renderer);
		cImGui_ImplSDLRenderer2_RenderDrawData(ImGui_GetDrawData(), renderer);
		SDL_RenderPresent(renderer);
	}

	cImGui_ImplSDLRenderer2_Shutdown();
	cImGui_ImplSDL2_Shutdown();
	ImGui_DestroyContext(NULL);
	SDL_Quit();
	return 0;
}
