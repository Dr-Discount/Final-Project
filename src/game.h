#pragma once  
#include "snake.h"  
#include "food.h"  
#include <iostream>

class Game {  
public:  
   Snake snake = Snake();  
   Food food = Food();  

   void Draw() {  
       snake.Draw();  
       food.ranPosition(snake.body);
       food.Draw();  
       
   }  

   void Update() {  
       snake.Update();  
   }  

   void CheckCollisionWithFood() {  
       if (Vector2Equals(snake.body[0], food.position)) {  
           food.position = food.ranPosition(snake.body);  
           snake.body.push_back(snake.body.back());  
           std::cout << "Food eaten!" << std::endl;
       }  
   }  
};