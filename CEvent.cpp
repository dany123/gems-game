#include "CEvent.h"
#include <iostream>

CEvent::CEvent()
{
}

CEvent::~CEvent()
{
}

COORDS CEvent::onEvent(SDL_Event* event)
{
    COORDS click_coords;
    click_coords.x = -1;
    click_coords.y = -1;

    switch(event->type) {
        case SDL_ACTIVEEVENT: {
            switch(event->active.state) {
                case SDL_APPMOUSEFOCUS: {
                    if ( event->active.gain )    onMouseFocus();
                    else                onMouseBlur();

                    break;
                }
                case SDL_APPINPUTFOCUS: {
                    if ( event->active.gain )    onInputFocus();
                    else                onInputBlur();

                    break;
                }
                case SDL_APPACTIVE:    {
                    if ( event->active.gain )    onRestore();
                    else                onMinimize();

                    break;
                }
            }
            break;
        }

        case SDL_KEYDOWN: {
            onKeyDown(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
            break;
        }

        case SDL_KEYUP: {
            onKeyUp(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
            break;
        }

        case SDL_MOUSEMOTION: {
            onMouseMove(event->motion.x, event->motion.y, event->motion.xrel, event->motion.yrel,(event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
            break;
        }

        case SDL_MOUSEBUTTONDOWN: {
            switch(event->button.button) {
                case SDL_BUTTON_LEFT: {
                                                      // in click_coords we'll have the coordinates of the click
                    click_coords.x = event->button.x;
                    click_coords.y = event->button.y;

                    onLButtonDown(event->button.x, event->button.y);

                    return click_coords;

                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    onRButtonDown(event->button.x, event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    onMButtonDown(event->button.x, event->button.y);
                    break;
                }
            }
            break;
        }

        case SDL_MOUSEBUTTONUP:    {
            switch(event->button.button) {
                case SDL_BUTTON_LEFT: {
                    onLButtonUp(event->button.x, event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    onRButtonUp(event->button.x, event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    onMButtonUp(event->button.x, event->button.y);
                    break;
                }
            }
            break;
        }

        case SDL_JOYAXISMOTION: {
            onJoyAxis(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
            break;
        }

        case SDL_JOYBALLMOTION: {
            onJoyBall(event->jball.which, event->jball.ball, event->jball.xrel, event->jball.yrel);
            break;
        }

        case SDL_JOYHATMOTION: {
            onJoyHat(event->jhat.which, event->jhat.hat, event->jhat.value);
            break;
        }
        case SDL_JOYBUTTONDOWN: {
            onJoyButtonDown(event->jbutton.which, event->jbutton.button);
            break;
        }

        case SDL_JOYBUTTONUP: {
            onJoyButtonUp(event->jbutton.which, event->jbutton.button);
            break;
        }

        case SDL_QUIT: {
            onExit();
            break;
        }

        case SDL_SYSWMEVENT: {
            //Ignore
            break;
        }

        case SDL_VIDEORESIZE: {
            onResize(event->resize.w, event->resize.h);
            break;
        }

        case SDL_VIDEOEXPOSE: {
            onExpose();
            break;
        }

        default: {
            onUser(event->user.type, event->user.code, event->user.data1, event->user.data2);
            break;
        }
    }
    return click_coords;
}

void CEvent::onInputFocus() {
    //Pure virtual, do nothing
}

void CEvent::onInputBlur() {
    //Pure virtual, do nothing
}

void CEvent::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    //Pure virtual, do nothing
}

void CEvent::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    //Pure virtual, do nothing
}

void CEvent::onMouseFocus() {
    //Pure virtual, do nothing
}

void CEvent::onMouseBlur() {
    //Pure virtual, do nothing
}

void CEvent::onMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
    //Pure virtual, do nothing
}

void CEvent::onMouseWheel(bool Up, bool Down) {
    //Pure virtual, do nothing
}

void CEvent::onLButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::onLButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::onRButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::onRButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::onMButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::onMButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::onJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
    //Pure virtual, do nothing
}

void CEvent::onJoyButtonDown(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
}

void CEvent::onJoyButtonUp(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
}

void CEvent::onJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
    //Pure virtual, do nothing
}

void CEvent::onJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
    //Pure virtual, do nothing
}

void CEvent::onMinimize() {
    //Pure virtual, do nothing
}

void CEvent::onRestore() {
    //Pure virtual, do nothing
}

void CEvent::onResize(int w,int h) {
    //Pure virtual, do nothing
}

void CEvent::onExpose() {
    //Pure virtual, do nothing
}

void CEvent::onExit() {
    //Pure virtual, do nothing
}

void CEvent::onUser(Uint8 type, int code, void* data1, void* data2) {
    //Pure virtual, do nothing
}
