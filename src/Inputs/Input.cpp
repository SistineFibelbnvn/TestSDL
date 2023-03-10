#include "Input.h"
#include "Engine.h"
Input* Input::s_Instance=nullptr;
Input::Input()
{
    m_KeyStates=SDL_GetKeyboardState(nullptr);
}
void Input::Listen()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT: Engine::GetInstance()->Quit();break;
            case SDL_KEYDOWN: KeyDown();break;
            case SDL_KEYUP: KeyUp();break;
        }
    }
}

bool Input::GetKeyDown(SDL_Scancode key)
{
    if(m_KeyStates[key]==1) return true;
    return false;
}

void Input::KeyUp()
{
    m_KeyStates=SDL_GetKeyboardState(nullptr);

}

void Input::KeyDown()
{
    m_KeyStates=SDL_GetKeyboardState(nullptr);
}
int Input::GetAxisKey(Axis axis)
{
    switch(axis){
        case HORIZONTAL:
            if(GetKeyDown(SDL_SCANCODE_D)) return 1;
            if(GetKeyDown(SDL_SCANCODE_A)) return -1;
            break;

        case VERTICAL:
            if(GetKeyDown(SDL_SCANCODE_W)) return 1;
            if(GetKeyDown(SDL_SCANCODE_S)) return -1;
            break;
        default: return 0;
    }
    return 0;
}



