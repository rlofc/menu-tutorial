#include "Menu.h"

Menu* Menu::create()
{
   return new Menu();
}

Menu::Menu()
{
   _scene = Scene::load("res/menu.scene");
   Camera * cam = _scene->getActiveCamera();
   if (cam) 
   {
      cam->setAspectRatio(Game::getInstance()->getAspectRatio());
      cam->getNode()->rotateY(MATH_DEG_TO_RAD(-90));
   }
   Node * light = _scene->findNode("Spot");
   if (light) 
   {
      _scene->setLightDirection(light->getForwardVector());
   }

   const char* options[] = {"menu_play", "menu_extras", "menu_options"};

   for (int i = 0 ; i < sizeof(options)/sizeof(char*) ; i++) {
      Node* option = _scene->findNode(options[i]);
      if (option) {
         Animation* anim = option->getAnimation();
         anim->createClips("res/menu_item.animation");
         anim->play("bounce");
      }
   }

   _scene->findNode("menu_play")->getAnimation()->getClip("bounce")->addEndListener(this); 
}

Menu::~Menu()
{
   SAFE_RELEASE(_scene);
}

void Menu::update(float elapsedTime)
{
    _scene->findNode("Cube")->rotateY(MATH_DEG_TO_RAD((float)elapsedTime / 1000.0f * 180.0f));
}

void Menu::render(float elapsedTime)
{
    _scene->visit(this, &Menu::drawScene);
}

bool Menu::drawScene(Node* node)
{
    Model* model = node->getModel(); 
    if (model)
    {
        model->draw();
    }
    return true;
}

bool Menu::checkScene(Node* node, Ray* ray)
{
   Model* model = node->getModel();
   if (model)
   {
      BoundingBox worldSpaceBoundingBox(model->getMesh()->getBoundingBox());
      worldSpaceBoundingBox.transform(node->getWorldMatrix());

      float distance = FLT_MAX;
      if( (distance = ray->intersects(worldSpaceBoundingBox)) != Ray::INTERSECTS_NONE )
      {
         onUserSelection(node);
      }

   }
}

void Menu::touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex)
{
   switch (evt)
   {
   case Touch::TOUCH_PRESS:
      break;
   case Touch::TOUCH_RELEASE:
      {
         Ray ray;
         Camera* camera = _scene->getActiveCamera();
         if (camera) {
            camera->pickRay(Game::getInstance()->getViewport(), x, y, &ray);
            _scene->visit(this, &Menu::checkScene, &ray);
         }
      }
      break;
   case Touch::TOUCH_MOVE:
      break;
   };
}

void Menu::animationEvent(gameplay::AnimationClip* clip, gameplay::AnimationClip::Listener::EventType evt)
{
   if (evt==AnimationClip::Listener::END)
   {
      _scene->findNode("menu_play")->getAnimation()->play("jiggle");
   }
}

void Menu::onUserSelection(Node* node) 
{
   if (strcmp(node->getId(),"menu_play")==0) {
      puts("go to play");
   }
   if (strcmp(node->getId(),"menu_options")==0) {
      puts("go to options");
   }
   if (strcmp(node->getId(),"menu_extras")==0) {
      puts("go to extras");
   }
}
