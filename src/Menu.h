#ifndef MENU_H_WVSZJCBK
#define MENU_H_WVSZJCBK

#include "gameplay.h"

using namespace gameplay;

class Menu : public AnimationClip::Listener
{
public:
   static Menu* create(); 

   Menu();
   virtual ~Menu();

   void update(float elapsedTime);
   void render(float elapsedTime);
   bool drawScene(Node* node);
   bool checkScene(Node* node, Ray* ray);
   void touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex);
   void animationEvent(gameplay::AnimationClip*, gameplay::AnimationClip::Listener::EventType);

   void onUserSelection(Node* node);

private:
   Scene* _scene;
};

#endif /* end of include guard: MENU_H_WVSZJCBK */

