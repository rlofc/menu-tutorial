#ifndef TEMPLATEGAME_H_
#define TEMPLATEGAME_H_

#include "gameplay.h"
#include "Menu.h"
using namespace gameplay;

/**
 * Main game class.
 */
class MenuTutorial: public Game
{
public:

    /**
     * Constructor.
     */
    MenuTutorial();

    /**
     * @see Game::keyEvent
     */
	void keyEvent(Keyboard::KeyEvent evt, int key);
	
    /**
     * @see Game::touchEvent
     */
    void touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex);

protected:

    /**
     * @see Game::initialize
     */
    void initialize();

    /**
     * @see Game::finalize
     */
    void finalize();

    /**
     * @see Game::update
     */
    void update(float elapsedTime);

    /**
     * @see Game::render
     */
    void render(float elapsedTime);

private:
   Menu* _menu;
};

#endif
