#include "MenuTutorial.h"

// Declare our game instance
MenuTutorial game;

MenuTutorial::MenuTutorial() : _menu(NULL)
{
}

void MenuTutorial::initialize()
{
   _menu = Menu::create();
}

void MenuTutorial::finalize()
{
   SAFE_DELETE(_menu);
}

void MenuTutorial::update(float elapsedTime)
{
   if (_menu)
   {
      _menu->update(elapsedTime);
   }
}

void MenuTutorial::render(float elapsedTime)
{
   clear(CLEAR_COLOR_DEPTH, Vector4::zero(), 1.0f, 0);
   if (_menu)
   {
      _menu->render(elapsedTime);
   }

}

void MenuTutorial::keyEvent(Keyboard::KeyEvent evt, int key)
{
    if (evt == Keyboard::KEY_PRESS)
    {
        switch (key)
        {
        case Keyboard::KEY_ESCAPE:
            exit();
            break;
        }
    }
}

void MenuTutorial::touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex)
{
   if (_menu)
   {
      _menu->touchEvent(evt,x,y,contactIndex);
   }
}
