#include "Engine.h"

Engine::Engine()
{
	render = new Render();
}

void Engine::Init()
{
	render->Init();

}

void Engine::Tick()
{
	render->Tick();
}

void Engine::Clear()
{
	render->Clear();
}

Engine::~Engine()
{
	delete render;
}