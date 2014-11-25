/*
 * CS475/CS675 - Computer Graphics
 *  ToyLOGO Assignment Base Code
 *
 * Copyright 2011, Parag Chaudhuri, Department of CSE, IIT Bombay
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "render_drawing.hpp"
#include <math.h>


void triline(turtle_t &turt, double length)
{
   if (length <= 0.01)
   {
      turt.forward(length);
   }
   else
   {
     double newlength = length/3.0;
     triline(turt, newlength);
     turt.turn_left(60);
     triline(turt, newlength);
     turt.turn_right(120);
     triline(turt, newlength);
     turt.turn_left(60);
     triline(turt, newlength);
   }
}

//Drawing a Koch Snowflake
void koch(turtle_t &turt, double x)
{
   turt.reset();
   turt.clear();
   turt.set_pos(-0.3, 0.5);
   turt.turn_right(30);

   for (int i = 0; i<3; i++)
     {
       triline(turt, x);
       turt.turn_right(120);
     }
}

void draw_plant(turtle_t &turt, double x){
	if (x <= 0.01){
		turt.forward(x);
		turt.turn_right(25);
		turt.forward(x / 2);
		turt.backward_move(x / 2);
		turt.turn_left(50);
		turt.forward(x / 2);
		turt.backward_move(x / 2);
		turt.turn_right(25);
		turt.backward_move(x);
	}
	else{
		turt.forward(x);
		turt.turn_right(25);
		draw_plant(turt, x / 2);
		turt.turn_left(50);
		draw_plant(turt, x / 2);
		turt.turn_right(25);
		turt.backward_move(x);
	}
}

void plant(turtle_t &turt, double x){
	turt.reset();
	turt.clear();
	turt.set_pos(0,-1);
	turt.turn_left(90);
	draw_plant(turt, x);
}

void draw_square(turtle_t &turt, double x){
	for (int i = 0; i < 4; i++){
		turt.forward(x);
		turt.turn_left(90);
	}
}

void draw_square1(turtle_t &turt, double x){
	for (int i = 0; i < 4; i++){
		turt.forward(x);
		turt.turn_right(90);
	}
}

void draw_tree(turtle_t &turt, double x){
	if (x <= 0.01);
	else{
		draw_square(turt, x);
		turt.turn_left(90);
		turt.forward_move(x);
		turt.turn_right(45);
		draw_tree(turt, (x / sqrt(2)));
		turt.forward_move(x / sqrt(2));
		turt.turn_right(90);
		draw_tree(turt, (x / sqrt(2)));
		turt.turn_left(90);
		turt.backward_move(x / sqrt(2));
		turt.turn_left(45);
		turt.backward_move(x);
		turt.turn_right(90);
	}
}

void draw_tree1(turtle_t &turt, double x){
	if (x <= 0.01);
	else{
		draw_square1(turt, x);
		turt.turn_right(90);
		turt.forward_move(x);
		turt.turn_left(45);
		draw_tree1(turt, (x / sqrt(2)));
		turt.turn_left(45);
		turt.forward_move(x);
		turt.turn_left(45);
		turt.backward_move(x / sqrt(2));
		draw_tree1(turt, (x / sqrt(2)));
		turt.forward_move(x / sqrt(2));
		turt.turn_right(45);
		turt.backward_move(x);
		turt.turn_left(90);
		turt.forward_move(x);
		turt.turn_right(90);
	}
}

void plant1(turtle_t &turt, double x){
	turt.reset();
	turt.clear();
	turt.set_col(0,1,0);
	turt.set_pos(-0.125, -0.25);
	draw_tree(turt, x);
	turt.reset();
}

void render_drawing(turtle_t &turt)
{
  //koch(turt, 1.0);
  plant1(turt, 0.25);
}
